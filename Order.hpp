#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include "OrderItem.hpp"

class OrderItem;

class Order {
  private:
    int id;
    std::string customerName;
    std::vector<OrderItem*> items;
    std::string restaurant;
    int cost;
    int duration;
    bool completed;

  public:
    static int orderCount;
    Order();
    Order(std::string customerName, std::string restaurant, std::vector<OrderItem*> items, int cost, int duration);
    int getId();
    std::string getCustomerName();
    std::vector<OrderItem*> getItems();
    std::string getRestaurant();
    int getCost();
    int getDuration();
    bool getCompleted();
    void setCompleted(bool completed);
};

#endif