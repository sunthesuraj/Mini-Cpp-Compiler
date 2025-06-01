# Mini-C++-Compiler


A simple Mini C++ compiler project implemented in C++.  
This project includes a lexer, parser, abstract syntax tree (AST) generation, and a code generator for a small subset of C++-like language features.

---

## Table of Contents
- [Project Overview](#project-overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Build Instructions](#build-instructions)
- [Usage](#usage)
- [Example](#example)
- [Future Work](#future-work)
- [Contributing](#contributing)
- [License](#license)

---

## Project Overview

This Mini C++ compiler demonstrates the core components of a compiler:
- **Lexer:** Tokenizes input source code.
- **Parser:** Parses tokens into an abstract syntax tree (AST).
- **AST:** Represents the syntactic structure of the program.
- **Code Generator:** Produces output code or executes the program based on the AST.

The project is primarily educational, designed to help understand the compiler design process and how language parsing and code generation work at a fundamental level.

---

## Features

- Supports variable declaration and assignment
- Simple arithmetic expressions
- Print statements
- Basic error handling in parsing
- Easily extensible AST and parser for new language features

---

## Project Structure
mini-cpp-compiler/
│
├── ast.h # AST node definitions
├── lexer.h # Lexer declarations
├── lexer.cpp # Lexer implementation
├── parser.h # Parser declarations
├── parser.cpp # Parser implementation
├── codegen.h # Code generator declarations
├── codegen.cpp # Code generator implementation
├── main.cpp # Entry point for the compiler
├── examples/ # Sample source files to test
│ └── test.ml # Sample mini-language program
└── README.md # Project documentation



---

## Build Instructions

Make sure you have a C++ compiler supporting C++11 or later (e.g., `g++`, `clang++`, or MSVC).

To build the project using `g++` (assuming all `.cpp` files are in the root directory):


g++ main.cpp lexer.cpp parser.cpp codegen.cpp vm.cpp -o mini_compiler
This will produce an executable named mini-compiler.

./mini_compiler examples/test.ml


---
##Example

Input:
-let x = 4
-let y = 2
-let z = x * y + 6
-print z


Output:
-Program started
-Argument received: examples/test.ml
-Source length: 49
-Starting lexer
-Tokens count: 19
-AST nodes count: 4
-[CodeGen] Generating bytecode from AST with 4 nodes
-[VM] run() started
-[VM] Executing instruction 0: opcode=0, operand='4'
-[VM] Executing instruction 1: opcode=2, operand='x'
-[VM] Executing instruction 2: opcode=0, operand='2'
-[VM] Executing instruction 3: opcode=2, operand='y'
-[VM] Executing instruction 4: opcode=1, operand='x'
-[VM] Executing instruction 5: opcode=1, operand='y'
-[VM] Executing instruction 6: opcode=5, operand=''
-[VM] Executing instruction 7: opcode=0, operand='6'
-[VM] Executing instruction 8: opcode=3, operand=''
-[VM] Executing instruction 9: opcode=2, operand='z'
-[VM] Executing instruction 10: opcode=1, operand='z'
-[VM] Executing instruction 11: opcode=7, operand=''
-[VM] Print: 14
-[VM] run() finished

---

##Future Work
- Implement support for functions and control flow (if/else, loops)
- Add more complex data types and operators
- Improve error messages with line numbers and detailed diagnostics
- Optimize the generated code or integrate with LLVM backend
- Add a REPL for interactive testing





Created by:
Suraj Singh

