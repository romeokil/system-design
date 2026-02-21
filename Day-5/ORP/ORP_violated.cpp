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
// yha pe ORP violate kr rhe hai qki hmlog ek hi class ke andr saara function baana ke bs ghusa diye
// toh eslie ye ORP violate kr rhe hai jiska kehna tha ki aap existing code me change mt kro
// toh hm existing code me hi alter kr diye eslie ye violate ho gy.
class ShoppingCartDB{
    private:
        ShoppingCart* cart;
    public:
        ShoppingCartDB(ShoppingCart* cart){
            this->cart=cart;
        }
        void SavetoSQLDB(){
            cout<<"Saving the data into SQL DB..."<<endl;
        }
        void SavetoMongoDB(){
            cout<<"Saving the data into MONGO DB..."<<endl;
        }
        void SavetoFiles(){
            cout<<"Saving the data into some files"<<endl;
        }
};
int main(){

    ShoppingCart* cart=new ShoppingCart();
    cart->addItem(new Products("Laptop",70000));
    cart->addItem(new Products("Mouse",500));

    ShoppingCartPrinter* obj1=new ShoppingCartPrinter(cart);
    obj1->printInvoice();

    ShoppingCartDB* obj2=new ShoppingCartDB(cart);
    obj2->SavetoSQLDB();
    obj2->SavetoMongoDB();
    obj2->SavetoFiles();

    return 0;
}