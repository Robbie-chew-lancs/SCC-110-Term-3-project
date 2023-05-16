#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

    char mystring[101];
    char space[2] = " ";
    
    while (fgets(mystring, 100, textFile1)){
        char* token;

        token = strtok(mystring, space);

        while(token != NULL){
            int i = 0;
            int j = 0;
            char filtered[101];// string to hold the punctuationless version of the string

            while(token[i] != 0){
                if(!ispunct(token[i])){
                    filtered[j] = token[i]; // copy the character to the filtered string

                    j++;//moves the pointer one step down the filtered string. 
                }
                i++;
            }
            
            filtered[j] = '\n';
            printf("%s", filtered);
            token = strtok(NULL, space);
        }
    }

    while (fgets(mystring, 100, textFile2)){
        char* token;

        token = strtok(mystring, space);

        while(token != NULL){
            int i = 0;
            int j = 0;
            char filtered[101];// string to hold the punctuationless version of the string

            while(token[i] != 0){
                if(!ispunct(token[i])){
                    filtered[j] = token[i]; // copy the character to the filtered string

                    j++;//moves the pointer one step down the filtered string. 
                }
                i++;
            }
            
            filtered[j] = '\n';
            printf("%s", filtered);
            token = strtok(NULL, space);
        }
    }

    while (fgets(mystring, 100, textFile3)){
        char* token;

        token = strtok(mystring, space);

        while(token != NULL){
            int i = 0;
            int j = 0;
            char filtered[101];// string to hold the punctuationless version of the string

            while(token[i] != 0){
                if(!ispunct(token[i])){
                    filtered[j] = token[i]; // copy the character to the filtered string

                    j++;//moves the pointer one step down the filtered string. 
                }
                i++;
            }
            
            filtered[j] = '\n';
            printf("%s", filtered);
            token = strtok(NULL, space);
        }
    }

    while (fgets(mystring, 100, textFile4)){
        char* token;

        token = strtok(mystring, space);

        while(token != NULL){
            int i = 0;
            int j = 0;
            char filtered[101];// string to hold the punctuationless version of the string

            while(token[i] != 0){
                if(!ispunct(token[i])){
                    filtered[j] = token[i]; // copy the character to the filtered string

                    j++;//moves the pointer one step down the filtered string. 
                }
                i++;
            }
            
            filtered[j] = '\n';
            printf("%s", filtered);
            token = strtok(NULL, space);
        }
    }

    while (fgets(mystring, 100, textFile5)){
        char* token;

        token = strtok(mystring, space);

        while(token != NULL){
            int i = 0;
            int j = 0;
            char filtered[101];// string to hold the punctuationless version of the string

            while(token[i] != 0){
                if(!ispunct(token[i])){
                    filtered[j] = token[i]; // copy the character to the filtered string

                    j++;//moves the pointer one step down the filtered string. 
                }
                i++;
            }
            
            filtered[j] = '\n';
            printf("%s", filtered);
            token = strtok(NULL, space);
        }
    }
    
}