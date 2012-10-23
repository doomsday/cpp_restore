#include "dc.hpp"
#include <iostream>
#include <sstream>

using namespace std;
using namespace Driver;
using namespace Error;
using namespace Lexer;
using namespace Parser;

int Driver::no_of_errors = 0;
std::istream* Driver::input = 0;

void Driver::skip() {
    no_of_errors++;
    while (*input) {
        char ch;
        input->get(ch);

        switch (ch) {
        case '\n':
        case ';':
            input->get(ch);
            return;
        }
    }
}

int main(int argc, char* argv[]) {

    table["pi"] = 3.14159265;
    table["e"] = 2.71828182;

    switch (argc) {
    case 1:
        input = &cin;
        break;
    case 2:
        input = new istringstream(argv[1]);
        break;
    default:
        //      error("too many arguments");
        return 1;
    }

    while(*input) {
        try {
            get_token();
            if (curr_tok == END) break;
            if (curr_tok == PRINT) continue;
            cout << expr(false) << '\n';
        }
        catch (Zero_divide) {
            cerr << "attempt to divide by zero\n";
            skip();
        }
        catch (Syntax_error e) {
            cerr << "syntax error:" << e.p << "\n";
            skip();
        }
        if (input != &cin) delete input;
        return no_of_errors;
    }
}
