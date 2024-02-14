#include "Strategy.hpp"

// Static function to filter out the restaurants that cannot serve the current order.
std::vector<Restaurant*> Strategy::filterRestaurants(RestaurantManager* restaurantManager, std::vector<OrderItem*> orderItems) {
  return restaurantManager->findServableRestaurants(orderItems);
}

// Static function to implement a strategy to find out the restaurant that can serve the order with the lowest final cost.
Restaurant* Strategy::lowestCost(RestaurantManager* restaurantManager, std::vector<OrderItem*> orderItems) {
  std::vector<Restaurant*> servableRestaurants = Strategy::filterRestaurants(restaurantManager, orderItems);
  int minCost = INT_MAX;
  Restaurant* servingRestaurant = NULL;
  for (Restaurant* restaurant : servableRestaurants) {
    int cost = restaurantManager->calculateCost(restaurant->getName(), orderItems);
    if (cost < minCost) {
      cost = minCost;
      servingRestaurant = restaurant;
    }
  }
  return servingRestaurant;
}