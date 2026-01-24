#include<iostream>
using namespace std;

class grandParent{
    public:
        void hardworking(){
            cout<<"Hardworking property inherited successfully!!!"<<endl;
        }
};
class Parent{
    public:
        void intelligent(){
            cout<<"Intelligent property inherited successfully!!"<<endl;
        }
};
class Child:public Parent,public grandParent{
    public:
        void runner(){
            cout<<"I am good runner!!!"<<endl;
        }
};

int main(){
    Child c;
    c.runner();
    c.intelligent();
    c.hardworking();
    return 0;
}