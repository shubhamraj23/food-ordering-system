#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include <string>
#include <utility>
#include <vector>
#include "Order.hpp" 
#include "OrderItem.hpp"
#include "RestaurantManager.hpp"
#include "Strategy.hpp"

class Order;
class OrderItem;
class RestaurantManager;
class Strategy;

class OrderManager {
  private:
    std::vector<Order*> orders;
    RestaurantManager* restaurantManager;
    Strategy* strategy;

  public:
    OrderManager();
    OrderManager(RestaurantManager* restaurantManager, Strategy* strategy);
    static std::vector<OrderItem*> generateOrderItems(std::vector< std::pair<std::string, int> > items);
    void placeOrder(std::string customerName, std::vector< std::pair<std::string, int> > items);
    void createOrder(std::string customerName, Restaurant* restaurant, std::vector<OrderItem*> orderItems);
    int calculateTime();
    void processOrder(Order* order);
    void printAllOrders();
};

#endif