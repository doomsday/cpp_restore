#include "parser_impl.hpp"
#include "table.hpp"

double Parser::prim(bool get){

    using Lexer::number_value;
    using Lexer::string_value;
    if(get) get_token();
    switch (curr_tok) {
    case NUMBER:                                        // Floating-point constant
    {
        double v = number_value;
        get_token();
        return v;
    }
    case NAME:
    {
        double& v = table[string_value];
        if(Lexer::get_token() == ASSIGN) v = expr(true);
        return v;
    }
    case MINUS:                                         // Unary minus
        return -prim(true);
    case LP:
    {
        double e = expr(true);
        if (curr_tok != RP) throw Syntax_error(") expected");
        get_token();                                    // Eat ')'
        return e;
    }
    default:
        throw Syntax_error("primary expected");
    }
}

double Parser::term(bool get) {
    double left = prim(get);
    for(;;)
        switch (curr_tok) {
        case MUL:
            left *= prim(true);
            break;
        case DIV:
            if (double d = prim(true)) {
                left /= d;
                break;
            }
            throw Zero_divide();
        default:
            return left;
        }
}

double Parser::expr(bool get) {
    double left = term(get);
    for(;;)
        switch (curr_tok) {
        case PLUS:
            left += term(true);
            break;
        case MINUS:
            left -= term(true);
            break;
        default:
            return left;
        }
}
