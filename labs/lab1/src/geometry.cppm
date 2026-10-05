export module geometry;

template <typename T>
struct Point
{
    T _x = 0;
    T _y = 0;

    Point(T x, T y) : _x(x), _y(y) {}
};

template <typename T>
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
};