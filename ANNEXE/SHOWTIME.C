	/*  SHOWTIME affiche l'heure … l'‚cran. La position d'affichage est donn‚e sur 
	     la ligne de commande par le bais de deux paramŠtres (ligne, colonne).  */
	#include <stdio.h>
	#include <time.h>                                      /*  time, localtime  */
	#include <conio.h>                                               /*  kbhit  */
	#include <stdlib.h>                                               /*  atoi  */
	#define POS(x,y)  printf("\033[%d;%dH", x,y)
	main(int argc, char **argv)
	{
	   void postime(int row, int col);
	   int row, col;
	   row = atoi(argv[1]);
	   col = atoi(argv[2]);
	   postime(row, col);
	}
	void postime(int row, int col)                           /*  affiche l'heure  */
	{
	   long start, current;                   /*  heure de d‚but, heure courante  */
	   struct tm *h;                 /*  pointeur vers structure 'tm' d‚clar‚e dans 
	                                           TIME.H. Pour 'localtime', les champs 
	                                  contiennent entre autres : temps en secondes, 
	                                                       minutes, heures, etc.  */
	   printf("\033[2J");
	   time(&start);                          /*  r‚cup‚ration heure en secondes  */
	   while (!kbhit())                /*  la montre tourne jusqu'… appui touche  */
	   {
	   do                                                   /*  mesure 1 seconde  */
	   {
	   time(&current);
	   } while ((current - start) < 1);
	   h = localtime(&current);      /*  conversion en heures, minutes, secondes  */
	   POS(row,col);                                    /*  positionne la montre  */
	   printf("\033[7m");                                    /*  inversion vid‚o  */
	       /*  affiche heure : format 0 pour avoir des z‚ros de tˆte … la place des 
	        blancs, format 2 pour avoir une largeur de champ = 2. Sans ces formats, 
	              l'affichage pr‚c‚dent ne serait pas complŠtement ‚cras‚, ou alors 
	         les largeurs d'affichage ne seraient pas les mˆmes selon que le nombre 
	                                                    comporte 1 ou 2 chiffres  */
	   printf("%02d:%02d:%02d", h->tm_hour, h->tm_min, h->tm_sec);
	   start = current;    /*  point de d‚part pour prochain intervalle de temps  */
	   }
	   printf("\033[40m");                                       /*  fond normal  */
	   printf("\033[37m");                                      /*  texte normal  */
	}


