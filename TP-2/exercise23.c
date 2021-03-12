#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
enum CASETYPE{upper = 1, lower = 0};

char **break_up_string(char str[]){
    char **words;
    char delim[] = " ";
    return(words);
}
void change_case(char *input, int char_count){
    int i;
    enum CASETYPE selection;
    printf("Please choose if you want to change your string to lower-case(type 0) or upper-case (type 1).\n");
    scanf("%d", &selection);
    printf("%d", selection);
    if(selection == upper){
        printf("you selected upper\n");
        for(i = 0; i<char_count; i++){
            input[i] = toupper(input[i]);
        }
    }
    else if (selection == lower){       
        printf("you selected lower\n");
        for(i = 0; i<char_count; i++){
            input[i] = tolower(input[i]);
        }
    }
    else{
        printf("you did not make a correct selection\n");
        exit(0);
    }  
}


int read_input(char *input){
    int ch;
    int char_count;
    char_count = 0;
    while ( (ch = getchar()) !='\n')
        {
            char *temp = realloc(input, char_count + 1);
            input = temp;
            input[char_count++] = ch;
        }

        char *temp = realloc(input, char_count + 1);
        input = temp;
        input[char_count++] = '\0';
    free(temp);
    return(char_count);
}
void text_processor(void){
    char *input = malloc(1);
    int char_count;
    char **word_table;
    printf("Please give your text and press enter when you finish.\n");
    char_count = read_input(input);
    printf("\nHere is what I got: %s\n", input);
    change_case(input, char_count);
    printf("\nHere is what I got: %s\n", input);
    word_table = break_up_string(input);
    free(input);
    
}


int main(void){
    text_processor();
    return(0);
}