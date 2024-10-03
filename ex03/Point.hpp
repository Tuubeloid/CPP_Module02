/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 22:33:37 by tvalimak          #+#    #+#             */
/*   Updated: 2024/10/03 22:44:01 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    const Fixed x;
    const Fixed y;

public:
    Point();  // Default constructor
    Point(const float x, const float y);  // Parameterized constructor
    Point(const Point &other);  // Copy constructor
    Point& operator=(const Point &other);  // Copy assignment operator
    ~Point();  // Destructor

    Fixed getX() const;
    Fixed getY() const;
};

#endif