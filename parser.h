#pragma once
#include <vector>
#include <memory>
#include "lexer.h"
#include "ast.h"

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    std::vector<std::shared_ptr<ASTNode>> parse();

private:
    std::vector<Token> tokens;
    size_t pos = 0;

    Token peek();
    Token advance();
    bool match(TokenType type);

    std::shared_ptr<ASTNode> statement();
    std::shared_ptr<ASTNode> let_statement();
    std::shared_ptr<ASTNode> print_statement();
    std::shared_ptr<ASTNode> expression();
    std::shared_ptr<ASTNode> term();
    std::shared_ptr<ASTNode> factor();
};