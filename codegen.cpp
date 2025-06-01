#include "codegen.h"
#include <iostream>

CodeGenerator::CodeGenerator() {}

std::vector<Instruction> CodeGenerator::generate(const std::vector<std::shared_ptr<ASTNode>>& ast) {
    bytecode.clear();
    std::cout << "[CodeGen] Generating bytecode from AST with " << ast.size() << " nodes\n";
    for (const auto& stmt : ast) generate_stmt(stmt);
    return bytecode;
}

void CodeGenerator::generate_stmt(const std::shared_ptr<ASTNode>& node) {
    switch (node->type) {
        case ASTNodeType::LetStatement:
            generate_expr(node->right);
            bytecode.emplace_back(OpCode::StoreVar, node->left->value);
            break;
        case ASTNodeType::PrintStatement:
            generate_expr(node->left);
            bytecode.emplace_back(OpCode::Print);
            break;
        default:
            generate_expr(node);
            break;
    }
}

void CodeGenerator::generate_expr(const std::shared_ptr<ASTNode>& node) {
    if (!node) return;
    switch (node->type) {
        case ASTNodeType::Number:
            bytecode.emplace_back(OpCode::LoadConst, node->value);
            break;
        case ASTNodeType::Variable:
            bytecode.emplace_back(OpCode::LoadVar, node->value);
            break;
        case ASTNodeType::BinaryOp:
            generate_expr(node->left);
            generate_expr(node->right);
            if (node->value == "+") bytecode.emplace_back(OpCode::Add);
            else if (node->value == "-") bytecode.emplace_back(OpCode::Sub);
            else if (node->value == "*") bytecode.emplace_back(OpCode::Mul);
            else if (node->value == "/") bytecode.emplace_back(OpCode::Div);
            break;
        default:
            break;
    }
}