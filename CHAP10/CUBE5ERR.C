/*** cube5err montre l'effet de d‚clarations de fonctions mal positionn‚es ***/

#include <stdio.h>

main()
  {
     double first(void);
     double second(double x);
     printf("\nVolume = %f", first());
  }

double first(void) 
  {
     double e;
     printf("Longueur de l'arˆte : ");
     scanf("%lf", &e);
     return (second(e));
  }

double second(double x)
  {
     return (x * x * x);
  }  
