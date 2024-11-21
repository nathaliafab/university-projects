from lexer import *
import sys

def readFile(file): 
    input = None
    with open(file, 'r') as inputFile:
        input = inputFile.read()
    return input

def readTokens(input):
    lexer = Lexer(input)
    token = lexer.getToken()
    tokens = []
    tokens.append(token)
    while token.kind != TokenType.EOF:
        token = lexer.getToken()
        tokens.append(token)
    return tokens

def test_Simples():
    file = "data/Simples.java"
    tokens = readTokens(readFile(file))        

    assert TokenType.WHILE == tokens[19].kind
    assert TokenType.IDENT == tokens[24].kind
    assert TokenType.L_PAREN == tokens[25].kind
    assert TokenType.SEMICOLON == tokens[27].kind
    assert TokenType.L_BRACK == tokens[15].kind
    assert TokenType.R_BRACK == tokens[1].kind
    assert TokenType.STRING == tokens[8].kind
    assert TokenType.R_PAREN == tokens[7].kind
    assert TokenType.L_BRACK == tokens[3].kind
    assert TokenType.INT == tokens[17].kind
    assert TokenType.L_PAREN == tokens[14].kind
    assert TokenType.L_SQBRACK == tokens[9].kind
    assert TokenType.STATIC == tokens[11].kind
    assert TokenType.VOID == tokens[12].kind
    assert TokenType.DOT == tokens[23].kind
    assert TokenType.THIS == tokens[21].kind
    assert TokenType.R_SQBRACK == tokens[10].kind
    assert TokenType.PUBLIC == tokens[4].kind
    assert TokenType.THIS == tokens[22].kind
    assert TokenType.IDENT == tokens[2].kind
    assert TokenType.ELSE == tokens[18].kind
    assert TokenType.CLASS == tokens[0].kind
    assert 29 == len(tokens)
    assert TokenType.EOF == tokens[28].kind
    assert TokenType.NEW == tokens[5].kind
    assert TokenType.R_PAREN == tokens[26].kind
    assert TokenType.IF == tokens[20].kind
    assert TokenType.IDENT == tokens[16].kind
    assert TokenType.IDENT == tokens[13].kind
    assert TokenType.MAIN == tokens[6].kind

def test_Tokens():
    file = "data/Tokens.java"
    tokens = readTokens(readFile(file))        

    assert TokenType.LT == tokens[8].kind
    assert TokenType.STRING == tokens[21].kind
    assert TokenType.GT == tokens[10].kind
    assert TokenType.FOR == tokens[5].kind
    assert TokenType.GT == tokens[12].kind
    assert TokenType.L_SQBRACK == tokens[22].kind
    assert TokenType.R_PAREN == tokens[39].kind
    assert TokenType.EOF == tokens[42].kind
    assert TokenType.BREAK == tokens[41].kind
    assert TokenType.CLASS == tokens[0].kind
    assert TokenType.IDENT == tokens[37].kind
    assert TokenType.THIS == tokens[35].kind
    assert TokenType.IDENT == tokens[3].kind
    assert TokenType.IDENT == tokens[29].kind
    assert TokenType.DOT == tokens[36].kind
    assert TokenType.L_PAREN == tokens[27].kind
    assert 43 == len(tokens)
    assert TokenType.NEW == tokens[7].kind
    assert TokenType.L_PAREN == tokens[38].kind
    assert TokenType.STATIC == tokens[24].kind
    assert TokenType.IDENT == tokens[26].kind
    assert TokenType.L_BRACK == tokens[4].kind
    assert TokenType.IF == tokens[33].kind
    assert TokenType.SEMICOLON == tokens[40].kind
    assert TokenType.ELSE == tokens[31].kind
    assert TokenType.INT == tokens[30].kind
    assert TokenType.R_PAREN == tokens[20].kind
    assert TokenType.VOID == tokens[25].kind
    assert TokenType.EQ == tokens[11].kind
    assert TokenType.GTEQ == tokens[2].kind
    assert TokenType.EQ == tokens[9].kind
    assert TokenType.EQEQ == tokens[16].kind
    assert TokenType.EQ == tokens[18].kind
    assert TokenType.GT == tokens[15].kind
    assert TokenType.GT == tokens[13].kind
    assert TokenType.WHILE == tokens[32].kind
    assert TokenType.LTEQ == tokens[14].kind
    assert TokenType.THIS == tokens[34].kind
    assert TokenType.R_SQBRACK == tokens[23].kind
    assert TokenType.R_BRACK == tokens[1].kind
    assert TokenType.MAIN == tokens[19].kind
    assert TokenType.LTEQ == tokens[17].kind
    assert TokenType.PUBLIC == tokens[6].kind
    assert TokenType.L_BRACK == tokens[28].kind

