#include <stdio.h>
#include <stdlib.h>
/*
Kash Pritt
Project P3.1
CS 332 Dr.Garfield
This program creates a binary tree in C, where the node values are populated from 1-17. This program then prints the results in Post and Breadth form
Provided are two resources used for  making this project.
*/
// https://stackoverflow.com/questions/53799322/how-to-properly-stop-running-dotnet-core-web-application
// https://stackoverflow.com/questions/12574506/binary-tree-in-c
//  Define the structure of a tree node
int MAX_SIZE = 17;
// constructor for creating nodes with left and right children
struct TreeNode
{
    int node_Value;

    struct TreeNode *left_node;
    struct TreeNode *right_node;
};
// Create a node with a left and right children initialized at null and filled with data
struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    newNode->node_Value = data;

    newNode->left_node = NULL;
    newNode->right_node = NULL;

    return newNode;
}

// This is recursive where is the node is not null and the left and right node are not null, call itself starting leftmost until
// null node is found so we can add ours to the tree
struct TreeNode *addNode(int data, struct TreeNode *main_Node)
{

    if (main_Node == NULL)
    {
        main_Node = createNode(data);
    }
    else if (main_Node->left_node == NULL)
    {
        main_Node->left_node = addNode(data, main_Node->left_node);
    }
    else if (main_Node->left_node != NULL && main_Node->right_node == NULL)
    {
        main_Node->right_node = addNode(data, main_Node->right_node);
    }
    else if (main_Node->left_node != NULL && main_Node->right_node != NULL)
    {
        main_Node->left_node = addNode(data, main_Node->left_node);
    }

    return main_Node;
}

//  Traverse left mto right
void postOrder(struct TreeNode *main_Node)
{
    // will stop the traversal
    if (main_Node == NULL)
    {
        return;
    }
    // will do entire left side
    postOrder(main_Node->left_node);
    // then do the right of the left until all left and right are done
    postOrder(main_Node->right_node);

    printf("%d ", main_Node->node_Value);
}

// Traverse top down
void breadthFirst(struct TreeNode *main_Node)
{

    struct TreeNode *node_array[MAX_SIZE]; // Make an array to traverse

    int left = 0;  // left node
    int right = 1; // right node

    node_array[0] = main_Node; // sets the first queue value to print to spot 0 in queue which is top most from tree

    // This while loop sees which node values are FIlled or Null, if Filled set the node value in the array starting from
    // left to right then go down and save left to right then go down.. etc. Incrementing the array stored values
    while (left != right)
    {
        struct TreeNode *node = node_array[left]; // fill array with node pointer

        if (node->left_node != NULL)
        {
            node_array[right++] = node->left_node;
        }

        if (node->right_node != NULL)
        {
            node_array[right++] = node->right_node;
        }
        left++; // set pointer to next node
    }
    // print results
    for (int i = 0; i < MAX_SIZE; i++)
    {
        printf("%d ", node_array[i]->node_Value);
    }
}

int main()
{
    // Create the main node
    struct TreeNode *tree_Main = createNode(1);
    // creates the tree with nodes being of valued 1-17
    for (int i = 2; i < MAX_SIZE; i++)
    {
        addNode(i, tree_Main);
    }

    printf("Post-Order Traversal: ");
    postOrder(tree_Main);
    printf("\n");

    printf("Breadth First Traversal: ");
    breadthFirst(tree_Main);
    printf("\n");

    return 0;
}
