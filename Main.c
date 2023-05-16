#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *filter(char *mystring)//stolen from stack overflow. I wont pretend that I understand it. 
{
    char *in = mystring;
    char *out = mystring;

    do {
        if (!ispunct(*in))
            *out++ = *in;
    } while (*in++);

    return mystring;
}

void analyse_file(FILE *textFile){
    char mystring[101];
    char space[2] = " ";
    
    while (fgets(mystring, 100, textFile)){
        char* token;

        token = strtok(mystring, space);

        while(token != NULL){
            char* filteredtoken = filter(token);

            printf( " %s\n", filteredtoken);

            token = strtok(NULL, space);
        }
    }
}

int main(){


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


    
    
    analyse_file(textFile1);
    analyse_file(textFile2);
    analyse_file(textFile3);
    analyse_file(textFile4);
    analyse_file(textFile5);
}

