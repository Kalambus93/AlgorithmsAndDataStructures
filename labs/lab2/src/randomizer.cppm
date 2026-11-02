export module randomizer;
import std;

export int Randomizer(int a, int b)
{
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dis(a, b);
    return dis(gen);
}

export float Randomizer(float a, float b)
{
    static std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<float> dis(a, b);
    return dis(gen);
}

export double Randomizer(double a, double b)
{
    static std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<double> dis(a, b);
    return dis(gen);
}