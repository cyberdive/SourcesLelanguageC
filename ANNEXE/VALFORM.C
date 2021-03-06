	/*  valform affiche des valeurs format�es de diverse mani�re  */
	
	#include <stdio.h>                                         /*  pour printf  */
	
	main()
	{
	   int i = 98;
	   int num;                /*  pour r�cup�rer le nombre de caract�res saisis  */
	   double d = 765.4321;
	
	   printf("Affichage de la variable i :\n");
	   printf("%05d\n%c\n%5d%n", i, i, i, &num);
	
	             /*  Affiche i avec trois z�ros de t�te, puis en tant que caract�re 
	                             et enfin avec des espaces de t�te. La variable num 
	                             m�morise les caract�res affich�s compt�s par %n.  */
	
	   printf("\nOn a affich� %d caract�res.\n\n\n", num);      /*  13 caract�res : 
	                                        11 pour les variables et 2 <Entr�e>  */
	
	   printf("Affichage de la variable double d :\n");
	   printf("%f\n", d);                                      /*  format normal  */
	   printf("%.4f\n", d);                      /*  4 chiffres apr�s la virgule  */
	   printf("%.2f\n", d);                      /*  2 chiffres apr�s la virgule  */
	   printf("%#.0f\n", d);                     /*  sans chiffre apr�s la virgule, 
	                                             avec point d�cimal � cause du #  */
	   printf("%.f\n", d);                     /*  sans chiffre apr�s la virgule et 
	                                                          sans point d�cimal  */
	   printf("%.2E\n", d);                  /*  format exponentiel avec 2 chiffres 
	                                                            apr�s la virgule  */
	   printf("%e\n", d);                                    /*  format standard  */
	   printf("\nAffichage de la cha�ne :\n");
	   printf("%.1s\n", "C_IS_FUN");        /*  n'affiche que la premi�re lettre  */
	   printf("%5.4s\n", "C_IS_FUN");                /*  4 premiers caract�res avec 
	                                                            un espace devant  */
	   printf("%10s\n", "C_IS_FUN");                  /*  toutes les lettres avec 2 
	                                                              espaces devant  */
	   printf("%7.4s\n", "C_IS_FUN");                /*  4 premi�res lettres avec 3 
	                                                              espaces devant  */
	   printf("%5.1s\n", "C_IS_FUN");  /*  premi�re lettre avec un espace devant  */
	}

