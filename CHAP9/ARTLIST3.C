/***  ARTLIST3 gŠre un nombre quelconque d'enregistrements, tri‚s en ordre  ***/
/***  alphab‚tique croissant, sous forme de liste chaŒn‚e double.           ***/

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
    
    typedef struct article3
       {
          char name[21];                                       /* d‚signation */
          long num;                                               /* quantit‚ */
          struct article3 *pre;            /* pointeur vers ‚l‚ment pr‚c‚dent */
          struct article3 *suiv;             /* pointeur vers ‚l‚ment suivant */
       } listelement;               /* type personnalis‚ pour struct article3 */
    
    listelement *deb;                         /* pointeur vers d‚but de liste */
    listelement *fin;                           /* pointeur vers fin de liste */
    listelement * nouv;                       /* pointeur vers nouvel ‚l‚ment */
    listelement *der;            /* pointeur vers dernier l'expression ins‚r‚ */
    listelement * a;                                  /* variable de contr“le */
    char buffer [81];                           /* pour contr“le de la saisie */
    int i;                                      /* compteur d'enregistrements */
    int s = 1;                                           /* compteur de pages */
    int j, k, rep;                                   /* variables de contr“le */
    
/******************** allocation m‚moire pour premier ‚l‚ment  ****************/
    
    if ((deb = (listelement *) malloc(sizeof(listelement))) == NULL)
       {
          printf("\n\nPlus de m‚moire libre.");
          exit(1);                                           /* fin programme */
       }
    i = 0;
    fin = nouv = der = deb;                           /* initialise pointeurs */
    deb->pre = deb->suiv = NULL;
    printf("\033[2J");
    printf("CREATION DE NOMENCLATURE \n\n\n");
   
/************************  saisie des enregistrements  ************************/
    do
       {
          printf("\nEnregistrement no %d\n\n", i+1);
          printf("D‚signation (20 caractŠres maximum, fin par \"0\") : ");
          gets(buffer);
          while (strlen(buffer) > 20)                 /* contr“le d‚signation */
             {
                printf("\nD‚signation trop longue.");
                printf("\n D‚signation (20 caractŠres max., fin par \"0\") : ");
                gets(buffer);
             }
          strcpy(nouv->name, buffer);      /* ajout d‚signation dans la liste */
          if (strcmp(nouv->name, "0"))               /* si d‚signation != "0" */
             {
                printf("Quantit‚ : ");
                scanf("%ld", &nouv ->num);
                while (getchar() != '\n')          /* vidage tampon de saisie */
                        ;
    
                /*****************  insertion nouvel ‚l‚ment ******************/

                if (strcmp(nouv->name, deb->name) <= 0) /* nouveau <= premier */
                   {
                      if (nouv != deb)    /* si au moins 1 ‚l‚ment dans liste */
                         {
                           nouv->pre = NULL; /* insertion nouveau premier elt */
                           nouv->suiv = deb;
                           deb->pre = nouv;
                           deb = nouv;
                         }
                   }
                else if (strcmp(nouv->name, fin->name) >= 0)
                                                        /* nouveau >= dernier */
                   {
                      if (nouv != deb)       /* si au moins 1 ‚l. dans liste  */
                         {
                            nouv->pre = fin; /* insertion nouveau dernier ‚lt */
                            nouv->suiv = NULL;
                            fin->suiv = nouv;
                            fin= nouv;
                         }
                   }
                else if (strcmp(nouv->name, der->name) >= 0) 
                                                 /* nouveau >= dernier ins‚r‚ */
                   {
                      if (nouv != deb)           /* au moins 1 ‚l. dans liste */
                         {
    
                          /***** calcul de la position du nouvel ‚l‚ment  *****/
                            for(a = der; strcmp(a->suiv->name, nouv->name) < 0;
                                   a = a->suiv)
                                           ;
                            nouv->pre = a;        /* insertion nouvel ‚l‚ment */
                            nouv->suiv = a->suiv;
                            a->suiv->pre = nouv;
                            a->suiv = nouv;
                         }                            
                   }
               else                               /* nouveau < dernier ins‚r‚ */
                   {
    
                    /******** calcul de la position du nouvel ‚l‚ment  ********/
                      for(a = der; strcmp(nouv->name, a->pre->name) < 0;
                          a = a->pre)
                                 ;
                      nouv->pre = a->pre;         /* insertion nouvel ‚l‚ment */
                      nouv->suiv = a;
                      a->pre->suiv = nouv;
                      a->pre = nouv;
                   }
    
               der = nouv;         /* actualise pointeur vers dernier ‚l‚ment */
                 
                     /********  allocation m‚moire pour nouvel ‚l‚ment  *******/
    
               if ((nouv = (listelement *) malloc(sizeof(listelement))) == NULL)
                  {
                     printf("\n\nPlus de m‚moire. <Entr‚e> pour continuer.");
                     getch();        
                     i++;                          /* actualise compteur enr. */
                     break;                               /* sortie de boucle */
                  }
               i++;
             
             }    /* fin if(strcmp(...)) sup‚rieur */
    
          else    /* si fin de saisie */
             der= nouv;                        /* tester le dernier nom saisi */
                                               /* dans la condition de boucle */
       } while (strcmp(der->name, "0"));
 
 /***************  affichage des enregistrements  *****************************/
    
    if (i > 0)                             /* au moins 1 enregistrement saisi */
       {
         printf("\033[2J");
         printf("\n\nNombre d'enregistrements saisis : %d", i);
         printf("\n\nAFFICHER LES ENREGISTREMENTS :\n\n");
         printf("Tri‚s en ordre ascendant\t\t(a)\n");
         printf("Tri‚s en ordre descendant\t\t(d)\n");
         printf("\nFin par appui sur une touche quelconque\n\n");
         printf("Votre choix : ");
         rep = getche();
    
        switch (rep)
           {
              case 'a':    
                  printf("\033[2J");
                  HEADER(s);                                       /* en-tˆte */
                  for (a = deb, k = 1; a != NULL; a = a->suiv, k++)
                      {
                         printf("\n\n%d\t\t%-20s\t\t%ld", k, a->name, a->num);
                         if ((k%9) == 0 && k != i)
                            {
                               printf("\n\n<Entr‚e> pour page suivante.");
                               getch();
                               printf("\033[2J");
                               s++;                      /* compteur de pages */
                               HEADER(s);
                            }
                      }
                  break;
              case 'd':    
                  printf("\033[2J");
                  HEADER(s);                                       /* en-tˆte */
                  for (a = fin, k = 1; a != NULL; a = a->pre, k++)
                      {
                         printf("\n\n%d\t\t%-20s\t\t%ld", k, a->name, a->num);
                         if ((k%9) == 0 && k != i)
                            {
                               printf("\n\n<Entr‚e> pour page suivante.");
                               getch();
                               printf("\033[2J");
                               s++;                      /* compteur de pages */
                               HEADER(s);
                            }
                      }
                  break;
              default:
                       ;
           }
     
 /*******************  lib‚ration de la m‚moire  ************************/
    
        for (a = deb; a != NULL; a = nouv)
            {
               nouv = a->suiv;                /* sauve adresse suivante avant */
                                    /* lib‚ration de l'‚l‚ment actuel contenu */
                              /* dans cette adresse. Autrement, cette adresse */
                            /* serait perdue et l'accŠs … la liste impossible */
               free(a);
            }
  
       }                                                      /* fin if i > 0 */

  }                                                               /* fin main */
