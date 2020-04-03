#include <stdio.h>
main()
{
     fonc();                           /*     1er appel de la fonction     */
     fonc();                          /*     2Šme appel de la fonction     */
}
fonc()
{
     int x = 1;
     printf("Appel no %d de fonc : la valeur de x est %d\n", x, x);
     x++;
}

