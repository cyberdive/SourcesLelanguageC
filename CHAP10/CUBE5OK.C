/***  cube5ok montre comment bien placer les d‚clarations de fonctions  ***/

#include <stdio.h>

main()
  {
     double first(void);
     printf("\nVolume = %f", first());
  }

double first(void) 
  {
     double e;
     double second(double x);
     printf("Longueur de l'arˆte : ");
     scanf("%lf", &e);
     return (second(e));
  }
 
 double second(double x)
  {
     return (x * x * x);
  }
