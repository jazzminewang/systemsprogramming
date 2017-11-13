#include <stdio.h>

// In this template, we use the array binaryTree[] to encode the binary
// tree in Figure 1. The first slot of binaryTree[] is used to record the number of nodes in the
// tree. 

// INPUT: 'bt', a binary tree.
//	'node', a node in the tree.
// OUTPUT: the index of given value in the tree.
int getIndex(int *bt, int node){
    int length = bt[0];
    for (int i = 1; i <= length; i++) {
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
    int length = bt[0];
    int nodeIndex = getIndex(bt, node);
    int parentIndex = nodeIndex/2;

    if (nodeIndex == 1) {
        printf("%d is the root\n", node);
    } else if (nodeIndex > length || nodeIndex < 1) {
        printf("%d is not in the tree\n", node);
    } else if (parentIndex == -1) {
        //no parent if root or too small, or if too large
        printf("There is no parent! :( %d is an orphan node\n", node);
    } else {
        printf("The parent node of %d is %d\n", node, bt[parentIndex]);
    }
}

// INPUT: 'bt', a binary tree
//	'node', a node in the tree.
// OUPUT: print the left child of 'node'. 
void printLeftChildNode (int *bt, int node){
// when the given node has no left child, or the given node is not
// in the given tree, then an error message should be printed.
    int length = bt[0];
    int nodeIndex = getIndex(bt, node);
    int leftChildIndex = nodeIndex * 2;
    //if node isn't in tree or left child is out of bounds
    if (nodeIndex < 1) {
        //no parent if root or too small, or if too large
        printf("%d doesn't exist :(\n", node);
    } else if (leftChildIndex > length) { 
        printf("%d doesn't have a left child. :(\n", node);   
    } else {
        printf("The left child of %d is %d\n", node, bt[leftChildIndex]);
    }
}

// INPUT: 'bt', a binary tree
//	'node', a node in the tree.
// OUPUT: print the right child of 'node' 
void printRightChildNode (int *bt, int node){
    //if node isn't in tree or left child is out of bounds

    int length = bt[0];
    int nodeIndex = getIndex(bt, node);
    int rightChildIndex = nodeIndex*2 + 1;
    if (nodeIndex < 1) {
        //no parent if root or too small, or if too large
        printf("%d doesn't exist :(\n", node);
    } else if (rightChildIndex > length) { 
        printf("%d doesn't have a right child. :(\n", node);
    } else {
        printf("The right child of %d is %d\n", node, bt[rightChildIndex]);
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
        printf("One of these nodes isn't in the tree. :(\n");
    }
    int nearestAncestor = 1; //root
    int length = bt[0];
    int ancestors[length];
    int temp1 = node1; //fuck this is a pointer i think
    int temp2 = node2;
    
    int i = 0;
    while (temp1 >= 1) {
        ancestors[i++] = temp1;
        temp1 = temp1/2;
    }
    //ancestors is now filled with the index of the ancestors of node1, with 
    //remaining elements in ancestors being 0
    
    while (temp2 >= 1) {
        for (i = 0; i < length; i++) {
            if (ancestors[i] == 0) break;
            if (temp2 == ancestors[i]) {
                nearestAncestor = temp2;
                printf("The nearest common ancestor of Node %d and Node %d is Node %d\n", node1, node2, bt[nearestAncestor]);
                return;
            }
        }
        temp2 = temp2/2;
    }
    printf("The nearest common ancestor of Node %d and Node %d is Node %d\n", node1, node2, bt[nearestAncestor]);
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