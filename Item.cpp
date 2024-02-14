#include "Item.hpp"

Item::Item() {}

Item::Item(std::string name, int price) {
  this->name = name;
  this->price = price;
}

std::string Item::getName() {
  return this->name;
}
    
int Item::getPrice() {
  return this->price;
}

void Item::setPrice(int newPrice) {
  this->price = newPrice;
}