	/*  CHECKTEX d�termine le nombre de caract�res, de mots et de phrases d'un 
	     texte saisi au clavier. Il calcule, en outre, la longueur moyenne des 
	     phrases exprim�e en caract�res et en mots.
	     Selon, le syst�me d'exploitation, on remplacera <CTRL>+<Z> (fin de 
	     saisie) par la combinaison de touches ad hoc.  */
	#include <stdio.h>                                  /*  printf, getchar, EOF  */
	main()
	{
	   char buffer [2001];                              /*  buffer pour le texte  */
	   int i = 0;
	   struct text
	   {
	   int characters;
	   int words;
	   int sentences;
	   float slenc;                       /*  longueur des phrases en caract�res  */
	   float slenw;                             /*  longueur des phrases en mots  */
	   } t = {0};                        /*  initialise � 0 tous les champs de t  */
	   printf("\033[2J");
	   printf("\n\nLe programme compte caract�res, mots et phrases dans \n"
	   "un texte que vous saisissez (2000 caract�res au plus).\n");
	   printf("Entrez votre texte (Fin par <CTRL>+<Z>):\n\n");
	/*  saisie du texte  */
	   while ((buffer[ i ] = getchar()) != EOF)
	   {
	   if (i > 1999)
	   {
	   printf("\n\nTrop de caract�res. Les 2000 premiers sont enregistr�s.");
	   break;
	   }
	   i++;
	   }
	   buffer[ i ] = '\0';                           /*  ajout du  caract�re nul  */
	/*  calculs  */
	   i = 0;
	   while (buffer[ i ] != 0)
	   {
	   if (buffer[ i ] == ' ')
	   t.words++;                                            /*  compte les mots  */
	   if ((buffer[ i ] == '.' || buffer[ i ] == '!' || buffer[ i ] == '?')  &&  buffer[i+1] == ' ')
	   t.sentences++;                                     /*  compte les phrases  */
	   t.characters++;                                 /*  compte les caract�res  */
	   i++;
	   }
	/*  affiche les r�sultats  */
	   printf("\n\nLe texte saisi comporte %d caract�res, %d mots et %d phrases.",
	   t.characters, t.words+1, t.sentences+1);
	   t.slenc = (float) t.characters / (t.sentences+1);      /*  nb caract�res par 
	                                                                       phrase  */
	   t.slenw = (float) t.words / (t.sentences+1);       /*  nb mots par phrase  */
	   printf("\n\nUne phrase fait en moyenne %.1f caract�res et %.1f mots.",
	   t.slenc, t.slenw);
	}

