	/*  exerc2 affiche deux cha�nes de caract�res apr�s avoir effac� l'�cran  */

	#include <stdio.h>                                         /*  pour printf  */

	main()
	{

	   printf("\033[2J");                                /*  s�quence d'�chappement
	                                                        pour effacer l'�cran  */

	   printf("Ceci est un essai.\n\n\n\n");          /*  4 sauts de lignes donnent
	                                                              3 lignes vides  */
	   printf("***   FIN DU PROGRAMME   ***");
	}

