import std;
import geometry;
import randomizer;
import tasks;

template <typename T>
void TestComplex()
{
    using C = std::complex<T>;

    Point<C> point_1(C(3, 4), C(5, 6));
    Point<C> point_2(C(-3, 2), C(6, -1));
    Point<C> point_3(C(8, -5), C(-6, 7));

    std::cout << "\n"
              << "Creating polyline with point" << "\n";
    Polyline<C> line_1(point_1);
    std::cout << line_1;

    std::cout << "\n"
              << "Added points" << "\n";
    line_1.AddPoint(point_2);
    line_1.AddPoint(point_3);
    std::cout << line_1;

    std::cout << "\n"
              << "Erase point" << "\n";
    line_1.ErasePoint(1);
    std::cout << line_1;

    std::cout << "\n"
              << "Copy" << "\n";
    Polyline<C> line_2 = line_1;
    std::cout << "line_1:" << line_1 << "\n";
    std::cout << "line_2:" << line_2;

    std::cout << "\n"
              << "Random" << "\n";
    Polyline<C> line_rand(5);
    std::cout << line_rand;

    Polyline<C> line_range_manual(point_1);
    line_range_manual.AddPoint(point_2);

    std::cout << "\n"
              << "Index access" << "\n";
    const Point<C> access_index_point = line_1[1];
    std::cout << access_index_point;

    std::cout << "\n"
              << "Concatenation line to line" << "\n";
    Polyline<C> cat_line_ll = line_rand + line_range_manual;
    std::cout << cat_line_ll;

    std::cout << "\n"
              << "Concatenation line to point" << "\n";
    Polyline<C> cat_line_lp = line_rand + access_index_point;
    std::cout << cat_line_lp;

    std::cout << "\n"
              << "Concatenation point to line" << "\n";
    Polyline<C> cat_line_pl = access_index_point + line_range_manual;
    std::cout << cat_line_pl;

    Polyline<C> line_3(5);

    std::cout << "\n";
    std::cout << "line_1 == line_2: " << (line_1 == line_2 ? "true" : "false") << "\n";
    std::cout << "line_1 != line_2: " << (line_1 != line_2 ? "true" : "false") << "\n";
    std::cout << "line_1 == line_3: " << (line_1 == line_3 ? "true" : "false") << "\n";
    std::cout << "line_1 != line_3: " << (line_1 != line_3 ? "true" : "false") << "\n";

    std::cout << "\n"
              << "Lens" << "\n";
    double len_1 = LenPolyline(line_1);
    double len_2 = LenPolyline(line_2);
    double len_3 = LenPolyline(line_3);
    std::cout << len_1 << "\n"
              << len_2 << "\n"
              << len_3;

    std::cout << "\n";
}

template <typename T>
void Test()
{
    Point<T> point_1(T(3), T(5));
    Point<T> point_2(T(-3), T(6));
    Point<T> point_3(T(8), T(-6));

    std::cout << "\n"
              << "Creating polyline with point" << "\n";
    Polyline<T> line_1(point_1);
    std::cout << line_1;

    std::cout << "\n"
              << "Added points" << "\n";
    line_1.AddPoint(point_2);
    line_1.AddPoint(point_3);
    std::cout << line_1;

    std::cout << "\n"
              << "Erase point" << "\n";
    line_1.ErasePoint(1);
    std::cout << line_1;

    std::cout << "\n"
              << "Copy" << "\n";
    Polyline<T> line_2 = line_1;
    std::cout << "line_1:" << line_1 << "\n";
    std::cout << "line_2:" << line_2;

    std::cout << "\n"
              << "Random" << "\n";
    Polyline<T> line_rand(5);
    std::cout << line_rand;

    if constexpr (!(std::is_same_v<T, std::complex<float>> ||
                    std::is_same_v<T, std::complex<double>>))
    {
        std::cout << "\n"
                  << "Range" << "\n";
        Polyline<T> line_range(T(1), T(5));
        std::cout << line_range;
    }

    std::cout << "\n"
              << "Index access" << "\n";
    const Point<T> access_index_point = line_1[1];
    std::cout << access_index_point;

    Polyline<T> line_range_manual(point_1);
    line_range_manual.AddPoint(point_2);

    std::cout << "\n"
              << "Concatenation line to line" << "\n";
    Polyline<T> cat_line_ll = line_rand + line_range_manual;
    std::cout << cat_line_ll;

    std::cout << "\n"
              << "Concatenation line to point" << "\n";
    Polyline<T> cat_line_lp = line_rand + access_index_point;
    std::cout << cat_line_lp;

    std::cout << "\n"
              << "Concatenation point to line" << "\n";
    Polyline<T> cat_line_pl = access_index_point + line_range_manual;
    std::cout << cat_line_pl;

    Polyline<T> line_3(5);

    std::cout << "\n";
    std::cout << "line_1 == line_2: " << (line_1 == line_2 ? "true" : "false") << "\n";
    std::cout << "line_1 != line_2: " << (line_1 != line_2 ? "true" : "false") << "\n";
    std::cout << "line_1 == line_3: " << (line_1 == line_3 ? "true" : "false") << "\n";
    std::cout << "line_1 != line_3: " << (line_1 != line_3 ? "true" : "false") << "\n";

    std::cout << "\n"
              << "Lens" << "\n";
    auto len_1 = LenPolyline(line_1);
    auto len_2 = LenPolyline(line_2);
    auto len_3 = LenPolyline(line_3);
    std::cout << len_1 << "\n"
              << len_2 << "\n"
              << len_3;

    std::cout << "\n";
}

int main()
{
    std::cout << "\n"
              << "\n"
              << "Int" << "\n";
    Test<int>();
    std::cout << "\n"
              << "\n"
              << "Float" << "\n";
    Test<float>();
    std::cout << "\n"
              << "\n"
              << "Double" << "\n";
    Test<double>();
    std::cout << "\n"
              << "\n"
              << "ComplexFloat" << "\n";
    TestComplex<float>();
    std::cout << "\n"
              << "\n"
              << "ComplexDouble" << "\n";
    TestComplex<double>();
    return 0;
}