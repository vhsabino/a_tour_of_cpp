#include <iostream>
#include <string>

enum Type {ptr, num};

struct Node{
    int data;
    struct Node* next;
};

union Value{
    Node* p;
    int i;
};

struct Entry {
    std::string name;
    Type t;
    Value v; //
};

void f(Entry* pe){
    if (pe->t == num)
        std::cout << pe->name << " is " << pe->v.i <<" years old.\n";
}

int main(){
    Entry s;
    s.t = num;
    s.name = "John";
    s.v.i = 10;
    f(&s);
}