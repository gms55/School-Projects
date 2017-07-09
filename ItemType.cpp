/*
File Name: ItemType.cpp
Author: Glen Stevenson
Date: 6/16/2017
Homework Assignment Number 1
CS 3358.501 Summer 2017
Instructor: Dr. Rodion Podorozhny

Defines the functions from the ItemType class.
*/

#include"ItemType.h"

ItemType::ItemType() {
   value = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const {
   if(value < otherItem.value)
      return LESS;
   else if(value > otherItem.value)
      return GREATER;
   else
      return EQUAL;
}

void ItemType::Initialize(int number) {
   value = number;
}

void ItemType::Print(ofstream& out) const {
   out << value << " ";
}
