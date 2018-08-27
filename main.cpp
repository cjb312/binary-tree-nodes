#include <iostream>
#include <iomanip>
#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree <int> tree;

    cout << "Inserting nodes with 20, 5, 8, 3, 12, 9, 2, and 16\n";
    
    // Inserting nodes
    tree.insertNode(20);
    tree.insertNode(5);
    tree.insertNode(8);
    tree.insertNode(3);
    tree.insertNode(12);
    tree.insertNode(9);
    tree.insertNode(2);
    tree.insertNode(16);

    // Displaying number of nodes in the tree
    cout << "\nThe number of nodes in the tree is now " << tree.numNodes() << endl;

    // Displaying nodes in order
    cout << "\nHere are the values in the tree in order:" << endl;
    tree.displayInOrder();

    // Deleting specified nodes
    cout << endl << "\nNow deleting 8 from the tree...";
    cout << "\nNow deleting 12 from the tree...";
    tree.remove(8);
    tree.remove(12);

    // Displaying number ofnodes in the tree
    cout << endl <<"\nThe number of nodes in the tree is now " << tree.numNodes() << endl;

    // Displaying nodes in order
    cout <<"\nHere are the values in the tree order:" <<endl;
    tree.displayInOrder();

    // Nodes in post order 
    cout << endl << "\nHere are the values in the tree in POST order:" << endl;
    tree.displayPostOrder();

    // Display visual binary tree with branches that exist
    cout << endl << "\n" << setw(22) << "Tree";
    cout << "\n" << setw(21) << "|";
    cout << "\n" << setw(21) << "20";
    cout << "\n" << setw(20) << "/";
    cout << "\n" << setw(19) << "5";
    cout << "\n" << setw(18) << "/";
    cout << "\n" << setw(17) << "3";
    cout << "\n" << setw(16) << "/";
    cout << "\n" << setw(15) << "2";

    return 0;
}