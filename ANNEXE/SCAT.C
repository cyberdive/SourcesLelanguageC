	/*  Scat concat�ne deux cha�ne de caract�res saisies par l'utilisateur, de 
	     telle sorte que la seconde soit accroch�e � la premi�re.  */
	#include <stdio.h>                                     /*  printf, getchar  */
	#include <conio.h>                                              /*  getche  */
	main()
	{
	   char first [161];                       /*  premi�re cha�ne de caract�res  */
	   char second [81];                        /*  seconde cha�ne de caract�res  */
	   int rep = 'o', i, k, ok;                        /*  variables de contr�le  */
	   int c;                                                         /*  buffer  */
	   while (rep == 'o')
	   {
	   printf("\033[2J");
	   printf("CONCATENATION DE CHAINES : cha�ne2 accroch�e � cha�ne1\n\n");
	   printf("Longueur maximale de chaque cha�ne : 80 caract�res.");
	   /***  saisie des cha�nes  ************/
	   do
	   {
	   i = 0;
	   ok = 1;
	   printf("\n\nCha�ne 1 : ");
	   while ((c = getchar()) != '\n')
	   {
	   *(first + i) = c;
	   if (i > 79)
	   {
	   printf("\n\nTrop de caract�res.");
	   ok = 0;
	   while (getchar() != '\n')   ;                 /*  vidage tampon de saisie  */
	   break;
	   }
	   i++;
	   }
	   } while (!ok);
	   *(first + i) = '\0';                           /*  ajout du caract�re nul  */
	   do
	   {
	   k = 0;
	   ok = 1;
	   printf("\n\nCha�ne 2 : ");
	   while ((c = getchar()) != '\n')
	   {
	   *(second + k) = c;
	   if (k > 79)
	   {
	   printf("\n\nTrop de caract�res.");
	   ok = 0;
	   while (getchar() != '\n');                    /*  vidage tampon de saisie  */
	   break;
	   }
	   k++;
	   }
	   } while (!ok);
	   *(second + k) = '\0';                          /*  ajout du caract�re nul  */
	   /***  concat�nation des cha�nes  *******/
	   i = k = 0;
	   while ( *(first + i))                    /*  on recherche la fin de first  */
	   i++;
	   while ( *(first + i++) = *(second + k++))
	   ;
	   printf("\n\nLa concat�nation donne la cha�ne de caract�res :\n\n%s", first);
	   printf("\n\nAutre concat�nation (o/n)");
	   rep = getche();
	   }                                                 /*  Fin while sup�rieur  */
	}                                                              /*  Fin main  */


