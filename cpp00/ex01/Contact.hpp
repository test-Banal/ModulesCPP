/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:49:44 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/11 16:49:45 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:
        Contact(void);
        ~Contact(void);

    	void		set_infos(std::string first_name, std::string last_name,
            std::string nickname, std::string phone_number, std::string darkest_secret);
        void		show_info(void);
        std::string	get_first_name()const;
        std::string	get_last_name()const;
        std::string	get_nickname()const;
        std::string	get_phone_number()const;
        std::string	get_darkest_secret()const;
};




#endif
