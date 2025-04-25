/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:50:21 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/25 18:38:34 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "utils.hpp"
#include <iomanip>
#include <iostream>
#include <algorithm> // pour std::min


Phonebook::Phonebook(void) : _size(0)
{
    // for (int i = 0; i < 8; i++)
    //     this->contacts[i] = Contact();
}

Phonebook::~Phonebook(void)
{
}

int Phonebook::get_size()
{
    return _size;
}

void Phonebook::addContact()
{
    if (this->size == 8)
    {
        std::cout << "The phonebook is full." << std::endl;
        return;
    }
    Contact contact;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    std::cout << "Enter the first name: ";
    first_name = get_input();
    std::cout << "Enter the last name: ";
    last_name = get_input();
    std::cout << "Enter the nickname: ";
    nickname = get_input();
    std::cout << "Enter the phone number: ";
    phone_number = get_input();
    std::cout << "Enter the darkest secret: ";
    darkest_secret = get_input();
    contact.set_infos(first_name, last_name, nickname, phone_number, darkest_secret);
    this->contacts[this->size] = contact;
    this->size++;
}

void Phonebook::listContacts()
{
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < this->size; i++)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << this->contacts[i].get_first_name() << "|";
        std::cout << std::setw(10) << this->contacts[i].get_last_name() << "|";
        std::cout << std::setw(10) << this->contacts[i].get_nickname() << std::endl;
    }
}

void Phonebook::displayContact(int index)
{
    if (index < 0 || index >= this->size)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    this->contacts[index].show_info();
}