#include "Point.hpp"

static Fixed crossProduct(Point const p1, Point const p2, Point const p3)
{
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) -
		(p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

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

