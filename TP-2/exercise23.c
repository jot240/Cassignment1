#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
enum CASETYPE{upper = 1, lower = 0};

void print_list_info(char **word_table, int string_count){
    int word;
    float summation = 0;
    float average;
    printf("THis is the string count %d\n", string_count);
    for (word = 0; word<string_count; word++){
        printf("\n'%s' has length %d\n", word_table[word], strlen(word_table[word]));
        summation += (float) strlen(word_table[word]);
    }
    average = summation ;
    printf("The total number of words is %d and the average\number of letters per word is %f\n", string_count, average);
}

char **break_up_string(char str[], int *word_count){
    char **words =  NULL;
    char *token;
    int count = 0;
    int i;
    char delim[] = " ";
    token = strtok(str, delim);
    do
    {
        words = (char**)realloc(words, (count+1)*sizeof(*words));
        words[count] = (char*)malloc(sizeof(token));
        strcpy(words[count], token);
        printf("\n This is the word%s\n", words[count]);
        count++;
    } while ((token = strtok(NULL, delim))!= NULL);
    *word_count = count;
      for (int word = 0; word< *word_count; word++){
        printf("\n'%s' has length %d\n", words[word], strlen(words[word]));
    }
    return(words);
  
}
void change_case(char *input, int char_count){
    int i;
    enum CASETYPE selection;
    printf("Please choose if you want to change your string to lower-case(type 0) or upper-case (type 1).\n");
    scanf("%d", &selection);

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
void delete_stringlist(char **matrix, int dimension){
    int row;
    for (row= 0; row <dimension; row++){
        free(matrix[row]);
    }
    free(matrix);
}

char *read_input( int *count_length){
    int ch;
    int i;
    char *input = malloc(1);
    int char_count;
    char_count = 0;
    while ( (ch = getchar()) !='\n' && ch != EOF)
        {
            char *temp = realloc(input, (char_count + 1) * 1);
            input = temp;
            input[char_count++] = ch;
        }
        char *temp = realloc(input, char_count + 1);
        input = temp;
        input[char_count++] = '\0';

        *count_length = char_count;
    return(input);
}
void text_processor(void){
    int i;
    char *user_text;
    int char_count;
    int word_count;
    char **word_table;
    printf("Please give your text and press enter when you finish.\n");
    user_text = read_input(&char_count);
 
    printf("\nHere is what I got:  \n");
       for(i = 0; i<char_count; i++){
            putchar(user_text[i]);
        }
    printf("\n") ;  
    change_case(user_text, char_count);
    printf("\n Here is the processed text: \n") ;
     for(i = 0; i<char_count; i++){
            putchar(user_text[i]);
        }
    printf("\n") ;
    word_table = break_up_string(user_text, &word_count);

    print_list_info(word_table, word_count);
    free(user_text);
    delete_stringlist(word_table, word_count);
}


int main(void){
    text_processor();
    return(0);
}