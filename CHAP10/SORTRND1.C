/*** SORTRND1 range des nombres al‚atoires dans un tableau 'short', ***/
/*** trie le tableau en ordre croissant et l'affiche                ***/

#include <stdio.h>                                                  /* printf */
#include <stdlib.h>                                                   /* rand */

main()
  {
     void bsort(short *arr, int elements);
     short n[10];
     int i;

     printf("\033[2J");
     printf("Le programme a choisi les nombres al‚atoires suivants : \n\n");
     for (i = 0; i < 10; i++)            /* g‚n‚ration des nombres al‚atoires */
          {
            n[i] = rand();
            printf("%hd  ", n[i]);
          }
     
     bsort(n, 10);                      /* tri du tableau : call by reference */
     printf("\n\nVoil… les nombres tri‚s :\n\n");
     
     for (i = 0; i < 10; i++)                              /* affiche tableau */
          printf("%hd  ", n[i]);
  }

/*******  fonction de tri  ********/

void bsort(short *arr, int elements)
  {
     void swapshort(short *x, short *y);
     int i, k;
     
     for (i = elements-1; i != 0; i--)
          for (k = 0; k < i; k++)
               if(arr[k] > arr[k+1])
                   swapshort(&arr[k], &arr[k+1]);
  }

/*******  fonction de permutation  ********/

void swapshort(short *x, short *y)
  {
     short buffer;
     buffer = *x;
     *x = *y;
     *y = buffer;
  }
