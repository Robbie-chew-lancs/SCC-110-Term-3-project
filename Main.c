#include <stdio.h>
#include <string.h>

int main(){
    char FileAddress[255];
    scanf("%s", FileAddress);


    FILE *textfile;

    textfile = fopen(FileAddress, "r");
}