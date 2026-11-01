import std;

template <typename T>
export struct Node
{
    T _info;
    Node *_prev;
    Node *_next;
};

template <typename T>
export class TwoLinkedLists
{
private:
    Node<T> *_head;
    Node<T> *_tail;

public:
    TwoLinkedLists() : head(nullptr), tail(nullptr) {}

    TwoLinkedLists() {}

    TwoLinkedLists(const TwoLinkedLists &other) {}

    TwoLinkedLists(TwoLinkedLists &&other) noexcept {}

    ~TwoLinkedLists() {}

    TwoLinkedLists &operator=(const TwoLinkedLists &other) {}

    TwoLinkedLists &operator=(TwoLinkedLists &&other) noexcept {}

    void push_tail(T &el)
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

    void push_tail(TwoLinkedLists &list) {}

    void push_head(T &el)
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

    void push_head(TwoLinkedLists &list) {}

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

    void delete_node(T info) {}

    const Node<T> &operator[](int &index) const {}

    Node<T> &operator[](int &index) {}
};

export template <typename T>
std::ostream &operator<<(std::ostream &out, const TwoLinkedLists &list) {}