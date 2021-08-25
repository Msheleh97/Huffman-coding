#include "huffman_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void take_a_step_back(bit_buffer *bitbuffer);
static void pre_order(code *ptr,bit_buffer *bitbuffer, tree_node *node, int direction);


code *make_huffman_table (tree_node *root){
  code *ptr = malloc(MAX * sizeof(code));
  for (int i = 0; i < MAX; i++) {
    ptr[i].the_code = NULL;
  }
  bit_buffer *bitbuffer = bit_buffer_empty();
  pre_order(ptr,bitbuffer,left_node(root),LEFT);
  pre_order(ptr,bitbuffer,right_node(root),RIGHT);
  bit_buffer_free(bitbuffer);
  return ptr;
}

/* ---- External functions used by other functions --- */

/**
 * @brief             This function is a recursive function that
 *                    can be uses to search in the tree to find leafs and store
 *                    it datas in the huffman table.
 *
 * @param 1           A pointer to the table that will be filld with every alphabet
 *                    and it code.
 * @param 2           A pointer to bitbuffer that countains the road.
 * @param 3           A pointer to trie.
 * @param 4           An int that represent the way that will be tooken 1 for
 *                    right and 0 for the left.
 * @return            A pointer to the trie.
 */
static void pre_order(code *ptr,bit_buffer *bitbuffer, tree_node *node, int direction){
  bit_buffer_insert_bit(bitbuffer,direction);
  if (left_node(node) == 0 && right_node(node) == 0){
    ptr[node_data(node)].data = node_data(node);
    ptr[node_data(node)].the_code = bit_buffer_copy(bitbuffer);
    ptr[node_data(node)].code_length = bit_buffer_size(bitbuffer);
    take_a_step_back(bitbuffer);
    return;
  }
  else{
    pre_order(ptr,bitbuffer,left_node(node),LEFT);
    pre_order(ptr,bitbuffer,right_node(node),RIGHT);
    take_a_step_back(bitbuffer);
  }
}

/**
 * @brief          This function insert the all tooked steps except
 *                 of the last one and then it delets all unused bits.
 *                 If the code is 0001 it insert all the bit except the last once
 *                 -> 0001000 the it remove the firt bit -> 000.
 * @param 1        A pointer to the bitbuffer.
 * @return         Nothing.
 */
static void take_a_step_back(bit_buffer *bitbuffer){
  int size = bit_buffer_size(bitbuffer);
  for (int i = 0; i < size-1; i++) {
    bit_buffer_insert_bit(bitbuffer,bit_buffer_inspect_bit(bitbuffer,i));
  }
  for (int i = 0; i < size; i++) {
    bit_buffer_remove_bit(bitbuffer);
  }
}
