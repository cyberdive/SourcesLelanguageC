/***  READREC1 lit un enregistrement, le range dans ***/
/***  une variable structur‚e et ensuite l'affiche. ***/

#include <stdio.h>                          /* pour printf, scanf, gets, puts */

main()
  {
     struct nompre
       {
         char prenom [15];
         char nom [15];
       };
    
     struct livre3
       {
                        struct nompre auteur;              /* Nom de l'auteur */
                        char titre [40];                    /* Titre du livre */
                        char editeur [20];                      /* Publi‚ par */
                        short an;                     /* Ann‚e de publication */
               } l;                                    /* Variable structur‚e */

          printf("\033[2J");
          printf("FICHE BIBLIOGRAPHIQUE :\n\n");

     /* saisie de l'enregistrement */
     printf("Nom de l'auteur : ");
     gets(l.auteur.nom);
     printf("\nPr‚nom : ");
     gets(l.auteur.prenom);
     printf("\nTitre du livre : ");
     gets(l.titre);
     printf("\nEditeur : ");
     gets(l.editeur);
     printf("\nAnn‚e de publication : ");
     scanf("%hd", &l.an);
 
    /* affichage de l'enregistrement */
     printf("\n\nVous avez enregistr‚ les donn‚es suivantes :\n\n");
     printf("%s %s\n", l.auteur.prenom, l.auteur.nom);
     puts(l.titre);
     printf("%s %hd", l.editeur, l.an);

  }
