TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    lexer.cpp \
    parser.cpp \
    table.cpp

HEADERS += \
    parser.hpp \
    parser_impl.hpp \
    error.hpp \
    lexer.hpp \
    table.hpp \
    driver.hpp

