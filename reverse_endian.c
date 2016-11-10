
/*Sooyeon E. Chough (A92093139)
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
     int *ptr = malloc(sizeof(int));
     ptr = NULL;
     int *flip = malloc(sizeof(int));
     flip = NULL;

     // Accounting for if not enough arguments when opening file
     if( argc < 3 )
     {
          return 0;
     }
     // Opening file
     fi = fopen( argv[ 1 ], "r" );
     fo = fopen( argv[ 2 ], "w" );
     // Getting first number
     // Going through whole file
     while(1){
          // Flipping bytes and writing to output file
          fread(ptr,4,1,fi);
          *flip = reorder_bytes( *ptr );
          fwrite((const void*)flip, 4, 1, fo );
          if(feof(fo)){
            break;
          }
     }
     // Closing the files
     fclose( fo );
     fclose( fi );
     free(ptr);
     free(flip);
     // Ending main
     return 0;
}
