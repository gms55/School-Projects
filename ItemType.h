/*
File Name: ItemType.h
Author: Glen Stevenson
Date: 6/28/2017
Homework Assignment Number 2
CS 3358.501 Summer 2017
Instructor: Dr. Rodion Podorozhny

Defines the ItemType class.
*/

#include<fstream>
#include<iostream>
#include<cassert>
using namespace std;

enum RelationType {LESS, GREATER, EQUAL};

class ItemType {
   public:
      ItemType();
      RelationType ComparedTo(ItemType item) const;
      void Print(ofstream& fout) const;
      void Initialize(int number);
   private:
      int value;
}; 
