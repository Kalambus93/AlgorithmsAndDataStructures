import std;
import tllist;
import randomizer;
import task;

int main()
{
    TwoLinkedLists<int> empty;
    TwoLinkedLists<int> random_int(3);
    TwoLinkedLists<float> random_float(2);
    TwoLinkedLists<std::string> random_str(4);

    std::cout << "Empty: " << empty << "\n";
    std::cout << "Random int: " << random_int << "\n";
    std::cout << "Random float: " << random_float << "\n";
    std::cout << "Random string: " << random_str << "\n\n";

    TwoLinkedLists<int> list;
    list.push_tail(1);
    list.push_tail(2);
    list.push_head(0);
    std::cout << "After push: " << list << " (size=" << list.GetSize() << ")\n";

    TwoLinkedLists<int> other;
    other.push_tail(10);
    other.push_tail(20);
    list.push_tail(other);
    std::cout << "After push_tail(list): " << list << "\n";

    list.push_head(other);
    std::cout << "After push_head(list): " << list << "\n\n";

    std::cout << "list[0]=" << list[0] << ", list[2]=" << list[2] << "\n";
    list[1] = 999;
    std::cout << "After list[1]=999: " << list << "\n\n";

    list.pop_head();
    list.pop_tail();
    std::cout << "After pop: " << list << " (size=" << list.GetSize() << ")\n\n";

    TwoLinkedLists<int> del;
    del.push_tail(1);
    del.push_tail(2);
    del.push_tail(2);
    del.push_tail(3);
    del.delete_node(2);
    std::cout << "After delete_node(2): " << del << "\n\n";

    TwoLinkedLists<int> copy = list;
    copy[0] = 12345;
    std::cout << "Original: " << list << "\n";
    std::cout << "Copy (modified): " << copy << "\n\n";

    TwoLinkedLists<int> moved = std::move(list);
    std::cout << "Moved: " << moved << "\n";
    std::cout << "Source after move: " << list << " (size=" << list.GetSize() << ")\n\n";

    try
    {
        list[100];
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Caught: " << e.what() << "\n";
    }

    std::cout << "\n";
    AdressBook(5, 3);

    return 0;
}