#include <iostream>
#include "Vector.h"
#include <cmath>

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

int main(){
    Vector my_Vec(7);
    add_elem(my_Vec);
    double s = sqrt_sum(my_Vec);
    std::cout << "Sum of squares: " << s;
}