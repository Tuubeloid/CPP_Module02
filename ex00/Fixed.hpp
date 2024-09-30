/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:55:28 by tvalimak          #+#    #+#             */
/*   Updated: 2024/10/01 00:58:17 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int                 _value;
    static const int    _fractionalBits = 8;

public:
    // Constructors
    Fixed();
    Fixed(const Fixed& other);

    // Destructor
    ~Fixed();

    // Copy assignment operator
    Fixed& operator=(const Fixed& other);

    // Member functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif