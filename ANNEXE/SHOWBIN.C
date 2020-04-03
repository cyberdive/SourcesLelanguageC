	/*  showbin affiche un nombre entier sous forme binaire  */
	
	#include <stdio.h>                                         /*  printf, scanf  */
	
	main()
	   {
	      long entry;
	      int p;   /*  compteur pour positions binaires  */
	      printf("\033[2J");
	      printf("Entrez un nombre entier : ");
	      scanf("%ld", &entry);
	      for(p = 31; p >= 0; p--)                           /*  pour chaque bit  */
	      {
	         printf("%d", (entry >> p) & 1);                 /*  afficher le bit  */
	         if (p % 8 == 0)                                 /*  tous les 8 bits  */
	         printf(" ");                    /*  ins‚rer un espace de s‚paration  */
	      } 
	   }

