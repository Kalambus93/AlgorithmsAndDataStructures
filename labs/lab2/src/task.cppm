export module task;

import std;
import tllist;
import randomizer;

export void AdressBook(int count_flats, int max_residents_per_flat)
{
    TwoLinkedLists<std::string> *address_book = new TwoLinkedLists<std::string>[count_flats];

    for (int i = 0; i < count_flats; ++i)
    {
        int residents_count = Randomizer(0, max_residents_per_flat);

        address_book[i] = TwoLinkedLists<std::string>(residents_count);
    }

    std::cout << "Adress book the house\n\n";
    for (int i = 0; i < count_flats; ++i)
    {
        std::cout << "Flat №" << (i + 1) << ": ";

        if (address_book[i].GetSize() == 0)
        {
            std::cout << "(empty)";
        }
        else
        {
            std::cout << address_book[i];
        }
        std::cout << "\n";
    }

    delete[] address_book;
}