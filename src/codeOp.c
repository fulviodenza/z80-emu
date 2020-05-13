#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){

    FILE *fp;
    FILE *nf;
    fp = fopen("listInstr.txt", "r");
    nf = fopen("listEncodedInstr.txt", "w");
    char str[40];

    while(fgets(str, 20, fp) != NULL){

        printf("Writing %s as %d to file\n", str, atoi(str));
        fprintf(nf, "%d\n",atoi(str));
    }
}