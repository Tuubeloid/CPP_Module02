/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 22:37:10 by tvalimak          #+#    #+#             */
/*   Updated: 2024/10/03 22:44:01 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor: initializes x and y to 0 using Fixed class
Point::Point() : x(0), y(0) {}

// Parameterized constructor: initializes x and y using the given float values
Point::Point(const float xVal, const float yVal) : x(Fixed(xVal)), y(Fixed(yVal)) {}

// Copy constructor: initializes this object by copying another Point
Point::Point(const Point &other) : x(other.x), y(other.y) {}

// Copy assignment operator: assigns the values from another Point to this one
Point& Point::operator=(const Point &other) {
    // Since x and y are const, they cannot be reassigned.
    // But we return *this as required for assignment operators
    if (this != &other) {
        // Do nothing because x and y are const, no reassignment is allowed
        // In case of const attributes, assignment operator may not be functional
    }
    return *this;
}

// Destructor
Point::~Point() {}

// Getter for x coordinate
Fixed Point::getX() const {
    return this->x;
}

// Getter for y coordinate
Fixed Point::getY() const {
    return this->y;
}