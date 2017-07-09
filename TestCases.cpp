/*
File Name: TestCases.cpp
Author: Glen Stevenson
Date: 6/16/2017
Homework Assignment Number 1
CS 3358.501 Summer 2017
Instructor: Dr. Rodion Podorozhny

Tests the UnsortedList functions: SplitLists, MakeEmpty, InsertItem,
DeleteItem, RetrieveItem, ResetList, GetNextItem and writes results to an 
output file named Output.txt
*/

#include"UnsortedList.h"

int main() {

   ItemType test1, test2, test3, test4, splitValue;
   UnsortedType<ItemType> test, l1, l2;
   bool found;
   ofstream out;
   out.open("Output.txt");

   if(out.is_open()) {
/*******************************************************************************
The code below tests GetLength to determine the initial size of the list after 
only the default constructor is utilized. It then prints the size of the list
to the output file.
*///****************************************************************************
      test.GetLength();
      out << "The initial size of the list is: " << test.GetLength() << endl;

/*******************************************************************************
The code below tests the ItemType function, Initialize, and it tests the
UnsortedList function, InsertItem.
*///****************************************************************************
      test1.Initialize(5);
      test.InsertItem(test1);

/*******************************************************************************
The code below displays the length of the list after the using the PutItem 
function once.
*///****************************************************************************
      out << "After adding one element, the size of the list is: "
          << test.GetLength()<< endl;

/*******************************************************************************
The code below dispays the entire list.
*///****************************************************************************
      out << "The list consists of the element(s): ";
      test.PrintList(test, out);

/*******************************************************************************
The code below deletes the single item currently in the list. 
*///****************************************************************************
      test.DeleteItem(test1);

/*******************************************************************************
The code below displays the length of the list after the using the DeleteItem
function once.
*///****************************************************************************
      out << "After deleting one item the size of the list is: "
          << test.GetLength() << endl;

/*******************************************************************************
The code below initializes four ItemType values and then uses InsertItem to 
insert them into a list. 
*///****************************************************************************
      test1.Initialize(3);
      test2.Initialize(5);
      test3.Initialize(9);
      test4.Initialize(1);

      test.InsertItem(test1);
      test.InsertItem(test2);
      test.InsertItem(test3);
      test.InsertItem(test4);

/*******************************************************************************
The code below prints the new list. 
*///****************************************************************************
      out << "The new list consists of the element(s): ";
      test.PrintList(test, out);

/*******************************************************************************
The code below resets the list the the beginning using ResetList and then 
retrieves and item from the list utilizing RetrieveItem. It then prints true or 
false based on if the item was in the list.
*///****************************************************************************
      test.ResetList();
      test.RetrieveItem(test1, found);
      out << "The element searched for, ";
      test1.Print(out);
      out << ", was found (true or false): " << boolalpha << found << endl;

/*******************************************************************************
The code below outputs the item on the list after the one previously searched
for, using the function, GetNextItem. 
*///****************************************************************************
      out << "The next element in the list is: ";
      (test.GetNextItem()).Print(out);
      out << endl;

/*******************************************************************************
The code below resets the list the the beginning using ResetList and then 
initializes the value that will be used to determine how to split the list later
in SplitLists.
*///****************************************************************************
      test.ResetList();

      splitValue.Initialize(6);
      out << "The value to compare against the list values is: ";
      splitValue.Print(out);
      out << endl;

/*******************************************************************************
The code below uses SplitLists to split the list into two different lists based
upon if the item entrys are greater than a specified value, or less than or 
equal to that value. Then the code prints both of the new lists. 
*///****************************************************************************
      test.ResetList();
      test.SplitLists(test, splitValue, l1, l2);

      out << "The original list was split into two new lists, List 1 and List 2."
          << endl << "List 1 consists of the elements from the original list that"
          << " are less than or equal to ";
      splitValue.Print(out);
      out << endl
          << "List 2 consists of the elements from the original list that are "
          << "greater than ";
      splitValue.Print(out);
      out << endl;
   
      out << "List 1: ";
      l1.PrintList(l1, out);
      out << "List 2: ";
      l2.PrintList(l2, out);

/*******************************************************************************
The code below uses MakeEmpty to empty out the main list. It then prints the
size of the emptied list.
*///****************************************************************************
      test.MakeEmpty();
      out << "The list was emptied so its length is now: "
          << test.GetLength() << endl;

/*******************************************************************************
The code below empties the new lists from SplitLists and checks to make sure all
lists were emptied properly.
*///****************************************************************************
      l1.MakeEmpty();
      l2.MakeEmpty();
      if((test.GetLength() != 0) || (l1.GetLength() != 0)
         || (l2.GetLength() != 0)) {
         out << "List is: ";
         test.PrintList(l1, out);
         out << "List 1: ";
         l1.PrintList(l1, out);
         out << "List 2: ";
         l2.PrintList(l2, out);
         out << "Which ever list printed above was not emptied correctly"
             << " using MakeEmpty." << endl;
      }
      out.close();
   }
   else
      cout << "Unable to open Output.txt" << endl;
}
