import sys
from lexer import *

class ParseException(Exception):
    pass

class Parser: 
    def __init__(self, lexer):
        self.lexer = lexer
        self.tokenAtual = None
        self.proximoToken = None
        self.nextToken()
        self.nextToken()

    #Retorna true se o Token **atual** casa com tipo de Token esperado
    def checkToken(self, tipo):
        return tipo == self.tokenAtual.kind

    #Retorna true se o próximo Token **(peek)** casa com tipo de Token esperado
    def checkPeek(self, tipo):
        return tipo == self.proximoToken.kind

    #Tenta fazer o casamento do Token atual. Se conseguir, avança para o próximo Token. Do contrário, gera mensagem de erro.
    def match(self, tipo):
        if not self.checkToken(tipo):
            self.abort("Esperava por token do tipo " + tipo.name + ", mas apareceu " + self.tokenAtual.kind.name)
        else:
            self.nextToken()

    # Avançando com os ponteiros dos tokens (atual e peek)
    def nextToken(self):
        self.tokenAtual = self.proximoToken
        self.proximoToken = self.lexer.getToken()

    def abort(self, msg):
        raise ParseException("Erro sintático: "+msg)

    # MINIJAVA GRAMMAR
    # Program ::= MainClass Classes
    # Classes ::= ClassDecl Classes | ϵ
    # ClassDecl ::= "class" <IDENTIFIER> ClassA
    # ClassA ::= "extends" <IDENTIFIER> "{" ClassB | "{" ClassB
    # ClassB ::= "}"
    # | "static" VarDecl ClassB
    # | VarDecl ClassB
    # | "public" MethodDecl ClassC
    # ClassC ::= "}"
    # | "public" MethodDecl ClassC
    # VarDecl ::= Type <IDENTIFIER> ";"
    # MethodDecl ::= Type <IDENTIFIER> "(" MethodA
    # MethodA ::= ")" "{" "}"
    # | Type <IDENTIFIER> MethodB
    # MethodB ::= ")" "{" "}"
    # | "," Type <IDENTIFIER> MethodB
    # Type ::= SimpleType ArrayPart
    # SimpleType ::= "boolean"
    # | "float"
    # | "int"
    # | <IDENTIFIER>
    # ArrayPart ::= ϵ
    # | "[" "]" ArrayPart


    def parse(self):
        self.Program()
        self.match(TokenType.EOF)
        return True
        
    # Program ::= MainClass Classes
    def Program(self):
        pass
