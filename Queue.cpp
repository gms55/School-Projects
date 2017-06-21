/*
File Name: Queue.cpp
Author: Glen Stevenson
Date: 6/28/2017
Homework Assignment Number 2
CS 3358.501 Summer 2017
Instructor: Dr. Rodion Podorozhny

Defines the functions of the Queue class.
*/

#include "Queue.h"

/*******************************************************************************
Function: class constructor
Preconditon: n/a
Postcondition: front and rear are set to NULL
*///****************************************************************************

QueType::QueType() {
   front = NULL;
   rear = NULL;
}

/*******************************************************************************
Function: class destructor
*///****************************************************************************

QueType::~QueType() {
   MakeEmpty();
}

/*******************************************************************************
Function: initializes the queue to an empty state
Preconditon: n/a
Postcondition: queue is empty; all elements have been deallocated
*///****************************************************************************

void QueType::MakeEmpty() {
   NodeType* tempPtr;
   
   while(front) {
      tempPtr = front;
      front = front->next;
      delete tempPtr;
   }
   rear = NULL;
}

/*******************************************************************************
Function: adds a new item to the rear of the queue
Preconditon: queue has been initialized
Postcondition: if the queue is full, full queue exception is thrown, else the 
   new item appears at the rear of the queue
*///****************************************************************************

void QueType::Enqueue(ItemType item) {
   assert(!IsFull());
   
   NodeType* newNode;
   
   newNode = new NodeType;
   newNode->info = item;
   newNode->next = NULL;
   if(rear == NULL)
      front = newNode;
   else
      rear->next = newNode;
   rear = newNode;
}

/*******************************************************************************
Function: removes front item from the queue and returns it in item
Preconditon: queue has been initialized
Postcondition: if the queue is emptu, empty queue exception is thrown and item 
   is undefinied, else front element has been removed from queue and item is a 
   copy of removed element
*///****************************************************************************

void QueType::Dequeue(ItemType& item) {
   assert(!IsEmpty());
   
   NodeType* tempPtr;
   
   tempPtr = front;
   item = front->info;
   front = front->next;
   if(front == NULL)
      rear = NULL;
   delete tempPtr;
}

/*******************************************************************************
Function: determines whether the queue is empty
Preconditon: queue has been initialized
Postcondition: function value = (queue is empty)
*///****************************************************************************

bool QueType::IsEmpty() const {
   return (front == NULL);
}

/*******************************************************************************
Function: determines whether the queue is full
Preconditon: queue has been initialized
Postcondition: returns true if there is no room for another NodeType on the 
   free store and false otherwise
*///****************************************************************************

bool QueType::IsFull() const {
   NodeType* location;
   try {
      location = new NodeType;
      delete location;
      return false;
   }
   catch (bad_alloc exception){
      return true;
   }
}
