#include "Point.hpp"

/**
 * @brief Computes the cross product of vectors (p1-p3) and (p2-p3).
 *
 * This is used to determine the relative orientation of three points
 * in 2D space. Positive result indicates one orientation, negative
 * another, and zero means the points are collinear.
 *
 * @param p1 First point.
 * @param p2 Second point.
 * @param p3 Third point (common origin for the vectors).
 * @return Fixed The scalar cross product value.
 */
static Fixed crossProduct(Point const p1, Point const p2, Point const p3)
{
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) -
		(p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
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

	if (d1 == 0 || d2 == 0 || d3 == 0)
		return false;

	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}

