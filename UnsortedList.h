/*
File Name: UnsortedList.h
Author: Glen Stevenson
Date: 6/16/2017
Homework Assignment Number 1
CS 3358.501 Summer 2017
Instructor: Dr. Rodion Podorozhny

Creates UnsortedType class and defines all of its functions.
*/

#include"ItemType.h"
#include<cassert>

template<class ItemType>
struct NodeType {
   ItemType info;
   NodeType* next;
};

template<class ItemType>
class UnsortedType {
   public:
      UnsortedType();
      void MakeEmpty();
      bool IsFull() const;
      int GetLength() const;
      ItemType RetrieveItem(ItemType item, bool& found);
      void InsertItem(ItemType item);
      void DeleteItem(ItemType item);
      void ResetList();
      ItemType GetNextItem();
      void GetCurrentItem();
      void PrintList(UnsortedType list,ofstream& out);
      void SplitLists(UnsortedType list, ItemType item,
           UnsortedType& list1, UnsortedType& list2);
   private:
      NodeType<ItemType>* listData;
      int length;
      NodeType<ItemType>* currentPos;
};

/*******************************************************************************
Class constructor
*///****************************************************************************

template<class ItemType>
UnsortedType<ItemType>::UnsortedType() {
   length = 0;
   listData = NULL;
}

/*******************************************************************************
Preconditon: n/a
Postcondition: list is empty; all items have been deallocated.
*///****************************************************************************

template<class ItemType>
void UnsortedType<ItemType>::MakeEmpty() {
   NodeType<ItemType>* tempPtr;
   
   while(listData != NULL) {
      tempPtr = listData;
      listData = listData->next;
      delete tempPtr;
   }
   length = 0;
}

/*******************************************************************************
Returns true if there is no room for another ItemType on the free store;
   false otherwise.
*///****************************************************************************

template<class ItemType>
bool UnsortedType<ItemType>::IsFull() const {
   NodeType<ItemType>* location;
   
   try {
      location = new NodeType<ItemType>;
      delete location;
      return false;
   }
   catch(bad_alloc exception) {
      return true;
   }
}

/*******************************************************************************
Preconditon: n/a
Postcondition: number of items in the list is returned.
*///****************************************************************************

template<class ItemType>
int UnsortedType<ItemType>::GetLength() const {
   return length;
}

/*******************************************************************************
Preconditon: key member(s) of the item is initialized.
Postcondition: if found, item's key matches an element's key in the list and a 
               copy of that element has been returned; otherwise, item is 
               returned.
*///****************************************************************************

template<class ItemType>
ItemType UnsortedType<ItemType>::RetrieveItem(ItemType item, bool& found) {
   bool moreToSearch;
   NodeType<ItemType>* location;
   
   location = listData;
   found = false;
   moreToSearch = (location != NULL);
   
   while(moreToSearch && !found) {
      switch(item.ComparedTo(location->info)) {
         case LESS    : location = location->next;
                        moreToSearch = (location != NULL);
                        break;
         case GREATER : location = location->next;
                        moreToSearch = (location != NULL);
                        break;
         case EQUAL   : found = true;
                        item = location->info;
                        break;
      }
   }
   return item;
}

/*******************************************************************************
item is in the list; length has been incremented.
*///****************************************************************************

template<class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item) {
   assert(!IsFull());
   
   NodeType<ItemType>* location;
   
   location = new NodeType<ItemType>;
   location->info = item;
   location->next = listData;
   
   listData = location;
   
   length++;
}

/*******************************************************************************
Preconditon: item's key has been initialized. 
             an element in the list has a key that matches item's.
Postcondition: No element in the list has a key that matches item's.
*///****************************************************************************

template<class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item) {
   NodeType<ItemType>* location = listData;
   NodeType<ItemType>* tempLocation;
   
   if(item.ComparedTo(listData->info) == EQUAL) {
      tempLocation = location;
      listData = listData->next;
   }
   else {
      while(item.ComparedTo((location->next)->info) != EQUAL)
         location = location->next;
      
      tempLocation = location->next;
      location->next = (location->next)->next;
   }
   delete tempLocation;
   length--;
}

/*******************************************************************************
Preconditon: n/a
Postcondition: current position has been initialized.
*///****************************************************************************

template<class ItemType>
void UnsortedType<ItemType>::ResetList() {
   currentPos = NULL;
}

/*******************************************************************************
Preconditon: no transformer has been executed since last call.
Postcondition: A copy of the next item in the list is returned. 
               When the end of the list is reached, currentPos is reset.
*///****************************************************************************

template<class ItemType>
ItemType UnsortedType<ItemType>::GetNextItem() {
   if(currentPos == NULL)
      currentPos = listData;
   else
      currentPos = currentPos->next;
   return currentPos->info;
}

/*******************************************************************************
Preconditon: list has been initialized. 
             out is open and ready for writing.
Postcondition: each component in the list has been written to out.
               out is still open.
*///****************************************************************************

template<class ItemType>
void UnsortedType<ItemType>::PrintList(UnsortedType list, ofstream& out) {
   int length;
   ItemType item;
 
   list.ResetList();
   length = list.GetLength();
 
   for (int i = 0; i < length; i++) {
      item = list.GetNextItem();
      item.Print(out);
   }
   out << endl;
}

/*******************************************************************************
Preconditon: the list is not empty.
Postcondition: the new split lists are populated.
*///****************************************************************************

template<class ItemType>
void UnsortedType<ItemType>::SplitLists(UnsortedType list, ItemType item,
     UnsortedType& list1, UnsortedType& list2) {
   ItemType listItem;
   
   if((list.GetLength()) == 0)
      cout << "The list cannot be split because it is empty." << endl;
   
   else {
      list1.MakeEmpty();
      list2.MakeEmpty();
   
      for(int i = 0; i < length; i++) {
         listItem = list.GetNextItem();
         if((listItem.ComparedTo(item)) == GREATER)
            list2.InsertItem(listItem);
         else
            list1.InsertItem(listItem);
      }
   }
}
   
