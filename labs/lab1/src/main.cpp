import std;

template <typename T>
struct Point
{
    T _x = 0;
    T _y = 0;

    Point() : _x(0), _y(0) {}
    Point(T x, T y) : _x(x), _y(y) {}
};

template <typename T>
class Polyline
{
private:
    T *_data = nullptr;
    int _size = 0;
    int _capacity = 0;

    void Reallocate(int new_capacity, int index)
    {

        T *new_data = new T(new_capacity);

        if (index == -1)
        {
            for (int i = 0; i < _size; ++i)
            {
                new_data[i] = std::move(_data[i]);
            }
        }

        else
        {
            for (int i = 0; i < _size; ++i)
            {
                if (i != index)
                {
                    new_data[i] = std::move(_data[i]);
                }
            }
        }

        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    }

public:
    Polyline() : _data(nullptr), _size(0), _capacity(0) {}

    ~Polyline() { delete[] _data; }

    void AddEnd(T element)
    {
        if (_size == _capacity)
        {
            int new_capacity = (_capacity == 0) ? 1 : new_capacity * 2;
            Reallocate(new_capacity, -1);
        }

        _data[_size] = element;
        ++_size;
    }

    void Erase(int index)
    {
        int new_capacity = (_capacity == 0) ? throw std::logic_error("Error delete index") : new_capacity - 1;
        Reallocate(new_capacity, index);

        --_size;
    }
};

int main()
{
    return 0;
}