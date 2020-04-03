/***   PARTLST gŠre dynamiquement dix chaŒnes de caractŠres saisies au      ***/ 
/***   clavier et rang‚es en m‚moire sans perte de place superflue.         ***/
/***   Les adresses sont stock‚es dans un tableau de pointeurs dont les     ***/
/***   ‚l‚ments sont tri‚s selon l'ordre alphab‚tique des chaŒnes.          ***/

 #include <stdio.h>                                           /* printf, gets */
 #include <string.h>                                /* strlen, strcpy, strcmp */
 #include <stdlib.h>                                    /* malloc, free, exit */
 #include <conio.h>                                                 /* getche */
 main()
   {
     char *list[10];                        /* tableau de 10 pointeurs 'char' */
     char *temp;                             /* buffer pour op‚rations de tri */
     char buffer[128];                                    /* buffer de saisie */
     int i = 0;                                        /* compteur de strings */
     int m, n, rep;                                  /* variables de contr“le */

     printf("\033[2J");
     printf("CREATION D'UNE LISTE TRIEE\n");
     printf("\n10 participants au maximum. Format de saisie :");
     printf("\n\n\tNom, Pr‚nom (Pays)\n\n");

     do    /************  saisie des strings  **********/
        {
           printf("\n\nParticipant %d (fin par \"0\"): ", i+1);
           gets(buffer);
           if (strcmp(buffer, "0"))
              {
                if ((list[i] = (char *) malloc(strlen(buffer) + 1)) == NULL)
                   {                           /* +1 … cause du caractŠre nul */
                       printf("\n\nPlus de m‚moire.");
                       if (i > 0)                 /* au moins 1 string saisi. */
                          {
                             printf("\n\nAfficher la liste actuelle ? (o/n)");
                             rep = getche();
                             if (rep == 'o')
                                 break;                   /* sortie de boucle */
                          }
                       exit(1);                 /* autrement fin du programme */
                   }
     
                strcpy(list[i], buffer); /* ranger string … l'adresse list[i] */
                i++;
              }    /* fin if strcmp(buffer, "0") */
        } while (i < 10 && strcmp(buffer, "0"));
     
     /**************  tri du tableau de pointeurs (Bubble Sort)  **************/
     for (m = i-1; m > 0; m--)             /* pointeur i : i-1 passes de tri. */
                                            /* Chaque passe amŠne un pointeur */
                                                      /* … la bonne position. */
         for (n = 0; n < m; n++)           /* m comparaisons par passe de tri */
             if (strcmp(list[n], list[n+1]) > 0)   
                 {                              /* si chaŒne i > chaŒne (i+1) */
                     temp = list[n];                  /* ‚change de pointeurs */
                     list[n] = list[n+1];
                     list[n+1] = temp;
                 }
     
     /*******************  affichage de la liste  *****************************/
     
     if (i > 0)                                          /* si liste non vide */
        {
           printf("\033[2J");
           printf("\n\nLISTE DES PARTICIPANTS :\n\n");
           for (m = 0; m < i; m++)
               printf("%s\n\n", list[m]);
        }
     
     /********************  lib‚ration de la m‚moire allou‚e  *****************/
     for (m = 0; m < i; m++)
         free(list[m]);
   }