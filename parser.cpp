#include "parser.hpp"
#include <cstdlib>
#include <iostream>

Parse::Parse(Lex::TokenVec tokens): tokens(tokens){}
Parse::~Parse(){}

int Parse::expression(){
    term();

    Lex::Token curr = getCurr();

    while(curr.token == Lex::TokenType::PLUS || curr.token == Lex::TokenType::MINUS){
        next();

        int left = ast.top();
        ast.pop();

        term();

        int right = ast.top();
        ast.pop();
        
        if (curr.token == Lex::TokenType::PLUS) {
            ast.push(left+right);

        }else{
            ast.push(left-right);        
        }
        
        curr = getCurr();
    }

    return ast.top();
}

void Parse::term(){
    factor();

    Lex::Token curr = getCurr();

    while(curr.token == Lex::TokenType::DIVIDE || curr.token == Lex::TokenType::MULTIPLICATION){
        next();

        int left = ast.top();
        ast.pop();

        factor();

        int right = ast.top();
        ast.pop();

        if (curr.token == Lex::TokenType::DIVIDE) {
            ast.push(left/right);         
        }else{
            ast.push(left*right);         
        }

        curr = getCurr();

    }


}

void Parse::factor(){
    Lex::Token curr = getCurr();

    if(curr.token == Lex::TokenType::INT_L){
        next();
        ast.push(curr.data);
    }else{
        panic("Invalid syntax");
    }

}