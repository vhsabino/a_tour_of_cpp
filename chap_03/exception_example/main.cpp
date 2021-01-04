#include <iostream>
#include "Vector.h"
#include <cmath>
#include <stdexcept>

double sqrt_sum(Vector& v){
    double sum = 0;
    for (int i=0; i!=v.size(); ++i)
        sum+=std::sqrt(v[i]);       //sum of square roots
    return sum;
}

void add_elem(Vector& v){
    for (int i = 0; i != v.size(); ++i)
    {
        std::cout << "Type an element...\n";
        std::cin >> v[i];
    }
}

void f(Vector& v){
    try{
        std::cout << "Vector size is: " << v.size() << std::endl;
        v[3] = 100;
    } catch (std::out_of_range& err){
        std::cerr << "Out of Range error: " << err.what() << std::endl;
    }
}

int main(){
    Vector my_Vec(2);
    add_elem(my_Vec);
    double s = sqrt_sum(my_Vec);
    std::cout << "Sum of squares: " << s << std::endl;
    f(my_Vec);
    return 0;
}