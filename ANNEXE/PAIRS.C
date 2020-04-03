	/*  pairs affiche toutes les paires possibles avec 10 joueurs  */
	
	#include <stdio.h>                                           /*  pour printf  */
	
	main()
	   {
	      int p, q;                                     /*  variable de contr“le  */
	      int z = 0;                                       /*  compte les paires  */
	
	      printf("\033[2J");
	      printf("Paires possible pour 10 joueurs A - J\n\n");
	      for (p = 'A'; p < 'K'; p++)                    /*  pour chaque joueur  */
	         {
	           for (q = p + 1; q < 'K'; q++)    /*  pour chaque adversaire dont la 
	                                                 lettre suit celle du joueur  */
	              {
	                 printf("%c:%c\t", p, q);              /*  afficher la paire  */
	                 z++;                                   /*  compter la paire  */
	              }
	           printf("\n\n");
	        }
	     printf("On doit organiser %d rencontres.", z);
	  }

