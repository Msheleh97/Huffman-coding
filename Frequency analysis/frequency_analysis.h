#ifndef FREQUENCY_ANALYSIS
#define FREQUENCY_ANALYSIS
/**
 * @defgroup FREQUENCY_ANALYSIS_H
 *
 * @brief A modul that count the quantity of a sign and save it in a array.
 *
 * This modul take care of counting the quantity och all 265 sign in
 * the inputed file and save all values in an array.
 *
 * @author  Mohammad Mshaleh
 * @since   2020-03-06
 *
 * @{
 */

// Define all the 265 sign in a variable.
#define MAX 256

/**
 * @brief             A function that count the quantity of each sign and store
 *                    them in an array.
 *
 * @param 1           A pointer to the input file.
 * @param 2           An array that store the quantity of each sign.
 * @return            Nothing (void)
 */
void get_frequency_analysis(FILE *p, int frequency_analysis_array[]);


#endif
