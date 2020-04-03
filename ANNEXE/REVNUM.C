	/*  revnum lit un nombre entier de 4 chiffres, calcule la valeur obtenue en 
	     inversant les chiffres, puis affiche la somme des deux nombres  */
	
	#include <stdio.h>                                  /*  pour printf, scanf  */
	
	main()
	{
	       int x, xreverse;                         /*  le nombre et son inverse  */
	       int u, d, c, m;    /*  unit‚s, dizaines, centaines et milliers dans x  */
	   printf("\033[2J");
	   printf("Entrez un entier de 4 chiffres : ");
	       scanf("%d", &x);
	
	   m = x / 1000;                         /*  calcul du chiffres des milliers  */
	   c = x % 1000 / 100;                  /*  calcul du chiffres des centaines  */
	   d = x % 100 / 10;                     /*  calcul du chiffres des dizaines  */
	   u = x % 10;                             /*  calcul du chiffres des unit‚s  */
	
	   /*  inversion des chiffres de x :  */
	   xreverse = m + (10 * c) + (100 * d) + (1000 * u);
	   printf("\nL'inversion de %d donne %d.\n", x, xreverse);
	   printf("La somme des deux nombres vaut : %d", x + xreverse);
	}

