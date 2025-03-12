/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:49:58 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/12 11:23:12 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

int main()
{
    Phonebook phonebook;
    std::string command;
    std::cout << "Phonebook : List of commands : ADD to add a new contact, SEARCH to search a contact or EXIT to exit" << std::endl;
    while (1)
    {
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);
        if (command == "EXIT")
            break;
        else if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
        {
            if (phonebook.get_size() == 0)
                std::cout << "The phonebook is empty." << std::endl;
            else
            {
                phonebook.listContacts();
                std::cout << "Enter the index of the contact you want to display: ";
                std::getline(std::cin, command);
                if (command.length() == 1 && std::isdigit(command[0]))
                {
                    int index = std::atoi(command.c_str());
                    if (index >= 0 && index < phonebook.get_size())
                        phonebook.displayContact(index);
                    else
                        std::cout << "Invalid index." << std::endl;
                }
                else
                    std::cout << "Invalid index." << std::endl;
            }
        }
            else
            std::cout << "Invalid command." << std::endl;
    }
    return 0;
}
