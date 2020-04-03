	/*  exerc2 affiche deux chaånes de caractäres apräs avoir effacÇ l'Çcran  */

	#include <stdio.h>                                         /*  pour printf  */

	main()
	{

	   printf("\033[2J");                                /*  sÇquence d'Çchappement
	                                                        pour effacer l'Çcran  */

	   printf("Ceci est un essai.\n\n\n\n");          /*  4 sauts de lignes donnent
	                                                              3 lignes vides  */
	   printf("***   FIN DU PROGRAMME   ***");
	}

