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
        #Completar a implementação construindo conjuntos FIRST para cada um dos não-terminais
    
    #TODO implementar construção dos conjuntos FOLLOW da gramática
    def buildFollowSets(self):
        #Condição inicial dos conjuntos FOLLOW
        for nt in self.nonTerminals:
            self.followSet[nt] = set()
        self.followSet[self.startSymbol].add(EOF)
        #Completar a implementação construindo conjuntos FOLLOW para cada um dos não-terminais


    #TODO implementar geração da tabela de parsing da gramática
    def generateParsingTable(self):
        #Estrutura da tabela
        for nt in self.nonTerminals:
            self.parsingTable[nt] = {}
            for t in self.terminals:
                self.parsingTable[nt][t.name] = []
            #Adicionando EOF como coluna
            self.parsingTable[nt]['$'] = []

    #TODO implementar checagem da gramática. Retorna True se a gramática é LL(1), False do contrário.
    def checkIfLL1(self):
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