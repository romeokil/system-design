#include<iostream>
using namespace std;
class Mom{
    public:
        void optimistic(){
            cout<<"Optimistic Property Inherited!!"<<endl;
        }
};
class Child1:public Mom{
    public:
        void naughty(){
            cout<<"Child1 i am good naughty!!"<<endl;
        }
};
class Child2:public Mom{
    public:
        void swimmer(){
            cout<<"Child2 i am good swimmer"<<endl;
        }
};
int main(){

    Child1 c1;
    Child2 c2;
    c1.naughty();
    c1.optimistic();
    c2.swimmer();
    c2.optimistic();
    return 0;
}