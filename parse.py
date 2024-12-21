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
    def Program(self):
        self.MainClass()
        self.Classes()
    
    # MainClass ::= "class" <IDENTIFIER> "{" "public static void main(String[] a) { System.out.println(); } }
    def MainClass(self):
        self.match(TokenType.CLASS)
        self.match(TokenType.IDENT)
        self.match(TokenType.L_BRACK)
        self.match(TokenType.PUBLIC)
        self.match(TokenType.STATIC)
        self.match(TokenType.VOID)
        self.match(TokenType.MAIN)
        self.match(TokenType.L_PAREN)
        self.match(TokenType.STRING)
        self.match(TokenType.L_SQBRACK)
        self.match(TokenType.R_SQBRACK)
        self.match(TokenType.IDENT)
        self.match(TokenType.R_PAREN)
        self.match(TokenType.L_BRACK)
        self.match(TokenType.SYSTEM_OUT_PRINTLN)
        self.match(TokenType.L_PAREN)
        self.match(TokenType.R_PAREN)
        self.match(TokenType.SEMICOLON)
        self.match(TokenType.R_BRACK)
        self.match(TokenType.R_BRACK)

    # Classes ::= ClassDecl Classes | ϵ
    def Classes(self):
        if self.checkToken(TokenType.CLASS):
            self.ClassDecl()
            self.Classes()
        else:
            pass

    # ClassDecl ::= "class" <IDENTIFIER> ClassA
    def ClassDecl(self):
        self.match(TokenType.CLASS)
        self.match(TokenType.IDENT)
        self.ClassA()

    # ClassA ::= "extends" <IDENTIFIER> "{" ClassB | "{" ClassB
    def ClassA(self):
        if self.checkToken(TokenType.EXTENDS):
            self.match(TokenType.EXTENDS)
            self.match(TokenType.IDENT)
            self.match(TokenType.L_BRACK)
            self.ClassB()
        else:
            self.match(TokenType.L_BRACK)
            self.ClassB()

    # ClassB ::= "}"
    # | "static" VarDecl ClassB
    # | VarDecl ClassB
    # | "public" MethodDecl ClassC
    def ClassB(self):
        if self.checkToken(TokenType.R_BRACK):
            self.match(TokenType.R_BRACK)
        elif self.checkToken(TokenType.STATIC):
            self.match(TokenType.STATIC)
            self.VarDecl()
            self.ClassB()
        elif self.checkToken(TokenType.PUBLIC):
            self.match(TokenType.PUBLIC)
            self.MethodDecl()
            self.ClassC()
        else:
            self.VarDecl()
            self.ClassB()

    # ClassC ::= "}"
    # | "public" MethodDecl ClassC
    def ClassC(self):
        if self.checkToken(TokenType.R_BRACK):
            self.match(TokenType.R_BRACK)
        elif self.checkToken(TokenType.PUBLIC):
            self.match(TokenType.PUBLIC)
            self.MethodDecl()
            self.ClassC()

    # VarDecl ::= Type <IDENTIFIER> ";"
    def VarDecl(self):
        self.Type()
        self.match(TokenType.IDENT)
        self.match(TokenType.SEMICOLON)

    # MethodDecl ::= Type <IDENTIFIER> "(" MethodA
    def MethodDecl(self):
        self.Type()
        self.match(TokenType.IDENT)
        self.match(TokenType.L_PAREN)
        self.MethodA()

    # MethodA ::= ")" "{" "}"
    # | Type <IDENTIFIER> MethodB
    def MethodA(self):
        if self.checkToken(TokenType.R_PAREN):
            self.match(TokenType.R_PAREN)
            self.match(TokenType.L_BRACK)
            self.match(TokenType.R_BRACK)
        else:
            self.Type()
            self.match(TokenType.IDENT)
            self.MethodB()

    # MethodB ::= ")" "{" "}"
    # | "," Type <IDENTIFIER> MethodB
    def MethodB(self):
        if self.checkToken(TokenType.R_PAREN):
            self.match(TokenType.R_PAREN)
            self.match(TokenType.L_BRACK)
            self.match(TokenType.R_BRACK)
        else:
            self.match(TokenType.COMMA)
            self.Type()
            self.match(TokenType.IDENT)
            self.MethodB()

    # Type ::= SimpleType ArrayPart
    def Type(self):
        self.SimpleType()
        self.ArrayPart()

    # SimpleType ::= "boolean"
    # | "float"
    # | "int"
    # | <IDENTIFIER>
    def SimpleType(self):
        if self.checkToken(TokenType.BOOLEAN):
            self.match(TokenType.BOOLEAN)
        elif self.checkToken(TokenType.INT):
            self.match(TokenType.INT)
        elif self.checkToken(TokenType.IDENT):
            self.match(TokenType.IDENT)

    # ArrayPart ::= ϵ
    # | "[" "]" ArrayPart
    def ArrayPart(self):
        print("ArrayPart")
        print(self.tokenAtual.kind)

        if self.checkToken(TokenType.L_SQBRACK):
            self.match(TokenType.L_SQBRACK)
            self.match(TokenType.R_SQBRACK)
            self.ArrayPart()

    def parse(self):
        self.Program()
        self.match(TokenType.EOF)
        return True
        
    # Program ::= MainClass Classes
    def Program(self):
        self.MainClass()
        self.Classes()
