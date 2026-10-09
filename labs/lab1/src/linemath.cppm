export module linemath;

import geometry;
import std;

export template <typename T>
T LenPolyline(const Polyline<Point<T>> &line)
{
    if (line.GetCount() < 2)
        return 0;

    T final_summ = 0;

    for (int i = 0; i < line.GetCount() - 1; ++i)
    {
        Point<T> p1 = line.GetPoint(i);
        Point<T> p2 = line.GetPoint(i + 1);

        T delta_x = p2._x - p1._x;
        T delta_y = p2._y - p1._y;

        final_summ += std::sqrt(delta_x * delta_x + delta_y * delta_y);
    }

    return final_summ;
}

export template <typename T>
T LenPolyline(const Polyline<std::complex<T>> &line)
{
    if (line.GetCount() < 2)
        return 0;

    T final_summ = 0;

    for (int i = 0; i < line.GetCount() - 1; ++i)
    {
        std::complex<T> z1 = line.GetPoint(i);
        std::complex<T> z2 = line.GetPoint(i + 1);

        T delta_real = z2.real() - z1.real();
        T delta_imag = z2.imag() - z1.imag();

        T distance = std::sqrt(delta_real * delta_real + delta_imag * delta_imag);

        final_summ += distance;
    }

    return final_summ;
}