#include "parser.h"

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens) {}

Token Parser::peek() { return pos < tokens.size() ? tokens[pos] : Token{TokenType::End, ""}; }
Token Parser::advance() { return pos < tokens.size() ? tokens[pos++] : Token{TokenType::End, ""}; }

bool Parser::match(TokenType type) {
    if (peek().type == type) { advance(); return true; }
    return false;
}

std::vector<std::shared_ptr<ASTNode>> Parser::parse() {
    std::vector<std::shared_ptr<ASTNode>> program;
    while (peek().type != TokenType::End) program.push_back(statement());
    return program;
}

std::shared_ptr<ASTNode> Parser::statement() {
    if (peek().type == TokenType::Let) return let_statement();
    if (peek().type == TokenType::Print) return print_statement();
    return expression();
}

std::shared_ptr<ASTNode> Parser::let_statement() {
    advance(); // let
    std::string name = advance().value;
    match(TokenType::Assign);
    auto expr = expression();
    match(TokenType::Semicolon);
    auto var = std::make_shared<ASTNode>(ASTNodeType::Variable, name);
    return std::make_shared<ASTNode>(ASTNodeType::LetStatement, "", var, expr);
}

std::shared_ptr<ASTNode> Parser::print_statement() {
    advance();
    auto expr = expression();
    match(TokenType::Semicolon);
    return std::make_shared<ASTNode>(ASTNodeType::PrintStatement, "", expr);
}

std::shared_ptr<ASTNode> Parser::expression() {
    auto node = term();
    while (peek().type == TokenType::Plus || peek().type == TokenType::Minus) {
        Token op = advance();
        auto right = term();
        auto bin = std::make_shared<ASTNode>(ASTNodeType::BinaryOp, op.value);
        bin->left = node;
        bin->right = right;
        node = bin;
    }
    return node;
}

std::shared_ptr<ASTNode> Parser::term() {
    auto node = factor();
    while (peek().type == TokenType::Mul || peek().type == TokenType::Div) {
        Token op = advance();
        auto right = factor();
        auto bin = std::make_shared<ASTNode>(ASTNodeType::BinaryOp, op.value);
        bin->left = node;
        bin->right = right;
        node = bin;
    }
    return node;
}

std::shared_ptr<ASTNode> Parser::factor() {
    Token tok = advance();
    if (tok.type == TokenType::Number)
        return std::make_shared<ASTNode>(ASTNodeType::Number, tok.value);
    else if (tok.type == TokenType::Identifier)
        return std::make_shared<ASTNode>(ASTNodeType::Variable, tok.value);
    else if (tok.type == TokenType::LParen) {
        auto expr = expression();
        match(TokenType::RParen);
        return expr;
    }
    return nullptr;
}