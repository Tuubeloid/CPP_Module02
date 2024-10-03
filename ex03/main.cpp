/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:54:21 by tvalimak          #+#    #+#             */
/*   Updated: 2024/10/03 22:54:10 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

// Declaration of the bsp function
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    // Define a triangle with vertices a, b, and c
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    // Test case 1: Point strictly inside the triangle
    Point p1(5.0f, 5.0f);
    std::cout << "Point inside: " << (bsp(a, b, c, p1) ? "Yes" : "No") << std::endl;

    // Test case 2: Point outside the triangle
    Point p2(11.0f, 5.0f);
    std::cout << "Point outside: " << (bsp(a, b, c, p2) ? "Yes" : "No") << std::endl;

    // Test case 3: Point on one of the triangle's edges
    Point p3(5.0f, 0.0f); // On edge between a and b
    std::cout << "Point on edge: " << (bsp(a, b, c, p3) ? "Yes" : "No") << std::endl;

    // Test case 4: Point on the vertex of the triangle
    Point p4(0.0f, 0.0f); // Vertex 'a'
    std::cout << "Point on vertex: " << (bsp(a, b, c, p4) ? "Yes" : "No") << std::endl;

    // Test case 5: Point at the centroid of the triangle
    Point p5(a.getX().toFloat() / 3 + b.getX().toFloat() / 3 + c.getX().toFloat() / 3,
    a.getY().toFloat() / 3 + b.getY().toFloat() / 3 + c.getY().toFloat() / 3);

    // Test case 6: Point outside but close to one of the edges
    Point p6(5.0f, -0.1f); // Just below the edge between a and b
    std::cout << "Point near edge: " << (bsp(a, b, c, p6) ? "Yes" : "No") << std::endl;

    // Test case 7: Large triangle and point far outside
    Point a2(-1000.0f, -1000.0f);
    Point b2(1000.0f, -1000.0f);
    Point c2(0.0f, 1000.0f);
    Point p7(2000.0f, 2000.0f);
    std::cout << "Point far outside: " << (bsp(a2, b2, c2, p7) ? "Yes" : "No") << std::endl;

    // Test case 8: Degenerate triangle (all vertices in a straight line)
    Point a3(0.0f, 0.0f);
    Point b3(5.0f, 0.0f);
    Point c3(10.0f, 0.0f);
    Point p8(3.0f, 0.0f); // On the line but not part of the triangle
    std::cout << "Point on degenerate triangle: " << (bsp(a3, b3, c3, p8) ? "Yes" : "No") << std::endl;

    return 0;
}