import enum
import sys

class SymbolType(enum.Enum):
    TERMINAL = 0
    NONTERMINAL = 1
    EPSILON = 2
    EOF = 3

class Symbol:
    def __init__(self,name,type):
        self.name = name
        self.type = type
    def __repr__(self):
        return self.__str__()
    def __str__(self):
        return self.name

class Nonterminal(Symbol):
    def __init__(self, name):
        super().__init__(name, SymbolType.NONTERMINAL)

class Terminal(Symbol):
    def __init__(self, name):
        super().__init__(name, SymbolType.TERMINAL)

class SpecialSymbol(Symbol):
    def __init__(self, name, type):
        if type == SymbolType.EPSILON or type == SymbolType.EOF: 
            super().__init__(name, type)
        else: 
            sys.exit('Tipo inválido')

EPSILON = SpecialSymbol('ε', SymbolType.EPSILON)
EOF = SpecialSymbol('$', SymbolType.EOF)

class Rule: 
    def __init__(self, nt, production):
        self.nonterminal = nt
        self.production = production
    def __str__(self):
        return str(self.nonterminal) + " -> " + ' '.join([str(e) for e in self.production])

class Grammar:
    def __init__(self, productions, startSymbol):
        self.productions = productions
        self.startSymbol = startSymbol
        self.nonTerminals = set()
        self.terminals = set()
        for p in productions:
            self.nonTerminals.add(p.nonterminal)
            for s in p.production:
                if isinstance(s,Terminal):
                    self.terminals.add(s)

        self.firstSet = {}
        self.followSet = {}
        self.parsingTable = {}
        self.buildFirstSets()
        self.buildFollowSets()
        self.generateParsingTable()
    
    #TODO implementar construção dos conjuntos FIRST da gramática
    def buildFirstSets(self):
        #Condição inicial dos conjuntos FIRST (incluindo definição de FIRST(t)=t onde t é um terminal, EOF, ou EPSILON)
        self.firstSet[EOF] = {EOF}
        self.firstSet[EPSILON] = {EPSILON}
        for t in self.terminals:
            self.firstSet[t] = {t}
        for nt in self.nonTerminals:
            self.firstSet[nt] = set()
            for p in self.productions:
                lhs = p.nonterminal
                rhs = p.production

                if lhs == nt:
                    if rhs[0] in self.terminals:
                        self.firstSet[nt].add(rhs[0])

                    elif rhs[0] == EPSILON:
                        self.firstSet[nt].add(EPSILON)

                    elif rhs[0] in self.nonTerminals and rhs[0] != nt:
                        self.firstSet[nt].add(rhs[0])

                        for pp in self.productions:
                            if pp.nonterminal == rhs[0]:
                                if pp.production[0] == EPSILON and len(rhs) > 1:
                                    self.firstSet[nt].add(rhs[1])
                                    break
            
        for nt in self.nonTerminals:
            while self.nonTerminals.intersection(self.firstSet[nt]):
                for nnt in self.nonTerminals.intersection(self.firstSet[nt]):
                    self.firstSet[nt].remove(nnt)
                    self.firstSet[nt].update(self.firstSet[nnt])

            canRemoveEpsilon = True
            for p in self.productions:
                lhs = p.nonterminal
                rhs = p.production
                if lhs == nt and rhs[0] == EPSILON:
                    canRemoveEpsilon = False
                    break
            
            if canRemoveEpsilon and EPSILON in self.firstSet[nt]:
                self.firstSet[nt].remove(EPSILON)
    
    #TODO implementar construção dos conjuntos FOLLOW da gramática
    def buildFollowSets(self):
        #Condição inicial dos conjuntos FOLLOW
        for nt in self.nonTerminals:
            self.followSet[nt] = set()
        self.followSet[self.startSymbol].add(EOF)

        changed = True
        while changed:
            changed = False
            for p in self.productions:
                lhs = p.nonterminal
                rhs = p.production
                
                for i, nt in enumerate(rhs):
                    if nt in self.nonTerminals:
                        followingSymbols = rhs[i + 1:]

                        if followingSymbols:
                            for s in followingSymbols:
                                if s in self.terminals:
                                    if s not in self.followSet[nt]:
                                        self.followSet[nt].add(s)
                                        changed = True
                                    break
                                else:
                                    prevSize = len(self.followSet[nt])
                                    self.followSet[nt].update(self.firstSet[s] - {EPSILON})
                                    if len(self.followSet[nt]) > prevSize:
                                        changed = True

                                    if EPSILON not in self.firstSet[s]:
                                        break
                            else:
                                prevSize = len(self.followSet[nt])
                                self.followSet[nt].update(self.followSet[lhs])
                                if len(self.followSet[nt]) > prevSize:
                                    changed = True
                        else:
                            prevSize = len(self.followSet[nt])
                            self.followSet[nt].update(self.followSet[lhs])
                            if len(self.followSet[nt]) > prevSize:
                                changed = True


    #TODO implementar geração da tabela de parsing da gramática
    def generateParsingTable(self):
        #Estrutura da tabela
        for nt in self.nonTerminals:
            self.parsingTable[nt] = {}
            for t in self.terminals:
                self.parsingTable[nt][t.name] = []
            #Adicionando EOF como coluna
            self.parsingTable[nt]['$'] = []

        for p in self.productions:
            lhs = p.nonterminal
            rhs = p.production

            for i, s in enumerate(rhs):
                if s in self.terminals and rhs not in self.parsingTable[lhs][s.name]:
                    self.parsingTable[lhs][s.name].append(rhs)
                    break
                elif s == EPSILON:
                    for t in self.followSet[lhs]:
                        if rhs not in self.parsingTable[lhs][t.name]:
                            self.parsingTable[lhs][t.name].append(rhs)
                elif s in self.nonTerminals:
                    for t in self.firstSet[s]:
                        if t != EPSILON and rhs not in self.parsingTable[lhs][t.name]:
                            self.parsingTable[lhs][t.name].append(rhs)
                    if EPSILON in self.firstSet[s]:
                        for t in self.followSet[s]:
                            if rhs not in self.parsingTable[lhs][t.name]:
                                self.parsingTable[lhs][t.name].append(rhs)
        print(self.parsingTable)

    #TODO implementar checagem da gramática. Retorna True se a gramática é LL(1), False do contrário.
    def checkIfLL1(self):
        for nt in self.nonTerminals:
            for t in self.terminals:
                if len(self.parsingTable[nt][t.name]) > 1:
                    return False
        return True

    #Algoritmo de parsing, assume que cada caractere é um token 
    #NÃO É NECESSÁRIO MUDAR ESTE ALGORITMO
    def parse(self, sentence): 
        if not self.checkIfLL1():
            return 'Erro, gramática não é LL(1)!'
        else:
            size = len(sentence)
            i = 0
            stack = [EOF, self.startSymbol]
            a = sentence[i] 
            X = stack[len(stack)-1]
            while X != EOF:
                if type(X) == Terminal: 
                    if X.name == a: 
                        stack.pop()
                        i = i+1
                        if i < size:
                            a = sentence[i]
                        else: 
                            a = '$'
                    else:
                        return 'Erro sintático, esperava por '+X.name+' e apareceu '+a+'!'
                elif type(X) == Nonterminal:  
                    if len(self.parsingTable[X][a]) == 0:
                        return 'Erro sintático, caractere inesperado para resolver não-terminal '+X.name+': ' + a
                    elif len(self.parsingTable[X][a]) == 1:
                        stack.pop()
                        for s in reversed(self.parsingTable[X][a][0]):
                            if s != EPSILON:
                                stack.append(s)
                else:
                    return 'Tem algo errado com a tabela de parsing.'
                X = stack[len(stack)-1]
            if a == '$':
                return 'Palavra válida'
            else: 
                return 'Erro sintático, esperava por $ e apareceu: '+a