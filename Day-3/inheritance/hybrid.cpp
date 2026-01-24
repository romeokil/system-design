#include<iostream>
using namespace std;
class grandParents{
    public:
        void hardworking(){
            cout<<"Hardworking Property Inherited!!"<<endl;
        }
};
class Mom:virtual public grandParents{
    public:
        void intelligent(){
            cout<<"Intelligent Property Inherited"<<endl;
        }
};
class Dad:virtual public grandParents{
    public:
        void Optimistic(){
            cout<<"Optimistic Property Inherited"<<endl;
        }
};
class Child:public Dad,public Mom{
    public:
        void Honest(){
            cout<<"Honest Property is already There"<<endl;
        }
};
int main(){
    Child c;
    c.hardworking();
    c.intelligent();
    c.Optimistic();
    c.Honest();

    return 0;
}