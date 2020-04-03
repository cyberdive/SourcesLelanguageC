	/*  bitpos d‚termine le nombre et les positions des bits activ‚s 
	     d'un nombre entier  */
	
	#include <stdio.h>                                         /*  printf, scanf  */
	
	main()
	   {
	      long entry;
	      unsigned long m = 1;      /*  masque binaire de type unsigned. Il ne faut 
	                            pas prendre de valeurs n‚gatives dans les d‚calages 
	                                     (surtout vers la droite) car les positions 
	                                laiss‚es libres sont remplies non par des z‚ros 
	                                         mais par des copies du bit de signe  */
	      int pos = 0;                        /*  compteur de positions binaires  */
	      int b = 0;                                        /*  compteur de bits  */
	      printf("\033[2J");
	      printf("Entrez un nombre entier : ");
	      scanf("%ld", &entry);
	      printf("\n\n");
	
	      while (m)                                /*  tant que m diff‚rent de 0  */
	      {
	      pos++;                                         /*  marquer la position  */
	      if (entry & m)                            /*  si bit activ‚ dans entry  */
	      {
	      b++;                                              /*  compter les bits  */
	      printf("Bit activ‚ … la position %d\t", pos);
	      if (b % 2 == 0)                            /*  afficher sur 2 colonnes  */
	      printf("\n");
	      }
	      m <<= 1;   /*  d‚caler les bits du masque d'une position vers la gauche 
	                                     afin de tester le prochain bit de entry  */
	      }
	      printf("\n\nNombre de bits activ‚s : %d", b);
	   }                                                   <+><+><+>
	                                                            /*  fin du main  */

