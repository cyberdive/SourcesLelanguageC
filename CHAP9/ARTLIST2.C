/***  ARTLIST2 m‚morise un nombre quelconque d'enregistrements tri‚s par    ***/
/***  ordre alphab‚tique croissant, sous forme de liste chaŒn‚e simple,     ***/
/*** puis affiche la liste si on le d‚sire.                                 ***/

#include <stdio.h>                                     /* scanf, printf, gets */
#include <stdlib.h>                                     /* malloc, free, exit */
#include <conio.h>                                           /* getche, getch */
#include <string.h>                                         /* strcmp, strcpy */

/***********  Macro pour en-tˆte de page d'‚cran  ******************/

#define HEADER(s)    printf("Page %d\n\n",s);\
                     printf("No.\t\tD‚signation\t\tQuantit‚\n");\
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
    listelement * nouv;                       /* pointeur vers nouvel ‚l‚ment */
    listelement * a;                         /* pointeur vers ‚l‚ment courant */
    listelement *bkup;                                 /* pointeur de secours */
    char buffer [81];                           /* pour contr“le de la saisie */
    int i;                                      /* compteur d'enregistrements */
    int s = 1;                                           /* compteur de pages */
    int j, k;                                        /* variables de contr“le */
    int rep;                                          /* variable de contr“le */
    
  /******************* allocation m‚moire pour premier ‚l‚ment  ***************/
    
    if ((deb = (listelement *) malloc(sizeof(listelement))) == NULL)
       { 
          printf("\n\nPlus de m‚moire libre.");
          exit(1);                                           /* fin programme */
       }
    i = 0;
    nouv = bkup = deb;                                /* initialise pointeurs */
    deb->suiv = NULL;
    
    printf("\033[2J");
    printf("CREATION DE NOMENCLATURE \n\n\n");
    
  /**********************  saisie des enregistrements  ************************/
    
    do
       {
          printf("\nEnregistrement no %d\n\n", i+1);
          printf("D‚signation (20 caractŠres maximum, fin par \"0\") : ");
          gets(buffer);
          while (strlen(buffer) > 20)    /* contr“le d‚signation */
            {
              printf("\nD‚signation trop longue.");
              printf("\n D‚signation (20 caractŠres maximum, fin par \"0\"): ");
              gets(buffer);
            }
            strcpy(nouv->name, buffer);    /* ajout d‚signation dans la liste */
    
            if (strcmp(nouv->name, "0"))             /* si d‚signation != "0" */
               {
                 printf("Quantit‚ : ");
                 scanf("%ld", &nouv ->num);
                 while (getchar() != '\n')         /* vidage tampon de saisie */
                       ;
    
  /**********************  insertion nouvel ‚l‚ment  **************************/
    
                 if (strcmp(nouv->name, deb->name) < 0)  /* nouveau < premier */
                    {
                       nouv->suiv = deb;          /* ancien 1 devient nouv. 2 */
                       deb = nouv;                           /* nouveau d‚but */
                    }
                 else                                   /* nouveau >= premier */
                    {
                       if (nouv != deb)       /* si liste a plus d'un ‚l‚ment */
                          {
   
                       /** cherche premier ‚l‚ment > nouveau ou fin de liste **/
                             for(a = deb; a->suiv != NULL 
                             &&  strcmp(a->suiv->name, nouv->name) 
                                                 < 0; a = a->suiv)
                                            ;
                                                  /* insertion nouvel ‚l‚ment */
                             nouv->suiv = a->suiv;
                             a->suiv = nouv;
                          }
                    }
              
                     /********  allocation m‚moire pour nouvel ‚l‚ment  *******/
               bkup = nouv;      /* sauve adresse de l'enregistrement courant */
                               /* pour v‚rification de la condition de boucle */
               if ((nouv = (listelement *) malloc(sizeof(listelement))) == NULL)
                    {
                       printf("\n\nPlus de m‚moire.");
                       i++;                        /* actualise compteur enr. */
                       break;                             /* sortie de boucle */
                    }
                 i++;
               }                            /* fin if(strcmp(nouv->name,"0")) */
            else    /* si fin de saisie */
                 bkup = nouv;                  /* tester le dernier nom saisi */
                                               /* dans la condition de boucle */
       } while (strcmp(bkup->name, "0"));
    
  /*************  affichage des enregistrements  ******************************/
  
    if (i > 0)                       /* au moins 1 enregistrement a ‚t‚ saisi */
       {
          printf("\n\nNombre d'enregistrements saisis : %d", i);
          printf("\nAfficher la liste des enregistrements ? (o/n)");
          if ((rep = getche()) == 'o')
             {
                printf("\033[2J");
                HEADER(s);                           /* en-tˆte de page ‚cran */
                for (a = deb, k = 1; a != NULL; a = a->suiv, k++)
                    {
                       printf("\n\n%d\t\t%-20s\t\t%ld", k, a->name, a->num);
                       if ((k%9) == 0 && k != i)
                          {
                             printf("\n\n<Entr‚e> pour page suivante.");
                             getch();
                             printf("\033[2J");
                             s++;                       /* compteur de pages  */
                             HEADER(s);
                          }
                    }                                              /* fin for */
             }                                                  /* fin if rep */
       
  /************************  lib‚ration de la m‚moire  ************************/
  
          for (a = deb; a != NULL; a = bkup)
             {
                bkup = a->suiv;               /* sauve adresse suivante avant */
                                    /* lib‚ration de l'‚l‚ment actuel contenu */
                             /*  dans cette adresse. Autrement, cette adresse */
                            /* serait perdue et l'accŠs … la liste impossible */
                free(a);
             }
       }                                                      /* fin if i > 0 */
  }                                                               /* fin main */
