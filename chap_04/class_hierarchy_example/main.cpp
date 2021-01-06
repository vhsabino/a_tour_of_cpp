#include <iostream>
#include <vector>

class Point
{
    double x;
    double y;
};

class Shape{
public:
    virtual Point center() const = 0;   //pure virtual
    virtual void move(Point to) = 0;

    virtual void draw() const = 0;
    virtual void rotate(int angle) = 0;

    virtual ~Shape(){}                  //destructor
};

class Circle: public Shape{
public:
    Circle(Point p, int rad);           //constructor

    Point center() const override{
        return x;
    }
    void move(Point to) override{
        x = to;
    }

    void draw() const override;
    void rotate(int) override {}

    private:
        Point x;    //center
        int r;      //radius
};

class Smiley: public Circle{    //use circle as base for a face
public:
    Smiley(Point p, int rad): Circle{p, rad},mouth{nullptr}{}
    ~Smiley(){
        delete mouth;
        for(auto p : eyes)
            delete p;
    }

    void move(Point to) override;

    void draw() const override;
    void rotate(int) override;

    void add_eyes(Shape* s){
        eyes.push_back(s);
    }
    void set_mouth(Shape* s);
    virtual void wink(int i);   //piscar o olho i
private:
    std::vector<Shape*> eyes;
    Shape* mouth;
};

int main(){
    
}
