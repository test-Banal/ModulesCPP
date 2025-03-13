/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:22:04 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/13 16:27:01 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
    public:
        void complain(std::string level);
    private:
        void    _debug(void);
        void    _info(void);
        void    _warning(void);
        void    _error(void);
};

#endif