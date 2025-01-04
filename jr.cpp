#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    double price;
};

const string filename = "products.txt";

vector<Product> loadProducts() {
    vector<Product> products;
    ifstream file(filename);
    Product p;
    while (file >> p.id) {
        file.ignore();
        getline(file, p.name);
        file >> p.price;
        file.ignore();
        products.push_back(p);
    }
    return products;
}

void saveProducts(const vector<Product>& products) {
    ofstream file(filename);
    for (const auto& p : products) {
        file << p.id << "\n" << p.name << "\n" << p.price << "\n";
    }
}

void createProduct() {
    vector<Product> products = loadProducts();
    Product p;
    cout << "Enter ID: "; cin >> p.id;
    cin.ignore();
    cout << "Enter Name: "; getline(cin, p.name);
    cout << "Enter Price: "; cin >> p.price;
    products.push_back(p);
    saveProducts(products);
    cout << "Product added!\n";
}

void readProducts() {
    vector<Product> products = loadProducts();
    for (const auto& p : products) {
        cout << "ID: " << p.id << "\nName: " << p.name << "\nPrice: $" << p.price << "\n\n";
    }
    if (products.empty()) cout << "No products found.\n";
}

void updateProduct() {
    vector<Product> products = loadProducts();
    int id; bool found = false;
    cout << "Enter ID to update: "; cin >> id;
    for (auto& p : products) {
        if (p.id == id) {
            found = true;
            cin.ignore();
            cout << "Enter new Name: "; getline(cin, p.name);
            cout << "Enter new Price: "; cin >> p.price;
            saveProducts(products);
            cout << "Product updated!\n";
            break;
        }
    }
    if (!found) cout << "Product not found.\n";
}

void deleteProduct() {
    vector<Product> products = loadProducts();
    int id; bool found = false;
    cout << "Enter ID to delete: "; cin >> id;
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->id == id) {
            found = true;
            products.erase(it);
            saveProducts(products);
            cout << "Product deleted!\n";
            break;
        }
    }
    if (!found) cout << "Product not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Product\n2. View Products\n3. Update Product\n4. Delete Product\n5. Exit\nChoose: ";
        cin >> choice;
        if (choice == 1) createProduct();
        else if (choice == 2) readProducts();
        else if (choice == 3) updateProduct();
        else if (choice == 4) deleteProduct();
        else if (choice == 5) cout << "Exiting...\n";
        else cout << "Invalid choice.\n";
    } while (choice != 5);
    return 0;
}