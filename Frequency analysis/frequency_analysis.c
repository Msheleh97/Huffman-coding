#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "frequency_analysis.h"

void get_frequency_analysis(FILE *p, int frequency_analysis_array[]){
  int text;
  for (int i = 0; i < MAX; i++){
    frequency_analysis_array[i] = 0;
  }
  do{
    text = fgetc(p);
    int value = text;
    frequency_analysis_array[value]+=1;
  }while (text != EOF);
}
