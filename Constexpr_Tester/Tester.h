#pragma once
#include <stdio.h>
#include <exception>
#include <vector>
#include <iostream>
//#include <hash>
class ConstString
{
private:
    const char* p = NULL;
    std::size_t sz = 0;

public:
    template<std::size_t N>
    constexpr ConstString(const char(&a)[N])
        : p(a), sz(N - 1)
    {

    }

public:
    constexpr char operator[](std::size_t n) const
    {
        return n < sz ? p[n] : throw std::out_of_range("");
    }

public:
    constexpr std::size_t size() const { return sz; }
};

// 소문자가 몇개인지 수를 세는 함수
constexpr std::size_t CountLowercase(ConstString s, std::size_t n = 0, std::size_t c = 0)
{
    return n == s.size() ? 
        c : s[n] >= 'a' && s[n] <= 'z' ? 
        CountLowercase(s, n + 1, c + 1) : CountLowercase(s, n + 1, c);
}

// 컴파일타임 상수를 테스트해 보기 위한 템플릿
template<int n>
struct ConstN
{
    ConstN()
    {
        std::cout << n << '\n';
    }
};


////////////////////////////////////


template<unsigned n>
struct Fibonacci
{
    static const unsigned value = Fibonacci<n - 1>::value + Fibonacci<n - 2>::value;
};

template<>
struct Fibonacci<0>
{
    static const unsigned value = 0;
};

template<>
struct Fibonacci<1>
{
    static const unsigned value = 1;
};


///////////////////////////////////////////////////////////////////////////////////////////////

constexpr unsigned fibonacci(const unsigned x)
{
    return x <= 2 ? 1 : fibonacci(x - 1) + fibonacci(x - 2);
}

