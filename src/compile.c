#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "instructionSet.h"
#include "z80.h"

#define MAXCHAR 1000

int main(int argc, char *argv[]) {

    if(argc != 2) {
        fprintf(stderr,"Open just one file!\n");
        return 1;
    }

    char *str[MAXCHAR];
    char *filename = argv[1];

    FILE *input_file = fopen(filename, "r");

    if(input_file == NULL) {
        printf("Could not open file %s",filename);
        return 1;
    }

    FILE *output_file = fopen("out.z80", "wb");
    
    /* create the file and write the value */
    if( output_file == NULL)
    {
        fprintf(stderr,"Error writing to %s\n",output_file);
        return(1);
    }
    while (fgets(str, MAXCHAR, input_file) != NULL) {
        fputs(str, output_file);
    }
    fclose(output_file);
}

uint8_t encode(op_code opcode){

}