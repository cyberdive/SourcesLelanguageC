/*** SORTRND2 range des nombres al‚atoires dans un tableau et ***/
/*** trie un sous-tableau choisi au hasard                    ***/

#include <stdio.h>                                                  /* printf */
#include <stdlib.h>                                            /* rand, srand */
#include <conio.h>                                                   /* getch */

#define ESC 27

main()
  {
     void bsort(short *start, short *end);
     void fill(short *a, unsigned n);
     void shownorm(short *a, unsigned n);
     void showinv(short *a, unsigned n, unsigned first, unsigned last);
     
     short nums[80];                       /* tableau pour nombres al‚atoires */
     unsigned x, y;                                 /* coordonn‚es al‚atoires */
     unsigned seed = 0;        /* valeur initiale pour rand (param. de srand) */
     int rep;                                         /* variable de contr“le */
     
     do
       {
         printf("\033[2J");
         printf("Le programme a produit les nombres al‚atoires suivants :\n\n");
     
         srand(++seed);                      /* initialise la fonction 'rand' */
         if (seed > 65534)              /* r‚initialise 'seed' afin de ne pas */
             seed = 0;                         /* d‚border des 'unsigned int' */
             fill(nums, 80);                        /* remplissage du tableau */
             shownorm(nums, 80);                  /* affiche tableau non tri‚ */
         
         do                            /* s‚lection al‚atoire du sous-tableau */
           {
             x = rand() % 80;         /* cr‚e nb. al‚atoire entre 0 et 79 qui */
                                            /* donne le d‚but du sous-tableau */
             y = rand() % 80;             /* idem pour la fin du sous-tableau */
             
           } while(x >= y);               /* premier index doit ˆtre < second */
  
         printf("\n\nLe sous-tableau … trier commence … la position %u"
                " et finit … la position %u :\n\n", x+1, y+1);
         bsort(&nums[x], &nums[y]);                    /* tri du sous-tableau */
         showinv(nums, 80, x, y);                /* affichage du tableau tri‚ */
         printf("\n\n<Entr‚e> pour continuer. Fin par <ECHAP>:");
         rep = getch();
         
       } while(rep != ESC);
  }

/*******  fonction de tri ********/

void bsort(short *start, short *end)
  {
     void swapshort(short *x, short *y);
     int i, k;
     
     for (i = end-start; i != 0; i--)
          for (k = 0; k < i; k++)
               if(start[k] > start[k+1])
                  swapshort(&start[k], &start[k+1]);
                  
  }

/*******  fonction de remplissage  ********/

void fill(short *a, unsigned n)
  {
     unsigned i;

     for (i = 0; i < n; i++)
          a[i] = rand();

  }

/***  fonction d'affichage normal **/

void shownorm(short *a, unsigned n)
  {
     unsigned i;
 
     for (i = 0; i < n; i++)
         {
           printf("%5hd  ", a[i]);
           if ((i+1)%10 == 0 && i != n-1)                      /* 10 colonnes */
               printf("\n");
         }
  }

/*** fonction d'affichage invers‚ ***/
void showinv(short *a, unsigned n, unsigned first, unsigned last)
  {
     unsigned i;
 
     for (i = 0; i < n; i++)
         {
           if (i >= first && i <= last)
              printf("\033[7m%5hd  ", a[i]); 
                                        /* sous-tableau tri‚ en inverse vid‚o */
           else
              printf("\033[0m%5hd  ", a[i]);  /* le reste en affichage normal */
          
           if (last == 79)                     /* remettre l'affichage normal */
              printf("\033[0m");       /* si inversion va jusqu'… fin tableau */
   
           if ((i+1)%10 == 0 && i != n-1)                      /* 10 colonnes */
              printf("\n");
              
         }
  }

/*******  fonction de permutation ********/

void swapshort(short *x, short *y)
  {
     short buffer;
     buffer = *x;
     *x = *y;
     *y = buffer;
  }
