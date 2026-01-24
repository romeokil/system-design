#include<iostream>
using namespace std;

class Shape{
    public:
        virtual void display(){
            cout<<"This is the base class display function"<<endl;
        }
};

class Rectangle:public Shape{
    public:
        // because they have some addition display logic.
        void display(){
            cout<<"This is the derived Rectangle display function"<<endl;
        }
};

class Circle:public Shape{
    public:
        // because they have some addition display logic.
        void display(){
            cout<<"This is the derived Circle display function"<<endl;
        }
};

int main(){

    Shape *s;
    Rectangle r;
    s=&r;
    s->display();
    Circle c;
    s=&c;
    s->display();
    return 0;   
}