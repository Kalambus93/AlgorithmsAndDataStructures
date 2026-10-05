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

export std::complex<float> Randomizer(std::complex<float> a, std::complex<float> b)
{
    static std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<float> dis_r(a.real(), b.real());
    std::uniform_real_distribution<float> dis_i(a.imag(), b.imag());
    return {dis_r(gen), dis_i(gen)};
}

export std::complex<double> Randomizer(std::complex<double> a, std::complex<double> b)
{
    static std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<double> dis_r(a.real(), b.real());
    std::uniform_real_distribution<double> dis_i(a.imag(), b.imag());
    return {dis_r(gen), dis_i(gen)};
}