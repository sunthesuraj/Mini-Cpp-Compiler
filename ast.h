#ifndef AST_H
#define AST_H

#include <string>
#include <memory>

enum class ASTNodeType {
    LetStatement,
    PrintStatement,
    Number,
    Variable,
    BinaryOp
};

struct ASTNode {
    ASTNodeType type;
    std::string value;
    std::shared_ptr<ASTNode> left;
    std::shared_ptr<ASTNode> right;

    ASTNode(ASTNodeType t, const std::string& val = "",
            std::shared_ptr<ASTNode> l = nullptr,
            std::shared_ptr<ASTNode> r = nullptr)
        : type(t), value(val), left(l), right(r) {}
};

#endif
