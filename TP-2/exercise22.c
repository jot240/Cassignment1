#include "exchange.h"
#include <stdio.h>
#include <stdlib.h>

float **allocate_square_matrix(int dimension){
    float **matrix = (float **)malloc(dimension * sizeof(float *));
    int row;

    for (row = 0; row < dimension; row++){
        matrix[row] = (float *)malloc(dimension * sizeof(float));
    }
    return matrix;
}
void delete_matrix(float **matrix, int dimension){
    int row;
    for (row= 0; row <dimension; row++){
        free(matrix[row]);
    }
    free(matrix);
}
void populate_square_matrix(float **matrix, int dimension){
    int row;
    int column;
    for (row = 0; row < dimension; row++){
        for(column=0; column<dimension; column++){
            matrix[row][column]= 10*(float)rand()/((float)RAND_MAX);
            printf("%f ", matrix[row][column]);
        }
        printf("\n");
    }
    printf("\n");
}
void transpose_square_matrix(float **matrix, int dimension){
    int row;
    int column;
    for(row = 0; row<dimension; row++ ){
        for(column = row; column<dimension; column++ ){
            exchange(&matrix[row][column], &matrix[column][row]);
    
        }
        printf("\n");
    }
}
void print_matrix(float **matrix, int dimension){
    int row;
    int column;
    for (row = 0; row < dimension; row++){
        for(column=0; column<dimension; column++){
            printf("%f ", matrix[row][column]);
        }
        printf("\n");
    }
    printf("\n");
}
void matrix_routine(void){
    int dimension;
    printf("please specify dimension for nxn matrix\n");
    scanf("%d", &dimension);
    printf("you entered %d\n", dimension);
    float **my_matrix = allocate_square_matrix(dimension);
    populate_square_matrix(my_matrix,dimension);
    transpose_square_matrix(my_matrix, dimension);
    print_matrix(my_matrix, dimension);
    delete_matrix(my_matrix, dimension);

}
int main(void){
   matrix_routine();
  return 0;
}