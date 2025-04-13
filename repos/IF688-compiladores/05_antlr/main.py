from antlr4 import *
from ArithmeticLexer import ArithmeticLexer
from ArithmeticParser import ArithmeticParser

class ArithmeticVisitor:
    def __init__(self):
        self.vars = {}

    def visit(self, ctx):
        if isinstance(ctx, ArithmeticParser.ProgramContext):
            #print("Program")
            return self.visitProgram(ctx)
        elif isinstance(ctx, ArithmeticParser.StatementContext):
            #print("Statement")
            return self.visitStatement(ctx)
        elif isinstance(ctx, ArithmeticParser.AssignmentContext):
            #print("Assignment")
            return self.visitAssignment(ctx)
        elif isinstance(ctx, ArithmeticParser.ExprContext):
            #print("Expr")
            return self.visitExpr(ctx)
        elif isinstance(ctx, ArithmeticParser.TermContext):
            #print("Term")
            return self.visitTerm(ctx)
        elif isinstance(ctx, ArithmeticParser.FactorContext):
            #print("Factor")
            return self.visitFactor(ctx)
        elif isinstance(ctx, ArithmeticParser.IfstmtContext):
            return self.visitIfstmt(ctx)

    def visitExpr(self, ctx):
        result = self.visit(ctx.term(0))
        for i in range(1, len(ctx.term())):
            if ctx.getChild(i * 2 - 1).getText() == '+':
                result += self.visit(ctx.term(i))
            else:
                result -= self.visit(ctx.term(i))
        return result

    def visitTerm(self, ctx):
        result = self.visit(ctx.factor(0))
        for i in range(1, len(ctx.factor())):
            if ctx.getChild(i * 2 - 1).getText() == '*':
                result *= self.visit(ctx.factor(i))
            else:
                result /= self.visit(ctx.factor(i))
        return result

    def visitFactor(self, ctx):
        if ctx.INT():
            return int(ctx.INT().getText())
        elif ctx.VAR():
            var = ctx.VAR().getText()
            if var in self.vars:
                return self.vars[var]
            else:
                raise Exception(f"Variável '{var}' não foi definida.")
        else:
            return self.visit(ctx.expr())
        
    #program: statement+ ;
    #statement: assignment | expr | ifstmt ;
    #assignment: VAR ASSIGN expr ;
    #ifstmt: 'if' (expr) 'then' (statement) ('else' (statement))? ;

    def visitProgram(self, ctx):
        result = None
        for i in range(ctx.getChildCount()):
            result = self.visit(ctx.getChild(i))
        return result

    def visitStatement(self, ctx):
        return self.visit(ctx.getChild(0))
    
    def visitAssignment(self, ctx):
        var = ctx.VAR().getText()
        value = self.visit(ctx.expr())
        self.vars[var] = value
        return value
    
    def visitIfstmt(self, ctx):
        if self.visit(ctx.expr()):
            return self.visit(ctx.statement(0))
        else:
            if ctx.statement(1):
                return self.visit(ctx.statement(1))
            else:
                return None

def main():
    visitor = ArithmeticVisitor()
    print("\n>>>> REPL [Digite uma expressão aritmética ou '1xau' para sair]")
    while True:
        try:
            expression = input("> ")  
            if expression.strip().lower() == '1xau':
                print("Xau!")
                break
            
            lexer = ArithmeticLexer(InputStream(expression))
            stream = CommonTokenStream(lexer)
            parser = ArithmeticParser(stream)
            tree = parser.program()
            result = visitor.visit(tree)
            
            print(">> ", result)
            print(">> ", visitor.vars)

        except Exception as e:
            print(f"Erro: {e}")

if __name__ == '__main__':
    main()