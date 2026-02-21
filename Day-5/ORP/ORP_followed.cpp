#include<iostream>
#include<vector>
using namespace std;

class Products{
    public:
        string name;
        double price;
        Products(string name,double price){
            this->name=name;
            this->price=price;
        }
};

class ShoppingCart{
    private:
        vector<Products*> products;
    public:
        void addItem(Products* p){
            products.push_back(p);
        }
        vector<Products*> getProducts(){
            return products;
        }
};  
class ShoppingCartPrinter{
    private:
        ShoppingCart* cart;
    public:
        ShoppingCartPrinter(ShoppingCart* cart){
            this->cart=cart;
        }
        void printInvoice(){
            cout<<"Summary Invoice-> "<<endl;
            for(auto it:cart->getProducts()){
                cout<<"Name of the Item "<<it->name<<endl;
                cout<<"Price of the Item $"<<it->price<<endl;
            }
        }
};
// ab dekho ye kaise follow kr rha hai ORP ko
// hmlog esko pehli baat toh segregate kr diya or isme abstraction +polymorphism + inheritance ka combo use krte hai
// ab kisi ko ek chiz change krna hai toh wo aaaram se apna respective class me change kr skte hai.
class PersistDB{
    private:
        ShoppingCart* cart;
    public:
        virtual void save(){
            cout<<"Persist DB save function called...."<<endl;
        }
};  
class PersistDBtoMongo:public PersistDB{
    private:
        ShoppingCart* cart;
    public:
        void save(){
            cout<<"Persist DB save function but in Mongo"<<endl;
        }
};
class PersistDBtoSQL:public PersistDB{
    private:
        ShoppingCart* cart;
    public:
        void save(){
            cout<<"Persist DB save function but in SQL"<<endl;
        }
};
class PersistDBtoFiles:public PersistDB{
    private:
        ShoppingCart* cart;
    public:
        void save(){
            cout<<"Persist DB save function but in Files"<<endl;
        }
};
int main(){

    ShoppingCart* cart=new ShoppingCart();
    cart->addItem(new Products("Laptop",70000));
    cart->addItem(new Products("Mouse",500));

    ShoppingCartPrinter* obj1=new ShoppingCartPrinter(cart);
    obj1->printInvoice();

    
    PersistDB* db1=new PersistDBtoSQL();
    PersistDB* db2=new PersistDBtoMongo();
    PersistDB* db3=new PersistDBtoFiles();

    db1->save();
    db2->save();
    db3->save();
    return 0;
}