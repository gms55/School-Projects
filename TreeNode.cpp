/*
File Name: TreeNode.cpp
Author: Glen Stevenson
Date: 6/28/2017
Homework Assignment Number 2
CS 3358.501 Summer 2017
Instructor: Dr. Rodion Podorozhny

Defines the functions of the TreeNode class.
*/

#include"TreeNode.h"

/*******************************************************************************
Function: TreeType constructor
Preconditon: n/a
Postcondition: root is set to NULL
*///****************************************************************************

TreeType::TreeType() {
   root = NULL;
}

/*******************************************************************************
Function: calls recursive function Destroy to destroy the tree
*///****************************************************************************

TreeType::~TreeType() {
   Destroy(root);
}

/*******************************************************************************
Function: deletes of all the nodes in the tree
Preconditon: n/a
Postcondition: the tree is destroyed
*///****************************************************************************

void TreeType::Destroy(TreeNode*& tree) {
   if(tree != NULL) {
      Destroy(tree->left);
      Destroy(tree->right);
      delete tree;
   }
}

/*******************************************************************************
Function: calls the recursive function CopyTree to copy originalTree
Preconditon: original tree exists
Postcondition: copy is the root of a tree that is a duplicate of original tree
*///****************************************************************************

void TreeType::CopyTree(TreeNode*& copy, const TreeNode* originalTree) {
   if(originalTree == NULL)
      copy = NULL;
   else {
      copy = new TreeNode;
      copy->info = originalTree->info;
      CopyTree(copy->left, originalTree->left);
      CopyTree(copy->right, originalTree->right);
   }
}

/*******************************************************************************
Function: calls the recursive function CopyTree to copy originalTree into root
Preconditon: original tree exists
Postcondition: new copy of tree
*///****************************************************************************

TreeType::TreeType(const TreeType& originalTree) {
   CopyTree(root, originalTree.root);
}

/*******************************************************************************
Function: calls the recursive function CopyTree to copy originalTree into root
Preconditon: original tree exists
Postcondition: new copy of tree
*///****************************************************************************

void TreeType::operator=(TreeType& originalTree) {
   if(&originalTree == this)
      return;
   Destroy(root);
   CopyTree(root, originalTree.root);
}

/*******************************************************************************
Function: initializes the tree to an empty state
Preconditon: n/a
Postcondition: the tree exists and is empty
*///****************************************************************************

void TreeType::MakeEmpty() {
   Destroy(root);
}

/*******************************************************************************
Function: determines whether the tree is empty
Preconditon: n/a
Postcondition: function value = (tree is empty)
*///****************************************************************************

bool TreeType::IsEmpty() const {
   return root == NULL;
}

/*******************************************************************************
Function: determines whether the tree is full
Preconditon: n/a
Postcondition: function value = (tree is full)
*///****************************************************************************

bool TreeType::IsFull() const {
   TreeNode* location;
   try {
      location = new TreeNode;
      delete location;
      return false;
   }
   catch(bad_alloc exception) {
      return true;
   }
}

/*******************************************************************************
Function: determines the number of elements in the tree by recursively calling 
   CountNodes
Preconditon: n/a
Postcondition: function value = number of elements in the tree
*///****************************************************************************

int TreeType::GetLength() const {
   return CountNodes(root);
}

/*******************************************************************************
Function: counts the number of nodes in the tree
Preconditon: n/a
Postcondition: returns number of nodes to GetLength
*///****************************************************************************

