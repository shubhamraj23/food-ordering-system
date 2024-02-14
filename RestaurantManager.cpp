#include <iostream>
#include "RestaurantManager.hpp"

// Function to add a restaurant to the list of restaurants.
void RestaurantManager::addRestaurant(std::string name, std::vector< std::pair<std::string, int> > items, int capacity) {
  std::unordered_map<std::string, Item*> menu = RestaurantManager::generateMenu(items);
  Restaurant* restaurant = new Restaurant(name, menu, capacity);
  this->restaurants[name] = restaurant;
}

// Function to update the menu of a restaurant.
void RestaurantManager::updateMenu(std::string name, std::vector< std::pair<std::string, int> > items) {
  Restaurant* restaurant = this->restaurants[name];
  std::unordered_map<std::string, Item*> newMenu = RestaurantManager::generateMenu(items);
  std::unordered_map<std::string, Item*> menu = restaurant->getMenu();
  for (auto i = newMenu.begin(); i != newMenu.end(); i++) {
    if (menu.find(i->first) != menu.end()) delete menu[i->first];
    menu[i->first] = i->second;
  }
  restaurant->updateMenu(menu);
}

// Function to print the details of all the restaurants.
void RestaurantManager::printRestaurantDetails() {
  for (auto i = this->restaurants.begin(); i != this->restaurants.end(); i++) {
    Restaurant* restaurant = i->second;
    std::cout << "Restaurant Name: " << restaurant->getName() << std::endl;
    std::unordered_map<std::string, Item*> menu = restaurant->getMenu();
    std::cout << "Restaurant Menu:" << std::endl;
    for (auto i = menu.begin(); i != menu.end(); i++) {
      Item* item = i->second;
      std::cout << "Item Name: " << item->getName() << ", Price: " << item->getPrice() << std::endl;
    }
    std::cout << "Restaurant Total Capacity: " << restaurant->getCapacity() << std::endl;
    std::cout << "Restaurant Utilised Capacity: " << restaurant->getCapacityInUse() << std::endl;
    std::cout << std::endl;
  }
}

// Static function to generate a restaurant menu from the list of items specified.
std::unordered_map<std::string, Item*> RestaurantManager::generateMenu(std::vector< std::pair<std::string, int> > items) {
  std::unordered_map<std::string, Item*> menu;
  for (int i = 0; i < items.size(); i++) {
    std::string name = items[i].first;
    int price = items[i].second;
    Item* item = new Item(name, price);
    menu[name] = item;
  }
  return menu;
}

// Function to find the list of restaurants available to pick an order from all the restaurants.
std::vector<Restaurant*> RestaurantManager::findAvailableRestaurants() {
  std::vector<Restaurant*> availableRestaurants;
  for (auto i = this->restaurants.begin(); i != this->restaurants.end(); i++) {
    Restaurant* restaurant = i->second;
    if (restaurant->getAvailability()) availableRestaurants.push_back(restaurant);
  }
  return availableRestaurants;
}

// Function to find the list of restaurants that can serve the given items.
std::vector<Restaurant*> RestaurantManager::findServableRestaurants(std::vector<OrderItem*> orderItems) {
  std::vector<Restaurant*> availableRestaurants = this->findAvailableRestaurants();
  std::vector<Restaurant*> servableRestaurants;

  for (Restaurant* restaurant : availableRestaurants) {
    bool servable = true;
    for (OrderItem* orderItem : orderItems) {
      if (restaurant->getMenu().find(orderItem->getItem()) == restaurant->getMenu().end()) {
        servable = false;
        break;
      }
    }
    if (servable) servableRestaurants.push_back(restaurant);
  }

  return servableRestaurants;
}

// Function to calculate the total cost of the order.
int RestaurantManager::calculateCost(std::string restaurantName, std::vector<OrderItem*> orderItems) {
  Restaurant* restaurant = this->restaurants[restaurantName];
  int cost = 0;
  for (OrderItem* orderItem : orderItems) {
    cost += orderItem->getQuantity() * restaurant->getMenu()[orderItem->getItem()]->getPrice();
  }
  return cost;
}