// ISP -> Interface Seggregation Principle

// ye bolta hai ki bhai dekho aisa hai ki tm ek hi interface me sbko daalne ka koshish mt kro otherwise 
// child class ko jbrdsti unneccessary methods ko implement krna pdega toh esliye segregate kro interface ko

// esme follow ho rha hai , qki interface dekho hmlog 2-d and 3-d interface banae hai taaki option hi ni aae


#include<iostream>
using namespace std;
class twodimesionalShape{
    virtual double area()=0;
};

class threedimesionalShape{
    virtual double area()=0;
    virtual double volume()=0;
};

class Square:public twodimesionalShape{
    private:   
        double side;
    public:
        Square(double s){
            side=s;
        }
        double area() override{
            return side*side;
        }
};
class Rectangle:public twodimesionalShape{
    private:
        double length,breadth;
    public:
        Rectangle(double l,double b){
            length=l;
            breadth=b;
        }
        double area(){
            return length*breadth;
        }
};
class Cube:public threedimesionalShape{
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

    Square *s= new Square(10);
    Rectangle *r= new Rectangle(4,6);
    Cube *c=new Cube(4);

    cout<<"Area of the square "<<s->area()<<endl;
    cout<<"Area of the rectangle "<<r->area()<<endl;
    cout<<"Area of the cube "<<c->area()<<endl;
    cout<<"Volume of the cube "<<c->volume()<<endl;
    return 0;
}