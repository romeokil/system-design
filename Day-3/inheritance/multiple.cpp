#include<iostream>
using namespace std;
class Mom{
    public:
        void optimistic(){
            cout<<"Optimistic property Inherited!!!"<<endl;
        }
};
class Dad{
    public:
        void hardworking(){
            cout<<"Hardworking property Inherited"<<endl;
        }
};
class Child:public Mom,public Dad{
    public:
        void intelligent(){
            cout<<"I am intelligent"<<endl;
        }
};
int main(){

    Child c;
    c.optimistic();
    c.hardworking();
    c.intelligent();
    return 0;
}