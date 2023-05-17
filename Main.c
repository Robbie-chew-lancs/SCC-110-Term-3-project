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

struct wordFrequency{
    char word[MAX_LEN];
    int frequency;
};


void analyse_file(FILE *textFile){
    char mystring[101];
    char space[2] = " ";
    struct wordFrequency wordArray[MAX_WORDS];
    int numWords = 0; 

    while (fgets(mystring, 100, textFile)){
        char* token;//individual word tokens

        token = strtok(mystring, space);// splits the string into tokens, spliting on spaces 

        while(token != NULL){
            char* filteredtoken = filter(token);//removes punctuation

            int found = 0;
            for(int i=0; i < numWords; i++){
                if(strcmp(filteredtoken, wordArray[i].word) ==0){
                    wordArray[i].frequency++;
                    found = 1;
                    break;
                }
            }
            
            if((found ==0) && (numWords < MAX_WORDS)){
                strcpy(wordArray[numWords].word, filteredtoken);
                wordArray[numWords].frequency = 1;
                numWords++;
                //printf("%s\n", filteredtoken);
            }


            token = strtok(NULL, space);
        }
    }

    for(int i = 0; i < numWords; i++){
        printf("%s  ", wordArray[i].word);
        printf("Count: %i\n", wordArray[i].frequency);

    }

}

int main(){

    FILE *textFile1;    
    FILE *textFile2;
    FILE *textFile3;
    FILE *textFile4;
    FILE *textFile5;    


    //note that this will only work if the files are in the same folder that the program is executed. aditionaly, the names are fixed 
    textFile1 = fopen("test1.txt", "r");
    textFile2 = fopen("test2.txt", "r");
    textFile3 = fopen("test3.txt", "r");
    textFile4 = fopen("test4.txt", "r");
    textFile5 = fopen("test5.txt", "r");    

    printf("Analysing file 1....\n");
    analyse_file(textFile1);    
    printf("Analysing file 2....\n");
    analyse_file(textFile2);
    printf("Analysing file 3....\n");
    analyse_file(textFile3);
    printf("Analysing file 4....\n");
    analyse_file(textFile4);
    printf("Analysing file 5....\n");
    analyse_file(textFile5);
}

