/** typerr montre quelques erreurs de type sur les param�tres des fonctions **/

#include <stdio.h>

main()
  {
     void func(int i);       /* d�claration de la fonction 'func' (prototype) */
     double d = 3.14;
     func(d);             /* appel de 'func' avec un param�tre de type erron� */
  }

void func(int i)                          /* d�finition de la fonction 'func' */
  {
     printf("%d", i);
  }
