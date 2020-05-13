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

//THIS IS JUST PSEUDOCODE
uint8_t encode(char *str){

    uint8_t x = atoi(str);

    switch (x) {
    case "nop":
        return 0x00;
        break;
    case "ld_bc_xx":
        return 0x01;
        break;
    case "ld_bc_a":
        return 0x02;
        break;
    case "ld_bc_a":
        return 0x02;
        break;
    case "inc_bc":
        return 0x03; //done
        break;
    case "inc_b":
        return 0x04;
        break;   
    default:
        break;
    }
}