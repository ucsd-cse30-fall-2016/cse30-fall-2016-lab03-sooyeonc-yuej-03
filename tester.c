/*
 * Sooyeon E. Chough (A92093139)
 * Yue Jiang (A92095681)
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "common.h"
#include "encoder.h"
#include "decoder.h"

int main(int argc, char *argv[])
{
    // Files to test with
    FILE *fi, *fo, *fp;
    
    // Opening files
     fi = fopen( argv[ 1 ], "r" );
     fo = fopen( argv[ 2 ], "w" );
    
    // Testing actual methods
    textToBinary( fi, fo );
    
    // Closing files
    fclose( fi );
    fclose( fo );
    
    // End of file
    return 0;
}
