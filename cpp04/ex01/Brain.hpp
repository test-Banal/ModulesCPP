#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
private:
        //std::array<std::string, 100> ideas; // interdit dans le sujet mais mieux a l'avenir methode STL
        std::string ideas[100]; // Tableau de 100 idées
public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif