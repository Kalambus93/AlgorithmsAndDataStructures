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

    void push_tail(Node<T> &el) {}

    void push_tail(TwoLinkedLists &list) {}

    void push_head(Node<T> &el) {}

    void push_head(TwoLinkedLists &list) {}

    void pop_head() {}

    void pop_tail() {}

    void delete_node(T info) {}

    const Node<T> &operator[](int &index) const {}

    Node<T> &operator[](int &index) {}
};

export template <typename T>
std::ostream &operator<<(std::ostream &out, const TwoLinkedLists &list) {}