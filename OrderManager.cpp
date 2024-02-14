#include <ctime>
#include <iostream>
#include <random>
#include <thread>
#include "OrderManager.hpp"

OrderManager::OrderManager() {}

OrderManager::OrderManager(RestaurantManager* restaurantManager, Strategy* strategy) {
  this->restaurantManager = restaurantManager;
  this->strategy = strategy;
}

void OrderManager::placeOrder(std::string customerName, std::vector< std::pair<std::string, int> > items) {
  std::vector<OrderItem*> orderItems = OrderManager::generateOrderItems(items);
  Restaurant* restaurant = Strategy::lowestCost(this->restaurantManager, orderItems);
  if (restaurant == NULL) {
    std::cout << "Order cannot be placed." << std::endl;
    return;
  }
  this->createOrder(customerName, restaurant, orderItems);
}

void OrderManager::createOrder(std::string customerName, Restaurant* restaurant, std::vector<OrderItem*> orderItems) {
  int cost = this->restaurantManager->calculateCost(restaurant->getName(), orderItems);
  int duration = this->calculateTime();
  Order* order = new Order(customerName, restaurant->getName(), orderItems, cost, duration);
  this->orders.push_back(order);
  restaurant->addOrder(order);
  restaurant->incrementCapacityInUse();
  std::cout << "Order with order id: " << order->getId() << " placed with restaurant " << restaurant->getName() << std::endl;
  
  std::thread([this, order]() {
    this->processOrder(order);
  }).detach();
}

int OrderManager::calculateTime() {
  std::mt19937 rng(std::time(0));
  std::uniform_int_distribution<int> distribution(10, 30);
  int randomNumber = distribution(rng);
  return randomNumber;
}

void OrderManager::processOrder(Order* order) {
  int duration = 100*order->getDuration();
  std::this_thread::sleep_for(std::chrono::milliseconds(duration));
  Restaurant* restaurant = this->restaurantManager->restaurants[order->getRestaurant()];
  order->setCompleted(true);
  restaurant->decrementCapacityInUse();
  std::string processed = "Order with order ID: " + std::to_string(order->getId()) + " has been fulfilled.\n";
  std::cout << processed;
}

std::vector<OrderItem*> OrderManager::generateOrderItems(std::vector< std::pair<std::string, int> > items) {
  std::vector<OrderItem*> orderItems;
  for (auto item : items) {
    std::string name = item.first;
    int quantity = item.second;
    OrderItem* orderItem = new OrderItem(name, quantity);
    orderItems.push_back(orderItem);
  }
  return orderItems;
}

void OrderManager::printAllOrders() {
  for (Order* order : this->orders) {
    std::cout << "Order ID: " << order->getId() << std::endl;
    std::cout << "Customer Name: " << order->getCustomerName() << std::endl;
    std::cout << "Restaurant Name: " << order->getRestaurant() << std::endl;
    std::cout << "Order Details:" << std::endl;
    for (OrderItem* item : order->getItems()) {
      std::cout << "Item Name: " << item->getItem() << ", Quantity: " << item->getQuantity() << std::endl;
    }
    std::cout << "Total Cost: " << order->getCost() << std::endl;
    std::cout << "Time to Prepare: " << order->getDuration() << std::endl;
    std::string status = (order->getCompleted()) ? "Completed" : "Preparing";
    std::cout << "Order Status: " << status << std::endl;
    std::cout << std::endl;
  }
}