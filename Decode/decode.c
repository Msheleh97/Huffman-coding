#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decode.h"
#include "bit_buffer.h"

static void search_and_fyll(tree_node* root,FILE *file_1 ,FILE *resultfile);

void huffman_decode(FILE *frequency_analysis, FILE *file_1, FILE *resultfile){
  int frequency_analysis_array[MAX];
  get_frequency_analysis(frequency_analysis,frequency_analysis_array);
  tree_node* root = make_the_tree(frequency_analysis_array);
  search_and_fyll(root,file_1,resultfile);
  deallocate_trie(root);
  fclose(frequency_analysis);
  fclose(file_1);
  fclose(resultfile);
}

/*
 * @brief             This function is  the responsable function of reading from
 *                    the binery file (encoded file) and it search after the alphabet
 *                    in the binery tree and when it find one it take tha founded
 *                    alphbet and put it in the output filr.
 *
 * @param 1           A pointer to the trie (binery tree).
 * @param 2           A pointer to file 2 wich countain the binery code (encoded file);
 * @param 3           A pointer to file 3 wich use to write the output on it
 * @return            nothing.
 */
static void search_and_fyll(tree_node* root,FILE *file_1 ,FILE *resultfile){
  int character = fgetc(file_1);
  tree_node *current_node = root;
  bit_buffer* bit_seq = bit_buffer_empty();
  while(character != EOF){
    bit_buffer_insert_byte(bit_seq,character);
    character = fgetc(file_1);
  }
  for (int i = 0; i <= bit_buffer_size(bit_seq); i++) {
    int bit = bit_buffer_inspect_bit(bit_seq,i);
    if (left_node(current_node) == 0 && right_node(current_node) == 0){
      if (node_data(current_node) == '\4'){
        break;
      }
      fputc(node_data(current_node),resultfile);
      current_node = root;
      i--;
    }else if (bit == 0) {
      current_node = left_node(current_node);
    }else if (bit == 1){
      current_node = right_node(current_node);
    }
  }
  bit_buffer_free(bit_seq);
  printf("File decoded succesfully.\n");
}
