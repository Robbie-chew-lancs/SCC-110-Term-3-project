#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 1000 // maximum number of words to store
#define MAX_LEN 100 // maximum length of a word

//Filter out Punctuation, newline and whitespace
//Return pointer to filtered string
char *filter(char *mystring)
{
    char *in = mystring;
    char *out = mystring;

    do {//Remove punctuation and whitespace
        if (!(ispunct(*in) || (*in == '\n') || (*in == ' ') || (*in == ' ')))
            *out++ = *in;
    } while (*in++);

    
    //Convert string to lowercase
    for (int i = 0; mystring[i]; i++) {
        mystring[i] = tolower(mystring[i]);
    }
    return mystring;
}


//Struct that stores words and their associated frequencies
struct wordfrequency{
    char word[MAX_LEN];
    int frequency;
};


int frequencycompare(const void *a, const void *b){//dammed c and its no passing structs arround rules
    struct wordfrequency *word1 = (struct wordfrequency *)a;
    struct wordfrequency *word2 = (struct wordfrequency *)b;
    return word2->frequency - word1->frequency;//combined comparison and return 
}

//analyse the frequency of the words in the file
//print out each word and its frequency
void analyse_file(FILE *textfile){
    char linefragment[10001];                   //Buffer for reading a line of text 
    char space[2] = " ";                      //Holds character that split occours on
    struct wordfrequency wordarray[MAX_WORDS];//Array that stores word frequency pairs 
    int numwords = 0; 

    while (fgets(linefragment, 10000, textfile)){
        char* token;                          //individual word tokens

        token = strtok(linefragment, space);  //Splits the string into tokens, spliting on spaces 

        while(token != NULL){
            char* filteredtoken = filter(token);//removes punctuation

            int found = 0; //flag word to check if it is in the array 
            for(int i=0; i < numwords; i++){
                if(strcmp(filteredtoken, wordarray[i].word) ==0){//If word in array 
                    wordarray[i].frequency++;//update frequency count
                    found = 1;//flag as in array 
                    break;//exit loop
                }
            }


            //If word is not in the array and there is space left
            if((found ==0) && (numwords < MAX_WORDS)){
                strcpy(wordarray[numwords].word, filteredtoken);//Copy the word into the array 

                wordarray[numwords].frequency = 1;//Set the frequency to one
                numwords++;//Update the number of word in the array
            }

            //Get next token 
            token = strtok(NULL, space);
        }
    }

    qsort(wordarray, numwords, sizeof(struct wordfrequency), frequencycompare);

    //Print out each word and its frequency
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


    //Note that this will only work if the files are in the same folder that the program is executed. Additionally, the names are fixed 
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

    return 0;
}

