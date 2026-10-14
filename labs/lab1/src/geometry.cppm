export module geometry;

import std;
import randomizer;

export template <typename T>
struct Point
{
    T _x = 0;
    T _y = 0;
    Point() : _x(0), _y(0) {}
    Point(T x, T y) : _x(x), _y(y) {}

    T GetX() const
    {
        return _x;
    }

    T GetY() const
    {
        return _y;
    }

    bool operator==(const Point &other) const
    {
        if constexpr (std::is_same_v<T, int>)
        {
            return _x == other._x && _y == other._y;
        }

        else if constexpr (std::is_same_v<T, float> || std::is_same_v<T, std::complex<float>>)
        {
            float eps = 1e-5f;
            return std::abs(_x - other._x) < eps && std::abs(_y - other._y) < eps;
        }

        else if constexpr (std::is_same_v<T, double> || std::is_same_v<T, std::complex<double>>)
        {
            double eps = 1e-9;
            return std::abs(_x - other._x) < eps && std::abs(_y - other._y) < eps;
        }

        else
        {
            return _x == other._x && _y == other._y;
        }
    }

    bool operator!=(const Point &other) const
    {
        return !(*this == other);
    }
};

export template <typename T>
std::ostream &operator<<(std::ostream &out, const Point<T> &p)
{
    if constexpr (std::is_same_v<T, int>)
    {
        out << "(" << p.GetX() << ", " << p.GetY() << ")";
    }
    else if constexpr (std::is_same_v<T, float>)
    {
        out << "(" << std::fixed << std::setprecision(3) << p.GetX()
            << ", " << std::fixed << std::setprecision(3) << p.GetY() << ")";
    }
    else if constexpr (std::is_same_v<T, double>)
    {
        out << "(" << std::fixed << std::setprecision(5) << p.GetX()
            << ", " << std::fixed << std::setprecision(5) << p.GetY() << ")";
    }
    else if constexpr (std::is_same_v<T, std::complex<float>>)
    {
        out << "((" << std::fixed << std::setprecision(3) << p.GetX().real()
            << "," << std::fixed << std::setprecision(3) << p.GetX().imag() << "), ("
            << std::fixed << std::setprecision(3) << p.GetY().real()
            << "," << std::fixed << std::setprecision(3) << p.GetY().imag() << "))";
    }
    else if constexpr (std::is_same_v<T, std::complex<double>>)
    {
        out << "((" << std::fixed << std::setprecision(5) << p.GetX().real()
            << "," << std::fixed << std::setprecision(5) << p.GetX().imag() << "), ("
            << std::fixed << std::setprecision(5) << p.GetY().real()
            << "," << std::fixed << std::setprecision(5) << p.GetY().imag() << "))";
    }
    return out;
}

export template <typename T>
class Polyline
{
private:
    Point<T> *_data = nullptr;
    int _count = 0;
    int _size = 0;

    void Reallocate(int size)
    {
        Point<T> *temp_data = new Point<T>[size];

        for (int i = 0; i < _count; ++i)
        {
            temp_data[i] = _data[i];
        }

        delete[] _data;
        _data = temp_data;
        temp_data = nullptr;

        _size = size;
    }

public:
    ~Polyline()
    {
        delete[] _data;
    }

    Polyline(const Polyline &other) : _data(new Point<T>[other._size]), _count(other._count), _size(other._size)
    {
        for (int i = 0; i < _count; ++i)
        {
            _data[i] = other._data[i];
        }
    }

    Polyline &operator=(const Polyline &other)
    {
        if (this != &other)
        {
            delete[] _data;

            _size = other._size;
            _count = other._count;
            _data = new Point<T>[_size];

            for (int i = 0; i < _count; ++i)
            {
                _data[i] = other._data[i];
            }
        }

        return *this;
    }

    Polyline(Polyline &&other) noexcept : _data(other._data), _count(other._count), _size(other._size)
    {
        other._data = nullptr;
        other._size = 0;
        other._count = 0;
    }

    Polyline &operator=(Polyline &&other) noexcept
    {
        if (this != &other)
        {
            delete[] _data;

            _size = other._size;
            _count = other._count;
            _data = other._data;

            other._data = nullptr;
            other._count = 0;
            other._size = 0;
        }

        return *this;
    }

