#ifndef PARSER_IMPL_HPP
#define PARSER_IMPL_HPP

#include "parser.hpp"
#include "error.hpp"
#include "lexer.hpp"

namespace Parser {
    double prim(bool get);
    double term(bool get);
    double expr(bool get);

    using namespace Lexer;
    using namespace Error;
}

#endif // PARSER_IMPL_HPP
