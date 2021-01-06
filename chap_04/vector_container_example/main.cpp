#include <iostream>

class Vector{
public:
    Vector(int s): elem{new double[s]},sz{s}{  //constructor
        for (int i = 0; i != s; ++i)           //initialize elements
            elem[i] = 0;
    }

    ~Vector() {delete[] elem; }     //destructor

    double& operator[](int i);
    int size() const;
private:
    double* elem; //elem points to an array of sz doubles
    int sz;
};

int main(){
    Vector v1(5);
}