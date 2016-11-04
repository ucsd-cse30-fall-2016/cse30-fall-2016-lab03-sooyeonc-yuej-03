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
   FILE filename = fopen( fp, r );
   char *ascii[ 256 ];
   // Getting first char to start loop
   char ch = fgetc( filename );
   // Looping through the file 
   while( ch != EOF && ch != '\n' )
   {      
      // Converting to int
      int c = (int) ch;
      // Incrementing array
      ascii[ c ] = ascii[ c ] + 1;
      // Getting char 
      ch = fgetc( filename );
   }
   // Closing the stream
   fclose( filename );
   // Returning array
   return ascii;
}
  

int reorder_bytes(int num)
{
   /* Your code goes here*/
}
