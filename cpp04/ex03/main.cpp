/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:46:02 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/23 18:46:03 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

int main() {
    std::cout << "===== Test de base (sujet) =====" << std::endl;
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
    
    std::cout << "\n===== Tests supplémentaires =====" << std::endl;
    
    // Test de la création de materia avec un type inconnu
    src = new MateriaSource();
    src->learnMateria(new Ice());
    
    tmp = src->createMateria("unknown");
    if (tmp == NULL)
        std::cout << "Création d'une materia de type inconnu impossible - OK" << std::endl;
    
    // Test de l'équipement d'une materia NULL
    me = new Character("me");
    me->equip(NULL);
    
    // Test de l'utilisation d'un slot d'inventaire vide
    me->use(0, *me);
    
    // Test de l'utilisation d'un slot d'inventaire invalide
    me->use(-1, *me);
    me->use(4, *me);
    
    // Test de la déséquipement d'un slot d'inventaire vide
    me->unequip(0);
    
    // Test de la déséquipement d'un slot d'inventaire invalide
    me->unequip(-1);
    me->unequip(4);
    
    // Test de l'équipement et déséquipement d'une materia
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->unequip(0);
    delete tmp;
    
    // Test de la méthode getName
    std::cout << "Le nom du personnage est: " << me->getName() << std::endl;
    
    // Test d'équipement de plus de 4 materias
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp); // Cette materia ne devrait pas pouvoir être équipée
    delete tmp;     // On doit la supprimer manuellement pour éviter les fuites mémoire
    
    // Test de l'apprentissage de plus de 4 materias par la MateriaSource
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice()); // Cette materia ne devrait pas pouvoir être apprise
    
    // Test de copie d'un Character (copie profonde)
    Character* john = new Character("John");
    tmp = src->createMateria("ice");
    john->equip(tmp);
    
    Character* johnCopy = new Character(*john);
    std::cout << "Nom du personnage copié: " << johnCopy->getName() << std::endl;
    
    // Test d'utilisation d'une materia par le personnage copié
    ICharacter* target = new Character("Target");
    johnCopy->use(0, *target);
    
    // Test de l'opérateur d'affectation pour Character
    Character* jane = new Character("Jane");
    *jane = *john;
    std::cout << "Nom du personnage après affectation: " << jane->getName() << std::endl;
    
    // Test d'utilisation après affectation
    jane->use(0, *target);
    
    // Test de copie de MateriaSource
    MateriaSource* srcCopy = new MateriaSource(*(static_cast<MateriaSource*>(src)));
    tmp = srcCopy->createMateria("ice");
    if (tmp != NULL) {
        std::cout << "MateriaSource copié correctement - peut créer une materia de type " << tmp->getType() << std::endl;
        delete tmp;
    }
    
    // Test d'opérateur d'affectation pour MateriaSource
    MateriaSource* srcAssign = new MateriaSource();
    *srcAssign = *(static_cast<MateriaSource*>(src));
    tmp = srcAssign->createMateria("cure");
    if (tmp != NULL) {
        std::cout << "MateriaSource assigné correctement - peut créer une materia de type " << tmp->getType() << std::endl;
        delete tmp;
    }
    
    // Libération de la mémoire
    delete target;
    delete jane;
    delete johnCopy;
    delete john;
    delete srcAssign;
    delete srcCopy;
    delete src;
    delete me;
    return 0;
}
