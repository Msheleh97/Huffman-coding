#ifndef DECODE_H
#define DECODE_H
#include "frequency_analysis.h"
#include "trie.h"

/**
 * @defgroup DECODE
 *
 * @brief This modul is responsable to do the decode operations to the input file.
 *
 *  The function do a frequency analysis on the inputed file and make and nevigate every
 *  single sign from input file2 whith the maked trie and it write the text on
 *  output file.
 *
 *  @ auother:  Mohammad Mshaleh
 *  @ sine: 06-03-2020
 **/

 /**
  * @brief        This function is the responsable to do frequency analysis
  *               and making a trie and then wirte every decoded code
  *               on the output file.
  *
  * @param 1           A pointer to file  1 wich use to do a frequency_analysis
  * @param 2           A pointer to file 2  wich countain the binery code.
  * @param 3           A pointer to file 3  wich use to write the output on it
  * @return            nothing.
  **/void huffman_decode(FILE *frequency_analysis, FILE *file_1, FILE *resultfile);

#endif
