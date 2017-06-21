/*
File Name: ItemType.cpp
Author: Glen Stevenson
Date: 6/28/2017
Homework Assignment Number 2
CS 3358.501 Summer 2017
Instructor: Dr. Rodion Podorozhny

Defines the functions from the ItemType class.
*/

#include"ItemType.h"

/*******************************************************************************
Function: initializes an ItemType to a value of 0
Precondition: n/a 
Postcondition: ItemType is initialized
*///****************************************************************************

ItemType::ItemType() {
   value = 0;
}

/*******************************************************************************
Function: compares ItemType values
*///****************************************************************************

RelationType ItemType::ComparedTo(ItemType otherItem) const {
   if(value < otherItem.value)
      return LESS;
   else if(value > otherItem.value)
      return GREATER;
   else
      return EQUAL;
}

/*******************************************************************************
Function: initilizes the value of an ItemType
*///****************************************************************************

void ItemType::Initialize(int number) {
   value = number;
}

/*******************************************************************************
Function: prints to a file
Preconditon: fout has been opened
Postcondition: value has bees sent to fout
*///****************************************************************************

void ItemType::Print(ofstream& fout) const {
   fout << value << " ";
}
