/* showexpr montre comment utiliser une affectation comme argument de printf */
#include <stdio.h>                                          /*  pour printf  */
main()
{
     int x = 0;
     printf("%d ", x=2);           /*     affectation x=2 comme argument     */
     printf("%d ", x);             /*     variable x comme argument          */
     printf("%d", 2);              /*     constante 2 comme argument         */
}
