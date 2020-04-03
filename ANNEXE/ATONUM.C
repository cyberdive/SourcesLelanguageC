	/*  ATONUM convertit en la valeur num‚rique correspondante une suite de 
	     chiffres contenue dans un string. Si le string contient plusieurs 
	     suite de chiffres, seule la premiŠre est trait‚e.
	     Un point d‚cimal n'est donc pris comme tel que s'il se trouve … 
	     l'int‚rieur de la chaŒne des chiffres et non au d‚but ou … la fin de 
	     celle-ci.  */
	#include <stdio.h>                                          /*  gets, printf  */
	#include <conio.h>                                                /*  getche  */
	#include <stdlib.h>                                           /*  atol, atof  */
	#include <string.h>                                               /*  strlen  */
	main()
	{
	   char s [81];                                                   /*  buffer  */
	   char snum [81];                         /*  chaŒne de chiffres … extraire  */
	   union values                    /*  m‚morise le r‚sultat de la conversion  */
	   {
	   double d;                                           /*  comme nombre r‚el  */
	   long l;                                               /*  ou comme entier  */
	   } val;
	   int i;                                           /*  variable de contr“le  */
	   char reply = 'o';                                /*  variable de contr“le  */
	   int first;                                   /*  Index du premier chiffre  */
	   int floatflag;                                        /*  indique un r‚el  */
	   while ( reply == 'o')
	   {
	   printf("\033[2J");
	   printf("\n\nLe programme convertit une suite de chiffres contenue dans un "
	   "string en une valeur num‚rique.");
	   printf("\nEntrez une chaŒne contenant une suite de chiffres "
	   "(80 caractŠres au plus) :\n\n");
	   gets(s);
	/*  saute les caractŠres du d‚but qui ne sont pas des chiffres  */
	   i = 0;
	   while ((s[ i ] < 48  ||  s[ i ] > 57) && s[ i ] != '\0')
	   i++;
	   if (s[ i ])   /*  si il y a vraiment un chiffre  */
	   {
	   first = i;    /*  m‚morise index premier chiffre  */
	   floatflag = 0;     /*  initialise flag de r‚el : m‚moriser tous les chiffres 
	                                         ou seulement jusqu'au point d‚cimal  */
	   while ((s[ i ] > 47  &&  s[ i ] < 58)  &&  s[ i ] != '\0')
	   {
	   snum[i-first] = s[ i ];  /*  i-first : m‚morise depuis d‚but tableau snum  */
	   i++;
	   }
	   if (s[ i ] == '.')                                   /*  si point d‚cimal  */
	   {
	   floatflag = 1;
	   snum[i-first] = s[i++];                        /*  m‚morise point d‚cimal  */
	   while ((s[ i ] > 47  &&  s[ i ] < 58)  &&  s[ i ] != '\0')
	   {
	   snum[i-first] = s[ i ];                      /*  m‚morise autres chiffres  */
	   i++;
	   }
	   }
	   snum[i-first] = '\0';/*  termine la chaŒne des chiffres par caractŠre nul  */
	   if (floatflag)                                         /*  si nombre r‚el  */
	   {
	   val.d = atof(snum);
	   printf("\n\nLa valeur convertie est : %f", val.d);
	   }
	   else if (strlen(snum) > 9)
	   {
	   printf("\n\nLa chaŒne a trop de chiffres et ne peut ˆtre affich‚e sous forme entiŠre, mais sous forme r‚elle.\n");
	   val.d = atof(snum);
	   printf("\nLa valeur convertie est : %.0f", val.d);
	   }
	   else
	   {
	   val.l = atol(snum);
	   printf("\n\nLa valeur convertie est : %ld", val.l);
	   }
	   }                                                     /*  Fin if (s[ i ])  */
	   else
	   printf("\n\nLa chaŒne saisie ne contient aucun chiffre.");
	   printf("\n\nExtraction d'une autre suite de chiffres ? (o/n) ");
	   reply = getche();
	   }                                            /*  Fin while (reply == 'o')  */
	}

