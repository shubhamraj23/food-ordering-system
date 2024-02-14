# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Set the project name
project(food-ordering-system)

set(CMAKE_CXX_STANDARD 17)

# Add the executable and list your source files
add_executable(
  app
  system.cpp
  Item.cpp
  Order.cpp
  OrderItem.cpp
  OrderManager.cpp
  Restaurant.cpp
  RestaurantManager.cpp
  Strategy.cpp
)