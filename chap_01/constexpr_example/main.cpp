// constexpr suggests the compiler
// to evaluate the value at compile time
#include <iostream>

constexpr double nth(double x, int n){
    double res = 1;
    int i = 0;
    while (i < n){
        res *= x;
        ++i;
    }
    return res;
}

int main(){
    double a = nth(1.1,5);
    std::cout << "a = " << a << "\n" << std::endl;
}