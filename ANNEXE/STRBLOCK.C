	/*  STRBLOCK range des chaŒnes de caractŠres, les unes … la suite des autres, 
	     dans un tableau statique. Si le tableau est plein et qu'on ne peut plus y 
	     mettre de chaŒne, alors on peut ''effacer'' des chaŒnes d‚j… saisies. La 
	     place qu'elles occupaient devient disponible pour la nouvelle chaŒne. Dans 
	     ce processus, on ‚crase autant de chaŒnes de caractŠres que n‚cessaire
	     tandis que le reste du bloc est d‚cal‚ vers l'avant. La nouvelle chaŒne 
        est donc toujours accroch‚e … la fin du bloc existant.  */
	#include <stdio.h>                                       /*  printf, getchar  */
	#include <conio.h>                                                /*  getche  */
	#include <string.h>                                     /  *  strcpy, strlen  */
	main()
	{
	   char ibuf [81];                                      /*  tampon de saisie  */
	   char sbuf [256] = {'\0'};                        /*  tableau pour strings  */
	   char *p;                                         /*  variable de contr“le  */
	   unsigned i, j, k;                               /*  variables de contr“le  */
	   unsigned pos = 0;                  /*  position du prochain ‚l‚ment libre  */
	   unsigned freebytes = 255;                                /*  espace libre  */
	   unsigned delbytes;            /*  nb. d'octets pouvant ˆtre ‚cras‚s … partir 
	                                                         du d‚but du tableau  */
	   unsigned shiftbytes;          /*  nb. d'octets pouvant ˆtre d‚cal‚s … partir 
	                                                         du d‚but du tableau  */
	   int c;                                              /*  buffer caractŠre   */
	   int ok;                                     /*  Flag pour saisie correcte  */
	   int rep;                                         /*  variable de contr“le  */
	   int cnt;                                                     /*  compteur  */
	   printf("\033[2J");
	   printf("REMPLISSAGE D'UN TABLEAU STATIQUE PAR DES STRINGS.\n\n");
	   printf("Longueur maximale d'un string : 80 caractŠres.\n");
	   printf("ATTENTION : chaque string est muni par le programme d'une marque"
	   "de fin\n et doit donc ˆtre compt‚ avec un caractŠre de plus.");
	   cnt = 0;
	   do
	   {
	   do
	   {
	   ok = 1;
	   i = 0;
	   if (freebytes)                                   /*  s'il y a de la place  */
	   {
	   printf("\n\n");
	   if (cnt)
	   printf("Suivante\n");
	   printf("Entrez la chaŒne (%u octets libres. Fin par <Entr‚e>) :\n", freebytes);
	   }
	   else
	   printf("\n\nEntrez la chaŒne suivante. (Fin par <Entr‚e>) :\n");
	   while ((c = getchar()) != '\n')
	   {
	   ibuf[ i ] = c;
	   if (i > 79)
	   {
	   printf("\n\nChaŒne trop longue.");
	   ok = 0;
	   while (getchar() != '\n')
	                                              /*  vidage du tampon de saisie  */
	   break;
	   }
	   i++;
	   }
	   } while (!ok);
	   ibuf[ i ] = '\0';                                    /*  fin de la saisie  */
	   if (strlen(ibuf))                /*  si le string a au moins un caractŠre  */
	   {
	   if (freebytes + 1 >= strlen(ibuf) + 1)          /*  s'il y a de la place  */
	   {
	   strcpy(sbuf+pos, ibuf);                           /*  string dans tableau  */
	   cnt++;
	   if (sbuf[254] != '\0')                                  /*  tableau plein  */
	   freebytes = 0;
	   else
	   freebytes = freebytes - (strlen(ibuf) + 1);
	   if (!freebytes)
	   {
	   printf("\n\nTableau rempli.\n"
	   "Voulez-vous ‚craser d'anciens strings au d‚but du"
	   "tableau pour faire de la place pour d'autres ? (o/n)");
	   rep = getche();
	   if (rep == 'o')
	   continue;                                                 /*  on reboucle  */
	   else                                              /*  sinon fin de saisie  */
	   break;
	   }                                                  /*  Fin if(!freebytes)  */
	   pos = pos + strlen(ibuf) + 1;                /*  prochaine position libre  */
	   }                                              /*  Fin if(freebytes+1 ...  */
	   else                                  /*  pas assez de place dans tableau  */
	   {
	   if (freebytes)                        /*  tableau pas complŠtement rempli  */
	   {
	   printf("\n\nPas assez de place.\n"
	   "Effacer d'anciens strings en d‚but de tableau "
	   "pour pouvoir ranger le string actuel ? (o/n)");
	   rep = getche();
	   }
	   if (rep == 'o')
	   {
	   p = sbuf;                                      /*  ptr vers d‚but tableau  */
	   /****  calcul du nb. d'octets … ‚craser  ****/
	   delbytes = strlen(p) + 1;
	   while (delbytes < strlen(ibuf) + 1)
	   {
	   p = p + strlen(p) + 1;
	   delbytes = delbytes + strlen(p) + 1;
	   }
	   /****  calcul du nb. d'octets d‚cal‚s  ****/
	   if (sbuf[254] != '\0')                                  /*  tableau plein  */
	   shiftbytes = 256 - delbytes - freebytes;
	   else                                                /*  tableau non plein  */
	   shiftbytes = 256 - delbytes - (freebytes+1);
	   /****  d‚calage vers d‚but tableau   ****/
	   for (j = 0, k = delbytes; k < delbytes + shiftbytes; j++, k++)
	   sbuf[j] = sbuf[k];
	   strcpy(sbuf + j, ibuf);                          /*  range nouveau string  */
	   /** remplissage par des z‚ros de la fin du tableau **/
	   for (i = j+strlen(ibuf)+1; i < 256; i++)
	   sbuf[ i ] = '\0';
	   pos = j + strlen(ibuf) + 1;                  /*  prochaine position libre  */
	   if (sbuf[254] != '\0')                                  /*  tableau plein  */
	   freebytes = 0;
	   else
	   freebytes = 255 - (j + strlen(ibuf) + 1);
	   if (!freebytes)
	   {
	   printf("\n\nTableau rempli.\n"
	   "Effacer d'anciens strings en d‚but de tableau "
	   "pour pouvoir ranger le string actuel ? (o/n)");
	   rep = getche();
	   if (rep == 'o')
	   continue;                                                 /*  on reboucle  */
	   else                                              /*  sinon fin de saisie  */
	   break;
	   }
	   }                                                    /*  Fin if(rep=='o')  */
	   else                                                    /*  si rep != 'o'  */
	   strcpy(ibuf, "\0");     /*  pas ‚craser strings, quitter do while externe  */
	   }                                                  /*  Fin else sup‚rieur  */
	   }                                                /*  Fin if(strlen(ibuf))  */
	   } while (strlen(ibuf));                          /*  Fin do while externe  */
	   /*****************  affichage des strings  ******************************/
	   if (strlen(sbuf))                   /*  au moins 1 string dans le tableau  */
	   {
	   printf("\n\nOn a rang‚ les chaŒnes suivantes :\n\n");
	   for (i = 0, p = sbuf; strlen(p) && i < 256; i = strlen(p)+1, p = p + strlen(p)+1)
	   printf("%s\n", p);
	   }
	}


