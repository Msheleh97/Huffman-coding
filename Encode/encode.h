#ifndef ENCODE_H
#define ENCODE_H
/**
 * @defgroup ENCODE
 *
 * @brief This modul is responsable to do the encode operation to the input file.
 *
 *  This function do a frequency analysis on the inputed file and make a huffman table
 *  and then print the codes on the output file as 0 and 1.
 *
 *  @ auother:  Mohammad Mshaleh
 *  @ sine: 06-03-2021
 **/

 /**
  * @brief             This function is responsable to do frequency analysis
  *                    and making huffman table and then write every sign with codes
  *                    on the output file.
  *
  * @param 1           A pointer to the frequency analysis array
  * @param 2           A pointer to file 1 that countain the original text
  * @param 3           A pointer to the file that will countain the codes
  * @return            nothing.
  **/
void huffman_encode(FILE *frequency_analysis, FILE *file_1, FILE *resultfile);

#endif
