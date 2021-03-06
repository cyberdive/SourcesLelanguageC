	/*  FINDCHAR recherche un caract�re saisi par l'utilisateur dans une cha�ne. 
		Si le caract�re a �t� trouv�, alors on peut le remplacer par un autre dans
		toutes ses occurrences.
		On effectue une copie du texte original. La combinaison de touches
		<CTRL>+<Z> (marque de fin EOF) vaut pour les machines fonctionnant
		sous le syst�me d'exploitation DOS. Pour d'autres syst�mes d'exploitation,
		il faut l'adapter en cons�quence (par exemple <CTRL>+<D> sous UNIX).  */
	#include <stdio.h>                          /*  printf, scanf, puts, getchar  */
	#include <conio.h>                                                /*  getche  */
	#include <string.h>                                               /*  strcpy  */
	main()
	{
	   char buffer [2001];                                 /*  tampon de lecture  */
	   char backup [2001];                             /*  duplicata de s�curit�  */
	   char c;                                           /*  caract�re recherch�  */
	   char replace;                               /*  caract�re de remplacement  */
	   int i = 0;                                       /*  variable de contr�le  */
	   int count = 0;                                 /*  compteur de caract�res  */
	   char rep1, rep2, rep3;                          /*  variables de contr�le  */
	   printf("\033[2J");
	   printf("\n\nEntrez votre texte (2000 caract�res au plus)."
				   "Fin par <CTRL>+<Z> :\n\n");
	   while ((buffer[ i ] = getchar()) != EOF)              /*  saisie du texte  */
	   {
	   if (i > 1999)
	   {
	   printf("\n\nTrop de caract�res. Les 2000 premiers sont enregistr�s.");
	   break;
	   }
	   i++;
	   }
	   buffer[ i ] = '\0';                     /*  placement du caract�re de fin  */
	
	   printf("\n\nQuel est le caract�re � rechercher ?? ");
	   c = getche();
	   count = 0;                             /*  initialise compteur caract�res  */
	   i = 0;
	   while (buffer[ i ] != '\0')                    /*  recherche du caract�re  */
	   {
	   if (buffer[ i ] == c)                             /*  compte la fr�quence  */
	   count++;
	   i++;
	   }
	   if (count)                                        /*  si caract�re trouv�  */
	   {
	   printf("\n\nLe caract�re %c est contenu %d fois\n", c, count);
	   printf("Faut-il le remplacer ? (o/n) ");
	   rep1 = getche();
	   if (rep1 == 'o')
	   {
	   printf("\n\nDonnez le caract�re de remplacement : ");
	   replace = getche();
	   strcpy(backup, buffer);                             /*  copie de s�curit�  */
	   i = 0;
	   while (buffer[ i ] != '\0')                     /*  remplace le caract�re  */
	   {
	   if (buffer[ i ] == c)
	   buffer[ i ] = replace;
	   i++;
	   }
	   printf("\n\nTexte modifi� :\n\n");
	   puts(buffer);
	   printf("\n\nFaut-il r�tablir le texte original ? (o/n) ");
	   rep2 = getche();
	   if (rep2 == 'o')
	   {
	   strcpy(buffer, backup);
	   printf("\n\nTexte restaur�. Affichage ? (o/n) ");
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
	   printf("\n\nLe caract�re %c n'a pas �t� trouv� dans le texte.", c);
	}                                                              /*  Fin main  */

