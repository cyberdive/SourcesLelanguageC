/*** BPRTEST teste la fonction 'bprint' qui affiche en binaire des nombres  ***/
/*** entiers et accepte, ce fraisant, un nombre variable de param�tres.     ***/

#include <stdio.h>                                         /* printf, putchar */
#include <stdarg.h>                      /* va_list, va_start, va_arg, va_end */

main()
 {
   void bprint(char *fstring, ...);                /* d�claration de 'bprint' */
   short a = 3, b = 14534;
   long x = 7333333, y = -50000;
   
                                                  /* param�tre fixe seulement */
   bprint("Le programme affiche en binaire quelques valeurs de test :\n\n");
   bprint("3\t\t=\t%S\n\n", a);                      /* 1 param�tre optionnel */
                                                   /* 2 param�tres optionnels */
   
   bprint("14534\t\t=\t%S\n-50000\t\t=\t%L\n\n", b, y);
   
                                                   /* 3 param�tres optionnels */
   
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
   while (*fstring)                          /* tant que pas de caract�re nul */
       {
         if (*fstring != '%')               /* si pas sp�cification de format */
            putchar(*fstring);                           /* affiche caract�re */
         else
            {
              switch(*++fstring)   /* caract�re suivant dans cha�ne de format */
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
                                       /* pas de format apr�s %: affiche car. */
                }                                               /* fin switch */
            }                                                     /* fin else */
         fstring++;                /* caract�re suivant dans cha�ne de format */
       }                                                         /* fin while */
   va_end(pp);                               /* fin �valuation : NULL dans pp */
 }                                                              /* fin bprint */
