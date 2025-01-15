cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SupermarketCheckOut)

# Add the executable
add_executable(SupermarketCheckOut main.cpp Item.cpp CheckOutPoint.cpp Database.cpp Bill.cpp)
