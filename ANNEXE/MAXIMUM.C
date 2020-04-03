	/*  maximum calcule le maximum de deux nombres saisis au clavier  */
	#include <stdio.h>                                  /*  pour printf, scanf  */
	
	main()
	{
	   long x, y;                         /*  pour d'‚ventuelles valeurs ‚lev‚es  */
	
	   printf("\033[2J");                                     /*  efface l'‚cran  */
	   printf("Entrez deux nombres entiers.\n");
	   printf("Confirmez votre saisie par <Entr‚e> :\n");
	   scanf("%ld %ld", &x, &y);
	   printf("\nLa plus grande des deux valeurs est : %ld", x >y ? x:y);
	}

