#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer.h"
#include "parser.h"
#include "codegen.h"
#include "vm.h"

int main(int argc, char* argv[]) {
    std::cout << "Program started\n";
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <source_file.ml>" << std::endl;
        return 1;
    }

    std::cout << "Argument received: " << argv[1] << std::endl;
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << argv[1] << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string source = buffer.str();
    std::cout << "Source length: " << source.length() << std::endl;

    try {
        Lexer lexer(source);
        std::cout << "Starting lexer\n";
        auto tokens = lexer.tokenize();
        std::cout << "Tokens count: " << tokens.size() << std::endl;

        Parser parser(tokens);
        auto ast = parser.parse();
        std::cout << "AST nodes count: " << ast.size() << std::endl;

        CodeGenerator codegen;
        auto bytecode = codegen.generate(ast);

        VM vm(bytecode);
        vm.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
