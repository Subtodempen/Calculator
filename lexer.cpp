#include "lexer.hpp"
#include <cstdio>


Lex::Lex(std::string subStr): subStr(subStr){
    strLen = subStr.length();
    
    nextChar();
}

Lex::TokenVec Lex::scan(){
    std::vector<Lex::Token> Tokens;
    
    while (!panic){  //while not panicking if anything goes wrong we PANIC
        if(isDigit()){
            int num = 0;
            int place = 1;

            do{
                num += int(currChar)-48 * place;

                place *= 10;
                nextChar();
            }while(isDigit());

            Tokens.push_back(Token{TokenType::INT_L, num});
        }else{  //dont need to check if it is a letter bcs its not a digit
            switch (currChar) {
                case '+':
                    Tokens.push_back(Token{TokenType::PLUS});
                    break;
                case '-':
                    Tokens.push_back(Token{TokenType::MINUS});
                    break;
                case '*':
                    Tokens.push_back(Token{TokenType::MULTIPLICATION});
                    break;
                case '/':
                    Tokens.push_back(Token{TokenType::DIVIDE});
                    break;
                default:
                    //unexpected syntax
                    panicFun("Unexpected syntax");
            } 

            nextChar();  
        }
    }
    
    return Tokens;  
}