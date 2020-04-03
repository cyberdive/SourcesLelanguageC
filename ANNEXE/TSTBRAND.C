	/*  TSTBRAND teste le g‚n‚rateur al‚atoire 'brand' qui produit des nombres 
	     compris entre deux nombres p et q.  */
	#include <stdio.h>
	#include <stdlib.h>                                        /*  srand, rand  */
	#include <time.h>                                                 /*  time  */
	main()
	{
	   int brand(int p, int q);
	   long sec;
	   int i, h;
	   int freq[10] = {0};                                        /*  fr‚quences  */
	   time(&sec);                                         /*  heure en secondes  */
	   srand((unsigned) sec);                                /*  initialise rand  */
	   for (i = 0; i < 10000; i++)
	   {
	   h = brand(90, 99) % 10;             /*  pour se d‚barrasser des d‚cimales  */
	   freq[h] = freq[h] + 1;         /*  totalisation de la fr‚quence du nombre  */
	   }
	   printf("\n\nR‚partition des fr‚quence ;\n\n");
	   for (i = 0; i < 10; i++)
	   printf("%6d", 90+i);
	   printf("\n\n");
	   for (i = 0; i < 10; i++)
	   printf("%6d", freq[ i ]);
	   }
	int brand(int p, int q)            /*  g‚nŠre des nb al‚atoires entre p et q  */
	{
	   return (p + (rand() % (q-p+1)));
	}


