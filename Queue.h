/*
File Name: Queue.h
Author: Glen Stevenson
Date: 6/28/2017
Homework Assignment Number 2
CS 3358.501 Summer 2017
Instructor: Dr. Rodion Podorozhny

Defines the Queue class.
*/

#include"ItemType.h"

struct NodeType {
   ItemType info;
   NodeType* next;
};

class FullQueue {
};

class QueType {
   public:
      QueType();
      ~QueType();
      void MakeEmpty();
      void Enqueue(ItemType item);
      void Dequeue(ItemType& item);
      bool IsEmpty() const;
      bool IsFull() const;
   private:
      NodeType* front;
      NodeType* rear;
};

