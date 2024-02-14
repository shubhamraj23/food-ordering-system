#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include "OrderManager.hpp"
#include "RestaurantManager.hpp"
#include "Strategy.hpp"

int main() {
  RestaurantManager* restaurantManager = new RestaurantManager();
  Strategy* strategy = new Strategy();
  OrderManager* orderManager = new OrderManager(restaurantManager, strategy);

  std::string restaurant1 = "resta1";
  std::vector<std::pair <std::string, int> > menu1;
  menu1.push_back(std::make_pair("king_burger", 10));
  menu1.push_back(std::make_pair("samosa_pizza", 20));
  menu1.push_back(std::make_pair("alu_pasta", 19));
  int capacity1 = 1;
  restaurantManager->addRestaurant(restaurant1, menu1, capacity1);

  std::string restaurant2 = "resta2";
  std::vector<std::pair <std::string, int> > menu2;
  menu2.push_back(std::make_pair("bendi_macaroni", 12));
  menu2.push_back(std::make_pair("samosa_pizza", 25));
  menu2.push_back(std::make_pair("alu_pasta", 17));
  int capacity2 = 2;
  restaurantManager->addRestaurant(restaurant2, menu2, capacity2);

  std::string updateRestaurant = "resta1";
  std::vector<std::pair <std::string, int> > updatedMenu;
  updatedMenu.push_back(std::make_pair("bendi_macaroni", 8));
  updatedMenu.push_back(std::make_pair("king_burger", 15));
  restaurantManager->updateMenu(updateRestaurant, updatedMenu);

  restaurantManager->printRestaurantDetails();

  std::string customer1 = "cust";
  std::vector<std::pair <std::string, int> > order1;
  order1.push_back(std::make_pair("bendi_macaroni", 3));
  order1.push_back(std::make_pair("samosa_pizza", 2));
  orderManager->placeOrder(customer1, order1);

  restaurantManager->printRestaurantDetails();

  std::string customer2 = "cust";
  std::vector<std::pair <std::string, int> > order2;
  order2.push_back(std::make_pair("bendi_macaroni", 3));
  order2.push_back(std::make_pair("samosa_pizza", 2));
  orderManager->placeOrder(customer2, order2);

  std::string customer3 = "cust";
  std::vector<std::pair <std::string, int> > order3;
  order3.push_back(std::make_pair("bendi_macaroni", 3));
  order3.push_back(std::make_pair("samosa_pizza", 2));
  orderManager->placeOrder(customer3, order3);
  orderManager->placeOrder(customer3, order3);

  orderManager->printAllOrders();

  restaurantManager->printRestaurantDetails();

  std::this_thread::sleep_for(std::chrono::seconds(5));
}