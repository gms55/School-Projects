/*
File Name: ItemType.h
Author: Glen Stevenson
Date: 6/16/2017
Homework Assignment Number 1
CS 3358.501 Summer 2017
Instructor: Dr. Rodion Podorozhny

Defines the ItemType class.
*/

#include<fstream>
#include<iostream>
using namespace std;

enum RelationType {LESS, GREATER, EQUAL};

class ItemType {
   public:
      ItemType();
      RelationType ComparedTo(ItemType item) const;
      void Print(ofstream&) const;
      void Initialize(int number);
   private:
      int value;
}; 
