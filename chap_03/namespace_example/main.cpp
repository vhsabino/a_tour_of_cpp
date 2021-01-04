#include <iostream>

namespace My_code{
    class complex{
        public:
            complex(double r, double i) : re{r}, im{i} {}
            double real() { return re; }
            double imag() { return im; }
        private:
            double re;
            double im;

    };

    int main();
}

int My_code::main(){
    complex z{1,2};
    std::cout << "{" << z.real() << "," << z.imag() << "}\n";
    return 0;
}

int main(){
    int r = My_code::main();
    std::cout << r << std::endl;
}