	/*  evenmax lit un entier de 5 chiffres et d‚termine son plus
	     grand chiffre pair  */
	#include <stdio.h>                                  /*  pour printf, scanf  */
	
	main()
	    {
	     short n1, n2, n3, n4, n5;                         /*  pour les chiffres  */
	         short maxeven;                  /*  pour le plus grand chiffre pair  */
	
	   printf("\033[2J");
	   printf("Entrez un entier de cinq chiffres : ");
	
	   /*  s‚paration des chiffres :  */
	   scanf("%1hd %1hd %1hd %1hd %1hd", &n1, &n2, &n3, &n4, &n5);
	
	   /*  d‚termine le plus grand chiffre pair :  */
	   maxeven = !(n1 % 2) ? n1 : 0;     /*  si premier chiffre pair : m‚moriser  */
	
	   /*  si second chiffre pair et plus grand que maxeven : m‚moriser  */
	   maxeven = !(n2 % 2) && n2 > maxeven ? n2 : maxeven;
	
	   /*  si chiffre 3 pair ...  */
	   maxeven = !(n3 % 2) && n3 > maxeven ? n3 : maxeven;
	
	   *  si chiffre 4 pair ...  */
	   maxeven = !(n4 % 2) && n4 > maxeven ? n4 : maxeven;
	
	   /*  si dernier chiffre pair ...  */
	   maxeven = !(n5 % 2) && n5 > maxeven ? n5 : maxeven;
	
	   printf("\nPlus grand chiffre pair : %hd", maxeven);
	}

