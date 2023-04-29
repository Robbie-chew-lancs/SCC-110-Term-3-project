#include <stdio.h>
#include <string.h>

int main(){
    char FileAddress1[255];
    scanf("%s", FileAddress1);


    FILE *textfile;

    textfile = fopen(FileAddress1, "r");

    char FileAddress2[255];
    scanf("%s", FileAddress2);


    FILE *textfile;

    textfile = fopen(FileAddress2, "r");

}