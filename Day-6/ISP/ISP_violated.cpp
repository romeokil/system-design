// ISP -> Interface Seggregation Principle

// ye bolta hai ki bhai dekho aisa hai ki tm ek hi interface me sbko daalne ka koshish mt kro otherwise 
// child class ko jbrdsti unneccessary methods ko implement krna pdega toh esliye segregate kro interface ko

#include<iostream>
using namespace std;

class Shape{
    virtual double area()=0;
    virtual double volume()=0;
};

class Rectangle{
    private:
        double length;
        double breadth;
    public:
        Rectangle(double l,double b){
            length=l;
            breadth=b;
        }
        double area(){
            return length*breadth;
        }
        double volume(){
            throw logic_error("Sorry for 2-d figures volumes can't be computed.");
        }
};

class Square{
    private:
        double side;
    public:
        Square(double s){
            side=s;
        }
        double area(){
            return side*side;
        }
        double volume(){
            throw logic_error("Sorry for 2-d figures volumes can't be computed");
        }
};

class Cube{
    private:
        double side;
    public:
        Cube(double s){
            side=s;
        }
        double area(){
            return 6*side*side;
        }
        double volume(){
            return side*side*side;
        }
};
int main(){


    Square *s=new Square(10);
    Rectangle *r=new Rectangle(4,6);
    Cube* c=new Cube(20);

    cout<<"Area of the square "<<s->area()<<endl;
    cout<<"Area of the rectangle "<<r->area()<<endl;
    cout<<"Area of the cube "<<c->area()<<endl;
    cout<<"Volume of the cube "<<c->volume()<<endl;

    try{
        cout<<"Square Volume: "<<s->volume()<<endl;
    }
    catch(logic_error& e){
        cout<<"Exception: "<<e.what()<<endl;
    }
    return 0;
}