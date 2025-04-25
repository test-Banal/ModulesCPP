/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:49:24 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/25 17:23:29 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void    Contact::set_infos(std::string first_name, std::string last_name,
            std::string nickname, std::string phone_number, std::string darkest_secret)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone_number = phone_number;
    this->darkest_secret = darkest_secret;
}

void    Contact::show_info(void)
{
    std::cout << "First name: " << this->first_name << std::endl;
    std::cout << "Last name: " << this->last_name << std::endl;
    std::cout << "Nickname: " << this->nickname << std::endl;
    std::cout << "Phone number: " << this->phone_number << std::endl;
    std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
}

std::string Contact::get_first_name()const //a modifier
{
    return truncate(this->first_name, 10);
}

std::string Contact::get_last_name()const // a modifier
{
    return truncate(this->last_name, 10);
}

std::string Contact::get_nickname()const // a modifier
{
    return truncate(this->nickname, 10);
}

std::string Contact::get_phone_number()const
{
    return this->phone_number;
}

std::string Contact::get_darkest_secret()const
{
    return this->darkest_secret;
}
