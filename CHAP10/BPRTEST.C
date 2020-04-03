/*** BPRTEST teste la fonction 'bprint' qui affiche en binaire des nombres  ***/
/*** entiers et accepte, ce fraisant, un nombre variable de paramätres.     ***/

#include <stdio.h>                                         /* printf, putchar */
#include <stdarg.h>                      /* va_list, va_start, va_arg, va_end */

main()
 {
   void bprint(char *fstring, ...);                /* dÇclaration de 'bprint' */
   short a = 3, b = 14534;
   long x = 7333333, y = -50000;
   
                                                  /* paramätre fixe seulement */
   bprint("Le programme affiche en binaire quelques valeurs de test :\n\n");
   bprint("3\t\t=\t%S\n\n", a);                      /* 1 paramätre optionnel */
                                                   /* 2 paramätres optionnels */
   
   bprint("14534\t\t=\t%S\n-50000\t\t=\t%L\n\n", b, y);
   
                                                   /* 3 paramätres optionnels */
   
   bprint("7333333 - 50000\t=\t%L\n14\t\t=\t%S\n-123\t\t=\t%S\n\n", x+y, 14, -123);
   bprint("%d%S\t%x%L", a, x);
 }

void bprint(char *fstring, ...)     /* affiche des entiers sous forme binaire */
 {
   va_list pp;                                        /* pointeur d'arguments */
   short s;
   long l;
   int pos;
   va_start(pp, fstring);        /* pointeur args = adr. 1er param. optionnel */
   while (*fstring)                          /* tant que pas de caractäre nul */
       {
         if (*fstring != '%')               /* si pas spÇcification de format */
            putchar(*fstring);                           /* affiche caractäre */
         else
            {
              switch(*++fstring)   /* caractäre suivant dans chaåne de format */
                {
                  case 'S': s = va_arg(pp, short);   /* va_arg donne un short */
                      for (pos = 15; pos >= 0; pos--)  /* afficher en binaire */
                          {
                            printf("%d", (s >> pos) & 1);
                            if (pos % 8 == 0)       /* espace tous les 8 bits */
                                printf(" ");
                          }
                      break;
                      
                  case 'L': l = va_arg(pp, long);     /* va_arg donne un long */
                      for (pos = 31; pos >= 0; pos--)  /* afficher en binaire */
                          {
                            printf("%d", (l >> pos) & 1);
                            if (pos % 8 == 0)       /* espace tous les 8 bits */
                                printf(" ");
                          }
                      break;
                      
                 default: putchar (*fstring);   
                                       /* pas de format apräs %: affiche car. */
                }                                               /* fin switch */
            }                                                     /* fin else */
         fstring++;                /* caractäre suivant dans chaåne de format */
       }                                                         /* fin while */
   va_end(pp);                               /* fin Çvaluation : NULL dans pp */
 }                                                              /* fin bprint */
