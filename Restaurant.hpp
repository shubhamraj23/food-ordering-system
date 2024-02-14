#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <unordered_map>
#include <vector>
#include "Item.hpp"

class Item;

class Restaurant {
  private:
    std::string name;
    std::unordered_map<std::string, Item*> menu;
    int capacity;
    int capacityInUse;

  public:
    Restaurant();
    Restaurant(std::string name, std::unordered_map<std::string, Item*> menu, int capacity);
    std::string getName();
    int getCapacity();
    void setCapacity(int newCapacity);
    int getCapacityInUse();
    void incrementCapacityInUse();
    void decrementCapacityInUse();
    std::unordered_map<std::string, Item*> getMenu();
    void updateMenu(std::unordered_map<std::string, Item*> newMenu);
    bool getAvailability();
};

#endif