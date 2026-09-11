import std;

bool HasDuplicateChars(const char *const string)
{
    if (!string)
        return false;

    const char *current1 = string;

    while (*current1 != '\0')
    {
        const char *current2 = string;

        while (*current2 != '\0')
        {
            if (current1 == current2)
            {
                ++current2;
                continue;
            }

            if (*current1 == *current2)
            {
                return true;
            }

            ++current2;
        }
        ++current1;
    }

    return false;
}

int main()
{

    return 0;
}

/*bool is_polindrom(const char *const string)
{
    const char *end = string;
    while (*end = '\0')
    {
        ++end;
    }

    --end;

    const char* start
}*/

/* Палиндром 1 1 задание*/
/*int main()
{
    std::string word;
    std::cin >> word;

    std::string verify_word;

    for (std::size_t i = word.size(); i > 0; --i)
    {
        verify_word.push_back(word[i - 1]);
    }

    std::println("{}", verify_word);

    if (verify_word == word)
    {
        std::println("Палиндром");
    }
    else
    {
        std::println("Не палиндром");
    }

    return 0;
}*/