/*
 * Sooyeon E. Chough (A92093139)
 * Yue Jiang (A92095681)
 */

#include <stdio.h>
#include <stdlib.h>
#include "warmup.h"

unsigned int *char_freqs(FILE *fp)
{
   // Checking if file is null
   if( fp == NULL )
   {
      return NULL;
   }
   // Getting file in read only mode
   char *ascii[ 256 ];
   // Getting first char to start loop
   char ch = fgetc( fp );
   // Looping through the file 
   while( ch != EOF && ch != '\n' )
   {      
      // Converting to int
      int c = (int) ch;
      // Incrementing array
      ascii[ c ] = ascii[ c ] + 1;
      // Getting char 
      ch = fgetc( fp );
   }
   // Closing the stream
   fclose( fp );
   // Returning array
   return &ascii;
}
  

int reorder_bytes(int num)
{
   int littlest = num >> 24;
   int littler = (num << 8) >> 24;
   int bigger = (num << 16) >> 24;
   int biggest = (num << 24) >> 24;
   int reverse = biggest + bigger + littler + littlest;
   return reverse;
}
