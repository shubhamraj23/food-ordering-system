#include "Restaurant.hpp"

// Default Constructor
Restaurant::Restaurant() {}

// Parameterized Constructor
Restaurant::Restaurant(std::string name, std::unordered_map<std::string, Item*> menu, int capacity) {
	this->name = name;
	this->menu = menu;
	this->capacity = capacity;
}

// Function to get the name of the restaurant.
std::string Restaurant::getName() {
	return this->name;
}

// Function to get the capacity of the restaurant.
int Restaurant::getCapacity() {
	return this->capacity;
}

// Function to update the capacity of the restaurant.
void Restaurant::setCapacity(int newCapacity) {
	this->capacity = newCapacity;
}

// Function to get the capacity being used by the restaurant.
int Restaurant::getCapacityInUse() {
  return this->capacityInUse;
}

// Function to increment the capacity being used by the restaurant.
void Restaurant::incrementCapacityInUse() {
  this->capacityInUse++;
}

// Function to decrement the capacity being used by the restaurant.
void Restaurant::decrementCapacityInUse() {
  this->capacityInUse--;
}

// Function to get the restaurant's menu.
std::unordered_map<std::string, Item*> Restaurant::getMenu() {
	return this->menu;
}

// Function to update the restaurant's menu.
void Restaurant::updateMenu(std::unordered_map<std::string, Item*> newMenu) {
	this->menu = newMenu;
}

// Function the get if the restaurant is currently available to take any orders or not.
bool Restaurant::getAvailability() {
	return this->capacityInUse < this->capacity;
}