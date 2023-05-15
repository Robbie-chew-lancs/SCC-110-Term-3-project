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

    textFile1 = fopen("./test1", "r");
    textFile2 = fopen("./test2", "r");
    textFile3 = fopen("./test3", "r");
    textFile4 = fopen("./test4", "r");
    textFile5 = fopen("./test5", "r");    

    char mystring[100];
    fgets(mystring, 100, textFile1);

    printf("%s", mystring);
    
    
}