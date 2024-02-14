#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
  private:
    std::string name;
    int price;
  
  public:
    Item();
    Item(std::string name, int price);
    std::string getName();
    int getPrice();
    void setPrice(int newPrice);
};

#endif