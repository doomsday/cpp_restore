#ifndef ERROR_HPP
#define ERROR_HPP

namespace Error {
    struct Zero_divide{};

    struct Syntax_error {
            const char* p;
            Syntax_error (const char* q) { p = q; }
    };
}

#endif // ERROR_HPP
