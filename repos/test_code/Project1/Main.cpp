#include "Main.h"
#include <memory>
#include <vector>
#include <queue>
//#define DMain
//#define emp
//#define Hack
//#define Hack2

std::greater<int>;

#ifdef DMain
class Main
{
    int val;

public:
    int data()& { return val; }
    int data() && { return std::move(val); }
    int bar() { return 1; }
    int bar() const { return 5; };
    int foo();
    int foo() const;

};

int Main::foo()
{
    return 2;
}
int Main::foo() const
{
    return 11;
}


void main()
{
    Main Amain;
    Amain.data();
    const Main Bmain;
    auto b = Amain.bar();
    auto c = Bmain.bar();

    auto d = Amain.foo();

    auto e = Bmain.foo();



    int xxx = 999;
}
#endif

#ifdef emp
// clang++ -std=c++11 -O2 bench.cpp -o bench
#include <iostream>
#include <chrono>
#include <map>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <random>

    char randchar()
    {
        static std::mt19937_64 rng(0xbeef);
        std::uniform_int_distribution<> dist(1, 255);
        return static_cast<char>(dist(rng));
    }

    std::vector<std::string>
        prepare(int len, int count)
    {
        std::vector<std::string> r;
        r.reserve(count);
        for (int vi = 0; vi < count; ++vi)
        {
            std::string s;
            s.reserve(len);
            for (int si = 0; si < len; ++si)
            {
                s += randchar();
            }
            r.push_back(std::move(s));
        }
        return r;
    }

    enum TestType
    {
        map,
        umap
    };

    int len = 10;
    int count = 107897;

    template <typename map_t>
    void run(int len, int count)
    {
        std::vector<std::string> srces = prepare(len, count);

        using mapped_type = typename map_t::mapped_type;

        auto start = std::chrono::high_resolution_clock::now();
        map_t map;
        for (auto &&s : srces)
        {
            map.emplace(std::move(s), mapped_type());
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout
            << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() /** 1e-3*/
            << "ms"
            << std::endl;


        int temp = 0;

        start = std::chrono::high_resolution_clock::now();
        //
        for (auto &&s : map)
        {
            temp += s.second;
        }
        //
        end = std::chrono::high_resolution_clock::now();

        std::cout
            << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() /** 1e-3*/
            << "ms"
            << std::endl;


    }

    int main()
    {
        int argc = 0;
        char argv[] = { "" };

        run<std::map<std::string, int>>(len, count);

        run<std::unordered_map<std::string, int>>(len, count);



        int a = 0;
    }

#endif 

#ifdef Hack


// https://codeforces.com/blog/entry/62393
#include <ctime>
#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 2000;
long long sum = 0;
long long sum2 = 0;

void insert_numbers(long long x) {
    clock_t begin = clock();
    unordered_map<long long, int> numbers;

    for (int i = 1; i <= N; i++)
        numbers[i] = i;

    sum = 0;

    for (auto &entry : numbers)
    {
        sum += (entry.first) * entry.second;
    }
    printf("x = %lld: %.3lf seconds, sum = %lld\n", x, (double)(clock() - begin) / CLOCKS_PER_SEC, sum);
}

int main() {
    insert_numbers(107897);
    insert_numbers(126271);


    long long temp = 0;
    for (size_t i = 1; i <= N; i++)
    {
        if (i > N - 1)
        {
            int a = 0;
        }

        temp += i*i;

    }
}



#endif // Hack

#ifdef Hack2
#include <map>
#include <ctime>
#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 2e5;

void insert_numbers(long long x) {
    clock_t begin = clock();
    unordered_map<long long, int> numbers;

    for (int i = 1; i <= N; i++)
        numbers[i ] = i;

    long long sum = 0;
    int count = 0;
    auto a = numbers.begin();
    for (auto &entry : numbers)
    {
        a++;
      //  sum += (entry.first / x) * entry.second;
        count++;

    }
    printf("x = %lld: %.3lf seconds, sum = %lld , %d\n", x, (double)(clock() - begin), sum, count);
}
void insert_numbers2(long long x) {
    clock_t begin = clock();
    map<long long, int> numbers;

    for (int i = 1; i <= N; i++)
        numbers[i] = i;

    long long sum = 0;
    int count = 0;

    for (auto &entry : numbers)
    {
        //sum += (entry.first / x) * entry.second;
        count++;
    }
    printf("x = %lld: %.3lf seconds, sum = %lld , %d\n", x, (double)(clock() - begin), sum, count);
}

void insert_numbers3(long long x) {
    clock_t begin = clock();
    map<long long, int> numbers;

    for (int i = 1; i <= N; i++)
        numbers[i] = i;

    long long sum = 0;
    int count = 0;
    for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
    {
       // sum += (iter->first / x) * iter->second;
        count++;
    }
    printf("x = %lld: %.3lf seconds, sum = %lld , %d\n", x, (double)(clock() - begin), sum, count);
}

int main() {
    insert_numbers(107897);
    insert_numbers(126271);
    insert_numbers(1056323);


    insert_numbers2(107897);
    insert_numbers2(126271);
    insert_numbers2(1056323);

    insert_numbers3(107897);
    insert_numbers3(126271);
    insert_numbers3(1056323);
    int a = 90;
}

#endif

#include <string>
#include <functional>
#include <iostream>
#include <optional>
// optional can be used as the return type of a factory that may fail
std::optional<std::string> create(bool b) {
    if (b)
        return "Godzilla";
    return {};
}

// std::nullopt can be used to create any (empty) std::optional
auto create2(bool b) {
    return b ? std::optional<std::string>{"Godzilla"} : std::nullopt;
}

// std::reference_wrapper may be used to return a reference
auto create_ref(bool b) {
    static std::string value = "Godzilla";
    return b ? std::optional<std::reference_wrapper<std::string>>{value}
    : std::nullopt;
}

int main()
{
    std::cout << "create(false) returned "
        << create(false).value_or("empty") << '\n';

    // optional-returning factory functions are usable as conditions of while and if
    if (auto str = create2(true)) {
        std::cout << "create2(true) returned " << *str << '\n';
    }
    if (auto str = create2(false)) {
        std::cout << "create2(false!!!) returned " << *str << '\n';
    }

    if (auto str = create_ref(true)) {
        // using get() to access the reference_wrapper's value
        std::cout << "create_ref(true) returned " << str->get() << '\n';
        str->get() = "Mothra";
        std::cout << "modifying it changed it to " << str->get() << '\n';
    }
}