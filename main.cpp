#include "lexer.hpp"
#include "parser.hpp"
#include <iostream>
#include <iterator>

int main(){
    Lex lexer("9 *");

    Lex::TokenVec tokens = lexer.scan();
    
   // for(auto token: tokens){
     //   std::cout<< token.data <<"," <<  token.token<<std::endl;
    //}

    Parse parser(tokens);

    std::cout<<parser.expression();
}