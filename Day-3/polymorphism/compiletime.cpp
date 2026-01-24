#include<iostream>
using namespace std;
class A{
    public:
        void display(int a,int b){
            cout<<"Display having 2 integer format"<<endl;
        }
        void display(int a, int b, int c){
            cout<<"Display having 3 integer format"<<endl;
        }
        void display(int a,char ch){
            cout<<"Display having one integer and a character"<<endl;
        }
};
int main(){

    A a;
    a.display(2,2);
    a.display(2,3,4);
    a.display(2,'a');

    return 0;   
}