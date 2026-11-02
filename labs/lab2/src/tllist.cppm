export module tllist;

import std;

export template <typename T>
class TwoLinkedLists
{
private:
    struct Node
    {
        T _info;
        Node *_prev;
        Node *_next;

        Node() : _info(), _prev(nullptr), _next(nullptr) {}
        Node(T info) : _info(info), _prev(nullptr), _next(nullptr) {}
    };

    Node *_head;
    int _size;

public:
    TwoLinkedLists() : _head(nullptr), _size(0) {}

    TwoLinkedLists(const TwoLinkedLists &other)
    {
        this->push_tail(other);
    }

    TwoLinkedLists(TwoLinkedLists &&other) noexcept : _head(other._head), _size(other._size)
    {
        other._head = nullptr;
        other._size = 0;
    }

    ~TwoLinkedLists()
    {
        while (_head)
        {
            this->pop_head();
        }
    }

    TwoLinkedLists &operator=(const TwoLinkedLists &other)
    {
        if (this != &other)
        {
            this->~TwoLinkedLists();

            push_tail(other);
        }

        return *this;
    }

    TwoLinkedLists &operator=(TwoLinkedLists &&other) noexcept
    {
        if (this != &other)
        {
            this->~TwoLinkedLists();

            _head = other._head;
            _size = other._size;

            other._head = nullptr;
            other._size = 0;
        }

        return *this;
    }

    void push_tail(const T &el)
    {
        Node *new_node = new Node(el);

        if (_head == nullptr)
        {
            _head = new_node;
        }

        else
        {
            Node *current = _head;
            while (current->_next)
            {
                current = current->_next;
            }

            new_node->_next = nullptr;
            new_node->_prev = current;

            current->_next = new_node;
        }

        ++_size;
    }

    void push_tail(const TwoLinkedLists &list)
    {
        for (int i = 0; i < list.GetSize(); ++i)
        {
            this->push_tail(list[i]);
        }
    }

    void push_head(const T &el)
    {
        Node *new_node = new Node(el);

        if (_head == nullptr)
        {
            _head = new_node;
        }
        else
        {
            new_node->_next = _head;
            new_node->_prev = nullptr;

            _head->_prev = new_node;

            _head = new_node;
        }

        ++_size;
    }

    void push_head(const TwoLinkedLists &list)
    {
        for (int i = list.GetSize() - 1; i >= 0; --i)
        {
            this->push_head(list[i]);
        }
    }

    void pop_head()
    {
        try
        {
            if (_head == nullptr)
            {
                throw std::out_of_range("Index is out");
            }

            Node *current = _head;
            _head = _head->_next;

            if (_head)
            {
                _head->_prev = nullptr;
            }

            delete current;
            current = nullptr;

            --_size;
        }

        catch (const std::out_of_range &e)
        {
            std::cout << "\n"
                      << e.what() << "\n";
        }
    }

    void pop_tail()
    {
        try
        {
            Node *current = _head;

            if (_head == nullptr)
            {
                throw std::out_of_range("Index is out");
            }

            if (current->_next == nullptr)
            {
                delete _head;
                _head = nullptr;
                --_size;
                return;
            }

            while (current->_next->_next != nullptr)
            {
                current = current->_next;
            }

            delete current->_next;
            current->_next = nullptr;
            --_size;
        }

        catch (const std::out_of_range &e)
        {
            std::cout << "\n"
                      << e.what() << "\n";
        }
    }

    void delete_node(T info)
    {
        Node *current = _head;

        while (current)
        {
            if (current->_info == info)
            {
                if (current->_prev != nullptr)
                {
                    current->_prev->_next = current->_next;
                }
                else
                {
                    _head = current->_next;
                }

                if (current->_next)
                {
                    current->_next->_prev = current->_prev;
                }

                Node *del = current;
                current = current->_next;

                delete del;

                --_size;
            }
            else
            {
                current = current->_next;
            }
        }
    }

    const T &operator[](int index) const
    {
        if (index < 0)
        {
            throw std::out_of_range("Invalid index");
        }

        Node *current = _head;
        for (int i = 0; i < index; ++i)
        {
            if (!current)
            {
                throw std::out_of_range("Index out of range");
            }
            current = current->_next;
        }

        if (!current)
        {
            throw std::out_of_range("Invalid index");
        }

        return current->_info;
    }

    T &operator[](int index)
    {
        if (index < 0)
        {
            throw std::out_of_range("Invalid index");
        }

        Node *current = _head;
        for (int i = 0; i < index; ++i)
        {
            if (!current)
            {
                throw std::out_of_range("Index out of range");
            }
            current = current->_next;
        }

        if (!current)
        {
            throw std::out_of_range("Invalid index");
        }

        return current->_info;
    }

    int GetSize() const
    {
        return _size;
    }
};

export template <typename T>
std::ostream &operator<<(std::ostream &out, const TwoLinkedLists<T> &list)
{
    int size = list.GetSize();
    out << "[";
    for (int i = 0; i < size; ++i)
    {
        out << list[i];
        if (i != size - 1)
        {
            out << ", ";
        }
    }
    out << "]";

    return out;
}