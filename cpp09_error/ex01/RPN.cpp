#include "RPN.hpp"

#include <stack>        //pour la stack biensur
#include <sstream>      //stringstream
#include <stdexcept>   // runtime_error pour les erreurs
#include <cctype>      // isdigit

RPN::RPN() {}

RPN::RPN(const RPN &src) {
    (void)src;
}

RPN &RPN::operator=(const RPN &rhs) {
    (void)rhs;
    return *this;
}

RPN::~RPN() {}

static bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Applique l'opérateur 'op' à lhs (left) et rhs (right).
// lhs et rhs sont les deux derniers éléments dépilés.
static int applyOperator(char op, int lhs, int rhs) {
    switch (op) {
        case '+':
            return lhs + rhs;
        case '-':
            return lhs - rhs;
        case '*':
            return lhs * rhs;
        case '/':
            if (rhs == 0) {
                // Division par zéro : on signale une erreur
                throw std::runtime_error("division by zero");
            }
            return lhs / rhs;
        default:
            // Ne devrait pas arriver si le parsing est correct
            throw std::runtime_error("invalid operator");
    }
}

int RPN::evaluate(const std::string &expression) {
    // pile pour "operande" = nombre
    std::stack<int> stack;

    // en gros lecture / split en token
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token.size() == 1) {
            char c = token[0];

            // Si c'est un chiffre (0 à 9), on le convertit en int et on le push
            if (std::isdigit(static_cast<unsigned char>(c))) {  //ici pourquoi static_cast<unsigned char> ?
                int value = c - '0';
                stack.push(value);
            }
            // Si c'est un opérateur, on dépile et on applique l'opération
            else if (isOperator(c)) {
                //check si min deux chiffre pour faire une op
                if (stack.size() < 2) {
                    throw std::runtime_error("not enough operands");
                }

               //en gros ici calcule rpn :  le top devient rhs / celui du dessous lhs et operation (pour le sens genre si div ou soustraction)
                int rhs = stack.top();
                stack.pop();
                int lhs = stack.top();
                stack.pop();

                int result = applyOperator(c, lhs, rhs);
                stack.push(result);
            }
            else { //si autre quun chiffre ou operateur
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

    return stack.top(); // on retourne le dernier nombre qui est en haut de la stack/pile   
}