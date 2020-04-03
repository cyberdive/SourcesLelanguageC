	/*  PUT20 affiche une saisie sous forme de lignes d'au moins 20 caractŠres.
	En outre, chaque ligne doit se terminer au plus tard sur la prochaine fin de
	mot (c'est … dire qu'aprŠs les 20 premiers caractŠres, on saute … la ligne
	lorsqu'on arrive … la premiŠre fin de mot rencontr‚e). Les lignes sont ‚galement
	num‚rot‚es. La combinaison clavier relative au caractŠre  de fin EOF d‚pend
	du systŠme d'exploitation utilis‚. PUT20 emploie les ouches <CTRL>+<Z> pour
	DOS.  */
	
	#include <stdio.h>                              /*  getchar, putchar, printf  */
	
	main()
	   {
	      int n = 0;                                  /*  compteur de caractŠres  */
	      int line = 1;                                   /*  compteur de lignes  */
	      int c;
	
	      printf("\033[2J");
	      printf("Entrez du texte. Fin par <CTRL>+<Z>:\n");
	
	      while((c = getchar()) != EOF)
	         {
	            n++;
	
	            if (n == 1)
	               printf("%d\t", line)             /*  afficher num‚ro de ligne  */
	            if (n < 21)
	               {
	                  putchar(c);
	                  if ( c == '\n')           /*  attention … la buff‚risation de 
	                                        getchar. Si le dernier caractŠre lu est 
	                                         <Entr‚e>, la derniŠre ligne affich‚e a 
	                                             ‚t‚ termin‚e par <Entr‚e> avant le 
	                                                            20Šme caractŠre.  */
	                     {
	                        line++;                /*  augmenter num‚ro de ligne  */
	                        n = 0;      /*  r‚initialiser : d‚but nouvelle ligne  */
	                     }
	               }
	         else if (c == ' ')    /*  si fin de mot aprŠs 20 caractŠres ou plus  */
	            {
	               printf("\n");                              /*  nouvelle ligne  */
	               line++;                         /*  augmenter num‚ro de ligne  */
	               n = 0;                                      /*  r‚initialiser  */
	            }
	         else                      /*  afficher caractŠres entre position 20 et 
	                                                prochain espace (fin de mot)  */
	            putchar(c);
	      }                                                        /*  fin while  */
	   }                                                           /*  fin main  */

