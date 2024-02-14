#include "Restaurant.hpp"

Restaurant::Restaurant() {}

Restaurant::Restaurant(std::string name, std::unordered_map<std::string, Item*> menu, int capacity) {
	this->name = name;
	this->menu = menu;
	this->capacity = capacity;
}

std::string Restaurant::getName() {
	return this->name;
}

int Restaurant::getCapacity() {
	return this->capacity;
}

void Restaurant::setCapacity(int newCapacity) {
	this->capacity = newCapacity;
}

int Restaurant::getCapacityInUse() {
  return this->capacityInUse;
}

void Restaurant::incrementCapacityInUse() {
  this->capacityInUse++;
}

void Restaurant::decrementCapacityInUse() {
  this->capacityInUse--;
}

std::unordered_map<std::string, Item*> Restaurant::getMenu() {
	return this->menu;
}

void Restaurant::updateMenu(std::unordered_map<std::string, Item*> newMenu) {
	this->menu = newMenu;
}

std::vector<Order*> Restaurant::getOrders() {
	return this->orders;
}

void Restaurant::addOrder(Order* order) {
	this->orders.push_back(order);
}

bool Restaurant::getAvailability() {
	return this->capacityInUse < this->capacity;
}