def test_BinarySearch(): 
    file = "data/BinarySearch.java"
    tokens = readTokens(readFile(file))        
    
    assert 650 == len(tokens)
    assert TokenType.L_PAREN == tokens[147].kind
    assert TokenType.SEMICOLON == tokens[469].kind
    assert TokenType.IDENT == tokens[378].kind
    assert TokenType.SEMICOLON == tokens[428].kind
    assert TokenType.IDENT == tokens[45].kind
    assert TokenType.DOT == tokens[214].kind
    assert TokenType.SEMICOLON == tokens[26].kind
    assert TokenType.IDENT == tokens[272].kind
    assert TokenType.L_PAREN == tokens[221].kind
    assert TokenType.SEMICOLON == tokens[615].kind
    assert TokenType.IDENT == tokens[616].kind
    assert TokenType.NUMBER == tokens[222].kind
    assert TokenType.SYSTEM_OUT_PRINTLN == tokens[14].kind
    assert TokenType.IDENT == tokens[342].kind
    assert TokenType.SEMICOLON == tokens[408].kind
    assert TokenType.IDENT == tokens[484].kind
    assert TokenType.IDENT == tokens[349].kind
    assert TokenType.NUMBER == tokens[23].kind
    assert TokenType.IDENT == tokens[415].kind
    assert TokenType.SEMICOLON == tokens[396].kind
    assert TokenType.L_PAREN == tokens[379].kind
    assert TokenType.IDENT == tokens[568].kind
    assert TokenType.INT == tokens[573].kind
    assert TokenType.EQ == tokens[596].kind
    assert TokenType.IDENT == tokens[284].kind

def test_BinaryTree(): 
    file = "data/BinaryTree.java"
    tokens = readTokens(readFile(file))        
    
    assert 1351 == len(tokens)
    assert TokenType.BOOLEAN == tokens[396].kind
    assert TokenType.SEMICOLON == tokens[377].kind
    assert TokenType.R_BRACK == tokens[752].kind
    assert TokenType.IDENT == tokens[273].kind
    assert TokenType.IDENT == tokens[795].kind
    assert TokenType.IDENT == tokens[919].kind
    assert TokenType.IDENT == tokens[86].kind
    assert TokenType.INT == tokens[847].kind
    assert TokenType.NUMBER == tokens[72].kind
    assert TokenType.R_BRACK == tokens[234].kind
    assert TokenType.IDENT == tokens[613].kind
    assert TokenType.L_BRACK == tokens[890].kind
    assert TokenType.BOOLEAN == tokens[399].kind
    assert TokenType.SEMICOLON == tokens[568].kind
    assert TokenType.IDENT == tokens[523].kind
    assert TokenType.SEMICOLON == tokens[295].kind
    assert TokenType.SEMICOLON == tokens[1229].kind
    assert TokenType.SEMICOLON == tokens[577].kind
    assert TokenType.IDENT == tokens[340].kind
    assert TokenType.EQ == tokens[675].kind
    assert TokenType.INT == tokens[633].kind
    assert TokenType.IDENT == tokens[784].kind
    assert TokenType.L_PAREN == tokens[939].kind
    assert TokenType.R_PAREN == tokens[1189].kind
    assert TokenType.IDENT == tokens[1213].kind

def test_BubbleSort(): 
    file = "data/BubbleSort.java"
    tokens = readTokens(readFile(file))        
    
    assert 378 == len(tokens)
    assert TokenType.IDENT == tokens[106].kind
    assert TokenType.VOID == tokens[5].kind
    assert TokenType.L_SQBRACK == tokens[266].kind
    assert TokenType.R_BRACK == tokens[376].kind
    assert TokenType.L_PAREN == tokens[18].kind
    assert TokenType.SEMICOLON == tokens[80].kind
    assert TokenType.SEMICOLON == tokens[122].kind
    assert TokenType.STRING == tokens[8].kind
    assert TokenType.R_BRACK == tokens[28].kind
    assert TokenType.EQ == tokens[348].kind
    assert TokenType.THIS == tokens[75].kind
    assert TokenType.EQ == tokens[355].kind
    assert TokenType.EQ == tokens[188].kind
    assert TokenType.SEMICOLON == tokens[122].kind
    assert TokenType.SEMICOLON == tokens[59].kind
    assert TokenType.IDENT == tokens[173].kind
    assert TokenType.NUMBER == tokens[238].kind
    assert TokenType.EQ == tokens[362].kind
    assert TokenType.IDENT == tokens[182].kind
    assert TokenType.R_PAREN == tokens[143].kind
    assert TokenType.IDENT == tokens[200].kind
    assert TokenType.NUMBER == tokens[134].kind
    assert TokenType.L_SQBRACK == tokens[176].kind
    assert TokenType.INT == tokens[117].kind
    assert TokenType.INT == tokens[105].kind

