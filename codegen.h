#pragma once
#include "ast.h"
#include <vector>
#include <string>

enum class OpCode {
    LoadConst, LoadVar,
    StoreVar,
    Add, Sub, Mul, Div,
    Print
};

struct Instruction {
    OpCode op;
    std::string operand;
    Instruction(OpCode o, const std::string& opnd = "") : op(o), operand(opnd) {}
};

class CodeGenerator {
public:
    CodeGenerator();
    std::vector<Instruction> generate(const std::vector<std::shared_ptr<ASTNode>>& ast);

private:
    std::vector<Instruction> bytecode;
    void generate_stmt(const std::shared_ptr<ASTNode>& node);
    void generate_expr(const std::shared_ptr<ASTNode>& node);
};