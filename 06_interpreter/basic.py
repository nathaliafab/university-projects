from lexer import *
from parser import *
from visitor import *
import sys

def main(): 
    if len(sys.argv) != 2:
        sys.exit("Erro: Precisamos de um arquivo como argumento.")
    with open(sys.argv[1], 'r') as inputFile:
        input = inputFile.read()

    lexer = Lexer(input)
    parser = Parser(lexer)
    program = parser.parse()
    print(program)
    
    # Type checking
    type_checker = TypeCheckVisitor(program)
    print(type_checker.symbolTable)
    type_checker.typecheck()
    print(type_checker.symbolTable)
    
    # Interpretador
    interpreter = InterpreterVisitor(program)
    interpreter.traverse()
    print(interpreter.variables)
main()