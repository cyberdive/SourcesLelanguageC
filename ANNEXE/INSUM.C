	/*  insum lit 3 entiers sous forme de somme non calcul‚e,
	     puis affiche le total calcul‚ ainsi que le nombre de caractŠres saisis  */
	
	#include <stdio.h>                                  /*  pour scanf, printf  */
	
	main()
	{
	   long x, y, z;        /*  type long au cas o— on entre des valeurs ‚lev‚es  */
	   int num;                           /*  pour compter les caractŠres saisis  */
	
	   printf("\033[2J");                                     /*  efface l'‚cran  */
	   printf("Entrez 3 entiers sous la forme \n");
	   printf("        a+b+c\n");
	   printf("et validez la saisie par <Entr‚e> :\n");
	
	   scanf("%ld+%ld+%ld%n", &x, &y, &z, &num);       /*  lecture des 3 valeurs et 
	            m‚morisation dans la variable num du nombre de caractŠres saisis  */
	
	   printf("\nLa somme de vos nombres est : %ld\n", x+y+z);
	   printf("Vous avez saisi %d caractŠres.", num);
	   }

