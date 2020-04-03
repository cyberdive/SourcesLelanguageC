	/*  CHIFTONR transforme des chiffres saisies comme caractŠres 
	     en les nombres correspondants  */
	
	#include <stdio.h>                         /*  pour printf, scanf, getchar  */
	main()
	  {
	   char n1, n2;                             /*  m‚morise les chiffres saisis  */
	
	   printf("\033[2J");                                     /*  efface l'‚cran  */
	   printf("Chiffre 1: ");
	       scanf("%c", &n1);
	
	       getchar();                    /*  vide le tampon de lecture : <Entr‚e> 
	                                                    sur la saisie pr‚c‚dente  */
	
	       printf("Chiffre 2: ");
	       scanf("%c", &n2);
	   printf("%d\n", n1 + n2);      /*  "Somme" des caractŠres, c'est … dire somme 
	                                              des valeurs ASCII des chiffres  */
	   printf("%d\n", n1-'0' + n2-'0');                    /*  Somme des nombres  */
	}

