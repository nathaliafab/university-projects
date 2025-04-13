grammar Arithmetic;

// Regras do Parser
expr: term ( (PLUS | MINUS) term )* ;
term: factor ( (MUL | DIV) factor )* ;
factor: INT | LPAREN expr RPAREN | VAR;

// Novas Regras do Parser
program: statement+ ;
statement: assignment | expr | ifstmt ;
assignment: VAR ASSIGN expr ;
ifstmt: 'if' (expr) 'then' (statement) ('else' (statement))? ;

// Regras do Lexer
PLUS: '+' ;
MINUS: '-' ;
MUL: '*' ;
DIV: '/' ;
INT: [0-9]+ ;
LPAREN: '(' ;
RPAREN: ')' ;
WS: [ \t\r\n]+ -> skip ;
   
// Novas Regras do Lexer
VAR: [a-zA-Z]+ ;
ASSIGN: '=' ;