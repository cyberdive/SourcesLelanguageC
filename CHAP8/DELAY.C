/*     DELAY montre la compilation conditionnelle de portions de programme
sur l'exemple de quelques boucles de comptage qui servent … faire des pauses
entre des affichages de caractŠres isol‚s. Selon la valeur de la constante
symbolique INDIC, on compile diff‚rentes portions de programme.     */

#include <stdio.h>
#define     INT30     30
#define     INT60     60
#define     FLO20     20
#define     FLO40     40
#define     INDIC     INT30

main()
{
     char c;
     int i;
     unsigned int u;
     float f;
     for (c = 'A'; c < 'E'; c++)
     {
     printf("%c ", c);
     #if INDIC == INT30
     for (i = 1; i <= 30000; i++);        /*     n'est compil‚ que si     */
						/*     INDIC vaut 30.     */
     #elif INDIC == INT60
     for (u = 1; u <= 60000; u++);       /*     n'est compil‚ que si      */
						/*     INDIC vaut 60.     */
     #elif INDIC == FLO20
     for (f = 1.0; f <= 2000.0; f++);    /*     n'est compil‚ que si      */
						/*     INDIC vaut 20.     */
     #elif INDIC == FLO40
     for (f = 1.0; f <= 4000.0; f++);    /*     n'est compil‚ que si      */
						/*     INDIC vaut 40.     */
     #else
     for (u = 1; u <= 45000; u++);                /* est compil‚ si INDIC */
				     /* est ind‚fini ou != 20, 30, 40, 60 */
     #endif
     }
}

