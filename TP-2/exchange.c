#include "exchange.h"
#include <stdio.h>

void exchange(float *a, float *b){
    float holder;
    holder = *a;
    *a = *b;
    *b = holder;
    

}


