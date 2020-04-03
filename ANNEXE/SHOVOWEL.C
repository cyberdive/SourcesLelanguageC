	/*  shovowel compte les fr‚quences des voyelles dans une saisie et les 
	     affiche sous forme de barres horizontales.  */
	
	#include <stdio.h>                          /*  pour printf, getchar, EOF  */
	
	main()
	   {
	   int c;
	   int k;                                        /*  variable de contr“le  */
	   int a = 0;
	   e = 0;
	   i = 0;                                       /*  compteurs de voyelles  */
	   o = 0;
	   u = 0;
	
	   printf("\033[2J");
	   printf("Entrez un caractŠre. Fin par <CTRL>+<Z>.\n");
	
	/*  compter les voyelles :  */
	
	      while ((c = getchar()) != EOF)
	         switch (c)
	            {
	               case 'a':
	               case 'A':   a++;
	                     break;
	
	               case 'e':
	               case 'E':   e++;
	                     break;
	
	               case 'i':
	               case 'I':   i++;
	                     break;
	
	               case 'o':
	               case 'O':   o++;
	
	                     break;
	               case 'u':
	               case 'U':   u++;
	            }
	/*  afficher les fr‚quences :  */
	
	      printf("\n\nA ");                        /*  afficher le nombre de a/A  */
	      for (k = 1; k <= a; k++)
			 printf("*");
	      printf("  %d", a);
	      printf("\n\nE ");                       /*  afficher le nombre de  e/E  */
	      for (k = 1; k <= e; k++)
			 printf("*");
	      printf("  %d", e);
	      printf("\n\nI ");                        /*  afficher le nombre de i/I  */
	      for (k = 1; k <= i; k++)
			 printf("*");
	      printf("  %d", i);
	      printf("\n\nO ");                        /*  afficher le nombre de o/O  */
	      for (k = 1; k <= o; k++)
			 printf("*");
	      printf("  %d", o);
	      printf("\n\nU ");                       /*  afficher le nombre de  u/U  */
	      for (k = 1; k <= u; k++)
	         printf("*");
	      printf("  %d", u);
	   }

