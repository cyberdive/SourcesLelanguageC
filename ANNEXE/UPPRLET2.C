	/*  upprlet2 transforme en majuscules toutes les minuscules d'une saisie  */
	
	#include <stdio.h>                              /*  getchar, printf, putchar  */
	
	main()
	   {
	      int c;
	
	      printf("\033[2J");
	      printf("Conversion des minuscules en majuscules.\n");
	      printf("Entrez du texte. Fin par <CTRL>+<Z>.\n\n");
	
	      while ((c = getchar()) != EOF)
	         {
	            if (c >= 'a' && c <= 'z')                       /*  si minuscule  */
	               putchar(c - 'a' + 'A');                /*  afficher majuscule  */
	            else if ( c == '„')                                 /*  si tr‚ma  */
	               putchar('Ž');
	            else if ( c == '”')
	               putchar('™');
	            else if ( c == '')
	               putchar('š');
	            else                                                   /*  sinon  */
	               putchar(c);                /*  afficher le caractŠre tel quel  */
	         }
	      }

