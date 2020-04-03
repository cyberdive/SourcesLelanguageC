	/*  FINDCHAR recherche un caractäre saisi par l'utilisateur dans une chaåne. 
		Si le caractäre a ÇtÇ trouvÇ, alors on peut le remplacer par un autre dans
		toutes ses occurrences.
		On effectue une copie du texte original. La combinaison de touches
		<CTRL>+<Z> (marque de fin EOF) vaut pour les machines fonctionnant
		sous le systäme d'exploitation DOS. Pour d'autres systämes d'exploitation,
		il faut l'adapter en consÇquence (par exemple <CTRL>+<D> sous UNIX).  */
	#include <stdio.h>                          /*  printf, scanf, puts, getchar  */
	#include <conio.h>                                                /*  getche  */
	#include <string.h>                                               /*  strcpy  */
	main()
	{
	   char buffer [2001];                                 /*  tampon de lecture  */
	   char backup [2001];                             /*  duplicata de sÇcuritÇ  */
	   char c;                                           /*  caractäre recherchÇ  */
	   char replace;                               /*  caractäre de remplacement  */
	   int i = 0;                                       /*  variable de contrìle  */
	   int count = 0;                                 /*  compteur de caractäres  */
	   char rep1, rep2, rep3;                          /*  variables de contrìle  */
	   printf("\033[2J");
	   printf("\n\nEntrez votre texte (2000 caractäres au plus)."
				   "Fin par <CTRL>+<Z> :\n\n");
	   while ((buffer[ i ] = getchar()) != EOF)              /*  saisie du texte  */
	   {
	   if (i > 1999)
	   {
	   printf("\n\nTrop de caractäres. Les 2000 premiers sont enregistrÇs.");
	   break;
	   }
	   i++;
	   }
	   buffer[ i ] = '\0';                     /*  placement du caractäre de fin  */
	
	   printf("\n\nQuel est le caractäre Ö rechercher ?? ");
	   c = getche();
	   count = 0;                             /*  initialise compteur caractäres  */
	   i = 0;
	   while (buffer[ i ] != '\0')                    /*  recherche du caractäre  */
	   {
	   if (buffer[ i ] == c)                             /*  compte la frÇquence  */
	   count++;
	   i++;
	   }
	   if (count)                                        /*  si caractäre trouvÇ  */
	   {
	   printf("\n\nLe caractäre %c est contenu %d fois\n", c, count);
	   printf("Faut-il le remplacer ? (o/n) ");
	   rep1 = getche();
	   if (rep1 == 'o')
	   {
	   printf("\n\nDonnez le caractäre de remplacement : ");
	   replace = getche();
	   strcpy(backup, buffer);                             /*  copie de sÇcuritÇ  */
	   i = 0;
	   while (buffer[ i ] != '\0')                     /*  remplace le caractäre  */
	   {
	   if (buffer[ i ] == c)
	   buffer[ i ] = replace;
	   i++;
	   }
	   printf("\n\nTexte modifiÇ :\n\n");
	   puts(buffer);
	   printf("\n\nFaut-il rÇtablir le texte original ? (o/n) ");
	   rep2 = getche();
	   if (rep2 == 'o')
	   {
	   strcpy(buffer, backup);
	   printf("\n\nTexte restaurÇ. Affichage ? (o/n) ");
	   rep3 = getche();
	   if (rep3 == 'o')
	   {
	   puts("\n\n");
	   puts(buffer);
	   }
	   }                                                         /*  Fin if rep2  */
	   }                                                         /*  Fin if rep1  */
	   }                                                        /*  Fin if count  */
	   else
	   printf("\n\nLe caractäre %c n'a pas ÇtÇ trouvÇ dans le texte.", c);
	}                                                              /*  Fin main  */

