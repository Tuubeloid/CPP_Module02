/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 22:39:06 by tvalimak          #+#    #+#             */
/*   Updated: 2024/10/03 22:48:15 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed sign(Point const p1, Point const p2, Point const p3) {
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(point, a, b);
    d2 = sign(point, b, c);
    d3 = sign(point, c, a);

    // Check if the point is on the triangle's edge
    if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0)) {
        return false;
    }

    has_neg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
    has_pos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

    return !(has_neg && has_pos);
}
