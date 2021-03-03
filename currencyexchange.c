#include <stdio.h>
#include <stdlib.h>
void change_rates(float* euro_dollar, float* dollar_euro,  float* gbp_euro,float* euro_gbp, float* gbp_dollar, float* dollar_gbp){
 printf("changing rates. What would you like for euro to dollar conversion? currently it is %f\n", *euro_dollar);
 scanf("%f", euro_dollar);
 *dollar_euro = 1/ *euro_dollar;
printf("Then the dollar to euro is: %f\n", *dollar_euro );
printf("changing rates. What would you like for pound to dollar conversion? currently it is %f\n", *gbp_dollar);
 scanf("%f", gbp_dollar);
 *dollar_gbp = 1/ *gbp_dollar;
printf("Then the dollar to pound is: %f\n", *dollar_gbp );
printf("changing rates. What would you like for euro to pound conversion? currently it is %f\n", *euro_gbp);
 scanf("%f", euro_gbp);
 *gbp_euro = 1/ *euro_gbp;
printf("Then the pound to euro is: %f\n", *gbp_euro );

}
void exchange_rate_selection(float* euro_dollar, float* dollar_euro,  float* gbp_euro,float* euro_gbp, float* gbp_dollar, float* dollar_gbp, char* yesno){   
    printf("These are current conversion rates:\n euro to dollar %f\n  euro_gbp %f\n gbp_dollar %f\n  Do you wish to change it? y/n\n", *euro_dollar, *euro_gbp, *gbp_dollar);
    scanf("%c", yesno);
    if (*yesno =='y')
    {
       change_rates(euro_dollar, dollar_euro,  gbp_euro,euro_gbp, gbp_dollar, dollar_gbp);
    }
    else if(*yesno =='n'){
        printf("continuing with predefined rates. You're such an easy customer!");
    }
    else{
        printf("nooo! you did not select a correct input. Please start the program again");
        exit(0);
    }
    }


void change_currency(float* euro_dollar, float* dollar_euro,  float* gbp_euro,float* euro_gbp, float* gbp_dollar, float* dollar_gbp){
    char currency_selection;
    float amount;
    printf("Please select a conversion: (a)euro to dollar (b) dollar to euro (c) Pound to euro (d) euro to pound (e)pound to dollar (f) dollar to pound\n");
    scanf(" %c", &currency_selection);
    printf("select the amount you wish to change:\n");
    scanf("%f", &amount);
    if (currency_selection =='a')
    {
        printf("you have selected euro to dollar. your %f euros are worth %f dollars\n", amount, amount * (*euro_dollar));
    }
    else if (currency_selection == 'b'){
        printf("you have selected dollar to euro. your %f dollars are worth %f euros\n", amount, amount * (*dollar_euro));
    }
    else if (currency_selection == 'c'){
        printf("you have selected pound to euro. your %f pounds are worth %f euros\n", amount, amount * (*gbp_euro));
    }
    else if (currency_selection == 'd'){
        printf("you have selected euro to pound. your %f euros are worth %f pounds\n", amount, amount * (*euro_gbp));
    }
    else if (currency_selection == 'e'){
        printf("you have selected pound to dollar. your %f pounds are worth %f dollar\n", amount, amount * (*gbp_dollar));
    }
    else if (currency_selection == 'f'){
        printf("you have selected dollar to pound. your %f dollars are worth %f pounds\n", amount, amount * (*dollar_gbp));
    }
    else{
        printf("it appears you did not select an available option. please start the program again");
    }
    
}
void currency_conversion(void){
    float euro_dollar, dollar_euro, gbp_euro, euro_gbp, dollar_gbp, gbp_dollar;
    char yesno;
    euro_dollar = 1.21;
    dollar_euro = 1/euro_dollar;
    gbp_euro = 1.16;
    euro_gbp = 1/gbp_euro;
    gbp_dollar= 1.40;
    dollar_gbp = 1/gbp_dollar;
    exchange_rate_selection(&euro_dollar, &dollar_euro, &gbp_euro, &euro_gbp, &gbp_dollar, &dollar_gbp, &yesno);
    change_currency(&euro_dollar, &dollar_euro, &gbp_euro, &euro_gbp, &gbp_dollar, &dollar_gbp);

    
}


int main(void){
    currency_conversion();
    return(0);
}