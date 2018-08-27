// Binary Tree Template
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

template <class T>
class BinaryTree
{
public:
   struct TreeNode
   {
      T value;
      TreeNode *left;
      TreeNode *right;
   };

   TreeNode *root;
   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void deleteNode(T, TreeNode *&);
   void makeDeletion(TreeNode *&);
   void displayInOrder(TreeNode *);
   void displayPreOrder(TreeNode *);
   void displayPostOrder(TreeNode *);
   int countNodes(TreeNode *&);

public:
   BinaryTree()      // Constructor
      { root = NULL; }
   ~BinaryTree()  // Destructor
      { destroySubTree(root); }
   void insertNode(T);
   bool searchNode(T);
   void remove(T);
   void displayInOrder()
      {  displayInOrder(root); }
   void displayPreOrder()
      {  displayPreOrder(root); }
   void displayPostOrder()
      {  displayPostOrder(root); }

   int numNodes();
};

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node.  The function inserts the *
// node into the tree pointed to by  the TreeNode pointer. This function is called recursively. *
//*************************************************************

template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == NULL)
	{
		// Insert the node.
		nodePtr = newNode;
	}
	else if (newNode->value < nodePtr->value)
	{
		// Search the left branch
		insert(nodePtr->left, newNode);
	}
	else
	{
		// Search the right branch
		insert(nodePtr->right, newNode);
	}
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************

template <class T>
void BinaryTree<T>::insertNode(T num)
{
   TreeNode *newNode = NULL;	// Pointer to a new node.

   // Create a new node and store num in it.
   newNode = new TreeNode;
   newNode->value = num;
   newNode->left = newNode->right = NULL;

   // Insert the node.
   insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************

template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)
{
	if (nodePtr->left)
	{
		destroySubTree(nodePtr->left);
	}

	if (nodePtr->right)
	{
		destroySubTree(nodePtr->right);
	}

   delete nodePtr;
}

//***************************************************
// searchNode determines if a value is present in the tree.  If so,  *
// the function returns true.  Otherwise, it returns false.    *
//***************************************************

template <class T>
bool BinaryTree<T>::searchNode(T num)
{
	bool status = false;

	TreeNode *nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->value == num)
		{
			status = true;
		}
		else if (num < nodePtr->value)
		{
			nodePtr = nodePtr->left;
		}
		else
		{
			nodePtr = nodePtr->right;
		}
	}

	return status;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************

template <class T>
void BinaryTree<T>::remove(T num)
{
   deleteNode(num, root);
}

//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************

template <class T>
void BinaryTree<T>::deleteNode(T num, TreeNode *&nodePtr)
{
	if (num < nodePtr->value)
	{
		deleteNode(num, nodePtr->left);
	}
	else if (num > nodePtr->value)
	{
		deleteNode(num, nodePtr->right);
	}
	else
	{
		makeDeletion(nodePtr);
	}
}

//***********************************************************
// makeDeletion takes a reference to a pointer to the node that is to be deleted. *
// The node is removed and the branches of the tree below the node are reattached.      *
//***********************************************************

template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)
{
	// Temporary pointer, used in reattaching the left subtree.
   TreeNode *tempNodePtr = NULL;

   if (nodePtr == NULL)
   {
	   cout << "Cannot delete empty node.\n";
   }

   else if (nodePtr->right == NULL)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left; // Reattach the left child
      delete tempNodePtr;
   }
   else if (nodePtr->left == NULL)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right; // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else
   {
      // Move one node the right.
      tempNodePtr = nodePtr->right;

      // Go to the end left node.
	  while (tempNodePtr->left)
	  {
		  tempNodePtr = tempNodePtr->left;
	  }

      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;

      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************

template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << "  ";//endl;
      displayInOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************

template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);
      displayPreOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************

template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      displayPostOrder(nodePtr->left);
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << "  "; //endl;
   }
}

//****************************************************************
// The numNodes function returns the number of nodes in the tree.*
//****************************************************************

template <class T>
int BinaryTree<T>::numNodes()
{
	return countNodes(root);
}

//****************************************************************
// The countNodes function uses recursion to count the nodes in  the tree.
// This function is called by the public member function numNodes.
//****************************************************************

template <class T>
int  BinaryTree<T>::countNodes(TreeNode *&nodePtr)
{
	int count;

	if (nodePtr == NULL)
	{
		count = 0;
	}
	else
	{
		count = 1 + countNodes(nodePtr->left) + countNodes(nodePtr->right);
	}

	return count;
}
#endif