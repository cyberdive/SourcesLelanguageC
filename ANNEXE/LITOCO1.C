	/*  LITOCO1 permute (… l'affichage seulement) les lignes et les colonnes d'un 
	     tableau 2D.  */
	#include <stdio.h>                                          /*  printf, puts  */
	main()
	{
	   char message [4] [5] = {"RATE", "YOUR", "MIND", "PALS"};
	   int i, k;
	   printf("\033[2J");
	   printf("\n\nStrings en horizontal :\n\n");
	   for (i = 0; i < 4; i++)
	   {
	   for (k = 0; k < 4; k++)
	   printf("%c ", message[ i ][k]);
	   printf("\n");
	   }
	   printf("\n\nStrings en vertical :\n\n");
	   for (i = 0; i < 4; i++)
	   {
	   for (k = 0; k < 4; k++)
	   printf("%c ", message[k][ i ]);
	   printf("\n"); 
	   }
	}

