/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:54:54 by tvalimak          #+#    #+#             */
/*   Updated: 2024/10/02 21:15:50 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructor from integer
Fixed::Fixed(const int intVal) {
    std::cout << "Int constructor called" << std::endl;
    _value = intVal << _fractionalBits;  // Shift integer value by fractional bits
}

// Constructor from float
Fixed::Fixed(const float floatVal) {
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(floatVal * (1 << _fractionalBits));  // Convert float to fixed-point
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    _value = other._value;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _value = other._value;
    }
    return (*this);
}

// Get raw bits
int Fixed::getRawBits(void) const {
    return (_value);
}

// Set raw bits
void Fixed::setRawBits(int const raw) {
    _value = raw;
}

// Convert fixed-point value to float
float Fixed::toFloat(void) const {
    return (static_cast<float>(_value) / (1 << _fractionalBits));
}

// Convert fixed-point value to int
int Fixed::toInt(void) const {
    return (_value >> _fractionalBits);
}

// Overload the << operator to output the float representation
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return (out);
}