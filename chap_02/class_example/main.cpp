#include <iostream>

class Vector{
    public:
        Vector(int s) :elem{new double[s]}, sz{s} {} //construct a Vector
        double& operator[](int i){ return elem[i]; } // element access
        int size() { return sz; }
    private:
        double* elem;
        int sz;
};

double read_and_sum(int s){
    Vector v(s);
    for (int i=0; i!=v.size(); ++i){
        std::cout << "Type an element...\n";
        std::cin >> v[i];
    }
    double sum = 0;
    for (int i=0; i!=v.size(); ++i)
        sum += v[i];
    std::cout << "Vector size is: " << v.size() << std::endl;
    std::cout << "Printing 2nd element: " << v.operator[](1) << std::endl;
    return sum;
}

int main(){
    double a = read_and_sum(5);
    std::cout << "Sum is " << a << std::endl;
}