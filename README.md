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

```bash
g++ -std=c++11 main.cpp lexer.cpp parser.cpp codegen.cpp -o mini-compiler

This will produce an executable named mini-compiler.

./mini-compiler examples/test.ml


let x = 5;
print x + 10;

output:
15


Created by:
Suraj Singh

