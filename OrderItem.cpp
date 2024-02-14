#include "OrderItem.hpp"

OrderItem::OrderItem() {};

OrderItem::OrderItem(std::string item, int quantity) {
  this->item = item;
  this->quantity = quantity;
}

std::string OrderItem::getItem() {
  return this->item;
}

int OrderItem::getQuantity() {
  return this->quantity;
}