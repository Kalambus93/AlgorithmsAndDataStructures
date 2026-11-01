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
    int _size = 0;

public:
    TwoLinkedLists() : _head(nullptr) {}

    TwoLinkedLists(const TwoLinkedLists &other) {}

    TwoLinkedLists(TwoLinkedLists &&other) noexcept {}

    ~TwoLinkedLists() {}

    TwoLinkedLists &operator=(const TwoLinkedLists &other) {}

    TwoLinkedLists &operator=(TwoLinkedLists &&other) noexcept {}

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
                return;
            }

            while (current->_next->_next != nullptr)
            {
                current = current->_next;
            }

            delete current->_next;
            current->_next = nullptr;
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

        return *current;
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

        return *current;
    }
};

export template <typename T>
std::ostream &operator<<(std::ostream &out, const TwoLinkedLists &list) {}