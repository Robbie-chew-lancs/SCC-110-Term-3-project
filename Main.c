#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000 // maximum number of words to store
#define MAX_LEN 100 // maximum length of a word

char *filter(char *mystring)
{
    char *in = mystring;
    char *out = mystring;

    do {
        if (!ispunct(*in) && (*in != '\n') && (*in != ' ') && (*in != ' '))
            *out++ = *in;
    } while (*in++);

    for (int i = 0; mystring[i]; i++) {
        mystring[i] = tolower(mystring[i]);
    }
    return mystring;
}

struct wordfrequency{
    char word[MAX_LEN];
    int frequency;
};


void analyse_file(FILE *textfile){
    char filedata[101];
    char space[2] = " ";
    struct wordfrequency wordarray[MAX_WORDS];
    int numwords = 0; 

    while (fgets(filedata, 100, textfile)){
        char* token;//individual word tokens

        token = strtok(filedata, space);// splits the string into tokens, spliting on spaces 

        while(token != NULL){
            char* filteredtoken = filter(token);//removes punctuation

            int found = 0;
            for(int i=0; i < numwords; i++){
                if(strcmp(filteredtoken, wordarray[i].word) ==0){
                    wordarray[i].frequency++;
                    found = 1;
                    break;
                }
            }
            
            if((found ==0) && (numwords < MAX_WORDS)){
                strcpy(wordarray[numwords].word, filteredtoken);
                wordarray[numwords].frequency = 1;
                numwords++;
                //printf("%s\n", filteredtoken);
            }


            token = strtok(NULL, space);
        }
    }

    for(int i = 0; i < numwords; i++){
        printf("%s  ", wordarray[i].word);
        printf("Count: %i\n", wordarray[i].frequency);

    }

}

int main(){

    FILE *textfile1;    
    FILE *textfile2;
    FILE *textfile3;
    FILE *textfile4;
    FILE *textfile5;    


    //note that this will only work if the files are in the same folder that the program is executed. aditionaly, the names are fixed 
    textfile1 = fopen("test1.txt", "r");
    textfile2 = fopen("test2.txt", "r");
    textfile3 = fopen("test3.txt", "r");
    textfile4 = fopen("test4.txt", "r");
    textfile5 = fopen("test5.txt", "r");    

    printf("Analysing file 1....\n");
    analyse_file(textfile1);    
    printf("Analysing file 2....\n");
    analyse_file(textfile2);
    printf("Analysing file 3....\n");
    analyse_file(textfile3);
    printf("Analysing file 4....\n");
    analyse_file(textfile4);
    printf("Analysing file 5....\n");
    analyse_file(textfile5);
}