int TreeType::CountNodes(TreeNode* tree) const {
   if(tree == NULL)
      return 0;
   else
      return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

/*******************************************************************************
Function: walks the tree to determine if searched for node is present
Preconditon: item key is initialized
Postcondition: returns true if found, false otherwise
*///****************************************************************************

void TreeType::Retrieve(TreeNode* tree, ItemType& item, bool& found) const {
   if(tree == NULL)
      found = false;
   else if(item.ComparedTo(tree->info) == LESS)
      Retrieve(tree->left, item, found);
   else if(item.ComparedTo(tree->info) == GREATER)
      Retrieve(tree->right, item, found);
   else {
      item = tree->info;
      found = true;
   }
}

/*******************************************************************************
Function: retrieves item whose key matches item's key, if present, by 
   recursively calling Retrieve
Preconditon: key member of item is initialized
Postcondition: if there is an element whose key matches the item's key, the 
   found = true and a copy of the item is returned; otherwise, found = false
   and item is returned. Tree is unchanged
*///****************************************************************************

ItemType TreeType::RetrieveItem(ItemType item, bool& found) const {
   Retrieve(root, item, found);
   return item;
}

/*******************************************************************************
Function: determines where to insert new tree node and inserts it
Preconditon: item is initialized
Postcondition: new tree node is added to tree
*///****************************************************************************

void TreeType::Insert(TreeNode*& tree, ItemType item) {
   if(tree == NULL) {
      tree = new TreeNode;
      tree->right = NULL;
      tree->left = NULL;
      tree->info = item;
   }
   else if(item.ComparedTo(tree->info) == LESS)
      Insert(tree->left, item);
   else
      Insert(tree->right, item);
}

/*******************************************************************************
Function: inserts a new item by recursively calling Insert
Preconditon: item is initialized
Postcondition: new tree node is added to tree
*///****************************************************************************

void TreeType::InsertItem(ItemType item) {
   assert(!IsFull());
   Insert(root, item);
}

/*******************************************************************************
Function: sets data to the info member of the rightmost node in tree
Preconditon: tree exists
Postcondition: info member set to the rightmost node in tree
*///****************************************************************************

void TreeType::GetPredecessor(TreeNode* tree, ItemType& data) {
   while(tree->right)
      tree = tree->right;
   data = tree->info;
}

/*******************************************************************************
Function: deletes the node pointed to by tree
Preconditon: n/a
Postcondition: The user's data in the node pointed to by tree is no longer in 
   the tree. If tree is a leaf node of has only one non-NULL child pointer, 
   the node pointed to by tree is deleted; otherwise, the user's data is 
   replaced by its logical predecessor's and the predecessor's node is deleted
*///****************************************************************************

void TreeType::DeleteNode(TreeNode*& tree) {
   ItemType data;
   TreeNode* tempPtr;
   
   tempPtr = tree;
   if(tree->left == NULL) {
      tree = tree->right;
      delete tempPtr;
   }
   else if(tree->right == NULL) {
      tree = tree->left;
      delete tempPtr;
   }
   else {
      GetPredecessor(tree->left, data);
      tree->info = data;
      Delete(tree->left, data);
   }
}

/*******************************************************************************
Function: deletes item from tree
Preconditon: item is initialized
Postcondition: item is deleted
*///****************************************************************************

void TreeType::Delete(TreeNode*& tree, ItemType item) {
   if(item.ComparedTo(tree->info) == LESS)
      Delete(tree->left, item);
   else if(item.ComparedTo(tree->info) == GREATER)
      Delete(tree->right, item);
   else
      DeleteNode(tree);
}

/*******************************************************************************
Function: calls Delete recursively to delete item
Preconditon: item is intialized
Postcondition: item is deleted
*///****************************************************************************

void TreeType::DeleteItem(ItemType item) {
   Delete(root, item);
}

/*******************************************************************************
Function: calls a function to create a queue of the tree elements in the desired
   order
Preconditon:
Postcondition:
*///****************************************************************************

void TreeType::ResetTree(OrderType order) {
   switch(order) {
      case PRE_ORDER : PreOrder(root, preQue);
                       break;
      case IN_ORDER  : InOrder(root, inQue);
                       break;
      case POST_ORDER: PostOrder(root, postQue);
                       break;
   }
}

/*******************************************************************************
Function: returns the next item in the desired order
Preconditon: n/a
Postcondition: for the desired order, item is the next item in the queue. If
   item is the last one in the queue, finished it true; otherwise, finished 
   is false
*///****************************************************************************

ItemType TreeType::GetNextItem(OrderType order, bool& finished) {
   ItemType item;
   finished = false;
   switch(order) {
      case PRE_ORDER   : preQue.Dequeue(item);
                         if(preQue.IsEmpty())
                            finished = true;
                         break;
      case IN_ORDER    : inQue.Dequeue(item);
                         if(inQue.IsEmpty())
                            finished = true;
      case POST_ORDER  : postQue.Dequeue(item);
                         if(postQue.IsEmpty())
                            finished = true;
                         break;
   }
   return item;
}

/*******************************************************************************
Function: prints info member of items in tree in sorted order on fout
Preconditon: n/a
Postcondition: info is printed to fout
*///****************************************************************************

void TreeType::PrintTree(TreeNode* tree, ofstream& fout) {
   if(tree != NULL) {
      PrintTree(tree->left, fout);
      tree->info.Print(fout);
      PrintTree(tree->right, fout);
   }
}

/*******************************************************************************
Function: calls recursive fucntion Print to print items in the tree
Preconditon: n/a
Postcondition: info is printed to fout
*///****************************************************************************

void TreeType::Print(ofstream& fout) {
   PrintTree(root, fout);
}

/*******************************************************************************
Postcondition: preQue contains the tree items in preorder
*///****************************************************************************

void TreeType::PreOrder(TreeNode* tree, QueType& preQue) {
   if(tree) {
      preQue.Enqueue(tree->info);
      PreOrder(tree->left, preQue);
      PreOrder(tree->right, preQue);
   }
}

/*******************************************************************************
Postcondition: inQue contains the tree items in inorder
*///****************************************************************************

void TreeType::InOrder(TreeNode* tree, QueType& inQue) {
   if(tree) {
      InOrder(tree->left, inQue);
      inQue.Enqueue(tree->info);
      InOrder(tree->right, inQue);
   }
}

/*******************************************************************************
Postcondition: postQue contains the tree items in postorder
*///****************************************************************************

void TreeType::PostOrder(TreeNode* tree, QueType& postQue) {
   if(tree) {
      PostOrder(tree->left, postQue);
      PostOrder(tree->right, postQue);
      postQue.Enqueue(tree->info);
   }
}
