/*
 * Sooyeon E. Chough (A92093139)
 * Yue Jiang (A92095681)
 */

/**
 * ALL IMPLEMENTATIONS AND HELPER FUNCTIONS FOR DECODER WILL BE IN THIS FILE.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "decoder.h"
 
/**
 * Takes a char c and int index as input. 
 * Extracts the bit at the input index from the char c. The 0 index
 * refers to the LSB, so for example, index 2 should extract the 3rd
 * least significant bit.
 *
 * @param c the char to extract a bit from
 * @param index the index of the bit to extract
 * @returns the value of the bit at index in c
 */
int extractBit(char c, int index)
{
    // Initializing necessary variables
    int ch, i = 0;
    // Getting the binary version of the char
    ch = (int) c;
    // Shifting ch as necessary to get wanted index
    ch = ch >> index;
    // Getting wanted bit
    i = ch & 0x01;
    // Returning the bit
    return i;
}

/**
 * Takes a 6 character array b as input and returns the corresponding
 * char from MAPPING that is indexed by the binary ASCII string b.
 * For example, if b = "010101", then the char that is mapped to it is 
 * in MAPPING, index 1*16 + 1*4 + 1*1 = 21.
 *
 * @param b a pointer to a 6 character array, with ASCII '1's and '0's
 * @returns the corresponding character from MAPPING
 */
char decodeChar(char *b)
{
    // Initializing necessary variables
    char *temp = NULL;
    int i, total = 0;
    // Going through each char of the given array
    for( i = 0; i < 6; i++ )
    {
        // Getting value and multiplying by corresponding power of 2
        temp = (char*) malloc( sizeof(char) );
        *temp = b[ i ];
        if( *temp == '1' )
        {
            total = total + ( 32 >> i );
        }
        free( temp );
    }
    // Returning char from MAPPING array
    return MAPPING[ total ];
}

/**
 * Takes a FILE handle in as input (corresponding to
 * an encoded file) and reads the file, char by char. The
 * bit at the input index of each char is extracted (by calling
 * extractBit). The least significant bit is in index 0.
 *
 * For each character, if the extracted bit is 0, output ASCII '0' to
 * the output file. If the extracted bit is 1, output ASCII
 * '1' to the output file.
 *
 * @param in the input file handle to read from
 * @param out the output file to write the extracted ASCII binary into
 * @param index the index of the bit to extract from each char
*/
void codeToBinary(FILE *in, FILE *out, int index)
{
    // Initializing necessary variables
    int bit = 0;
    char ch = ' ';
    char *ptr = NULL;
    // Getting first char
    ch = fgetc( in  );
    while( ch != EOF )
    {
        // Getting bit 
        bit = extractBit( ch, index );
        // Allocating memory
        ptr = (char*) malloc( sizeof(char) );
        // Getting necessary char '0' or '1'
        if( bit == 0 )
        {
            *ptr = '0';
        }
        else
        {
            *ptr = '1';
        }
        // Writing to output file 
        fwrite( ptr, sizeof(char), 1, out );
        // Freeing memory
        free( ptr );
        // Getting next char
        ch = fgetc( in );
    }
    // End of file
    return;
}

/**
 * Takes a FILE handle in as input (corresponding to a
 * "binary" decoded file) and reads the file, 6 chars at a
 * time. Each 6 chars (all ASCII 0's and 1's) should be read into a
 * char array and decoded into its corresponding char (by calling
 * decodeChar). The resulting chars would be output to the FILE handle
 * pointed to by out.
 *
 * @param in the input file, encoded as ASCII '1's and '0's
 * @Param out the decoded output file (ASCII)
*/
void binaryToText(FILE *in, FILE *out)
{
    // Initializing necessary variables
    char c = ' ';
    char *bin = NULL;
    int i = 0;
    // Reading file
    c = fgetc( in );
    // Going through file
    while( c != EOF )
    {
        // Allocating memory
        bin = (char*) malloc( sizeof(char)*6 );
        // Making the 6-char array
        for( i = 0; i < 6; i++ )
        {
            bin[ i ] = c;
            c = fgetc( in );
        }
        // Getting resulting char
        *bin = decodeChar( bin );
        // Writing onto file
        fwrite( bin, sizeof(char), 1, out );
        // Freeing memory
        free( bin );
    }
}

/**
 * Reads in a file from the specified input path and outputs a a binary decoding to
 * specified bin path and a fully decoded version to specified output path.
 * This should simply open the necessary files, call the above helper functions
 * in the correct sequence, and close the necessary files.
 *
 * @param input the path to the input file
 * @param bin the path to the decoded ASCII binary output file
 * @param output the path to the decoded output file
 * @param index The index of the bit from which binary values should be extracted
 */
void decodeFile(char* input, char* bin, char* output, int index)
{
    // Initializing necessary variables
    FILE *in, *out, *ascii;
    // Opening files
    in = fopen( input, "r" );
    out = fopen( output, "w" );
    ascii = fopen( bin, "w" );
    // Writing first time 
    codeToBinary( in, ascii, index );
    // Changing permissions
    fclose( ascii );
    fopen( bin, "r" );
    // Writing second time
    binaryToText( ascii, out );
    // Closing files
    fclose( in );
    fclose( out );
    fclose( ascii );
    // End of method
    return;
}
