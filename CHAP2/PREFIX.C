= /*  prefix affiche des variables short, long et double  */
#include <stdio.h>
main()
{
   short s = 123;
   long l = 123456;
   double d = 0.123456789;
   printf("short :\t d‚c = %hd\t\t  unsigned = %hu\n\t"
   " oct = %ho\t\t  hex = %hx\n\n", 
   s, s, s, s);
   printf("long :\t d‚c = %ld\t\t  unsigned = %lu\n\t"
   " oct = %lo\t\t  hex = %lx\n\n",
   l, l, l, l);
   printf("double :\t normal = %lf\t  exponentiel = %le", d, d, d, d);
}
