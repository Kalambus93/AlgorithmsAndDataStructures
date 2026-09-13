import std;

template <typename T>
struct Point
{
    T _x = 0;
    T _y = 0;
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
};

int main()
{
    return 0;
}