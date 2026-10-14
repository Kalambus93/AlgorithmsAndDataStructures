export module tasks;

import std;
import geometry;

export template <typename T>
Polyline<T> Triangle(const Point<T> &point, const T &c, const T &angle)
{
    T sin_angle = std::sin(angle);
    T cos_angle = std::cos(angle);

    T a = std::abs(c) * sin_angle;
    T b = std::abs(c) * cos_angle;

    Point<T> point_left_base(point._x - a, point._y - b);
    Point<T> point_right_base(point._x + a, point._y - b);

    Polyline<T> triangle(point);
    triangle.AddPoint(point_left_base);
    triangle.AddPoint(point_right_base);

    return triangle;
}