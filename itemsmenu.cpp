#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

struct MenuItem {
    std::string name;
    std::string category;
    int quantity;
    double price;
    double sales;
    int stock;
};

void saveToDatabase(const std::vector<MenuItem> &menuItems) {
    std::ofstream outputFile("menu_items.txt");
    for (const auto &item : menuItems) {
        outputFile << item.name << "," << item.category << "," << item.quantity << "," << item.price << "," << item.sales << "," << item.stock << std::endl;
    }
    outputFile.close();
}

int main() {
    std::vector<MenuItem> menuItems = {
        {"Pasta", "Main", 50, 10.99, 0, 100},
        {"Burger", "Main", 100, 8.99, 0, 150},
        {"Salad", "Starter", 30, 6.99, 0, 80}
    };

    saveToDatabase(menuItems);

    return 0;
}