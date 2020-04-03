/*  intmax calcule le plus grand chiffre d'un nombre de 5 chiffres  */
	
	#include <stdio.h>                                    /*  pour printf, scanf  */
	
	main()
	    {
	
	   short n1, n2, n3, n4, n5;                           /*  pour les chiffres  */
	       short maxint;                             /*  pour le chiffre maximal  */
	
	   printf("\033[2J");
	   printf("Entrez un entier de cinq chiffres : ");
	
	   /*  s‚paration des chiffres :  */
	   scanf("%1hd %1hd %1hd %1hd %1hd", &n1, &n2, &n3, &n4, &n5);
	
	   /*  calcul du maximum :  */
	   maxint = n1 > n2 ? n1 : n2;        /*  1er chiffre sup‚rieur au second ?  */
	
	   /*  on compare les autres chiffres avec maxint :  */
	   maxint = maxint > n3 ? maxint : n3;
	   maxint = maxint > n4 ? maxint : n4;
	   maxint = maxint > n5 ? maxint : n5;
	
	   printf("\nMaximum : %ld", maxint);                 /*  affiche le maximum  */
	}

