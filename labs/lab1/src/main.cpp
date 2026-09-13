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
T GenerateValue(T min_value, T max_value)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(static_cast<double>(min_value), static_cast<double>(max_value));

    return static_cast<T>(dis(gen));
}

std::complex<float> GenerateValue(float min_value, float max_value)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(min_value, max_value);

    return std::complex<float>(dis(gen), dis(gen));
}

std::complex<double> GenerateValue(double min_value, double max_value)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(min_value, max_value);

    return std::complex<double>(dis(gen), dis(gen));
}

template <typename T>
class Polyline
{
private:
    Point<T> *_data = nullptr;
    int _size = 0;
    int _capacity = 0;

    void Reallocate(int new_capacity, int index)
    {

        Point<T> *new_data = new Point<T>(new_capacity);

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

    void AddEnd(Point<T> element)
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

public:
    Polyline() : _data(nullptr), _size(0), _capacity(0) {}

    ~Polyline() { delete[] _data; }

    // Правило 5

    // Параметр координат
    Polyline(Point<T> coordinates)
    {
        AddEnd(coordinates);
    }

    // Параметр количества точек
    Polyline(int count_point)
    {
        for (int i = 0; i < count_point; ++i)
        {
            int a = 100;
            int b = 100;

            T t_a = static_cast<T>(a);
            T t_b = static_cast<T>(b);

            Point point(GenerateValue(t_a, t_b), GenerateValue(t_a, t_b));
            AddEnd(point);
        }
    }

    // Параметр с диапозоном
    Polyline(T a, T b)
    {
        Point point(GenerateValue(a, b), GenerateValue(a, b));
        AddEnd(point);
    }

    T operator[](int index)
    {
        return _data[index];
    }

    T operator[](int index, T element)
    {
        _data[index] = element;
        return _data[index];
    }
};

int main()
{
    return 0;
}