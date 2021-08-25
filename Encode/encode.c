#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "encode.h"
#include "frequency_analysis.h"
#include "huffman_table.h"

//static functions discreption below.
static void read_and_write(code *ptr,FILE *file_1, FILE *resultfile);

void huffman_encode(FILE *frequency_analysis, FILE *file_1, FILE *resultfile)
{
  int frequency_analysis_array[MAX];
  get_frequency_analysis(frequency_analysis,frequency_analysis_array);
  tree_node* root = make_the_tree(frequency_analysis_array);
  code *p = make_huffman_table(root);
  read_and_write(p,file_1,resultfile);
  for (int i = 0; i < MAX; i++) {
    if(p[i].the_code != NULL){
      bit_buffer_free(p[i].the_code);
    }
  }
  free(p);
  deallocate_trie(root);
  fclose(frequency_analysis);
  fclose(file_1);
  fclose(resultfile);
}

/* ---- External functions used by other functions --- */

/**
* @brief          This function read the input file sign by sign. for each sign
*                 it search for it code in huffman table and write the code
*                 on output file. It count the diffrent between the uncoded and
*                 encoded file and print the result.
*                 on the output files as 0 and 1..
* @param 1        A pointer to the huffman table that countains the codes.
* @param 2        A pointer to file_1 to read the signs and find thier code.
* @param 1        A pointer to the output file that uses to write the binary code.

* @return         An int of the amount of bytes of the original text.
*/
static void read_and_write(code *ptr,FILE *file_1, FILE *resultfile){
  char* text_to_bytes ;
  int character = fgetc(file_1);
  bit_buffer *text = bit_buffer_empty();
  int original_text_size = 0,coded_text_size = 0;

  while(character != EOF){
    for (int i = 0; i < bit_buffer_size(ptr[character].the_code); i++) {
      coded_text_size++;
      bit_buffer_insert_bit(text,bit_buffer_inspect_bit(ptr[character].the_code,i));
    }
    original_text_size++;
    character = fgetc(file_1);
  }
  for (int i = 0; i < bit_buffer_size(ptr[4].the_code); i++) {
    bit_buffer_insert_bit(text,bit_buffer_inspect_bit(ptr[4].the_code,i));
    coded_text_size++;
  }
  text_to_bytes = bit_buffer_to_byte_array(text);
  for (int i = 0; i < (bit_buffer_size(text)/8)+1 ; i++) {
    fputc(text_to_bytes[i],resultfile);
  }
  
  free(text_to_bytes);
  bit_buffer_free(text);
  printf("%d   bytes read from infil.txt.\n",original_text_size);
  printf("%d   bytes used in encoded form\n",coded_text_size/8);
}
