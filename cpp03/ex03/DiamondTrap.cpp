/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:06:31 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/13 15:35:12 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap() {
    std::cout << "DiamondTrap default constructor called" << std::endl;
    _name = "Default";
    
    // Herite des attributs des classes parentes
    _hitPoints = FragTrap::_hitPoints;       // 100 de FragTrap
    _attackDamage = 30; // 30 de FragTrap, Explication en bas
    _energyPoints = ScavTrap::_energyPoints; // 50 de ScavTrap
}

DiamondTrap::DiamondTrap(const std::string& name) 
    : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name") {
    std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
    _name = name;
    
    // Idem Herite des attributs des classes parentes
    _hitPoints = FragTrap::_hitPoints;
    _attackDamage = 30;// 30 de FragTrap , explication en bas
    _energyPoints = ScavTrap::_energyPoints;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) 
    : ClapTrap(src), FragTrap(src), ScavTrap(src) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = src;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
        _name = rhs._name;
    }
    return *this;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << _name << ", also known as ClapTrap " 
              << ClapTrap::_name << "!" << std::endl;
}

std::string DiamondTrap::getName() const {
    return _name;
}

unsigned int DiamondTrap::getHitPoints() const {
    return _hitPoints;
}

unsigned int DiamondTrap::getEnergyPoints() const {
    return _energyPoints;
}

unsigned int DiamondTrap::getAttackDamage() const {
    return _attackDamage;
}

// Tu ne fais pas une affectation à une variable statique, tu fais une affectation à la variable membre _attackDamage de ton instance courante, en prenant la valeur de celle de FragTrap.
// Mais comme tous les attributs (_attackDamage, etc.) viennent de ClapTrap, il n’existe qu’une seule instance de _attackDamage par DiamondTrap.
// Or, regarde l’ordre des appels de constructeurs :
// ClapTrap -> FragTrap -> ScavTrap -> DiamondTrap
// 🧨 Le bug se produit ici :
//     FragTrap initialise _attackDamage = 30
//     Puis ScavTrap réécrit _attackDamage = 20 (par son constructeur)
//     Ensuite seulement, tu entres dans DiamondTrap, et tu fais :
// _attackDamage = FragTrap::_attackDamage;
// Mais ici, FragTrap::_attackDamage ne veut rien dire ! Tu n’accèdes pas à une variable statique de la classe FragTrap, tu fais simplement référence à la variable d’instance _attackDamage qui a déjà été modifiée par le constructeur de ScavTrap avant que tu arrives dans DiamondTrap.
// Donc tu ne récupères pas 30, mais la valeur actuelle, qui est déjà écrasée à 20 par ScavTrap.

/*
Dans le cadre de la hiérarchie d’héritage multiple de DiamondTrap, la classe hérite de deux classes dérivées, FragTrap et ScavTrap, elles-mêmes héritant de ClapTrap. Tous ces types partagent une structure de données commune, notamment les membres protégés comme _hitPoints, _energyPoints et _attackDamage, déclarés dans la classe de base ClapTrap.
En C++, l’héritage multiple entraîne un comportement déterminé par l’ordre d’appel des constructeurs des classes parentes, qui se fait de gauche à droite, conformément à l’ordre d’apparition dans la déclaration de la classe dérivée. Dans ce cas précis, le constructeur de DiamondTrap appelle successivement ceux de ClapTrap, FragTrap et ScavTrap, dans cet ordre.
Le problème ici réside dans le fait que, bien que FragTrap initialise _attackDamage à 30 dans son constructeur, cette valeur est écrasée immédiatement après par le constructeur de ScavTrap, qui la réinitialise à 20. Cette redéfinition n’est pas visible directement dans le code de DiamondTrap, mais elle résulte de l’initialisation de la même sous-partie ClapTrap partagée dans l’objet complet.
Il ne s’agit pas de champs statiques, mais bien de membres d’instance hérités, et comme il n’y a qu’une seule sous-instance de ClapTrap dans DiamondTrap (pas de duplication grâce à l’absence de virtual inheritance), l’attribut _attackDamage est commun à tous les chemins d’héritage.
Ainsi, lorsque le constructeur de ScavTrap est exécuté, il modifie l’état de _attackDamage, écrasant la valeur précédemment définie par FragTrap.
Pour garantir que DiamondTrap hérite bien de la configuration propre à FragTrap concernant les points d’attaque (ici, 30), il est nécessaire de réaffecter manuellement la valeur souhaitée à _attackDamage après la construction complète des classes parentes. Cette réaffectation explicite permet de résoudre le conflit d’héritage non virtuel et d’assurer la cohérence de l’état initial de l’objet DiamondTrap.
D’où cette ligne dans le constructeur :
_attackDamage = 30;
Elle n’est donc ni arbitraire ni redondante : elle corrige un effet de bord inévitable causé par l’ordre d’initialisation en présence d’héritage multiple non virtuel
Elle permet de corriger un effet de bord (c’est-à-dire une modification involontaire de l’état d’un attribut) qui résulte de l’ordre d’appel des constructeurs dans une hiérarchie à héritage multiple non virtuel.
En effet, en C++, lorsqu’une classe hérite de plusieurs classes, les constructeurs des classes parentes sont appelés dans l’ordre où elles sont listées dans la déclaration de la classe dérivée. Mais comme il ne s’agit pas d’un héritage virtuel, chaque classe dérivée (FragTrap, ScavTrap) agit indépendamment sur les mêmes membres hérités de ClapTrap, puisque ceux-ci sont physiquement présents une seule fois dans l’objet final (DiamondTrap).
Dans ce contexte, même si FragTrap initialise _attackDamage à 30, cette valeur est ensuite écrasée par le constructeur de ScavTrap, qui redéfinit _attackDamage à 20. Cet écrasement est une conséquence directe du mécanisme d’initialisation automatique des sous-objets dans l’ordre d’héritage, et non d’un choix explicite dans DiamondTrap.
Puisqu’on ne peut pas interférer dans l’ordre d’appel des constructeurs des classes parentes, la seule solution consiste à rétablir manuellement la valeur souhaitée après la fin de cette phase d’initialisation. C’est précisément le rôle de l’instruction :


*/