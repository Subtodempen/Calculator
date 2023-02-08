#include <iostream>
#include "lexer.hpp"
#include "parser.hpp"

class Compile{
    public:
        Compile(std::string str);
        int compile();

    std::string input;
};