#include "Order.hpp"

int Order::orderCount = 0;

Order::Order() {}

Order::Order(std::string customerName, std::string restaurant, std::vector<OrderItem*> items, int cost, int duration) {
  this->customerName = customerName;
  this->restaurant = restaurant;
  this->items = items;
  this->cost = cost;
  this->duration = duration;
  this->completed = false;
  this->id = Order::orderCount;
  Order::orderCount++;
}

int Order::getId() {
  return this->id;
}

std::string Order::getCustomerName() {
  return this->customerName;
}

std::vector<OrderItem*> Order::getItems() {
  return this->items;
}

std::string Order::getRestaurant() {
  return this->restaurant;
}

int Order::getCost() {
  return this->cost;
}

int Order::getDuration() {
  return this->duration;
}

bool Order::getCompleted() {
  return this->completed;
}

void Order::setCompleted(bool completed) {
  this->completed = completed;
}