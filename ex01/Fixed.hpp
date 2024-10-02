/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:55:28 by tvalimak          #+#    #+#             */
/*   Updated: 2024/10/02 20:53:09 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 _value;
    static const int    _fractionalBits = 8;

public:
    // Constructors
    Fixed();
    Fixed(const int intVal);
    Fixed(const float floatVal);
    Fixed(const Fixed& other);
    // Destructor
    ~Fixed();
    // Copy assignment operator
    Fixed& operator=(const Fixed& other);
    // Member functions
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
};

// Overload the << operator to output the float representation
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif