#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double *generate_x( double *x, double sd, double mean, int samples){
      
       double start = mean -  3 * sd;
       double increment = 6 * sd / (samples-1);
       for( int i = 0; i < samples; i++){
          x[i] = start + increment * i;
       }
       return(x);

}

double *generate_x_fx(double *x, double *x_fx, double sd, double mean, int samples){
  for(int i =0; i<samples; i++){
    x_fx[i] = x[i];
    double a =  (x[i]-mean)/sd;
    x_fx[i + samples] = ( 1 / ( sd * sqrt(2*M_PI) ) ) * exp( -0.5 * a * a ) ;
  }
  return(x_fx);
}
double *generate_data(double mean, double sd, int samples){
    double x_init[samples];
    double x_fx_init[samples*2];
    double *x =  generate_x(x_init, sd, mean, samples);
    double *x_fx=  generate_x_fx(x,x_fx_init, sd, mean, samples);

     for(int i =0; i <samples * 2; i++){
         printf("%f,", x_fx[i]);
     }
     printf("\n");
    return(x_fx);
}

void write_to_file(double *coords, int samples){
    FILE *fp;
    fp = fopen("plotdata.txt","w");
    for(int i=0; i<samples; i++){
        fprintf(fp, "%lf %lf\n", coords[i], coords[i+samples]);
    }
    fclose(fp);

  
}
int main(int argc, char* argv[]){
  if (argc == 4){

    double mean =atof(argv[1]); /* TODO accept user input*/
    double sd = atof(argv[2]);
    int samples = atoi(argv[3]);
    double *x_fx =generate_data(mean, sd, samples);
    write_to_file(x_fx, samples);
    system("gnuplot --persist -e 'plot \"plotdata.txt\"'");
  }
  else{
    printf("you need to supply a mean, standard deviation, and number of samples");
  }
  return(1);
}