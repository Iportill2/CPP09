//
// Created by Aingeru Alvarez Sanchez on 3/21/23.
//

#include "RPN.hpp"
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <string>

RPN::RPN() : _operationStack() {}

RPN::RPN(const RPN &cpy) : _operationStack(cpy._operationStack) {}

bool RPN::parseInput(const std::string &input) {
    for (std::string::const_iterator it = input.begin(); it != input.end(); it++) {
        if ((!std::isdigit(*it) || std::strtol(&(*it), NULL, 10) > 10 || std::strtol(&(*it), NULL, 10) < 0)
            && (*it != '+' && *it != '-' && *it != '*' && *it != '/' && *it != ' '))
            return  true;
    }
    return  false;
}

std::string RPN::createTokens(const std::string &input) {
    std::string result;
    for (std::string::const_iterator it = input.begin(); it != input.end(); it++) {
        if (*it != ' ')
            result.push_back(*it);
    }
    return  result;
}

int RPN::performRpnOperation(const std::string &input) {
    if (input.empty() || input.find_first_not_of(' ') == std::string::npos
        || this->parseInput(input)) {
        throw   std::invalid_argument("");
    }

    std::string token = this->createTokens(input);
    int firstArg = 0, secondArg = 0;
    for (std::string::iterator it = token.begin(); it != token.end(); it++) {
        if (std::isdigit(*it)) {
            this->_operationStack.push(*it - '0');
        } else {
            firstArg = this->_operationStack.top();
            this->_operationStack.pop();
            if (this->_operationStack.empty()) {
                throw   std::invalid_argument("");
            }
            secondArg = this->_operationStack.top();
            this->_operationStack.pop();
            switch (*it) {
                case '+': this->_operationStack.push(secondArg + firstArg); break;
                case '-': this->_operationStack.push(secondArg - firstArg); break;
                case '*': this->_operationStack.push(secondArg * firstArg); break;
                case '/': this->_operationStack.push(secondArg / firstArg); break;
            }
        }
    }
    if (this->_operationStack.size() > 1) {
        throw   std::invalid_argument("");
    }
    return  this->_operationStack.top();
}

RPN &RPN::operator=(const RPN &cpy) {
    this->_operationStack = cpy._operationStack;
    return *this;
}

RPN::~RPN() {}
