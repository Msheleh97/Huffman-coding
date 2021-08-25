#ifndef HUFFMAN_TABLE
#define HUFFMAN_TABLE
#include "bit_buffer.h"
#include "trie.h"
#define LEFT   0
#define RIGHT  1
/**
 * @defgroup HUFFMAN TABLE
 *
 * @brief This modul is responsable to find the path for every singel sign
 *        out of the trie.
 *
 *  This modul creat empty bit buffer and to search for the sign in the trie
 *  and each step inserts in the bit buffer. when the sign is found the way
 *  stores in an array.
 *
 *  @ auother:  Mohammad Mshaleh
 *  @ sine: 06-03-2020
 **/

 // A struct to save every sign and thier way
typedef struct code{
  int data;
  int code_length;
  bit_buffer *the_code;
}code;


 /**
  * @brief         This function is the responsable alloctes memory to the table
  *                fyll the table and return it.
  *
  * @param 1           A pointer to trie.
  * @return            A pointer to the huffman table.
  */code *make_huffman_table (tree_node *root);

#endif
