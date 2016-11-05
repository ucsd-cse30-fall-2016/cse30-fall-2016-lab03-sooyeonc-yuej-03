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
   // Making array
   unsigned int *ascii[ 256 ];
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
   return *ascii;
}
  

int reorder_bytes(int num)
{
   // Creating necessary int
   int reverse = 0;
   int mask = 0xff;
   // Getting each necessary bit, reordering, and adding
   reverse = reverse + ( ( num & mask ) << 24 );
   reverse = reverse + ( ( (num >> 8) & mask ) << 16 );
   reverse = reverse + ( ( (num >> 16) & mask ) << 8 );
   reverse = reverse + ( (num >> 24) & mask );
   return reverse;
}
