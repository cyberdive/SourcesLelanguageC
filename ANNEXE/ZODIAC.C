	/*  ZODIAC affiche le signe du zodiaque correspondant … une date de naissance 
	     saisie au clavier  */
	#include <stdio.h>                                         /*  printf, scanf  */
	#include <conio.h>                                                /*  getche  */
	main()
	{
	/*  table des signes :  */
	   char zodiac [12] [11] = { "CAPRICORNE" , "VERSEAU", "POISSONS", "BELIER", "TAUREAU", "GEMEAUX", "CANCER", "LION", "VIERGE", "BALANCE", "SCORPION", "SAGITTAIRE"};
	                       /*  table des jours ‚coul‚s jusqu'… un certain mois :  */
	   int monsum [13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
	                           /*  num‚ro (1 - 365) du premier jour d'un signe :  */
	   int start [12] = { 1, 31, 62, 90, 121, 151, 183, 214, 246, 277, 307, 337 };
	                           /*  num‚ro (1 - 365) du dernier jour d'un signe :  */
	   int end [12] = { 30, 61, 89, 120, 150, 182, 213, 245, 276, 306, 336, 365 };
	   int day;                                            /*  jour de naissance  */
	   int mon;                                            /*  mois de naissance  */
	   int tnum;                              /*  jour et mois convertis en le jour 
	                                  correspondant (1-365) de l'ann‚e zodiacale  */
	   int i;                                           /*  variable de contr“le  */
	   int reply = 'o';                                 /*  variable de contr“le  */
	   while ( reply == 'o')
	   {
	   printf("\033[2J");
	   printf("Le programme calcule le signe du zodiaque.\n");
	   printf("\n\nEntrez le jour et le mois de naissance (jj/mm.) : ");
	   scanf("%d/%d.", &day, &mon);
	   if (monsum[mon] + day + 10 > 365)       /*  date convertie en nb de jours  */
	                                                 /*  ‚coul‚s depuis le 22.12  */
	   tnum = monsum[mon] + day + 10 - 365;
	   else
	   tnum = monsum[mon] + day + 10;             /*  premier signe : CAPRICORNE  */
	   for (i = 0; i < 12; i++)                          /*  recherche du signe  */
	   if (tnum >= start[i]  &&  tnum <= end[i])
	   {
	   printf("\n\nVotre signe est %s", zodiac[ i ]);
	   break;                               /*  sortie boucle quand signe trouv‚  */
	   }
	   printf("\n\nAutre date ? (o/n)");
	   reply = getche();
	   }                                                           /*  Fin while  */
	}                                                              /*  Fin main  */

