/**
 *
 * @brief
 *  This program is a program that can be used into encoding and decoding text
  * files, To start the program 5 argument have to be seted.
 *
 *  Encoding:
 *    ./huffman -encode file_1 file_2 file_3.
 *  file_1: the file that uses to do a frequency analisys on.
 *  file_2: the file that uses to count amout of bytes of the original text.
 *  file_3: the file that will be used as an result file.
 *  encoding prosses: First step of the encoding that is checking if the quantity
 *  of the argument is correct. The uses the function huffman_encode in the encode
 *  moudle this function is responsable of the encoding prosses. The first step in
 *  this funcktion is to do an frequency analisys on the file_1 with the moudle
 *  frequency_analisis. The next step is buldning the trie using the trie moudul.
 *  in the trie modul uses two data structurs piority queue and list.
 *  when the trie is done uses the modul huffman_table to bulid a tabel that countain
 *  the trie road into every sign from file _2. Fainelly uses the file_1 to read
 *  the text sign by sign and for every sign writes the code of it in file_3
 *  so file_3 have a text of 1 and 0.
 *
 *  Decoding:
 *    ./huffman -decode file_1 file_2 file_3.
 *  file_1: the file that uses to do a frequency analisys on.
 *  file_2: the file that countan the codes (the result file from encoding file_3).
 *  file_3: the file that will be used as an result file an it will be the same
 *          as file_1 from encodning.
 *  Decoding prosses:
 *  First it check the quantity of arguments the it use huffman decode  module that
 *  is responsable of the hole decode prosses. First it make a frequency analysis
 *  on file_1 using frequency_analisis moudul. In the next step it make a trie
 *  using trie moudle. The last step is to read from the binery file_2 and the
 *  it traversal in the trie to find every sign the write it in file_3 using module
 *  huffman decode.
 *
 *  @ auother:  Mohammad Mshaleh
 *  @ sine: 06-03-2020
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encode.h"
#include "decode.h"

void check_the_files (FILE *file_1, FILE *file_2 ,FILE *file_3);

int main(int argc, char const *argv[]) {
  FILE *file_1 = fopen (argv[2],"r");
  FILE *file_2 = fopen (argv[3],"r");
  FILE *file_3 = fopen (argv[4],"w");
  check_the_files(file_1,file_2,file_3);

  if (argc != 5){
    fprintf(stderr, "wrong input try again\n");
  }
  else if (strcmp (argv[1],"encode") == 0){
    huffman_encode (file_1,file_2,file_3);
  }
  else if(strcmp (argv[1],"decode") == 0){
    huffman_decode (file_1,file_2,file_3);
  }
  else {
    fprintf(stderr, "Nothing has progressed try again!\n");
  }
  return 0;
}


// This function check if the files have been open correctly
void check_the_files (FILE *file_1, FILE *file_2 ,FILE *file_3){
  if (file_1 == NULL){
    fprintf(stderr, "could not open FILE 1 \n");
  }

  else if (file_2 == NULL){
    fclose (file_1);
    fprintf(stderr, "could not open FILE 2 \n");
  }

  else if (file_3 == NULL){
    fclose(file_1);
    fclose(file_2);
    fprintf(stderr, "could not open FILE 3 \n");
  }
}
