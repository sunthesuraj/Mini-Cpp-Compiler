#pragma once
#include <string>
#include <vector>

enum class TokenType {
    Let, Print,
    Identifier, Number,
    Assign, Plus, Minus, Mul, Div,
    Semicolon, LParen, RParen,
    End
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
public:
    Lexer(const std::string& src);
    std::vector<Token> tokenize();

private:
    std::string source;
    size_t pos = 0;
    char peek();
    char advance();
    void skip_whitespace();
    Token number();
    Token identifier();
};
