/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:50:47 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/25 19:03:57 by aneumann         ###   ########.fr       */
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

#define MAX_CONTACTS 8
class Phonebook
{
private:
	int _size;
    Contact     _contacts[MAX_CONTACTS];
	int _index;


public:
	Phonebook();
	~Phonebook();

	int get_size();
	void add_contact();
	void list_contacts();
	void display_contact(int index);
};

#endif
