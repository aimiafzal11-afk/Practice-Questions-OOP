/* Create a Shopping Cart system using OOP. Use a base class Product and derive 
ElectronicsProduct (tax) and ClothingProduct (discount). Add products to cart and calculate final bill. */

#include <iostream>
using namespace std;

class Product {
protected:
    int productID;
    string name;
    double price;
    int static totalProducts;
public:
    Product(int id, string n, double p) {
        productID = id;
        name = n;
        price = p;
        totalProducts++;
    }
    void display() {
        cout << "Product ID = " << productID << endl;
        cout << "Name = " << name << endl;
    }
    static void showTotalProducts() {
        cout << "\nTotal Products = " << totalProducts << endl;
    }
    double get_price() { return price; }
};
int Product::totalProducts = 0;

class ElectronicsProduct : public Product {
private:
    double warranty;
    double tax;
public:
    ElectronicsProduct(int id, string n, double p, double warr, double t) : Product(id, n, p) {
        warranty = warr;
        tax = t;
    }
    void show() {
        display();
        cout << "Warranty years = " << warranty << endl;
        cout << "Tax = " << tax << " %" << endl;
    }
    double calcFinalPrice() {
        double taxAmount = price * (tax / 100.0);
        return price + taxAmount;
    }
};

class ClothingProduct : public Product {
private:
    int discountPercent;
public:
    ClothingProduct(int id, string n, double p, int per) : Product(id, n, p) {
        discountPercent = per;
    }
    void show() {
        display();
        cout << "Discount = " << discountPercent << " %" << endl;
    }
    double calcFinalPrice() {
        double discountAmount = price * (discountPercent / 100.0);
        return price - discountAmount;
    }
};

class ShoppingCart {
private:
    double total;
public:
    ShoppingCart() { total = 0; }
    void addElectronicItem(ElectronicsProduct& e) {
        double final = e.calcFinalPrice();
        total += final;
        cout << "Initial Price = " <<  e.get_price() << endl;
        cout << "Final Price = " << final << endl;
    }
    void addClothItem(ClothingProduct& c) {
        double t = c.calcFinalPrice();
        total += t;
        cout << "Initial Price = " << c.get_price() << endl;
        cout << "Final Price = " << t << endl;
    }
    void totalBill() {
        cout << "Total Bill = " << total << endl;
    }
};

int main()
{
    ShoppingCart cart1, cart2;
    ElectronicsProduct e1(176, "Iron", 8000, 2, 5);
    ElectronicsProduct e2(124, "Fridge", 80000, 1, 10);
    ElectronicsProduct e3(100, "Microwave", 25000, 1.5, 10);
    cout << "---CART 1---" << endl;
    cout << "PRODUCT 1 " << endl;
    e1.show();
    cart1.addElectronicItem(e1);
    cout << "\nPRODUCT 2 " << endl;
    e2.show();
    cart1.addElectronicItem(e2);
    cout << "\nPRODUCT 3 " << endl;
    e3.show();
    cart1.addElectronicItem(e3);
    cout << "-------------------------" << endl;
    cout << "CART 1 ";
    cart1.totalBill();
    cout << "-------------------------" << endl;

    ClothingProduct c1(245, "Skirt", 3000, 10);
    ClothingProduct c2(265, "Shirt", 2500, 20);
    cout << "\n---CART 2---" << endl;
    cout << "PRODUCT 1 " << endl;
    c1.show();
    cart2.addClothItem(c1);
    cout << "\nPRODUCT 2 " << endl;
    c2.show();
    cart2.addClothItem(c2);
    cout << "-------------------------" << endl;
    cout << "CART 2 ";
    cart2.totalBill();
    cout << "-------------------------" << endl;

    Product::showTotalProducts();
}

