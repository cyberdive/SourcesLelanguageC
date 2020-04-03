/***  READREC3 montre comment utiliser un tableau de structure pour la      ***/
/***  saisie et l'affichage d'enregistrements.                              ***/

#include <stdio.h>                           /* pour printf, scanf, getchar() */
#include <conio.h>                                      /* pour getche, getch */

main()
  {
     struct nompre                                /* d‚claration de structure */
       {
         char prenom [15];
         char nom [15];
       };
 
     struct livre3                                /* d‚claration de structure */
       {
         struct nompre auteur;
         char titre [40];
         char editeur [20];
         short an;
       };
  
     struct livre3 l[50];               /* D‚finition d'un tableau d'‚l‚ments */
                                                     /* de type struct livre3 */
     
     int i = 0;                 /* Variable de contr“le pour boucle de saisie */
     int last;                          /* Position du dernier enregistrement */
     char reply;                 /* d‚cide de l'affichage des enregistrements */
     int nextorstop;                                 /* ‚cran suivant ou stop */
     
     do
        {
          printf("\033[2J");
          printf("Ce programme vous permet de saisir une bibliographie\n"
                 "de 50 titres au plus. Fin de saisie par \'***\'.");
         
          /* saisie des fiches */
          
          printf("\n\n\nFiche no %d", i+1);
          printf("\n\nNom de l'auteur : ");
          gets(l[i].auteur.nom);
          if (strcmp(l[i].auteur.nom, "***") != 0)
             {
               printf("\nPr‚nom : ");
               gets(l[i].auteur.prenom);
               printf("\nTitre du livre : ");
               gets(l[i].titre);
               printf("\nEditeur : ");
               gets(l[i].editeur);
               printf("\nAnn‚e de parution : ");
               scanf("%hd", &l[i].an);
               while (getchar() != '\n')
                      ;
             }

          i++;

        } while (i < 50  &&  strcmp(l[i-1].auteur.nom, "***") != 0);
  
     if (i == 50)                                                 /* Position */
        last = i-1;                                             /* du dernier */
     else                                                   /* enregistrement */
        last = i-2;  
  
     if (i > 1)                                   /* si on a saisi des fiches */
        {
          if (i > 49)                                        /* tableau plein */
             printf("\n\n50 fiches enregistr‚es. Maximum atteint.");
        
        /* affichage des fiches */
          
          printf("\nVisualisation des fiches ? (o/n)");
          reply = getche();
          if (reply == 'o')
             {
               printf("\033[2J");
               for (i = 0; i <= last; i++)
                  {
                    printf("\n\n%s %s\n", l[i].auteur.prenom, l[i].auteur.nom);
                    puts(l[i].titre);
                    printf("%s %hd", l[i].editeur, l[i].an);

                    if (!((i+1) % 4)  && (i != last))
                                                  /* Stop toutes les 4 fiches */
                        {                       /* sauf aprŠs les 4 derniŠres */
                           printf("\n\n<Entr‚e> pour page suivante.");
                           printf("Fin affichage par <ECHAP>.");
                           nextorstop = getch();
                           if (nextorstop == 27)
                                          /* si <ECHAP>, fin boucle affichage */
                              i = last + 1;
                           else
                              printf("\033[2J");
                        }                             /* fin if(!((i+1) % 4)) */
                  
                  }                                                /* fin for */
            
             }                                       /* fin if (reply == 'o') */
       
        }                                                    /* fin if(i > 1) */
  
  }                                                               /* fin main */