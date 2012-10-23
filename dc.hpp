#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <iostream>
using std::istream;

namespace Error {
    struct Zero_divide{};
    struct Syntax_error {
            const char* p;
            Syntax_error (const char* q) { p = q; }
    };
    }
#include <string>

namespace Lexer {
    enum Token_value {
        NAME,       NUMBER,     END,
        PLUS='+',   MINUS='-',  MUL='*',    DIV='/',
        PRINT=';',  ASSIGN='=', LP='(',     RP=')'
    };
    extern Token_value curr_tok;
    extern double number_value;
    extern std::string string_value;

    using namespace Error;

    Token_value get_token();
    }

namespace Parser {
    double prim(bool get);
    double term(bool get);
    double expr(bool get);

    using namespace Lexer;
    using namespace Error;
    }

#include <map>

extern std::map<std::string,double>table;

namespace Driver {
    extern int no_of_errors;
    extern std::istream* input;
    void skip();
    }

#endif // LOGIC_HPP
