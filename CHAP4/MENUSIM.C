/* menusim simule, via un " do while ", un menu pour g‚rer des enregistrements
               dans lequel l'utilisateur peut choisir entre diverses actions. */

#include <stdio.h>                                             /* pour printf */
#include <conio.h>                                             /* pour getche */

main()
{
  int sel;                           /* variable de contr“le, non initialis‚e */
  do                                   /* ex‚cuter les instructions suivantes */
  {
  printf("\033[2J");
  printf("Menu de gestion des donn‚es SIM 1\n\n");
  printf("\t1 = Cr‚ation\n");
  printf("\t2 = Modification\n");
  printf("\t3 = Suppression\n");
  printf("\t4 = Impression\n");
  printf("\t0 = Fin\n\n");
  printf("\tVotre choix : ");
  sel = getche();                                          /* saisie du choix */
  switch (sel)                                           /* qu'a-t-on saisi ? */
         {
          case '1':     printf("\033[2J");
                        printf("\n\nSimulation de cr‚ation.\n");
                        printf("Retour au menu par une touche quelconque.");
                        getche();
                        break;
          case '2':     printf("\033[2J");
                        printf("\n\nSimulation de modification.\n");
                        printf("Retour au menu par une touche quelconque.");
                        getche();
                        break;
          case '3':     printf("\033[2J");
                        printf("\n\nSimulation de suppression.\n");
                        printf("Retour au menu par une touche quelconque.");
                        getche();
                        break;
          case '4':     printf("\033[2J");
                        printf("\n\nSimulation d'impression.\n");
                        printf("Retour au menu par une touche quelconque.");
                        getche();
                        break;
          case '0':     printf("\033[2J");                /* fin du programme */
                        printf("\n\n\t\t***\tFin de la simulation\t***");
                        break;
          default:      printf("\033[2J");                /* erreur de saisie */
                        printf("\n\nSaisie erron‚e\n");
                        printf("Retour au menu par une touche quelconque.");
                        getche();
                        break;
         }                                                   /* fin du switch */
     } while (sel != '0');                  /* tant que la saisie n'est pas 0 */
}                                                              /* fin du main */

