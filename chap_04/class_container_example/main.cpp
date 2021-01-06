#include <iostream>

class Vector
{
public:
    Vector(int s) : elem{new double[s]}, sz{s}
    {                                //constructor
        for (int i = 0; i != s; ++i) //initialize elements
            elem[i] = 0;
    }

    ~Vector() { delete[] elem; } //destructor

    double &operator[](int i){return elem[i];}
    int size() const { return sz;}

private:
    double *elem; //elem points to an array of sz doubles
    int sz;
};

class Container{
public:
    virtual double& operator[](int) = 0;    //pure virtual funciton
    virtual int size() const = 0;           //const member function
    virtual ~Container(){}                  //destructor
};

class Vector_container: public Container{   //Vector_container implements Container
public:
    Vector_container(int s): v(s){ }        //Vector of s elements
    ~Vector_container(){}

    double& operator[](int i) override{ return v[i];}
    int size() const override{return v.size();}
private:
    Vector v;
};

void use(Container& c){
    const int sz = c.size();
    for (int i = 0; i != sz; ++i)
        std::cout << c[i] << "\n";
}
int main(){
    Container* p = new Vector_container(10);
    use(*p);
}