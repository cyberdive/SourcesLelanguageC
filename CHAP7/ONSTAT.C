#include <stdio.h>
main()
{
     fonc();                           /*     1er appel de la fonction     */
     fonc();                          /*     2�me appel de la fonction     */
}
fonc()
{
     static int x = 1;
     printf("Appel no %d de fonc : la valeur de x est %d\n", x, x);
     x++;
}

