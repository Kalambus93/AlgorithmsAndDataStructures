export module tasks;

import std;
import geometry;

export template <typename T>
Polyline<T> Triangle(const Point<T> &point, const T &c, const T &angle_rad)
{
    double angle_degrees = static_cast<double>(angle_rad) * 3.1415 / 180.0;

    double s = std::sin(angle_degrees);
    double co = std::cos(angle_degrees);

    double val_c = std::abs(static_cast<double>(c));

    double dx = val_c * s;
    double dy = val_c * co;

    Point<T> point_left_base(
        static_cast<T>(static_cast<double>(point.GetX()) - dx),
        static_cast<T>(static_cast<double>(point.GetY()) - dy));

    Point<T> point_right_base(
        static_cast<T>(static_cast<double>(point.GetX()) + dx),
        static_cast<T>(static_cast<double>(point.GetY()) - dy));

    Polyline<T> triangle(point);
    triangle.AddPoint(point_left_base);
    triangle.AddPoint(point_right_base);

    return triangle;
}