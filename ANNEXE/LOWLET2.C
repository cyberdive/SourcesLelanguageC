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
	            else if ( c == '�')                                 /*  si tr�ma  */
	               putchar('�');
	            else if ( c == '�')
	               putchar('�');
	            else if ( c == '�')
	               putchar('�');
	            else                                                   /*  sinon  */
	               putchar(c);                /*  afficher le caract�re tel quel  */
	               }
	            }

