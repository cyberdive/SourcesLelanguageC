	/*  valform affiche des valeurs formatÇes de diverse maniäre  */
	
	#include <stdio.h>                                         /*  pour printf  */
	
	main()
	{
	   int i = 98;
	   int num;                /*  pour rÇcupÇrer le nombre de caractäres saisis  */
	   double d = 765.4321;
	
	   printf("Affichage de la variable i :\n");
	   printf("%05d\n%c\n%5d%n", i, i, i, &num);
	
	             /*  Affiche i avec trois zÇros de tàte, puis en tant que caractäre 
	                             et enfin avec des espaces de tàte. La variable num 
	                             mÇmorise les caractäres affichÇs comptÇs par %n.  */
	
	   printf("\nOn a affichÇ %d caractäres.\n\n\n", num);      /*  13 caractäres : 
	                                        11 pour les variables et 2 <EntrÇe>  */
	
	   printf("Affichage de la variable double d :\n");
	   printf("%f\n", d);                                      /*  format normal  */
	   printf("%.4f\n", d);                      /*  4 chiffres apräs la virgule  */
	   printf("%.2f\n", d);                      /*  2 chiffres apräs la virgule  */
	   printf("%#.0f\n", d);                     /*  sans chiffre apräs la virgule, 
	                                             avec point dÇcimal Ö cause du #  */
	   printf("%.f\n", d);                     /*  sans chiffre apräs la virgule et 
	                                                          sans point dÇcimal  */
	   printf("%.2E\n", d);                  /*  format exponentiel avec 2 chiffres 
	                                                            apräs la virgule  */
	   printf("%e\n", d);                                    /*  format standard  */
	   printf("\nAffichage de la chaåne :\n");
	   printf("%.1s\n", "C_IS_FUN");        /*  n'affiche que la premiäre lettre  */
	   printf("%5.4s\n", "C_IS_FUN");                /*  4 premiers caractäres avec 
	                                                            un espace devant  */
	   printf("%10s\n", "C_IS_FUN");                  /*  toutes les lettres avec 2 
	                                                              espaces devant  */
	   printf("%7.4s\n", "C_IS_FUN");                /*  4 premiäres lettres avec 3 
	                                                              espaces devant  */
	   printf("%5.1s\n", "C_IS_FUN");  /*  premiäre lettre avec un espace devant  */
	}

