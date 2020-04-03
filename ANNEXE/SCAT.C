	/*  Scat concatäne deux chaåne de caractäres saisies par l'utilisateur, de 
	     telle sorte que la seconde soit accrochÇe Ö la premiäre.  */
	#include <stdio.h>                                     /*  printf, getchar  */
	#include <conio.h>                                              /*  getche  */
	main()
	{
	   char first [161];                       /*  premiäre chaåne de caractäres  */
	   char second [81];                        /*  seconde chaåne de caractäres  */
	   int rep = 'o', i, k, ok;                        /*  variables de contrìle  */
	   int c;                                                         /*  buffer  */
	   while (rep == 'o')
	   {
	   printf("\033[2J");
	   printf("CONCATENATION DE CHAINES : chaåne2 accrochÇe Ö chaåne1\n\n");
	   printf("Longueur maximale de chaque chaåne : 80 caractäres.");
	   /***  saisie des chaånes  ************/
	   do
	   {
	   i = 0;
	   ok = 1;
	   printf("\n\nChaåne 1 : ");
	   while ((c = getchar()) != '\n')
	   {
	   *(first + i) = c;
	   if (i > 79)
	   {
	   printf("\n\nTrop de caractäres.");
	   ok = 0;
	   while (getchar() != '\n')   ;                 /*  vidage tampon de saisie  */
	   break;
	   }
	   i++;
	   }
	   } while (!ok);
	   *(first + i) = '\0';                           /*  ajout du caractäre nul  */
	   do
	   {
	   k = 0;
	   ok = 1;
	   printf("\n\nChaåne 2 : ");
	   while ((c = getchar()) != '\n')
	   {
	   *(second + k) = c;
	   if (k > 79)
	   {
	   printf("\n\nTrop de caractäres.");
	   ok = 0;
	   while (getchar() != '\n');                    /*  vidage tampon de saisie  */
	   break;
	   }
	   k++;
	   }
	   } while (!ok);
	   *(second + k) = '\0';                          /*  ajout du caractäre nul  */
	   /***  concatÇnation des chaånes  *******/
	   i = k = 0;
	   while ( *(first + i))                    /*  on recherche la fin de first  */
	   i++;
	   while ( *(first + i++) = *(second + k++))
	   ;
	   printf("\n\nLa concatÇnation donne la chaåne de caractäres :\n\n%s", first);
	   printf("\n\nAutre concatÇnation (o/n)");
	   rep = getche();
	   }                                                 /*  Fin while supÇrieur  */
	}                                                              /*  Fin main  */


