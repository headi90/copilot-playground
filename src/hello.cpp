#include <hello.hpp>
#include <iostream>

Hello::Hello(int i)
    : i_(i) {}

void Hello::print()
{
    std::cout << "Hello\n";
}
