#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000 // maximum number of words to store
#define MAX_LEN 100 // maximum length of a word

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

struct word_frequency{
    char word[MAX_LEN];
    int frequency;
};


void analyse_file(FILE *textFile){
    char mystring[101];
    char space[2] = " ";
    
    while (fgets(mystring, 100, textFile)){
        char* token;//individual word tokens

        token = strtok(mystring, space);// splits the string into tokens, spliting on spaces 

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

