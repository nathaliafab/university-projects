# Generated from Arithmetic.g4 by ANTLR 4.13.2
# encoding: utf-8
from antlr4 import *
from io import StringIO
import sys
if sys.version_info[1] > 5:
	from typing import TextIO
else:
	from typing.io import TextIO

def serializedATN():
    return [
        4,1,13,61,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
        6,1,0,1,0,1,0,5,0,18,8,0,10,0,12,0,21,9,0,1,1,1,1,1,1,5,1,26,8,1,
        10,1,12,1,29,9,1,1,2,1,2,1,2,1,2,1,2,1,2,3,2,37,8,2,1,3,4,3,40,8,
        3,11,3,12,3,41,1,4,1,4,1,4,3,4,47,8,4,1,5,1,5,1,5,1,5,1,6,1,6,1,
        6,1,6,1,6,1,6,3,6,59,8,6,1,6,0,0,7,0,2,4,6,8,10,12,0,2,1,0,4,5,1,
        0,6,7,61,0,14,1,0,0,0,2,22,1,0,0,0,4,36,1,0,0,0,6,39,1,0,0,0,8,46,
        1,0,0,0,10,48,1,0,0,0,12,52,1,0,0,0,14,19,3,2,1,0,15,16,7,0,0,0,
        16,18,3,2,1,0,17,15,1,0,0,0,18,21,1,0,0,0,19,17,1,0,0,0,19,20,1,
        0,0,0,20,1,1,0,0,0,21,19,1,0,0,0,22,27,3,4,2,0,23,24,7,1,0,0,24,
        26,3,4,2,0,25,23,1,0,0,0,26,29,1,0,0,0,27,25,1,0,0,0,27,28,1,0,0,
        0,28,3,1,0,0,0,29,27,1,0,0,0,30,37,5,8,0,0,31,32,5,9,0,0,32,33,3,
        0,0,0,33,34,5,10,0,0,34,37,1,0,0,0,35,37,5,12,0,0,36,30,1,0,0,0,
        36,31,1,0,0,0,36,35,1,0,0,0,37,5,1,0,0,0,38,40,3,8,4,0,39,38,1,0,
        0,0,40,41,1,0,0,0,41,39,1,0,0,0,41,42,1,0,0,0,42,7,1,0,0,0,43,47,
        3,10,5,0,44,47,3,0,0,0,45,47,3,12,6,0,46,43,1,0,0,0,46,44,1,0,0,
        0,46,45,1,0,0,0,47,9,1,0,0,0,48,49,5,12,0,0,49,50,5,13,0,0,50,51,
        3,0,0,0,51,11,1,0,0,0,52,53,5,1,0,0,53,54,3,0,0,0,54,55,5,2,0,0,
        55,58,3,8,4,0,56,57,5,3,0,0,57,59,3,8,4,0,58,56,1,0,0,0,58,59,1,
        0,0,0,59,13,1,0,0,0,6,19,27,36,41,46,58
    ]

