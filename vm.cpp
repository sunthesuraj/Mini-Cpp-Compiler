#include "vm.h"
#include <iostream>
#include <stdexcept>

VM::VM(const std::vector<Instruction>& bytecode) : code(bytecode) {}

void VM::run() {
    std::cout << "[VM] run() started\n";
    for (size_t i = 0; i < code.size(); ++i) {
        const auto& instr = code[i];
        std::cout << "[VM] Executing instruction " << i << ": opcode=" << static_cast<int>(instr.op) << ", operand='" << instr.operand << "'\n";

        switch (instr.op) {
            case OpCode::LoadConst:
                stack.push(std::stoi(instr.operand));
                break;
            case OpCode::LoadVar:
                if (variables.find(instr.operand) == variables.end()) throw std::runtime_error("Undefined variable: " + instr.operand);
                stack.push(variables[instr.operand]);
                break;
            case OpCode::StoreVar:
                if (stack.empty()) throw std::runtime_error("Stack underflow on StoreVar");
                variables[instr.operand] = stack.top();
                stack.pop();
                break;
            case OpCode::Add:
            case OpCode::Sub:
            case OpCode::Mul:
            case OpCode::Div: {
                if (stack.size() < 2) throw std::runtime_error("Stack underflow on binary op");
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                int res = 0;
                if (instr.op == OpCode::Add) res = a + b;
                else if (instr.op == OpCode::Sub) res = a - b;
                else if (instr.op == OpCode::Mul) res = a * b;
                else if (instr.op == OpCode::Div) {
                    if (b == 0) throw std::runtime_error("Division by zero");
                    res = a / b;
                }
                stack.push(res);
                break;
            }
            case OpCode::Print:
                if (stack.empty()) throw std::runtime_error("Stack underflow on Print");
                std::cout << "[VM] Print: " << stack.top() << std::endl;
                stack.pop();
                break;
        }
    }
    std::cout << "[VM] run() finished\n";
}
