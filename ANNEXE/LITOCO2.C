	/*  LITOCO2 permute les lignes et les colonnes d'un tableau 2D.  */
	#include <stdio.h>                                          /*  printf, puts  */
	main()
	{
	   char horizontal [4] [5] = {"RATE", "YOUR", "MIND", "PALS"};
	   char vertical [4] [5] = {'\0'};
	   int i, k;
	   printf("\033[2J");
	   printf("\n\nStrings en horizontal :\n\n");
	   for (i = 0; i < 4; i++)
	   puts(horizontal[ i ]);
	   for (i = 0; i < 4; i++)
	   for (k = 0; k < 4; k++)
	   vertical[k][ i ] = horizontal[ i ][k];
	   printf("\n\nStrings en vertical :\n\n");
	   for (i = 0; i < 4; i++)
	   puts(vertical[ i ]);
	}