    void AddPoint(const Point<T> &new_point)
    {
        if (_count >= _size)
        {
            int new_size = (_size == 0) ? 1 : _size * 2;
            Reallocate(new_size);
        }

        _data[_count] = new_point;
        ++_count;
    }

    void ErasePoint(int index)
    {
        try
        {
            if (index < 0 || index >= _count)
            {
                throw std::out_of_range("Index is out of polyline range");
            }

            for (int i = index; i < _count - 1; ++i)
            {
                _data[i] = _data[i + 1];
            }

            --_count;
        }

        catch (const std::out_of_range &e)
        {
            std::cout << "\n"
                      << e.what() << "\n";
        }
    }

    Polyline(Point<T> point)
    {
        AddPoint(point);
    }

    Polyline() = default;

    Polyline(int count_points)
    {
        for (int i = 0; i < count_points; ++i)
        {
            if constexpr (std::is_same_v<T, std::complex<float>> || std::is_same_v<T, std::complex<double>>)
            {
                T x_rand = Randomizer(T(1, 1), T(1000, 1000));
                T y_rand = Randomizer(T(1, 1), T(1000, 1000));
                Point<T> random_point(x_rand, y_rand);
                AddPoint(random_point);
            }
            else
            {
                T x_rand = Randomizer(T(1), T(1000));
                T y_rand = Randomizer(T(1), T(1000));
                Point<T> random_point(x_rand, y_rand);
                AddPoint(random_point);
            }
        }
    }

    Polyline(T x1, T x2)
    {
        for (T x = x1; x < x2; ++x)
        {
            T y_rand = Randomizer(x1, x2);
            AddPoint(Point<T>(x, y_rand));
        }
    }

    const Point<T> &operator[](int index) const
    {
        if (index < 0 || index >= _count)
        {
            throw std::out_of_range("Index is out of polyline range");
        }

        return _data[index];
    }

    Point<T> &operator[](int index)
    {
        if (index < 0 || index >= _count)
        {
            throw std::out_of_range("Index is out of polyline range");
        }

        return _data[index];
    }

    Polyline operator+(const Polyline &other) const
    {
        Polyline<T> result;

        int result_count = _count + other._count;

        if (result_count > 0)
        {
            result.Reallocate(result_count * 2);

            for (int i = 0; i < _count; ++i)
            {
                result.AddPoint(_data[i]);
            }

            for (int i = 0; i < other._count; ++i)
            {
                result.AddPoint(other._data[i]);
            }
        }

        return result;
    }

    Polyline operator+(const Point<T> point) const
    {
        Polyline<T> result;

        int result_count = _count + 1;

        if (result_count > 0)
        {
            result.Reallocate(result_count);

            for (int i = 0; i < _count; ++i)
            {
                result.AddPoint(_data[i]);
            }

            result.AddPoint(point);
        }

        return result;
    }

    bool operator==(const Polyline &other) const
    {
        if (_count != other._count)
        {
            return false;
        }

        for (int i = 0; i < _count; ++i)
        {
            if (_data[i] != other._data[i])
            {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const Polyline &other) const
    {
        if (_count != other._count)
        {
            return true;
        }

        for (int i = 0; i < _count; ++i)
        {
            if (_data[i] != other._data[i])
            {
                return true;
            }
        }

        return false;
    }

    int GetSize() const
    {
        return _size;
    }

    int GetCount() const
    {
        return _count;
    }

    Point<T> GetData(int index) const
    {
        if (index < 0 || index >= _count)
        {
            throw std::out_of_range("Index is out of polyline range");
        }

        return _data[index];
    }
};

export template <typename T>
Polyline<T> operator+(const Point<T> &point, const Polyline<T> &line)
{
    Polyline<T> result;

    int result_count = 1 + line.GetCount();

    if (result_count > 0)
    {
        result.AddPoint(point);

        for (int i = 0; i < line.GetCount(); ++i)
        {
            result.AddPoint(line.GetData(i));
        }
    }
    return result;
}

export template <typename T>
std::ostream &operator<<(std::ostream &out, const Polyline<T> &line)
{
    out << "[";
    for (int i = 0; i < line.GetCount(); ++i)
    {
        Point<T> p = line[i];
        out << p;

        if (i != line.GetCount() - 1)
        {
            out << ", ";
        }
    }
    out << "]";
    return out;
}