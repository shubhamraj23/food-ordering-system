#ifndef STRATEGY_H
#define STRATEGY_H

#include <vector>
#include "OrderItem.hpp"
#include "Restaurant.hpp"
#include "RestaurantManager.hpp"

class OrderItem;
class Restaurant;
class RestaurantManager;

class Strategy {
  public:
    static std::vector<Restaurant*> filterRestaurants(RestaurantManager* restaurantManager, std::vector<OrderItem*> orderItems);
    static Restaurant* lowestCost(RestaurantManager* restaurantManager, std::vector<OrderItem*> orderItems);
    
};

#endif