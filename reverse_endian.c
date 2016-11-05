/*
 * Sooyeon E. Chough (A92093139)
 * Yue Jiang (A92095681)
 *
 * For testing warmup methods
 */

#include <stdio.h>
#include <stdlib.h>
#include "warmup.h"

int main(int argc, char** argv)
{
     // Initializing variables for later usage
     FILE *fi, *fo;
     int *ptr;
     int flip;
     
     // Accounting for if not enough arguments when opening file
     if( argc < 3 )
     {
          return 0;
     }
     // Opening file 
     fi = fopen( argv[ 1 ], "r" );
     fo = fopen( argv[ 2 ], "w" );
     // Getting first number
     ptr = fread( ptr, 4, 1, fi );
     // Going through whole file
     while( ptr == sizeof( int ) )
     {
          // Flipping bytes and writing to output file
          flip = reorder_bytes( ptr );
          ptr = fwrite( flip, 4, 1, fo );
     }
     // Closing the files
     fclose( fo );
     fclose( fi );
     // Ending main
     return 0;
}
