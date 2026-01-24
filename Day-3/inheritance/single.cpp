#include<iostream>
using namespace std;

class Father{
    public:
        void hardworking(){
        cout<<"Hardworking property inherited Successfully!!"<<endl;
    }
};
class Son:public Father{
    public:
        void intelligent(){
        cout<<"Intelligent property inherited successfully!!"<<endl;
    }
};

int main(){
    Son s;
    s.intelligent();
    s.hardworking();
    return 0;

}