#include "Order.hpp"

// Static variable representing the count of orders so far.
int Order::orderCount = 0;

// Default Constructor
Order::Order() {}

// Parameterized Constructor
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

// Function to get the order id.
int Order::getId() {
  return this->id;
}

// Function to get the customer name.
std::string Order::getCustomerName() {
  return this->customerName;
}

// Function to get the list and quantity of items in the order.
std::vector<OrderItem*> Order::getItems() {
  return this->items;
}

// Function to get the name of the restaurant fulfilling the order.
std::string Order::getRestaurant() {
  return this->restaurant;
}

// Function to get the total cost of the order.
int Order::getCost() {
  return this->cost;
}

// Function to get the time taken to prepare the order.
int Order::getDuration() {
  return this->duration;
}

// Function to get the completion status of the order.
bool Order::getCompleted() {
  return this->completed;
}

// Function to update the completion status of the order.
void Order::setCompleted(bool completed) {
  this->completed = completed;
}