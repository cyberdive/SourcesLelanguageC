	/*  tab affiche un tableau avec des valeurs d‚cimales,
	     octales et hexad‚cimales  */
	
	#include <stdio.h>                                         /*  pour printf  */
	main()
	{
	   printf("\tD‚cimal\t\tOctal\t\tHexad‚cimal\n\n");               /*  titre,  */
	   printf("\t%5d\t\t%4o\t\t%6X\n", 200, 200, 200);        /*  tabulations et  */
	   printf("\t%5d\t\t%4o\t\t%6X\n", 201, 201, 201);     /*  largeur minimales  */
	   printf("\t%5d\t\t%4o\t\t%6X\n", 202, 202, 202);          /*  pour aligner  */
	   printf("\t%5d\t\t%4o\t\t%6X\n", 203, 203, 203);            /*  les valeurs  */
	   printf("\t%5d\t\t%4o\t\t%6X\n", 204, 204, 204);          /*  sur le titre  */
	}


