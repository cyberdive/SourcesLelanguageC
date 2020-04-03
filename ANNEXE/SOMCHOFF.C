	/*  somchiff lit un entier … 4 chiffres saisi par l'utilisateur et stocke
	    chaque chiffre dans une variable sp‚cifique afin de calculer et
	    d'afficher la somme de ces chiffres  */
	
	#include <stdio.h>                                  /*  pour scanf, printf  */
	
	main()
	{
	   short a, b, c, d;         /*  variables pour les chiffres du nombre saisi  */
	
	   printf("\033[2J");                                     /*  efface l'‚cran  */
	   printf("Entrez un entier de 4 chiffres : ");
	   scanf("%1hd %1hd %1hd %1hd", &a, &b, &c, &d);         /*  lit chaque chiffre 
	                                       et le range dans une variable sp‚ciale  */
	   printf("\nLa somme des chiffres du nombre est : %hd", a+b+c+d);  
	                                                        /*  affiche la somme  */
	}

