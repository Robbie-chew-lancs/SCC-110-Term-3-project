#include <stdio.h>
#include <string.h>

int main(){
//    char FileAddress1[255];
//    printf("File 1:");
//    scanf("%s", FileAddress1);
//
//
//    FILE *textfile;
//
//    textfile = fopen(FileAddress1, "r");
//
//    char FileAddress2[255];
//    printf("File 2:");
//    scanf("%s", FileAddress2);
//
//
//    FILE *textfile;
//
//    textfile = fopen(FileAddress2, "r");
//

    FILE *textFile1;    
    FILE *textFile2;
    FILE *textFile3;
    FILE *textFile4;
    FILE *textFile5;    

    textFile1 = fopen("test1.txt", "r");
    textFile2 = fopen("test2.txt", "r");
    textFile3 = fopen("test3.txt", "r");
    textFile4 = fopen("test4.txt", "r");
    textFile5 = fopen("test5.txt", "r");    

    char mystring[101];
    char space[2] = " ";
    
    while (fgets(mystring, 100, textFile1)){
        char* token;

        token = strtok(mystring, space);

        while(token != NULL){
            printf( " %s\n", token);

            token = strtok(NULL, space);
        }
    }

    while (fgets(mystring, 100, textFile2)){
        char* token;

        token = strtok(mystring, space);

        while(token != NULL){
            printf( " %s\n", token);

            token = strtok(NULL, space);
        }
    }

    while (fgets(mystring, 100, textFile3)){
        char* token;

        token = strtok(mystring, space);

        while(token != NULL){
            printf( " %s\n", token);

            token = strtok(NULL, space);
        }
    }

    while (fgets(mystring, 100, textFile4)){
        char* token;

        token = strtok(mystring, space);

        while(token != NULL){
            printf( " %s\n", token);

            token = strtok(NULL, space);
        }
    }

    while (fgets(mystring, 100, textFile5)){
        char* token;

        token = strtok(mystring, space);

        while(token != NULL){
            printf( " %s\n", token);

            token = strtok(NULL, space);
        }
    }
    
}