def test_LinearSearch(): 
    file = "data/LinearSearch.java"
    tokens = readTokens(readFile(file))        
    
    assert 362 == len(tokens)
    assert TokenType.NEW == tokens[297].kind
    assert TokenType.NUMBER == tokens[357].kind
    assert TokenType.SEMICOLON == tokens[53].kind
    assert TokenType.CLASS == tokens[29].kind
    assert TokenType.SEMICOLON == tokens[171].kind
    assert TokenType.IDENT == tokens[173].kind
    assert TokenType.THIS == tokens[98].kind
    assert TokenType.SEMICOLON == tokens[159].kind
    assert TokenType.IDENT == tokens[170].kind
    assert TokenType.SEMICOLON == tokens[118].kind
    assert TokenType.SEMICOLON == tokens[230].kind
    assert TokenType.L_PAREN == tokens[233].kind
    assert TokenType.INT == tokens[126].kind
    assert TokenType.R_SQBRACK == tokens[34].kind
    assert TokenType.SEMICOLON == tokens[115].kind
    assert TokenType.R_PAREN == tokens[12].kind
    assert TokenType.CLASS == tokens[29].kind
    assert TokenType.R_BRACK == tokens[156].kind
    assert TokenType.SEMICOLON == tokens[186].kind
    assert TokenType.L_PAREN == tokens[143].kind
    assert TokenType.L_SQBRACK == tokens[145].kind
    assert TokenType.R_PAREN == tokens[140].kind
    assert TokenType.IDENT == tokens[307].kind
    assert TokenType.WHILE == tokens[199].kind
    assert TokenType.IDENT == tokens[185].kind

def test_LinkedList(): 
    file = "data/LinkedList.java"
    tokens = readTokens(readFile(file))        
    
    assert 1111 == len(tokens)
    assert TokenType.R_PAREN == tokens[1011].kind
    assert TokenType.EQ == tokens[448].kind
    assert TokenType.L_BRACK == tokens[149].kind
    assert TokenType.SEMICOLON == tokens[575].kind
    assert TokenType.SEMICOLON == tokens[113].kind
    assert TokenType.FALSE == tokens[954].kind
    assert TokenType.NUMBER == tokens[952].kind
    assert TokenType.L_BRACK == tokens[690].kind
    assert TokenType.DOT == tokens[927].kind
    assert TokenType.IDENT == tokens[1000].kind
    assert TokenType.EQ == tokens[561].kind
    assert TokenType.IDENT == tokens[184].kind
    assert TokenType.DOT == tokens[927].kind
    assert TokenType.R_PAREN == tokens[1017].kind
    assert TokenType.IDENT == tokens[902].kind
    assert TokenType.RETURN == tokens[701].kind
    assert TokenType.R_PAREN == tokens[979].kind
    assert TokenType.NEW == tokens[851].kind
    assert TokenType.MINUS == tokens[511].kind
    assert TokenType.TRUE == tokens[395].kind
    assert TokenType.EQ == tokens[391].kind
    assert TokenType.RETURN == tokens[681].kind
    assert TokenType.L_PAREN == tokens[362].kind
    assert TokenType.SEMICOLON == tokens[462].kind
    assert TokenType.L_BRACK == tokens[2].kind

def test_QuickSort(): 
    file = "data/QuickSort.java"
    tokens = readTokens(readFile(file))        
    
    assert 500 == len(tokens)
    assert TokenType.L_PAREN == tokens[197].kind
    assert TokenType.EQ == tokens[149].kind
    assert TokenType.PUBLIC == tokens[3].kind
    assert TokenType.IDENT == tokens[163].kind
    assert TokenType.R_BRACK == tokens[497].kind
    assert TokenType.EQ == tokens[257].kind
    assert TokenType.SEMICOLON == tokens[309].kind
    assert TokenType.R_SQBRACK == tokens[34].kind
    assert TokenType.IDENT == tokens[317].kind
    assert TokenType.SEMICOLON == tokens[100].kind
    assert TokenType.SEMICOLON == tokens[154].kind
    assert TokenType.IDENT == tokens[416].kind
    assert TokenType.L_PAREN == tokens[18].kind
    assert TokenType.IF == tokens[237].kind
    assert TokenType.R_SQBRACK == tokens[469].kind
    assert TokenType.IF == tokens[141].kind
    assert TokenType.L_PAREN == tokens[407].kind
    assert TokenType.NUMBER == tokens[468].kind
    assert TokenType.NUMBER == tokens[77].kind
    assert TokenType.L_PAREN == tokens[22].kind
    assert TokenType.IDENT == tokens[243].kind
    assert TokenType.EQ == tokens[190].kind
    assert TokenType.R_SQBRACK == tokens[271].kind
    assert TokenType.EQ == tokens[413].kind
    assert TokenType.IDENT == tokens[317].kind