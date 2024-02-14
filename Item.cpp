#include "Item.hpp"

// Default Constructor
Item::Item() {}

// Parameterized Constructor
Item::Item(std::string name, int price) {
  this->name = name;
  this->price = price;
}

// Function to get the name of the item.
std::string Item::getName() {
  return this->name;
}

// Function to get the price of the item.
int Item::getPrice() {
  return this->price;
}

// Function to set the price of the item.
void Item::setPrice(int newPrice) {
  this->price = newPrice;
}