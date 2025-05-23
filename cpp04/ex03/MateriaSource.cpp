#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    //std::cout << "MateriaSource default constructor called" << std::endl;
    // Initialisation du tableau de templates à NULL
    for (int i = 0; i < templateSize; i++) {
        this->templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const & src) {
   // std::cout << "MateriaSource copy constructor called" << std::endl;
    
    for (int i = 0; i < templateSize; i++) {
        this->templates[i] = NULL;
    }
    
    // Copie profonde des templates
    for (int i = 0; i < templateSize; i++) {
        if (src.templates[i] != NULL) {
            this->templates[i] = src.templates[i]->clone();
        }
    }
}

MateriaSource::~MateriaSource() {
    //std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < templateSize; i++) {
        if (this->templates[i] != NULL) {
            delete this->templates[i];
            this->templates[i] = NULL;
        }
    }
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
   //std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &rhs) {
        for (int i = 0; i < templateSize; i++) {
            if (this->templates[i] != NULL) {
                delete this->templates[i];
                this->templates[i] = NULL;
            }
        }
        for (int i = 0; i < templateSize; i++) {
            if (rhs.templates[i] != NULL) {
                this->templates[i] = rhs.templates[i]->clone();
            }
        }
    }
    return *this;
}

// Apprendre une materia pour la stocker comme template
void MateriaSource::learnMateria(AMateria* m) {
    if (m == NULL) {
        std::cout << "Cannot learn NULL materia" << std::endl;
        return;
    }
    
    // Recherche du premier emplacement vide
    for (int i = 0; i < templateSize; i++) {
        if (this->templates[i] == NULL) {
            this->templates[i] = m;
            std::cout << "MateriaSource learns " << m->getType() << " at slot " << i << std::endl;
            return;
        }
    }
    std::cout << "MateriaSource is full, cannot learn more materias" << std::endl;
    delete m; // On doit supprimer la materia pour éviter les fuites mémoire
}

// Créer une nouvelle materia à partir d'un type connu
AMateria* MateriaSource::createMateria(std::string const & type) {
    // Recherche d'un template correspondant au type demandé
    for (int i = 0; i < templateSize; i++) {
        if (this->templates[i] != NULL && this->templates[i]->getType() == type) {
            std::cout << "MateriaSource creates a " << type << " materia" << std::endl;
            return this->templates[i]->clone();
        }
    }
    std::cout << "MateriaSource doesn't know how to create a " << type << " materia" << std::endl;
    return NULL;
}