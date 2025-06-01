#pragma once
#include "codegen.h"
#include <stack>
#include <unordered_map>

class VM {
public:
    VM(const std::vector<Instruction>& bytecode);
    void run();

private:
    std::vector<Instruction> code;
    std::stack<int> stack;
    std::unordered_map<std::string, int> variables;
};
