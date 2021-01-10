#include <iostream>
#include <vector>
//#include <thread>

//std::vector<std::thread> my_threads;

class Vector{
public:
    Vector(int s): elem{new double[s]}, sz{s}
    {                                //constructor
        for (int i = 0; i != s; ++i) //initialize elements
            elem[i] = 0;
    }
    ~Vector() { delete[] elem;}

    Vector(const Vector& a);            //copy constructor
    Vector& operator=(const Vector& a); //copy assignment

    double& operator[](int i) { return elem[i]; }
    //const double& operator[](int i) const;
    int size() const { return sz; }

private: 
    double* elem;
    int sz;
};

Vector::Vector(const Vector& a):        //copy constructor
                elem{new double[a.sz]}, //allocate space for elements
                sz{a.sz}{
    for (int i = 0; i != sz; ++i)       //copy elements
        elem[i] = a.elem[i];
}

Vector& Vector::operator=(const Vector& a){ //copy assignment
    double* p = new double[a.sz];
    for (int i = 0; i != a.sz; ++i)
        p[i] = a.elem[i];
    delete[] elem;                          // delete old elements
    elem = p;
    sz = a.sz;
    return *this;                           // this points to the object which the member function is called
}

Vector init(int n){
    //std::thread t {heartbeat};                   // run heartbeat concurrently
    //my_threads.push_back(std::move(t));    // move t into my_threads

    Vector vec(n);
    for (int i = 0; i != vec.size(); ++i)
        vec[i] = 777;
    return vec;
}

int main(){
    auto v = init(1000000);                     // start heartbeat and initialize v
}