class ArithmeticParser ( Parser ):

    grammarFileName = "Arithmetic.g4"

    atn = ATNDeserializer().deserialize(serializedATN())

    decisionsToDFA = [ DFA(ds, i) for i, ds in enumerate(atn.decisionToState) ]

    sharedContextCache = PredictionContextCache()

    literalNames = [ "<INVALID>", "'if'", "'then'", "'else'", "'+'", "'-'", 
                     "'*'", "'/'", "<INVALID>", "'('", "')'", "<INVALID>", 
                     "<INVALID>", "'='" ]

    symbolicNames = [ "<INVALID>", "<INVALID>", "<INVALID>", "<INVALID>", 
                      "PLUS", "MINUS", "MUL", "DIV", "INT", "LPAREN", "RPAREN", 
                      "WS", "VAR", "ASSIGN" ]

    RULE_expr = 0
    RULE_term = 1
    RULE_factor = 2
    RULE_program = 3
    RULE_statement = 4
    RULE_assignment = 5
    RULE_ifstmt = 6

    ruleNames =  [ "expr", "term", "factor", "program", "statement", "assignment", 
                   "ifstmt" ]

    EOF = Token.EOF
    T__0=1
    T__1=2
    T__2=3
    PLUS=4
    MINUS=5
    MUL=6
    DIV=7
    INT=8
    LPAREN=9
    RPAREN=10
    WS=11
    VAR=12
    ASSIGN=13

    def __init__(self, input:TokenStream, output:TextIO = sys.stdout):
        super().__init__(input, output)
        self.checkVersion("4.13.2")
        self._interp = ParserATNSimulator(self, self.atn, self.decisionsToDFA, self.sharedContextCache)
        self._predicates = None




    class ExprContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def term(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(ArithmeticParser.TermContext)
            else:
                return self.getTypedRuleContext(ArithmeticParser.TermContext,i)


        def PLUS(self, i:int=None):
            if i is None:
                return self.getTokens(ArithmeticParser.PLUS)
            else:
                return self.getToken(ArithmeticParser.PLUS, i)

        def MINUS(self, i:int=None):
            if i is None:
                return self.getTokens(ArithmeticParser.MINUS)
            else:
                return self.getToken(ArithmeticParser.MINUS, i)

        def getRuleIndex(self):
            return ArithmeticParser.RULE_expr

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterExpr" ):
                listener.enterExpr(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitExpr" ):
                listener.exitExpr(self)




    def expr(self):

        localctx = ArithmeticParser.ExprContext(self, self._ctx, self.state)
        self.enterRule(localctx, 0, self.RULE_expr)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 14
            self.term()
            self.state = 19
            self._errHandler.sync(self)
            _la = self._input.LA(1)
            while _la==4 or _la==5:
                self.state = 15
                _la = self._input.LA(1)
                if not(_la==4 or _la==5):
                    self._errHandler.recoverInline(self)
                else:
                    self._errHandler.reportMatch(self)
                    self.consume()
                self.state = 16
                self.term()
                self.state = 21
                self._errHandler.sync(self)
                _la = self._input.LA(1)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class TermContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def factor(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(ArithmeticParser.FactorContext)
            else:
                return self.getTypedRuleContext(ArithmeticParser.FactorContext,i)


        def MUL(self, i:int=None):
            if i is None:
                return self.getTokens(ArithmeticParser.MUL)
            else:
                return self.getToken(ArithmeticParser.MUL, i)

        def DIV(self, i:int=None):
            if i is None:
                return self.getTokens(ArithmeticParser.DIV)
            else:
                return self.getToken(ArithmeticParser.DIV, i)

        def getRuleIndex(self):
            return ArithmeticParser.RULE_term

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterTerm" ):
                listener.enterTerm(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitTerm" ):
                listener.exitTerm(self)




    def term(self):

        localctx = ArithmeticParser.TermContext(self, self._ctx, self.state)
        self.enterRule(localctx, 2, self.RULE_term)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 22
            self.factor()
            self.state = 27
            self._errHandler.sync(self)
            _la = self._input.LA(1)
            while _la==6 or _la==7:
                self.state = 23
                _la = self._input.LA(1)
                if not(_la==6 or _la==7):
                    self._errHandler.recoverInline(self)
                else:
                    self._errHandler.reportMatch(self)
                    self.consume()
                self.state = 24
                self.factor()
                self.state = 29
                self._errHandler.sync(self)
                _la = self._input.LA(1)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class FactorContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def INT(self):
            return self.getToken(ArithmeticParser.INT, 0)

        def LPAREN(self):
            return self.getToken(ArithmeticParser.LPAREN, 0)

        def expr(self):
            return self.getTypedRuleContext(ArithmeticParser.ExprContext,0)


        def RPAREN(self):
            return self.getToken(ArithmeticParser.RPAREN, 0)

        def VAR(self):
            return self.getToken(ArithmeticParser.VAR, 0)

        def getRuleIndex(self):
            return ArithmeticParser.RULE_factor

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterFactor" ):
                listener.enterFactor(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitFactor" ):
                listener.exitFactor(self)




    def factor(self):

        localctx = ArithmeticParser.FactorContext(self, self._ctx, self.state)
        self.enterRule(localctx, 4, self.RULE_factor)
        try:
            self.state = 36
            self._errHandler.sync(self)
            token = self._input.LA(1)
            if token in [8]:
                self.enterOuterAlt(localctx, 1)
                self.state = 30
                self.match(ArithmeticParser.INT)
                pass
            elif token in [9]:
                self.enterOuterAlt(localctx, 2)
                self.state = 31
                self.match(ArithmeticParser.LPAREN)
                self.state = 32
                self.expr()
                self.state = 33
                self.match(ArithmeticParser.RPAREN)
                pass
            elif token in [12]:
                self.enterOuterAlt(localctx, 3)
                self.state = 35
                self.match(ArithmeticParser.VAR)
                pass
            else:
                raise NoViableAltException(self)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class ProgramContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def statement(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(ArithmeticParser.StatementContext)
            else:
                return self.getTypedRuleContext(ArithmeticParser.StatementContext,i)


        def getRuleIndex(self):
            return ArithmeticParser.RULE_program

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterProgram" ):
                listener.enterProgram(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitProgram" ):
                listener.exitProgram(self)




    def program(self):

        localctx = ArithmeticParser.ProgramContext(self, self._ctx, self.state)
        self.enterRule(localctx, 6, self.RULE_program)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 39 
            self._errHandler.sync(self)
            _la = self._input.LA(1)
            while True:
                self.state = 38
                self.statement()
                self.state = 41 
                self._errHandler.sync(self)
                _la = self._input.LA(1)
                if not ((((_la) & ~0x3f) == 0 and ((1 << _la) & 4866) != 0)):
                    break

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class StatementContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def assignment(self):
            return self.getTypedRuleContext(ArithmeticParser.AssignmentContext,0)


        def expr(self):
            return self.getTypedRuleContext(ArithmeticParser.ExprContext,0)


        def ifstmt(self):
            return self.getTypedRuleContext(ArithmeticParser.IfstmtContext,0)


        def getRuleIndex(self):
            return ArithmeticParser.RULE_statement

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterStatement" ):
                listener.enterStatement(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitStatement" ):
                listener.exitStatement(self)




    def statement(self):

        localctx = ArithmeticParser.StatementContext(self, self._ctx, self.state)
        self.enterRule(localctx, 8, self.RULE_statement)
        try:
            self.state = 46
            self._errHandler.sync(self)
            la_ = self._interp.adaptivePredict(self._input,4,self._ctx)
            if la_ == 1:
                self.enterOuterAlt(localctx, 1)
                self.state = 43
                self.assignment()
                pass

            elif la_ == 2:
                self.enterOuterAlt(localctx, 2)
                self.state = 44
                self.expr()
                pass

            elif la_ == 3:
                self.enterOuterAlt(localctx, 3)
                self.state = 45
                self.ifstmt()
                pass


        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class AssignmentContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def VAR(self):
            return self.getToken(ArithmeticParser.VAR, 0)

        def ASSIGN(self):
            return self.getToken(ArithmeticParser.ASSIGN, 0)

        def expr(self):
            return self.getTypedRuleContext(ArithmeticParser.ExprContext,0)


        def getRuleIndex(self):
            return ArithmeticParser.RULE_assignment

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterAssignment" ):
                listener.enterAssignment(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitAssignment" ):
                listener.exitAssignment(self)




    def assignment(self):

        localctx = ArithmeticParser.AssignmentContext(self, self._ctx, self.state)
        self.enterRule(localctx, 10, self.RULE_assignment)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 48
            self.match(ArithmeticParser.VAR)
            self.state = 49
            self.match(ArithmeticParser.ASSIGN)
            self.state = 50
            self.expr()
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class IfstmtContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def expr(self):
            return self.getTypedRuleContext(ArithmeticParser.ExprContext,0)


        def statement(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(ArithmeticParser.StatementContext)
            else:
                return self.getTypedRuleContext(ArithmeticParser.StatementContext,i)


        def getRuleIndex(self):
            return ArithmeticParser.RULE_ifstmt

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterIfstmt" ):
                listener.enterIfstmt(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitIfstmt" ):
                listener.exitIfstmt(self)




    def ifstmt(self):

        localctx = ArithmeticParser.IfstmtContext(self, self._ctx, self.state)
        self.enterRule(localctx, 12, self.RULE_ifstmt)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 52
            self.match(ArithmeticParser.T__0)

            self.state = 53
            self.expr()
            self.state = 54
            self.match(ArithmeticParser.T__1)

            self.state = 55
            self.statement()
            self.state = 58
            self._errHandler.sync(self)
            la_ = self._interp.adaptivePredict(self._input,5,self._ctx)
            if la_ == 1:
                self.state = 56
                self.match(ArithmeticParser.T__2)

                self.state = 57
                self.statement()


        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx





