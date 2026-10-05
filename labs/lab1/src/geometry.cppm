export module geometry;

import std;

export template <typename T>
struct Point
{
    T _x = 0;
    T _y = 0;

    Point(T x, T y) : _x(x), _y(y) {}
};

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
    void AddPoint(Point<T> new_point)
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
};