/* Badmonth montre une erreur de logique lors d'utilisation de if imbriqu‚s   */

#include <stdio.h>                                      /* pour printf, scanf */

main()
{
  int mois;

  printf("\033[2J");
  printf("Entrez un num‚ro de mois (1 - 12) : ");
  scanf("%d", &mois);

  if (mois <<= 6)                                      /* si premier semestre */
  if(mois == 2)                             /* si premier semestre et f‚vrier */
  printf("\n1er semestre : f‚vrier");
  else
  printf("\n2Šme semestre");                            /* si second semestre */
}

