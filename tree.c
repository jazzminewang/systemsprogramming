#include <stdio.h>

// In this template, we use the array binaryTree[] to encode the binary
// tree in Figure 1. The first slot of binaryTree[] is used to record the number of nodes in the
// tree. 

// INPUT: 'bt', a binary tree.
//	'node', a node in the tree.
// OUTPUT: the index of given value in the tree.
int getIndex(int *bt, int node){
    int i;
    int length = sizeof(bt) / sizeof(a[0]);
    for (i = 1; i < length; i++) {
        //go to length because last char is null
        if (bt[i] == node) { return i; }
    }
    return -1; //if not found
}

// INPUT: 'bt', a binary tree.
//	'node ', a node in the tree.
// OUPUT: print the parent node of 'node'. 
void printParentNode (int *bt, int node){
// Your code should
// handle exceptional cases. If the given node is the root node, that is, if node is 1, then there
// is no parent. If the given node is not in the given tree, that is, if the given node index is too
// large or non-positive, then an error message should be printed.
    if (node <= 1 || getIndex(bt, node/2) == -1 {
        //no parent if root or too small, or if too large
        printf("There is no parent! :( orphaned node");
    } else {
        printf("Parent node: %d", getIndex(bt, i));
    }
}

// INPUT: 'bt', a binary tree
//	'node', a node in the tree.
// OUPUT: print the left child of 'node'. 
void printLeftChildNode (int *bt, int node){
// when the given node has no left child, or the given node is not
// in the given tree, then an error message should be printed.

    //if node isn't in tree or left child is out of bounds
    if (getIndex(bt, node) == -1 || getIndex(bt, node*2) == -1{
        //no parent if root or too small, or if too large
        printf("The node doesn't exist, or they don't have a left child. :(");
    } else {
        printf("Left child: %d", getIndex(bt, node*2));
    }
}

// INPUT: 'bt', a binary tree
//	'node', a node in the tree.
// OUPUT: print the right child of 'node' 
void printRightChildNode (int *bt, int node){
    //if node isn't in tree or left child is out of bounds
    if (getIndex(bt, node) == -1 || getIndex(bt, node*2 + 1) == -1{
        //no parent if root or too small, or if too large
        printf("The node doesn't exist, or they don't have a right child. :(");
    } else {
        printf("Right child: %d", getIndex(bt, node*2 + 1));
    }
}

// INPUT: 'bt', a binary tree
//	'node1', a node in the tree.
//	'node2', a node in the tree.
// OUPUT: print the nearest ancestor of 'node1' and 'node2'. 
void printNearestCommonAncestor(int *bt, int node1, int node2){
//For two given nodes, this
//function returns their nearest common ancestor in the tree. 
    //bad input check
    if (getIndex(bt, node1) == -1 || getIndex(bt, node2) == -1) {
        printf("One of these nodes isn't in the tree. :(");
    }
    int length = sizeof(bt) / sizeof(a[0]);
    int ancestors[length];
    int i = 0;

    while (node1 >= 2) {
        ancestors[i++] = node1;
        node1 /= 2;
    }
    //ancestors is now filled with the index of the ancestors of node1, with 
    //remaining elements in ancestors being 0
    while (node2 >= 2) {
        for (int i = 0; i < length; i++) {
            if (ancestors[i] == 0) break;
            if (node2 == ancestors[i]) {
                printf("Nearest Common Ancestor: %d", getIndex(bt, node2));
            }
        }
        node2 /= 2;
    }
}


/* binaryTree is an array to encode a binary tree.
The first element of this array is used to encode the number of nodes. */

int main() {

	int binaryTree[11] = {10, 16, 14, 10, 8, 7, 9, 3, 2, 4, 1};

	printParentNode(binaryTree, 16);
	printParentNode(binaryTree, 3);

	printLeftChildNode(binaryTree, 7);
	printLeftChildNode(binaryTree, 9);

	printRightChildNode(binaryTree, 7);
	printRightChildNode(binaryTree, 10);

	printNearestCommonAncestor(binaryTree, 8, 1);
	printNearestCommonAncestor(binaryTree, 8, 9);

	return 0;
}