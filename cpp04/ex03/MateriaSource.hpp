/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:46:22 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/23 18:46:24 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
private:
    AMateria* templates[4]; // Stockage des templates de materias
    static const int templateSize = 4;

public:
    MateriaSource(); 
    MateriaSource(MateriaSource const & src);
    virtual ~MateriaSource(); 

    MateriaSource & operator=(MateriaSource const & rhs);

    // Méthodes héritées de IMateriaSource
    virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(std::string const & type);
};

#endif
