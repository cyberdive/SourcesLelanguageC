	/*  PUT20 affiche une saisie sous forme de lignes d'au moins 20 caract�res.
	En outre, chaque ligne doit se terminer au plus tard sur la prochaine fin de
	mot (c'est � dire qu'apr�s les 20 premiers caract�res, on saute � la ligne
	lorsqu'on arrive � la premi�re fin de mot rencontr�e). Les lignes sont �galement
	num�rot�es. La combinaison clavier relative au caract�re  de fin EOF d�pend
	du syst�me d'exploitation utilis�. PUT20 emploie les ouches <CTRL>+<Z> pour
	DOS.  */
	
	#include <stdio.h>                              /*  getchar, putchar, printf  */
	
	main()
	   {
	      int n = 0;                                  /*  compteur de caract�res  */
	      int line = 1;                                   /*  compteur de lignes  */
	      int c;
	
	      printf("\033[2J");
	      printf("Entrez du texte. Fin par <CTRL>+<Z>:\n");
	
	      while((c = getchar()) != EOF)
	         {
	            n++;
	
	            if (n == 1)
	               printf("%d\t", line)             /*  afficher num�ro de ligne  */
	            if (n < 21)
	               {
	                  putchar(c);
	                  if ( c == '\n')           /*  attention � la buff�risation de 
	                                        getchar. Si le dernier caract�re lu est 
	                                         <Entr�e>, la derni�re ligne affich�e a 
	                                             �t� termin�e par <Entr�e> avant le 
	                                                            20�me caract�re.  */
	                     {
	                        line++;                /*  augmenter num�ro de ligne  */
	                        n = 0;      /*  r�initialiser : d�but nouvelle ligne  */
	                     }
	               }
	         else if (c == ' ')    /*  si fin de mot apr�s 20 caract�res ou plus  */
	            {
	               printf("\n");                              /*  nouvelle ligne  */
	               line++;                         /*  augmenter num�ro de ligne  */
	               n = 0;                                      /*  r�initialiser  */
	            }
	         else                      /*  afficher caract�res entre position 20 et 
	                                                prochain espace (fin de mot)  */
	            putchar(c);
	      }                                                        /*  fin while  */
	   }                                                           /*  fin main  */

