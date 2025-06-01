#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& src) : source(src) {}

char Lexer::peek() {
    return pos < source.size() ? source[pos] : '\0';
}

char Lexer::advance() {
    return pos < source.size() ? source[pos++] : '\0';
}

void Lexer::skip_whitespace() {
    while (isspace(peek())) advance();
}

Token Lexer::number() {
    std::string val;
    while (isdigit(peek())) val += advance();
    return {TokenType::Number, val};
}

Token Lexer::identifier() {
    std::string val;
    while (isalnum(peek()) || peek() == '_') val += advance();
    if (val == "let") return {TokenType::Let, val};
    if (val == "print") return {TokenType::Print, val};
    return {TokenType::Identifier, val};
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (peek()) {
        skip_whitespace();
        char c = peek();
        if (isdigit(c)) tokens.push_back(number());
        else if (isalpha(c)) tokens.push_back(identifier());
        else {
            switch (advance()) {
                case '=': tokens.push_back({TokenType::Assign, "="}); break;
                case '+': tokens.push_back({TokenType::Plus, "+"}); break;
                case '-': tokens.push_back({TokenType::Minus, "-"}); break;
                case '*': tokens.push_back({TokenType::Mul, "*"}); break;
                case '/': tokens.push_back({TokenType::Div, "/"}); break;
                case ';': tokens.push_back({TokenType::Semicolon, ";"}); break;
                case '(': tokens.push_back({TokenType::LParen, "("}); break;
                case ')': tokens.push_back({TokenType::RParen, ")"}); break;
            }
        }
    }
    tokens.push_back({TokenType::End, ""});
    return tokens;
}