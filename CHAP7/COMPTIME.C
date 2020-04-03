/*   COMPTIME compare les dur‚es requises par l'ex‚cution de deux boucles de
comptage. Une des boucles utilise comme compteur une variable register et
l'autre une variable normale auto. Le calcul de la dur‚e se fait au moyen
						de la fonction C time.     */
#include <stdio.h>                                       /*     printf     */
#include <time.h>                                          /*     time     */
main()
{
     long start;                             /*     heure d‚but boucle     */
     long end;                                 /*     heure fin boucle     */
     int a1, a2;                       /*     compteurs de boucle auto     */
     register int r1, r2;          /*     compteurs de boucle register     */

     printf("\033[2J");

     printf("\n\nLe programme compare les dur‚es d'ex‚cution\n"
     " d'une boucle de comptage (4000000 op‚rations de comptage)\bas‚e sur des"
						      " variables register\n"
     " et d'une autre boucle bas‚e sur des variables auto\n.");
     time(&start);         /*     r‚cup‚ration heure d‚but boucle auto     */
     for (a1 = 1; a1 <= 2000; a1++)
     for (a2 = 1; a2 <= 2000; a2++);

     time(&end);             /*     r‚cup‚ration heure fin boucle auto     */
     printf("La boucle auto demande %ld secondes.", end-start);
     time(&start);     /*     r‚cup‚ration heure d‚but boucle register     */
     for (r1 = 1; r1 <= 2000; r1++)
     for (r2 = 1; r2 <= 2000; r2++);

     time(&end);         /*     r‚cup‚ration heure fin boucle register     */
     printf("La boucle register demande %ld secondes.", end-start);
}

