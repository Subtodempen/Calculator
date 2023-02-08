#include "compiler.hpp"
#include <iostream>

Compile::Compile(std::string str): input(str){
    compile();
}

int Compile::compile(){
    int res;

    try {
        Lex lexer(input);
        Lex::TokenVec tokens = lexer.scan();

        Parse parser(tokens);

        res = parser.expression();
    }catch (const std::string error) {
        std::cerr<<error;
        std::cout<<"e";
        return -1;
    }

    return res;
}
