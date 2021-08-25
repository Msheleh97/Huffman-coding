#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include "pqueue.h"
#include "list.h"
#include "frequency_analysis.h"

// Static function discreption below.
static tree_node *make_leaf(int frequencys, int datas);
static tree_node *connect_nods(void *node_1, void *node_2);

tree_node * make_the_tree(int frequency_analysis_array[]){
  tree_node* leaf, *root;
  struct pqueue* p = pqueue_empty(comparetion);
  for (int i = 0; i < MAX; i++){
    if (frequency_analysis_array[i] >= 0){
      leaf = make_leaf(frequency_analysis_array[i],i);
      pqueue_insert(p,leaf);
      }
  }
  void *node_1;void *node_2;
  while (!pqueue_is_empty(p)){
    node_1 = pqueue_inspect_first(p);
    pqueue_delete_first(p);
    if (pqueue_is_empty(p)) {
      return node_1;
    }
    node_2 =pqueue_inspect_first(p);
    pqueue_delete_first(p);
    root = connect_nods(node_1,node_2);
    if(!pqueue_is_empty(p)){
      pqueue_insert(p,root);  
    }
  }
  pqueue_kill(p);
  return root;
}

int comparetion(void* val1, void* val2){
  tree_node *value1 = (tree_node*)val1;
  tree_node *value2 = (tree_node*)val2;
  if (value1->frequency > value2->frequency){
    return 1;
  }
  else if (value1->frequency <  value2->frequency){
    return -1;
  }
  else {
    return 0;
  }
}

void deallocate_trie(tree_node *node){
    if(left_node(node) == NULL && right_node(node) == NULL){
      free(node);
    }
    else{
      deallocate_trie(left_node(node));
      deallocate_trie(right_node(node));
      free(node);
    }
  }

  tree_node *left_node(tree_node *node){
    return node->left;
  }

  tree_node *right_node(tree_node *node){
    return node->right;
  }

  int node_data(tree_node *node){
    return node->data;
  }

/* ---- External functions used by other functions --- */

/**
 * @brief             This function allocate memory for the trie nodes and
 *                    sets the information in the node dependign on the parameters.
 * @param 1           An integer for the quantity of a sign.
 * @param 2           An integer for wich sign.
 * @return            A pointer to the node.
 */
 static tree_node *make_leaf(int frequencys, int datas){
  tree_node *p =(tree_node*)malloc(sizeof(tree_node));
  p-> frequency = frequencys;
  p-> data = datas;
  p->left = NULL;
  p->right = NULL;
  return p;
}
/**
 * @brief          This function connect two nodes together with a new allocated node.
 * @param 1        A void pointer that points to the first node to be connected.
 * @param 2        A void pointer that points to the second node to be connected..
 * @return         A pointer to the new node.
 */
 static tree_node *connect_nods(void *node_1, void *node_2){
  tree_node *node1 = (tree_node*)node_1;
  tree_node *node2 = (tree_node*)node_2;
  tree_node *node_1_2 = make_leaf((node1->frequency)+(node2->frequency),-1);
  node_1_2->left = node1;
  node_1_2->right = node2;
  return node_1_2;
}
