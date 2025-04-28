/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:50:21 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/28 11:03:36 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "utils.hpp"
#include <iomanip>
#include <iostream>

Phonebook::Phonebook(void)
{
	this->_index = 0;
	this->_size = 0;
}

Phonebook::~Phonebook(void)
{
}

int Phonebook::get_size()
{
    return _size;
}

// void Phonebook::add_contact()
// {
//     std::string first_name, last_name, nickname, phone_number, darkest_secret;

//     do {
//         std::cout << "Enter first name: ";
//         first_name = get_input("First Name: ");
//         if (first_name.empty())
//             std::cout << "First name cannot be empty. Please enter again." << std::endl;
//     } while (first_name.empty());

//     do {
//         std::cout << "Enter last name: ";
//         last_name = get_input("Last Name: ");
//         if (last_name.empty())
//             std::cout << "Last name cannot be empty. Please enter again." << std::endl;
//     } while (last_name.empty());

//     do {
//         std::cout << "Enter nickname: ";
//         nickname = get_input("Nickname: ");
//         if (nickname.empty())
//             std::cout << "Nickname cannot be empty. Please enter again." << std::endl;
//     } while (nickname.empty());

//     do {
//         std::cout << "Enter phone number: ";
//         phone_number = get_input("Phone Number: ");
//         if (phone_number.empty())
//             std::cout << "Phone number cannot be empty. Please enter again." << std::endl;
//     } while (phone_number.empty());

//     do {
//         std::cout << "Enter darkest secret: ";
//         darkest_secret = get_input("Darkest Secret: ");
//         if (darkest_secret.empty())
//             std::cout << "Darkest secret cannot be empty. Please enter again." << std::endl;
//     } while (darkest_secret.empty());

//     this->_contacts[this->_index].set_infos(first_name, last_name, nickname, phone_number, darkest_secret);
//     this->_index = (this->_index + 1) % MAX_CONTACTS;
//     if (this->_size < MAX_CONTACTS)
//         this->_size++;
// }


void Phonebook::add_contact()
{
    std::string first_name = get_input("First Name: ");
    std::string last_name = get_input("Last Name: ");
    std::string nickname = get_input("Nickname: ");
    std::string phone_number = get_input("Phone Number: ");
    std::string darkest_secret = get_input("Darkest Secret: ");

    // Ajout ou remplacement du contact à l’index courant
    this->_contacts[this->_index].set_infos(first_name, last_name, nickname, phone_number, darkest_secret);

    // Incrémentation circulaire de l’index (repart à 0 après 7)
    this->_index = (this->_index + 1) % MAX_CONTACTS;

    // Taille maximale atteinte ? On ne l’incrémente plus
    if (this->_size < MAX_CONTACTS)
        this->_size++;
}
void Phonebook::list_contacts()
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < this->_size; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << this->_contacts[i].get_first_name() << "|";
		std::cout << std::setw(10) << this->_contacts[i].get_last_name() << "|";
		std::cout << std::setw(10) << this->_contacts[i].get_nickname() << std::endl;
	}
}

void Phonebook::display_contact(int index)
{
	if (index < 0 || index >= this->_size)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	this->_contacts[index].show_info();
}