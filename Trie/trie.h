/**
 * @defgroup TRIE_H
 *
 * @brief This modul is responsable of making a trie (binary tree).
 *
 *  This modul allocte memory in shape of struct tree_node (nodes) for each sign
 *  that bigger that 0. All nodes inserts in priority queue and the 2 nodes
 *  with the less quantity coupled together until the priority queue is empty
 *  in this way this modul creat a trie.
 *
 **/
#ifndef TRIE_H
#define TIRE_H
#include "pqueue.h"
#include "list.h"
#include "frequency_analysis.h"



/* a struct of what every node contains*/
typedef struct tree_node{
  struct tree_node *left,*right;
  int frequency;
  int data;
}tree_node;

/**
 * @brief        This function is the responsable function of making the trie.
 *               In this function alloctes an empty priority queue that fills
 *               with all allocated nodes and sort them in increasing order.
 *               Finally coupls all nodes together to make a trie (binary tree).
 *
 * @param 1      The frequency analysis array.
 * @return       A pointer to the trie.
 */tree_node* make_the_tree(int frequency_analysis_array[]);


 /**
  * @brief           This function is a comparison function that compare two values
  *                  If value1 > value2  returns 1
  *                  if value1 < value2  returns -1
  *                  if value1 = value2  returns 0
  *
  * @param 1         A void pointer to the first value
  * @param 2         A void pointer to the second value.
  * @return          An integer.
  */int comparetion(void* val1, void* val2);

  /**
  * @brief          This function is a recursive function that
  *                 can be uses to deallocate the binery tree (trie).
  * @param 1        A pointer to the root of the tree.
  * @return         Nothing.
  */void deallocate_trie(tree_node *node);

  /**
  * @brief          This function returns the left node of the sent node.
  * @param 1        A pointer to the node.
  * @return         A pointer to the node into the left.
  */tree_node *left_node(tree_node *node);

  /**
  * @brief          This function returns the right node of the sent node.
  * @param 1        A pointer to the node.
  * @return         A pointer to the node into the right.
  */tree_node *right_node(tree_node *node);

  /**
  * @brief          This function returns the data that the node countains.
  * @param 1        A pointer to the node.
  * @return         The data (an int).
  */int node_data(tree_node *node);


#endif
