	/*  lowrlet2 transforme en minuscules toutes les majuscules d'une saisie  */
	
	#include <stdio.h>                              /*  getchar, printf, putchar  */
	
	main()
	   {
	      int c;
	
	      printf("\033[2J");
	      printf("Conversion des majuscules en minuscules.\n");
	      printf("Entrez du texte. Fin par <CTRL>+<Z>.\n\n");
	      while ((c = getchar()) != EOF)
	         {
	            if (c >= 'A'  &&  c <= 'Z')                     /*  si majuscule  */
	               putchar(c + 'a' - 'A');                /*  afficher minuscule  */
	            else if ( c == 'Ž')                                 /*  si tr‚ma  */
	               putchar('„');
	            else if ( c == '™')
	               putchar('”');
	            else if ( c == 'š')
	               putchar('');
	            else                                                   /*  sinon  */
	               putchar(c);                /*  afficher le caractŠre tel quel  */
	               }
	            }

