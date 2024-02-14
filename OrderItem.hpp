#ifndef ORDERITEM_H
#define ORDERITEM_H

#include <string>

class OrderItem {
  private:
    std::string item;
    int quantity;

  public:
    OrderItem();
    OrderItem(std::string item, int quantity);
    std::string getItem();
    int getQuantity();
};

#endif