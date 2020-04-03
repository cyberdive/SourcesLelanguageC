/***  ARTLIST1 range en m‚moire un nombre quelconque d'enregistrements sous ***/
/***  forme de liste chaŒn‚e simple, puis les affiche si on le d‚sire.      ***/

#include <stdio.h>                                     /* scanf, printf, gets */
#include <stdlib.h>                                     /* malloc, free, exit */
#include <conio.h>                                           /* getche, getch */
#include <string.h>                                         /* strcmp, strcpy */

/***********  Macro pour en-tˆte de page d'‚cran  ******************/

#define HEADER(s)    printf("Page %d\n\n",s);\
                     printf("No\t\tD‚signation\t\tQuantit‚\n");\
                     for(j = 0; j < 55; j++) printf("_")
main()
  {
    typedef struct article2
      {
        char name[21];                                         /* d‚signation */
        long num;                                                 /* quantit‚ */
        struct article2 *suiv;               /* pointeur vers ‚l‚ment suivant */
      } listelement;                /* type personnalis‚ pour struct article2 */
    listelement *deb;                         /* pointeur vers d‚but de liste */
    listelement *pac;                        /* pointeur vers ‚l‚ment courant */
    listelement *bkup;                                 /* pointeur de secours */
    char buffer [81];                           /* pour contr“le de la saisie */
    int i;                                      /* compteur d'enregistrements */
    int s = 1;                                           /* compteur de pages */
    int j, k;                                        /* variables de contr“le */
    int rep;                                          /* variable de contr“le */
    if ((deb = (listelement *) malloc(sizeof(listelement))) == NULL)
       {
          printf("\n\nPlus de m‚moire libre.");
          exit(1);                                          /* fin programme */
       }
    i = 0;
    pac = bkup = deb;
    printf("\033[2J");
    printf("CREATION DE NOMENCLATURE \n\n\n");
    
    /******************  saisie des enregistrements  ************************/
 
    do
       {
          printf("\nEnregistrement no %d\n\n", i+1);
          printf("D‚signation (20 caractŠres maximum, fin par \"0\") : ");
          gets(buffer);
          while (strlen(buffer) > 20)                 /* contr“le d‚signation */
             {
                printf("\nD‚signation trop longue.");
                printf("\n D‚signation (20 caractŠres maximum, fin par \"0\") : ");
                gets(buffer);
             }
             strcpy(pac->name, buffer);    /* ajout d‚signation dans la liste */
             if (strcmp(pac->name, "0"))             /* si d‚signation != "0" */
                 {
                   printf("Quantit‚ : ");
                   scanf("%ld", &pac->num);
                   while (getchar() != '\n')       /* vidage tampon de saisie */
                        ;
     
                   /******  allocation de m‚moire pour ‚l‚ment suivant  *******/

                      if ((pac->suiv = (listelement *) 
                                        malloc(sizeof(listelement))) == NULL)
                         {
                            printf("\n\nPlus de m‚moire.");
                            i++;      /* actualise compteur d'enregistrements */
                            break;                        /* sortie de boucle */
                         }
                         bkup = pac;  /* … cause de la prochaine instruction, */
                                    /* on sauve l'adresse de l'enregistrement */
                                /* courant, pour traitement ult‚rieur et pour */
                                  /* v‚rification de la condition de bouclage */
                         pac = pac->suiv;        /* range adresse du prochain */
                                        /* ‚l‚ment … traiter dans le pointeur */
                                                    /* vers l'‚l‚ment courant */
                 
                         i++;
                 }
             else    /* si fin de saisie */
                 {
                   bkup->suiv = NULL;            /* range NULL  dans pointeur */
                                                 /* du dernier enregistrement */
                   bkup = pac;  /* pour que soit v‚rifi‚ dans la condition de */
                                        /* bouclage le nom pr‚c‚demment entr‚ */
                 }
       } while (strcmp(bkup->name, "0"));
 
    /*************  affichage des enregistrements  *****************************/

    if (i > 0)                       /* au moins 1 enregistrement a ‚t‚ saisi */
       {
          printf("\n\nNombre d'enregistrements saisis : %d", i);
          printf("\nAfficher la liste des enregistrements ? (o/n)");
          if ((rep = getche()) == 'o')
            {
               printf("\033[2J");
               HEADER(s);                            /* en-tˆte de page ‚cran */
               for (pac = deb, k = 1; pac != NULL; pac = pac->suiv, k++)
                  {
                     printf("\n\n%d\t\t%-20s\t\t%ld", k, pac->name, pac->num);
                     if ((k%9) == 0 && k != i)
                        {
                           printf("\n\n<Entr‚e> pour page suivante.");
                           getch();
                           printf("\033[2J");
                           s++;                         /* compteur de pages  */
                           HEADER(s);
                        }
                  }                                                /* fin for */
            }                                                   /* fin if rep */

    /*******************  lib‚ration de la m‚moire  ************************/
 
          for (pac = deb; pac != NULL; pac = bkup)
            {
                bkup = pac->suiv;             /* sauve adresse suivante avant */
                                    /* lib‚ration de l'‚l‚ment actuel contenu */
                              /* dans cette adresse. Autrement, cette adresse */
                            /* serait perdue et l'accŠs … la liste impossible */
                free(pac);
            }
       }                                                      /* fin if i > 0 */
  }                                                               /* fin main */
