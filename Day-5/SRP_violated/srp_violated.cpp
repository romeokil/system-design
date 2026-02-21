#include <iostream>
#include <vector>
using namespace std;

class Products
{
public:
    string name;
    double price;
    Products(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart
{
private:
    vector<Products *> products;

public:
    void addItem(Products *p)
    {
        products.push_back(p);
    }
    vector<Products *> getProduct()
    {
        return products;
    }
    void printInvoice()
    {
        cout<<"Invoice Summary: ->"<<endl;
        for (auto it : products)
        {
            cout << "Name of the Item " << it->name << " " << endl;
            cout << "Price of the Item $" << it->price << " " << endl;
        }
    }
    void inserttoDB()
    {
        cout << "Inserting data into the database" << endl;
    }
};

int main()
{
    ShoppingCart *obj = new ShoppingCart();
    obj->addItem(new Products("Laptop", 60000));
    obj->addItem(new Products("Mouse", 400));

    obj->printInvoice();

    obj->inserttoDB();

    return 0;
}