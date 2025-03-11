/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:50:47 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/11 16:50:48 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstdlib> //version c++ meme si stdlib.h     fonctionne aussi

#include "Contact.hpp"

class Phonebook
{
    private:
        Contact contacts[8];
        int size;
    public:
        Phonebook(void);
        ~Phonebook(void);

        int get_size();
        void addContact();
        void listContacts();
        void displayContact(int index);
};

#endif
