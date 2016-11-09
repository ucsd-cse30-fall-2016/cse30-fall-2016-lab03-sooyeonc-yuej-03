/*
 * Sooyeon E. Chough (A92093139)
 * Yue Jiang (A92095681)
 */

/**
 * ALL FUNCTION IMPLEMENTATIONS AND HELPER FUNCTIONS FOR ENCODER WILL BE IN THIS FILE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "common.h"
#include "encoder.h"

/**
 *
 * This function takes a char c as input and returns a (6 character) array
 * that represents the 6 digit code for that character. This code is simply
 * the index of the char in the MAPPING array (represented in binary). 
 * You should use the REVERSE\_MAPPING array in this function to get 
 * the binary code for the character. REVERSE\_MAPPING array MUST be 
 * initialized with createReverseMapping(), prior to calling this function.
 *
 * @param c The input character to encode
 * @returns a six character array which encodes the index into ASCII binary
 */
char* encodeChar(char c)
{
    // Creating variables and the array to return
    char *coded = (char*) malloc( sizeof(char) );
    int index, temp, i;
    createReverseMapping();
    // Getting index value for c in the new map
    index = (int) c;
    index = REVERSE_MAPPING[ index ];
    // Turning into binary
    for( i = 6; i > 0; i-- ) 
    {
        temp = index & 0x01;
        if( temp == 0 )
        {
            coded[ i - 1 ] = '0';
        }
        else
        {
            coded[ i - 1 ] = '1';
        }
        index = index >> 1;
    }
    // Returns resulting array
    return coded;
}

/**
 * Takes a char c and int bit (should be either 0 or 1) and int index as input. 
 * Sets the bit at input index of c to be the input bit and returns the result.
 * The 0 index refers to the LSB, so for example, index 2 should 
 * set the 3rd least significant bit.
 * 
 * @param c the char to implant a bit into
 * @param bit the bit value to implant (0 or 1)
 * @param index the index to implant the bit into (0 is LSB)
 * @returns the char with bit b implanted into the input index
 */
char implantBit(char c, int bit, int index)
{
    // Initializing variables to use later
    char changed;
    int bin, mask;
    // Getting binary version of char
    bin = (int) c; 
    // Creating and using mask
    mask = 0xff - (0x01 << index);
    bin = bin & mask;
    changed = (char) (bin + (bit << index));
    return changed;
}

/**
 * Takes a FILE handle in as input (corresponding to a regular ASCII
 * text file) and reads the file, char by char. Encodes each char into
 * a 6 character "binary" char array (by calling encodeChar).  The
 * resulting character arrays should be written to the output file
 * handle out
 *
 * @param in The input text file to read
 * @param out The output file, in ASCII encoded "binary"
 */
void textToBinary(FILE *in, FILE *out)
{
    // Initializing variables necessary
    int *ptr = NULL;
    char c;
    char *bin = (char*) malloc( sizeof(char) );
    // Reading the input file
    c = fgetc( in );
    // Looping through file
    while( !foef( in ) )
    {
        // Getting char array in binary format
        bin = encodeChar( c );
        // Writing it to output file
        *ptr = fwrite( bin, sizeof(char)*6, 1, out );
        // Getting next char
        c = fgetc( in );
    }
}

/**
 * Takes a FILE handle in as input (corresponding to a
 * "binary" encoded file) and reads the file 1 char at a time. Each
 * char read will be an ASCII '0' or ASCII '1', and either 0 or 1 
 * will be implanted into randomized chars generated by rand()%256.
 *
 * If ASCII '0', then implant 0 into the bit at the input index 
 * of a randomized char . If ASCII '1', then implant 1 into the bit at 
 * the input index of the randomized char (by calling implantBit). 
 * Write the result into the output file handle out 
 * (Note: The least significant bit is in index 0)
 *
 * @param in The input file handle to read (ASCII encoded binary)
 * @param out The output file to write to
 * @param index the index of the bit where binary values should be implanted (0 is LSB)
 */
void binaryToCode(FILE *in, FILE *out, int index)
{
    srand(1); //DO NOT REMOVE OR EDIT THIS LINE OF CODE
    
    // TODO Implement me!
}

/**
 * Reads in a file from the specified input path and outputs a a binary encoding to
 * specified bin path and a fully encoded version to specified output path. 
 * This should simply open the necessary files and call the above helper 
 * functions in the correct sequence, and close the necessary files.
 *
 * @param input the path to the input file
 * @param bin the path to the encoded ASCII binary output file
 * @param output the path to the encoded output file 
 * @param index The index of the bit where binary values should be implanted (0 is LSB)
*/
void encodeFile(char* input, char* bin, char* output, int index)
{
    // TODO Implement me!
}
