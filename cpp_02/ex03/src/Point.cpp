#include "Point.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes the point at the origin (0,0).
 */
Point::Point(void) : _x(0), _y(0) {}

/**
 * @brief Constructor from float coordinates.
 *
 * Initializes the point with given x and y values.
 *
 * @param x The x coordinate.
 * @param y The y coordinate.
 */
Point::Point(const float x, const float y) : _x(x), _y(y) {}

/**
 * @brief Copy constructor.
 *
 * Creates a new Point as a copy of another Point.
 *
 * @param other The Point instance to copy.
 */
Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

/**
 * @brief Copy assignment operator.
 *
 * Assignment operator is defined but cannot modify const members,
 * so it does nothing.
 *
 * @param other The Point instance to copy from.
 * @return Reference to this Point.
 */
Point &Point::operator=(const Point &other) {
    (void)other;
    return *this;
}

/**
 * @brief Getter for the X coordinate.
 *
 * @return The X coordinate as a Fixed object.
 */
Fixed Point::getX(void) const { return _x; }

/**
 * @brief Getter for the Y coordinate.
 *
 * @return The Y coordinate as a Fixed object.
 */
Fixed Point::getY(void) const { return _y; }

/**
 * @brief Destructor.
 *
 * Cleans up the Point instance.
 */
Point::~Point() {}
