#include <iostream>

struct Vector{
    int sz;         // number of elements
    double* elem;   // pointer to elements
};

void vector_init(Vector& v, int s){
    v.elem = new double[s]; //allocate an array of s doubles
    v.sz = s;
}

// reads s integers from cin and return their sum (s > 0)
double read_and_sum(int s){
    Vector v;
    vector_init(v,s);

    for (int i=0; i != s; ++i){
        std::cout << "Please, insert an element...\n";
        std::cin >> v.elem[i];
    }
    double sum = 0;
    for (int i = 0; i != s; ++i)
        sum += v.elem[i];

    return sum;
}

int main(){
    double a = read_and_sum(5);
    std::cout << "Sum is " << a << std::endl;
}