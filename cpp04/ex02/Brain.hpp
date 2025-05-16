#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
private:
        //std::array<std::string, 100> ideas;
        std::string ideas[100]; // Tableau de 100 idées , + classique , - avancee mais je ne sais pas si la methode STL est autorisee ici
public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};


#endif