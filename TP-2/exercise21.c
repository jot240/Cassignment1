#include "exchange.h"
#include <stdio.h>
#include <stdlib.h>
void get_user_input( float *a, float *b){
    printf("please select a float value for a: \n");
    scanf("%f", a);
     printf("please select a float value for b: \n");
    scanf("%f", b);
    
}
void read_argv( char **argv, float *a, float *b){
    *a = atof(argv[1]) ;
    *b= atof(argv[2]);
}

void process_swap(int argc, char **argv){
    float a, b;
    printf("argc = %d\n", argc);
    if(argc == 3){
       read_argv(argv, &a, &b);
    }
    else if (argc ==1){
        printf("Looks like you need to input some values\n");
        get_user_input(&a, &b);
    }
    else{
        printf("Error. Please input exactly two floats to swap. Or zero.\n");
        exit(0);
    }
    
    printf("a is %f b is %f\n", a, b);
    exchange(&a, &b);
    printf("a is now %f b is now %f", a ,b);

}
int main(int argc, char **argv){
   process_swap(argc, argv);
  return 0;

}