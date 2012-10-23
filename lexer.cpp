#include "dc.hpp"
#include <iostream>
#include <cctype>

Lexer::Token_value Lexer::curr_tok;
double Lexer::number_value;
std::string Lexer::string_value;

Lexer::Token_value Lexer::get_token() {

    using Driver::input;
    using Lexer::curr_tok;
    extern istream* input;
    char ch;

    do { // skip whitespace except '\n'
        if(!input->get(ch)) return Lexer::curr_tok = END;    // istream& get ( char& c ); Extracts a character from the stream and stores it in c
    } while (ch != '\n' && isspace(ch));              // аЕбаЛаИ ch аНаЕ баИаМаВаОаЛ аНаОаВаОаЙ бббаОаКаИ а аЕбаЛаИ ch ббаО аПбаОаБаЕаЛ

    switch (ch) {
    case 0:
        return curr_tok = END;
    case ';' :
    case '\n':
        return curr_tok = PRINT;
    case '*' :
    case '/' :
    case '+' :
    case '-' :
    case '(' :
    case ')' :
    case '=' :
        return curr_tok = Token_value(ch);
    case '0' : case '1' : case '2' : case '3' : case '4' :
    case '5' : case '6' : case '7' : case '8' : case '9' : case '.' :
        input->putback(ch);
        input->operator >>(number_value);
        return curr_tok=NUMBER;
    default:
        if (isalpha(ch)) {
            string_value = ch;
            while (input->get(ch) && isalnum(ch)) {
                string_value.push_back(ch);
            }
            input->putback(ch);
            return curr_tok=NAME;
        }
        throw Syntax_error("bad token");
        return curr_tok=PRINT;
    }
}
