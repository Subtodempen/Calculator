#include"lexer.hpp"
#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>

class Parse{
    public:
        Parse(Lex::TokenVec tokens);
        ~Parse();
        int expression();

    void term();
    void factor();

    inline Lex::Token getCurr(){
        return tokens[index];
    }

    inline void next(){
        index++;//check ur not out of bounds TODO

        if(index > tokens.size()){
            panic("Invalid syntax");
        }
    }

    void panic(std::string error){
        std::cerr << "\033[1;31m" << error << "\033[0m" << std::endl;
        exit(1);
    }

    int index=0;
    std::stack<int> ast; // abstract syntax TREE
    Lex::TokenVec tokens;
};