/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:50:47 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/25 18:38:57 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstdlib> 
#include "Contact.hpp"
#include <array>

#define MAX_CONTACTS 8

class PhoneBook
{
private:
	int _size;
	std::array<Contact, MAX_CONTACTS> _contacts;

public:
	PhoneBook();
	~PhoneBook();

	int get_size();
	void add_contact();
	void list_contacts();
	void display_contact(int index);
};

#endif
