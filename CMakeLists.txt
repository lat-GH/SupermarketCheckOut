cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SupermarketCheckOut)

# Add the executable
add_executable(SupermarketCheckOut main.cpp Person.cpp Item.cpp CheckOutPoint.cpp Till.cpp)
