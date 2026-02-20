#include "Point.hpp"

/**
 * @brief Computes the 2D cross product (orientation test) of vectors BP and BA.
 *
 * This function determines the relative position of point @p p with respect
 * to the directed line formed by points @p a and @p b.
 *
 * The result represents the signed area of the parallelogram defined by
 * vectors (b → p) and (b → a):
 * - Positive value  → point is on one side of the line
 * - Negative value  → point is on the opposite side
 * - Zero            → points are on the line
 *
 * This is commonly used for half-space classification in
 * Binary Space Partitioning (BSP) and point-in-triangle tests.
 *
 * @param p The point to classify.
 * @param a First point defining the line.
 * @param b Second point defining the line (origin of vectors).
 * @return Fixed Signed result of the 2D cross product.
 */
static Fixed crossProduct(Point const p, Point const a, Point const b)
{
	Fixed x1 = p.getX() - b.getX();
	Fixed y1 = p.getY() - b.getY();

	Fixed x2 = a.getX() - b.getX();
	Fixed y2 = a.getY() - b.getY();

	return (x1 * y2) - (x2 * y1);
}

/**
 * @brief Determines if a point lies strictly inside a triangle.
 *
 * Uses the cross product method (barycentric technique) to check if
 * the point is inside the triangle defined by points a, b, c.
 * Points on the edges are considered outside.
 *
 * @param a First vertex of the triangle.
 * @param b Second vertex of the triangle.
 * @param c Third vertex of the triangle.
 * @param point The point to test.
 * @return true if the point is strictly inside the triangle.
 * @return false if the point is outside or on an edge.
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = crossProduct(point, a, b);
	Fixed d2 = crossProduct(point, b, c);
	Fixed d3 = crossProduct(point, c, a);

	// std::cout << "\nvalue of d1: " << d1 << std::endl;
	// std::cout << "value of d2: " << d2 << std::endl;
	// std::cout << "value of d3: " << d3 << std::endl;

	if (d1 == 0 || d2 == 0 || d3 == 0)
		return false;

	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}

