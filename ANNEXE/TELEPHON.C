	/*  telephon lit un indicatif de 4 chiffres et un num‚ro de 6 chiffres
	     selon un certain format, puis affiche le tout avec un autre format  */
	
	#include <stdio.h>                                  /*  pour printf, scanf  */
	
	main()
	{
	   int ind;                                             /*  pour l'indicatif  */
	   long num;                             /*  long car le num‚ro a 6 chiffres  */
	
	   printf("\033[2J");                                     /*  efface l'‚cran  */
	
	   printf("Entrez un num‚ro … 6 chiffres "
	     "avec un indicatif sur 4 chiffres \n"
	     "selon le modŠle suivant :   0iii/nnnnnn\n");
	
	   scanf("%d/%ld", &ind, &num); /*  saisie avec le caractŠre additionnel "/"  */
	   printf("\nLe num‚ro saisi est : (%04d) %ld", ind, num); 
	                                        /*  si le premier chiffre de l'indicatif 
	                                       est 0, %04d assure qu'il sera affich‚  */
	}

