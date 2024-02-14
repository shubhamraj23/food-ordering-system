# Food Ordering System

## Introduction
This is a C++ project to simulate a food ordering system.

## Repository Structure
The repository contains the following sets of files. All the files are present in the root folder, and there are no sub-folders.
- *CMakeLists.txt:* This is the CMake configuration file used to build the application and create the executable file.
- *system.cpp:* This is the file containing the source code of the main function. This file runs the food ordering system and adds a few restaurants and places a few orders.
- *Various header (.h) and implementation (.cpp) files:* The .h files contain the templates of the different classes, and the .cpp files contain the implementation of those templates. The contents of the different classes are described below:
  - **Item:** It contains information and methods related to a menu item.
  - **Order:** It contains information and methods related to an order placed by a customer.
  - **OrderItem:** It contains information and methods related to a menu item being requested by a customer.
  - **OrderManager:** A singleton class that manages all the orders across the restaurants.
  - **Restaurant:** It contains information and methods related to a restaurant.
  - **RestaurantManager:** A singleton class that manages all the restaurants availability.
  - **Strategy:** A singleton class that implements the stategy being used to select a restaurant for an order.