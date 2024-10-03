/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:54:54 by tvalimak          #+#    #+#             */
/*   Updated: 2024/10/03 22:46:45 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _value(0) {}

// Constructor from integer
Fixed::Fixed(const int intVal) {
    _value = intVal << _fractionalBits;
}

// Constructor from float
Fixed::Fixed(const float floatVal) {
    _value = roundf(floatVal * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed& other) : _value(other._value) {
}

// Destructor
Fixed::~Fixed() {}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        _value = other._value;
    }
    return *this;
}

// Conversion to float
float Fixed::toFloat(void) const {
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

// Conversion to int
int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const { return _value > other._value; }
bool Fixed::operator<(const Fixed& other) const { return _value < other._value; }
bool Fixed::operator>=(const Fixed& other) const { return _value >= other._value; }
bool Fixed::operator<=(const Fixed& other) const { return _value <= other._value; }
bool Fixed::operator==(const Fixed& other) const { return _value == other._value; }
bool Fixed::operator!=(const Fixed& other) const { return _value != other._value; }

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed& other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed& other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed& other) const { 
    if (other._value == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        exit(1);  // Terminate on division by zero
    }
    return Fixed(this->toFloat() / other.toFloat());
}

// Increment/Decrement operators
Fixed& Fixed::operator++() {  // Pre-increment
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int) {  // Post-increment
    Fixed temp(*this);
    _value++;
    return temp;
}

Fixed& Fixed::operator--() {  // Pre-decrement
    --_value;
    return *this;
}

Fixed Fixed::operator--(int) {  // Post-decrement
    Fixed temp(*this);
    _value--;
    return temp;
}

// Min and Max static member functions
Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }

Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }

// Overload the << operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}