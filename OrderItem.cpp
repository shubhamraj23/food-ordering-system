#include "OrderItem.hpp"

// Default Constructor
OrderItem::OrderItem() {};

// Parameterized Constructor
OrderItem::OrderItem(std::string item, int quantity) {
  this->item = item;
  this->quantity = quantity;
}

// Function to get the name of the item ordered.
std::string OrderItem::getItem() {
  return this->item;
}

// Function to get the quantity of the items order.
int OrderItem::getQuantity() {
  return this->quantity;
}