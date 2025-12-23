/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:12:15 by aneumann          #+#    #+#             */
/*   Updated: 2025/12/22 20:38:51 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <stack>        //pour la stack biensur
#include <list>
#include <sstream>      //stringstream
#include <stdexcept>   // runtime_error pour les erreurs
#include <cctype>      // isdigit

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    (void)other;
}

RPN &RPN::operator=(const RPN &other) {
    (void)other;
    return *this;
}

RPN::~RPN() {}

static bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

static long applyOperator(char op, long lhs, long rhs) {
    switch (op) {
        case '+':
            return lhs + rhs;
        case '-':
            return lhs - rhs;
        case '*':
            return lhs * rhs;
        case '/':
            if (rhs == 0) {
                throw std::runtime_error("division by zero");
            }
            return lhs / rhs;
        default:
            throw std::runtime_error("invalid operator");
    }
}

long RPN::evaluate(const std::string &expression) {
    // std::stack<long> stack;
    std::stack<long, std::list<long> > stack;
    
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token.size() == 1) {
            char c = token[0];

            if (std::isdigit(static_cast<unsigned char>(c))) {
                long value = c - '0';
                stack.push(value);
            }
           
            else if (isOperator(c)) {
                if (stack.size() < 2) {
                    throw std::runtime_error("not enough operands");
                }

                long rhs = stack.top();
                stack.pop();
                long lhs = stack.top();
                stack.pop();

                long result = applyOperator(c, lhs, rhs);
                stack.push(result);
            }
            else {
                throw std::runtime_error("invalid token");
            }
        }
        else {
            throw std::runtime_error("invalid token");
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("invalid expression");
    }

    return stack.top();
}
