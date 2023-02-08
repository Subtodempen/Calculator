#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

#pragma once


class Lex{
    public:        
        enum TokenType{
            PLUS,
            MINUS,
            MULTIPLICATION,
            DIVIDE,
            INT_L
        };

        struct Token{
            TokenType token;
            int data; 
        };
        typedef std::vector<Token> TokenVec;
        
        
        Lex(std::string subString);
        
        TokenVec scan(); 

    private:
        inline void nextChar(){
            currChar = subStr[charLoc++];
            
            checkWhitespace();// recursionnnnnnnnnnnnnn

            if(isEOF()){
                panic = true; //not an error we just need to stop looping
            }
        }
        
        inline void checkWhitespace(){
            if(currChar == ' '){
                nextChar();
            }
        }

        inline bool isDigit(){
            return currChar >= '0' && currChar <= '9'  || currChar == '.'; // '.' is a digit in float types
        }
        
        inline bool isLetter(){
            return !isDigit(); //if its a digit its not a letter 
        }

        inline bool isEOF(){
            return charLoc > strLen;
        }

        void panicFun(const std::string error){
            std::cerr << "\033[1;31m" << error << "\033[0m" << std::endl;
            exit(1);
        }

        std::string subStr;
        std::size_t strLen;

        char currChar;
        int charLoc = 0;
        bool panic = false;
};