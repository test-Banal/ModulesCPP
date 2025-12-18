#include "RPN.hpp"

#include <stack>       
#include <sstream>     // std::stringstream pour découper la string en tokens
#include <stdexcept>   // std::runtime_error pour les erreurs
#include <cctype>      // std::isdigit

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
    // Pile qui va contenir les opérandes (les nombres)
    std::stack<int> stack;

    // On utilise un stringstream pour lire l'expression token par token
    std::stringstream ss(expression);
    std::string token;

    // On lit chaque "mot" séparé par des espaces : ex: "8", "9", "*", "9", "-"
    while (ss >> token) {
        // On n'accepte que des tokens d'un seul caractère
        if (token.size() == 1) {
            char c = token[0];

            // Si c'est un chiffre (0 à 9), on le convertit en int et on le push
            if (std::isdigit(static_cast<unsigned char>(c))) {
                int value = c - '0'; // '0'->0, '1'->1, ..., '9'->9
                stack.push(value);
            }
            // Si c'est un opérateur, on dépile et on applique l'opération
            else if (isOperator(c)) {
                // Il faut au moins deux opérandes pour appliquer un opérateur binaire
                if (stack.size() < 2) {
                    throw std::runtime_error("not enough operands");
                }

                // Attention à l'ordre : le second pop est le lhs (left operand)
                int rhs = stack.top();
                stack.pop();
                int lhs = stack.top();
                stack.pop();

                int result = applyOperator(c, lhs, rhs);
                stack.push(result);
            }
            // Un seul caractère mais ni chiffre ni opérateur -> invalide
            else {
                throw std::runtime_error("invalid token");
            }
        }
        // Token de taille > 1 : le sujet ne demande pas de gérer les nombres multi-chiffres
        // ni les décimales -> on considère que c'est invalide.
        else {
            throw std::runtime_error("invalid token");
        }
    }

    // À la fin, l'expression est valide si et seulement s'il reste exactement 1 élément
    if (stack.size() != 1) {
        throw std::runtime_error("invalid expression");
    }

    // Le seul élément restant est le résultat final
    return stack.top();
}