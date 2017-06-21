/*
File Name: TestCasesDriver.cpp
Author: Glen Stevenson
Date: 6/28/2017
Homework Assignment Number 2
CS 3358.501 Summer 2017
Instructor: Dr. Rodion Podorozhny

Runs the test cases for hw2.
*/

#include"TreeNode.h"

int main() {
   ItemType item0, item1, item2, item3, item4, item5, item6, item7, item8,
            item9, item10, item11, item12, item13;
   TreeType tree;
   bool found;
   ofstream fout;

   fout.open("Output.txt");

   if(fout.is_open()) {
      fout << "Executing Test 1." << endl
           << "Inserting nodes with the following keys: 3, 201, 60, 30, 45 "
           << "(in this order)." << endl;
   
      item0.Initialize(3);
      item1.Initialize(201);
      item2.Initialize(60);
      item3.Initialize(30);
      item4.Initialize(45);
   
      tree.InsertItem(item0);
      tree.InsertItem(item1);
      tree.InsertItem(item2);
      tree.InsertItem(item3);
      tree.InsertItem(item4);
   
      fout << "Running the tree walk and printing the nodes in increasing "
           << "order: ";
      
      tree.Print(fout);
      
      tree.RetrieveItem(item1, found);
      
      fout << "\nRetrieving the node with key 201.\nThe node was found: "
           << boolalpha << found << "." << endl
           << "Deleting nodes with keys 3 and 60." << endl;
      
      tree.DeleteItem(item0);
      tree.DeleteItem(item2);
      
      fout << "Running the tree walk and printing the nodes in increasing "
           << "order: ";
      tree.Print(fout);
      
      fout << "\nThis verifies that the nodes with keys 3 and 60 were deleted."
           << endl;
      
      tree.MakeEmpty();
      
      fout << "\n\nExecuting Test 2." << endl
           << "Insert nodes with the following keys: -10, -150, 4, 300, 45, "
           << "-50, 200 (in this order)." << endl;
      
      item5.Initialize(-10);
      item6.Initialize(-150);
      item7.Initialize(4);
      item8.Initialize(300);
      item9.Initialize(45);
      item10.Initialize(-50);
      item11.Initialize(200);
      
      tree.InsertItem(item5);
      tree.InsertItem(item6);
      tree.InsertItem(item7);
      tree.InsertItem(item8);
      tree.InsertItem(item9);
      tree.InsertItem(item10);
      tree.InsertItem(item11);
      
      fout << "Running the tree walk and printing the nodes in increasing "
           << "order: ";
      
      tree.Print(fout);
      
      tree.RetrieveItem(item6, found);
      
      fout << "\nRetrieving the node with key -150.\nThe node was found: "
           << boolalpha << found << "." << endl
           << "Deleting nodes with keys -10 and 45." << endl;
      
      tree.DeleteItem(item5);
      tree.DeleteItem(item9);
      
      fout << "Running the tree walk and printing the nodes in increasing "
           << "order: ";
      tree.Print(fout);
      
      fout << "\nThis verifies that the nodes with keys -10 and 45 were "
           << "deleted." << endl;
      
      fout << "\n\nThis concludes the testing." << endl;
   }
}
