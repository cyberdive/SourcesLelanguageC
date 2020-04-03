/***  PARTLST2 gŠre dynamiquement un nombre quelconque de chaŒnes de        ***/
/***  caractŠres, sans perte de place superflue, et range leurs adresses    ***/
/***  dans un tableau tri‚ dynamique dont les ‚l‚ments correspondent …      ***/
/***  l'ordre alphab‚tique des strings.                                     ***/

#include <stdio.h>                                            /* printf, gets */
#include <string.h>                                 /* strlen, strcpy, strcmp */
#include <stdlib.h>                             /* malloc, realloc,free, exit */
#include <conio.h>                                           /* getche, getch */

#define HEADER(s)    printf("LISTE DES PARTICIPANTS\t\t\t\t\tPage %d\n", s);\
                     for (j = 0; j < 60; j++) printf("_"); printf("\n\n")

main()
  {
    char **pplist = NULL;    /* pointeur vers pointeur vers char : initialis‚ */
                                /* … NULL afin que 'realloc' fonctionne comme */
                                  /* 'malloc' lors de la premiŠre allocation. */
    
    char **ppbkup;                                 /* sauve contenu de pplist */
    char *temp;                                   /* buffer auxiliaire de tri */
    char buffer[128];                                     /* buffer de saisie */
    int s = 1;                                           /* compteur de pages */
    int i = 0;                                         /* compteur de strings */
    int j, m, n, rep;                                /* variables de contr“le */

    printf("\033[2J");
    printf("CREATION D'UNE LISTE TRIEE DE PARTICIPANTS\n");
    printf("\nFormat de saisie :\tNom, Pr‚nom (Pays)\n\n");
    
    do    /************  saisie des strings  **********/
      {
         printf("\n\nParticipant %d (fin par \"0\"): ", i+1);
         gets(buffer);
         if (strcmp(buffer, "0"))
            {
                                 /* allocation m‚moire pour tableau dynamique */
                                              /* de pointeurs et pour strings */
               ppbkup = pplist;
                         /* sauve adr. bloc pour affichage (cas pplist = NULL)*/
               if ((pplist = (char **) realloc(pplist, (i+1) * sizeof(char*)))
                         == NULL  ||
                   pplist[i] = (char *) malloc(strlen(buffer) + 1)) == NULL)
                   {
                      printf("\n\nErreur d'allocation. ");
                      printf ("DerniŠre saisie non prise en compte.");
                      if (i > 0)           /* au moins une chaŒne d‚j… saisie */
                         {
                            printf("\n\nAfficher liste actuelle ? (o/n)");
                            rep = getche();
                            if (rep == 'o')
                               {
                                  if (pplist == NULL)
                                     pplist = ppbkup;
                                     break;               /* sortie de boucle */
                               } 
                         }
                      exit(1);                     /* autrement fin programme */
                   }
               strcpy(pplist[i], buffer);                  /* m‚morise chaŒne */
               i++;
            }    /* fin if strcmp(buffer, "0") */
    
      } while (strcmp(buffer, "0"));
    
    /************  tri du tableau de pointeurs (Bubble Sort)  *****************/
    
    for (m = i-1; m > 0; m--)              /* pointeur i : i-1 passes de tri. */
                                            /* Chaque passe amŠne un pointeur */
                                                      /* … la bonne position. */
        
        for (n = 0; n < m; n++)                   /* m comparaisons par passe */
            if (strcmp(pplist[n], pplist[n+1]) > 0)
                                                   /* string i > string (i+1) */
               {
                 temp = pplist[n];                    /* ‚change de pointeurs */
                 pplist[n] = pplist[n+1];
                 pplist[n+1] = temp;
               }
    /*******************  affichage liste  *******************************/
    
    if (i > 0)                                              /* liste non vide */
       {
          printf("\033[2J");
          HEADER(s);
          for (m = 0; m < i; m++)
              {     
                 printf("%s\n\n", pplist[m]);
                 if ((m+1) % 9 == 0  &&  m != i-1)
                    {
                       printf("\n\n<Entr‚e> pour page suivante.");
                       getch();
                       printf("\033[2J");
                       s++;                              /* compteur de pages */
                       HEADER(s);
                    }
              }
       }
 
    /********************  lib‚ration m‚moire  ****************/
    
    for (m = 0; m < i; m++)            /* lib‚ration de l'espace de la string */
        free(pplist[m]);
        free(pplist);           /* lib‚ration du bloc du tableau de pointeurs */
  }
