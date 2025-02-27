from symboltable import *
from exceptions import *

class NodeVisitor(object):
    def visit(self, node):
        method_name = 'visit_' + type(node).__name__
        visitor = getattr(self, method_name, self.generic_visit)
        return visitor(node)

    def generic_visit(self, node):
        raise Exception('No visit_{} method'.format(type(node).__name__))

class GenericVisitor(NodeVisitor):
    def __init__(self,tree):
        self.ast = tree

    def traverse(self):
        self.visit(self.ast)
    
    def erro(self,msg):
        raise Exception(msg)

    def undeclaredVariable(self,name):
        raise UndeclaredVariable(name)

    def alreadyDeclaredVariable(self,name):
        raise AlreadyDeclaredVariable(name)

    def varTypeMismatch(self,name, expected, actual):
        raise VarTypeMismatch(name, expected, actual)

    def booleanExpTypeMismatch(self, stmt, actual):
        raise BooleanExpTypeMismatch(stmt, actual)

    def arithExpTypeMismatch(self, left_type, right_type):
        raise ArithExpTypeMismatch(left_type, right_type)

    def relExpTypeMismatch(self, left_type, right_type):
        raise RelExpTypeMismatch(left_type, right_type)

    def visit_Program(self,node):
        for stmt in node.stmts:
            self.visit(stmt)
    def visit_LetStmt(self, node):
        self.visit(node.exp)
    def visit_VarDeclStmt(self,node):
        pass
    def visit_PrintStmt(self,node):
        self.visit(node.exp)
    def visit_InputStmt(self,node):
        pass
    def visit_BlockStmt(self,node):
        for stm in node.body: 
            self.visit(stm)
    def visit_WhileStmt(self,node):
        self.visit(node.cond)
        for stm in node.body: 
            self.visit(stm)
    def visit_IfStmt(self,node):
        self.visit(node.cond)
        for stm in node.body: 
            self.visit(stm)

    def visit_NumExpr(self, node):
        pass
    def visit_IdExpr(self,node):
        pass
    def visit_StringExpr(self, node):
        pass    
    def visit_GreaterThanExpr(self,node):
        self.visit(node.left)
        self.visit(node.right)
    def visit_GreaterThanEqualsExpr(self,node):
        self.visit(node.left)
        self.visit(node.right)
    def visit_LessThanExpr(self,node):
        self.visit(node.left)
        self.visit(node.right)
    def visit_LessThanEqualsExpr(self,node):
        self.visit(node.left)
        self.visit(node.right)
    def visit_EqualsExpr(self,node):
        self.visit(node.left)
        self.visit(node.right)
    def visit_NotEqualsExpr(self,node):
        self.visit(node.left)
        self.visit(node.right)
    def visit_UnaryPlusExpr(self,node):
        self.visit(node.exp)
    def visit_UnaryMinusExpr(self,node):
        self.visit(node.exp)    
    def visit_SumExpr(self,node):
        self.visit(node.left)
        self.visit(node.right)
    def visit_SubExpr(self,node):
        self.visit(node.left)
        self.visit(node.right)
    def visit_MulExpr(self,node):
        self.visit(node.left)
        self.visit(node.right)
    def visit_DivExpr(self,node):
        self.visit(node.left)
        self.visit(node.right)

        
class TypeCheckVisitor(GenericVisitor):
    def __init__(self, tree):
        super().__init__(tree)
        self.symbolTable = ScopedSymbolTable(
            scope_name='program',
            scope_level=1
        )

    def typecheck(self):
        self.traverse()
    
    def BOOLEAN(self):
        return self.symbolTable.lookup('BOOLEAN')
    def INT(self):
        return self.symbolTable.lookup('INT')
    def STRING(self):
        return self.symbolTable.lookup('STRING')

    def visit_InputStmt(self, node):
        pass

    def visit_LetStmt(self, node):
        pass

    def visit_VarDeclStmt(self, node):
        pass

    def visit_WhileStmt(self, node):
        pass

    def visit_IfStmt(self, node):
        pass

    def visit_BlockStmt(self, node):
        pass

    def visit_NumExpr(self, node):
        pass

    def visit_StringExpr(self, node):
        pass

    def visit_IdExpr(self, node):
        pass

    def visit_SumExpr(self, node):
        pass
    
    def visit_SubExpr(self, node):
        pass
    
    def visit_DivExpr(self, node):
        pass
    
    def visit_MulExpr(self, node):
        pass
    
    def visit_GreaterThanExpr(self, node):
        pass

    def visit_GreaterThanEqualsExpr(self, node):
        pass

    def visit_LessThanEqualsExpr(self, node):
        pass

    def visit_LessThanExpr(self, node):
        pass

    def visit_EqualsExpr(self, node):
        pass

    def visit_NotEqualsExpr(self, node):
        pass
