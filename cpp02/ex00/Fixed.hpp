/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:58:30 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/20 13:53:54 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(Fixed const &src);
        ~Fixed();

        Fixed &operator=(Fixed const &rhs);

        int   getRawBits(void) const;
        void  setRawBits(int const raw);

    private:
        int _value;
        int const static _fractional_bits = 8;
};

#endif