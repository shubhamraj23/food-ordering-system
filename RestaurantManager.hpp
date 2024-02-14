#ifndef RESTAURANTMANAGER_H
#define RESTAURANTMANAGER_H

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include "Restaurant.hpp"

class Restaurant;

class RestaurantManager {
  public:
    std::unordered_map<std::string, Restaurant*> restaurants;

    static std::unordered_map<std::string, Item*> generateMenu(std::vector< std::pair<std::string, int> > items);
    void addRestaurant(std::string name, std::vector< std::pair<std::string, int> > items, int capacity);
    void updateMenu(std::string name, std::vector< std::pair<std::string, int> > items);
    void printRestaurantDetails();
    std::vector<Restaurant*> findAvailableRestaurants();
    std::vector<Restaurant*> findServableRestaurants(std::vector<OrderItem*> orderItems);
    int calculateCost(std::string restaurantName, std::vector<OrderItem*> orderItems);
};

#endif