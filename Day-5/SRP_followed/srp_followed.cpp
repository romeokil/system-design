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
        void addItem(Products *p){
            products.push_back(p);
        }
        vector<Products*> getProduct(){
            return products;
        }
};
class ShoppingCartPrint{
    private:
        ShoppingCart* cart;
    public:
        ShoppingCartPrint(ShoppingCart* cart){
            this->cart=cart;
        }
        void printInvoice(){
            for(auto it:cart->getProduct()){
                cout<<"Name of the Item"<<it->name<<" "<<endl;
                cout<<"Price of the Item"<<it->price<<" "<<endl;
            }
        }
};
class ShoppingCartDBInsert{
    private:
        ShoppingCart* cart;
    public:
        ShoppingCartDBInsert(ShoppingCart* cart){
            this->cart=cart;
        }
        void inserttoDB(){
            cout<<"Inserting data into the database"<<endl;
        }
};
int main(){

    ShoppingCart* cart=new ShoppingCart();
    cart->addItem(new Products("Laptop", 60000));
    cart->addItem(new Products("Mouse",500));


    ShoppingCartPrint *obj1=new ShoppingCartPrint(cart);
    obj1->printInvoice();

    ShoppingCartDBInsert *obj2=new ShoppingCartDBInsert(cart);
    obj2->inserttoDB();

    return 0;
}