/*
File Name: TreeNode.h
Author: Glen Stevenson
Date: 6/28/2017
Homework Assignment Number 2
CS 3358.501 Summer 2017
Instructor: Dr. Rodion Podorozhny

Defines the TreeNode class.
*/

#include"Queue.h"

struct TreeNode {
   ItemType info;
   TreeNode* left;
   TreeNode* right;
};

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

class TreeType {
   public:
      TreeType();
      ~TreeType();
      void Destroy(TreeNode*& tree);
      void CopyTree(TreeNode*& copy, const TreeNode* originalTree);
      TreeType(const TreeType& originalTree);
      void operator=(TreeType& originalTree);
      void MakeEmpty();
      bool IsEmpty() const;
      bool IsFull() const;
      int GetLength() const;
      int CountNodes(TreeNode* tree) const;
      void Retrieve(TreeNode* tree, ItemType& item, bool& found) const ;
      ItemType RetrieveItem(ItemType item, bool& found) const;
      void Insert(TreeNode*& tree, ItemType item); 
      void InsertItem(ItemType item);
      void DeleteNode(TreeNode*& tree);
      void GetPredecessor(TreeNode* tree, ItemType& data);
      void Delete(TreeNode*& tree, ItemType item);
      void DeleteItem(ItemType item);
      void ResetTree(OrderType order);
      ItemType GetNextItem(OrderType order, bool& finished);
      void PrintTree(TreeNode* tree, ofstream& fout);
      void Print(ofstream& fout);
      void PreOrder(TreeNode* tree, QueType& preQue);
      void InOrder(TreeNode* tree, QueType& inQue);
      void PostOrder(TreeNode* tree, QueType& postQue);
   private:
      TreeNode* root;
      QueType preQue;
      QueType inQue;
      QueType postQue;
};
