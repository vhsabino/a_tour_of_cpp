#include <iostream>

class complex{
    double re, im;
public:
    complex(double r, double i): re{r}, im{i} {} //construct complex for two scalars
    complex(double r): re{r}, im{0} {}           //construct complex for one scalar
    complex(): re{0}, im{0} {}                   //default complex: {0,0}

    double real() const{ return re;}
    void real (double d) { re = d;}
    double imag() const {return im;}
    void imag(double d) { im = d;}

    complex& operator+=(complex z){
        re+=z.re; // add to re and im
        im+=z.im;
        return *this; //return the result
    }

    complex& operator-=(complex z){
        re-=z.re;
        im-=z.im;
        return *this;
    }

    complex& operator*=(complex); //defined out of class
    complex& operator/=(complex); //defined out of class
};

int main(){
    complex z = {1,0};
    const complex cz{1,3};
    z = cz;
    double x = z.real();
    std::cout << "{" << x << "," << z.imag() << "}\n";
}