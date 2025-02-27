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
        symbol = self.symbolTable.lookup(node.id)
        if symbol is None:
            self.undeclaredVariable(node.id)

    def visit_LetStmt(self, node):
        symbol = self.symbolTable.lookup(node.id)
        if symbol is None:
            self.undeclaredVariable(node.id)
        
        symbol_type = self.symbolTable.lookup(symbol)
        exp_type = self.visit(node.exp)

        print('symbol_type:', symbol_type)
        print('exp_type:', exp_type)
        if symbol_type != exp_type:
            self.varTypeMismatch(node.id, symbol_type.__str__(), exp_type.__str__())

    def visit_VarDeclStmt(self, node):
        print(self.symbolTable.symbols)
        symbol = self.symbolTable.lookup(node.id, current_scope_only=True)
        if symbol is not None:
            # Se já foi declarado no escopo atual, erro. não tem problema se foi declarado em um escopo acima
            self.alreadyDeclaredVariable(node.id)
        # Se não foi declarado ainda no escopo atual, insere
        self.symbolTable.insert(node.id, node.type)

    def visit_WhileStmt(self, node):
        cond_type = self.visit(node.cond)
        if cond_type != self.BOOLEAN():
            self.booleanExpTypeMismatch('WHILE', cond_type.__str__())
        for stmt in node.body:
            self.visit(stmt)

    def visit_IfStmt(self, node):
        cond_type = self.visit(node.cond)
        if cond_type != self.BOOLEAN():
            self.booleanExpTypeMismatch('IF', cond_type.__str__())
        for stmt in node.body:
            self.visit(stmt)

    def visit_BlockStmt(self, node):
        old_scope = self.symbolTable
        self.symbolTable = ScopedSymbolTable(
            scope_name=node.name,
            scope_level=old_scope.scope_level + 1,
            enclosing_scope=old_scope
        )

        for stmt in node.body:
            self.visit(stmt)
        self.symbolTable = self.symbolTable.enclosing_scope

    def visit_NumExpr(self, node):
        return self.INT()

    def visit_StringExpr(self, node):
        return self.STRING()

    def visit_IdExpr(self, node):
        symbol = self.symbolTable.lookup(node.id)
        if symbol is None:
            self.undeclaredVariable(node.id)
        return self.symbolTable.lookup(symbol)

    def visit_SumExpr(self, node):
        left_type = self.visit(node.left)
        right_type = self.visit(node.right)
        if left_type != self.INT() or right_type != self.INT():
            self.arithExpTypeMismatch(left_type, right_type)
        return self.INT()
    
    def visit_SubExpr(self, node):
        left_type = self.visit(node.left)
        right_type = self.visit(node.right)
        if left_type != self.INT() or right_type != self.INT():
            self.arithExpTypeMismatch(left_type, right_type)
        return self.INT()
    
    def visit_DivExpr(self, node):
        left_type = self.visit(node.left)
        right_type = self.visit(node.right)
        if left_type != self.INT() or right_type != self.INT():
            self.arithExpTypeMismatch(left_type, right_type)
        return self.INT()
    
    def visit_MulExpr(self, node):
        left_type = self.visit(node.left)
        right_type = self.visit(node.right)
        if left_type != self.INT() or right_type != self.INT():
            self.arithExpTypeMismatch(left_type, right_type)
        return self.INT()
    
    def visit_GreaterThanExpr(self, node):
        left_type = self.visit(node.left)
        right_type = self.visit(node.right)
        if left_type != self.INT() or right_type != self.INT():
            self.relExpTypeMismatch(left_type, right_type)
        return self.BOOLEAN()

    def visit_GreaterThanEqualsExpr(self, node):
        left_type = self.visit(node.left)
        right_type = self.visit(node.right)
        if left_type != self.INT() or right_type != self.INT():
            self.relExpTypeMismatch(left_type, right_type)
        return self.BOOLEAN()

    def visit_LessThanEqualsExpr(self, node):
        left_type = self.visit(node.left)
        right_type = self.visit(node.right)
        if left_type != self.INT() or right_type != self.INT():
            self.relExpTypeMismatch(left_type, right_type)
        return self.BOOLEAN()

    def visit_LessThanExpr(self, node):
        left_type = self.visit(node.left)
        right_type = self.visit(node.right)
        if left_type != self.INT() or right_type != self.INT():
            self.relExpTypeMismatch(left_type, right_type)
        return self.BOOLEAN()

    def visit_EqualsExpr(self, node):
        left_type = self.visit(node.left)
        right_type = self.visit(node.right)
        if left_type != right_type:
            self.relExpTypeMismatch(left_type, right_type)
        return self.BOOLEAN()

    def visit_NotEqualsExpr(self, node):
        left_type = self.visit(node.left)
        right_type = self.visit(node.right)
        if left_type != right_type:
            self.relExpTypeMismatch(left_type, right_type)
        return self.BOOLEAN()
