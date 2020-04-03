/***   ARTICLES m‚morise un nombre quelconque d'enregistrements (articles)  ***/
/***   dans un tableau de structures dynamique et affiche, si on veut,      ***/
/***   la liste des donn‚es saisies.                                        ***/

#include <stdio.h>                                     /* scanf, printf, gets */
#include <stdlib.h>                                          /* realloc, free */
#include <conio.h>                                           /* getche, getch */
#include <string.h>                                         /* strcmp, strcpy */

/***********  macro d'en-tˆte de page ******************/

#define HEADER(s)    printf("Page %d\n\n",s);\
                             printf("No.\t\tD‚signation\t\tQuantit‚\n");\
                                 for(j = 0; j < 55; j++) printf("_")
main()
  {
    struct article
    {
       char name[21];                                          /* d‚signation */
       long num;                                         /* quantit‚ en stock */
    };
    
    struct article *plist = NULL;         /* pointeur vers 'struct article' : */
                         /* initialis‚ … NULL pour premier appel de 'realloc' */
    
    struct article *backup;        /* conserve adresse du bloc m‚moire au cas */
                                 /* o— 'realloc' retournerait NULL dans plist */
    
    char buffer[81];                       /* pour contr“le de la d‚signation */
    int i;                                      /* compteur d'enregistrements */
    int j, k, rep;                                   /* variables de contr“le */
    int s = 1;                                           /* compteur de pages */
    printf("\033[2J");
    printf("CREATION NOMENCLATURE \n\n\n");
    i = 0;
    do
         {
             backup = plist;                      /* conserve adresse du bloc */
    
    /*************************  allocation m‚moire  *********************/
    
             if ((plist = (struct article *) realloc(plist, (i+1) *
                        sizeof(struct article))) == NULL)
                {
                    printf("\n\nPas assez de m‚moire !");
                    i++;       /* pour affichage : autrement, il manque 1 … i */
                    break;
                }
    
    /******************  saisie des enregistrements  ************************/
    
       printf("\nEnregistrement no %d\n\n", i+1);
       printf("D‚signation (20 caractŠres maximum, fin par \"0\") : ");
       gets(buffer);
       while (strlen(buffer) > 20)                    /* contr“le d‚signation */
          {
             printf("\nD‚signation trop longue.");
             printf("\nD‚signation (20 caractŠres maximum, fin par \"0\") : ");
             gets(buffer);
          }
          strcpy(plist[i].name, buffer);
                                    /* ajoute nouvelle d‚signation … la liste */
          if (strcmp(plist[i].name, "0"))            /* si d‚signation != "0" */
             {
                printf("Quantit‚ : ");
                scanf("%ld", &plist[i].num);
                while (getchar() != '\n')       /* vidage du tampon de saisie */
                     ;
             }
       } while (strcmp(plist[i++].name, "0"));
    
    /*************  affichage des enregistrements  ****************************/
       
       if (i > 1)                 /* au moins un enregistrement a ‚t‚ saisi : */
                                /* valeur de i aprŠs boucle = 1 + nb. enregs. */
          {
             printf("\n\nNombre de fiches saisies : %d", i-1);
             printf("\nAfficher la liste des fiches ? (o/n)");
             if ((rep = getche()) == 'o')
                {
                     printf("\033[2J");
                     HEADER(s);              /* affichage entˆte de ƒge ‚cran */
                     if (plist == NULL)             /* si erreur d'allocation */
                        plist = backup;  /* on utilise le pointeur de secours */
                        for (k = 0; k < i-1; k++)
                            {
                              printf("\n\n%d\t\t%-20s\t\t%ld", k+1, 
                                         plist[k].name, plist[k].num);
                              if ((k+1)%10) == 0 && k != i-2)
                                 {
                                   printf("\nPage suivante par <Entr‚e>.");
                                   getch();
                                   printf("\033[2J");
                                   s++;                  /* compteur de pages */
                                   HEADER(s);
                                 }
                            }                                      /* fin for */
                }                                               /* fin if rep */
              free(plist);                              /* lib‚ration m‚moire */
          }                                                   /* fin if i > 1 */
  }                                                               /* fin main */
