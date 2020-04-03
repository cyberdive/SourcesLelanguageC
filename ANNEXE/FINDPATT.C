	/*  Findpatt examine une ligne saisie d'au plus 128 caractäres et y recherche 
	     une certaine suite de caractäres, saisie elle aussi. On affiche le nombre 
	     d'occurrences de la chaåne recherchÇe, ainsi que la position de sa premiäre 
	     occurrence. La ligne Ö examiner est rangÇe dans un bloc de mÇmoire 
	     dynamique de 32 octets pour commencer, mais qui peut si besoin est àtre 
	     agrandi par pas de 32 octets.  */
	#include <stdio.h>                                     /*  printf, getchar  */
	#include <stdlib.h>                                /*  realloc, free, exit  */
	#include <string.h>                                             /*  strlen  */
	main()
	{
	   char *buffer = NULL;               /*  ptr vers bloc de mÇmoire dynamique  */
	   char pattern [17];                                 /*  texte Ö rechercher  */
	   unsigned b = 1, i, m, p;                        /*  variables de contrìle  */
	   unsigned first_occ = 0;                 /*  Flag pour premiäre occurrence  */
	   int c;                                    /*  buffer pour caractäre isolÇ  */
	   int occs = 0;                                      /*  nombre occurrences  */
	   int ok;                                     /*  Flag pour saisie correcte  */
	/***  allocation de mÇmoire pour la saisie  ***/
	   if ((buffer = (char *) realloc(buffer, b * 32)) == NULL)
	   {
	   printf("\n\nErreur d'allocation.");
	   exit(1);
	   }
	   printf("\033[2J");
	   printf("Le programme vÇrifie si une ligne saisie (128 caractäres maximum)\n"
	   "contient un certain texte.");
	   i = 0;
	   printf("\n\nSaisie :\n\n");
	   while ((c = getchar()) != '\n')                          /*  saisie ligne  */
	   {
	   buffer[ i ] = c;
	   if (i >= (b*32)-1)                     /*  si bloc de mÇmoire trop petit  */
	   {
	   b++;
	   if ((buffer = (char *) realloc(buffer, b*32)) == NULL)
	   {
	   printf("\n\nErreur d'allocation.");
	   exit(1);
	   }
	   }
	   i++;
	   }   /*  Fin while  */
	   buffer[ i ] = '\0';                                     /*  fin de saisie  */
	   if (strlen(buffer))                       /*  au moins un caractäre saisi  */
	   {
	   do
	   {
	   printf("\n\nTexte Ö chercher (16 caractäres maximum) :\n\n");
	   m = 0;
	   ok = 1;
	   while (m < 16  &&  (c = getchar()) != '\n')
	   {
	   pattern[m] = c;
	   if (m > strlen(buffer)-1)
	   {
	   printf("\n\nLe texte ne peut àtre plus grand que la ligne.");
	   ok = 0;
	   while (getchar() != '\n')
	   ;
	   break;
	   }
	   else if (m > 15)
	   {
	   printf("\n\nTexte trop long.");
	   ok = 0;
	   while (getchar() != '\n')
	   ;
	   }
	   m++;
	   }
	   } while (!ok);
	   /*********************  recherche  ***************************/
	   pattern[m] = '\0';                  /*  fin de saisie du texte Ö chercher  */
	   if (strlen(pattern))                  /*  le texte a au moins 1 caractäre  */
	   {
	   for (p = 0; p + strlen(pattern) <= strlen(buffer); p++)
	   {
	   for (i=p, m=0; pattern[m] != '\0' && buffer[ i ] == pattern[m]; i++, m++)
	   ;
	   if (pattern[m] == '\0')                                  /*  texte trouvÇ  */
	   {
	   if (!first_occ)
	   first_occ = p;                         /*  mÇmorise position occurrence 1  */
	   occs++;
	   }
	   }
	   if (first_occ)                                        /*  si texte trouvÇ  */
	   {
	   printf("\n\nLe texte est contenu %d fois en tout.", occs);
	   printf("\n\nOccurrence 1 : caractäre %d de la ligne :\n", first_occ+1);
	   for (i = 0; i < first_occ; i++)               /*  afficher texte jusqu'Ö  */
	   printf("%c", buffer[ i ]);                               /*  occurrence 1  */
	   for (i = first_occ; i < first_occ + strlen(pattern); i++)
	   printf("\033[7m%c", buffer[ i ]);               /*  met en Çvidence le texte 
	                                              par une sÇquence ESC (reverse)  */
	   printf("\033[0m%s", buffer + i);            /*  suite en affichage normal  */
	   }
	   else
	   printf("\n\nTexte non trouvÇ.");
	   }                                            /*  Fin if (strlen(pattern))  */
	   }                                             /*  Fin if (strlen(buffer))  */
	   free(buffer);
	}                                                              /*  Fin main  */


