#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "instructionSet.h"
#include "z80.h"

int main()
{
    const char filename[] = "highscore.dat";
    int score = 1088;
    FILE *hs;

    /* create the file and write the value */
    printf("Writing high score: %d\n",score);
    hs = fopen(filename,"w");
    if( hs == NULL)
    {
        fprintf(stderr,"Error writing to %s\n",filename);
        return(1);
    }
    fwrite(&score, sizeof(int), 1, hs);
    fclose(hs);
}