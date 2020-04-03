	/*  CHECKTEX dÇtermine le nombre de caractäres, de mots et de phrases d'un 
	     texte saisi au clavier. Il calcule, en outre, la longueur moyenne des 
	     phrases exprimÇe en caractäres et en mots.
	     Selon, le systäme d'exploitation, on remplacera <CTRL>+<Z> (fin de 
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
	   float slenc;                       /*  longueur des phrases en caractäres  */
	   float slenw;                             /*  longueur des phrases en mots  */
	   } t = {0};                        /*  initialise Ö 0 tous les champs de t  */
	   printf("\033[2J");
	   printf("\n\nLe programme compte caractäres, mots et phrases dans \n"
	   "un texte que vous saisissez (2000 caractäres au plus).\n");
	   printf("Entrez votre texte (Fin par <CTRL>+<Z>):\n\n");
	/*  saisie du texte  */
	   while ((buffer[ i ] = getchar()) != EOF)
	   {
	   if (i > 1999)
	   {
	   printf("\n\nTrop de caractäres. Les 2000 premiers sont enregistrÇs.");
	   break;
	   }
	   i++;
	   }
	   buffer[ i ] = '\0';                           /*  ajout du  caractäre nul  */
	/*  calculs  */
	   i = 0;
	   while (buffer[ i ] != 0)
	   {
	   if (buffer[ i ] == ' ')
	   t.words++;                                            /*  compte les mots  */
	   if ((buffer[ i ] == '.' || buffer[ i ] == '!' || buffer[ i ] == '?')  &&  buffer[i+1] == ' ')
	   t.sentences++;                                     /*  compte les phrases  */
	   t.characters++;                                 /*  compte les caractäres  */
	   i++;
	   }
	/*  affiche les rÇsultats  */
	   printf("\n\nLe texte saisi comporte %d caractäres, %d mots et %d phrases.",
	   t.characters, t.words+1, t.sentences+1);
	   t.slenc = (float) t.characters / (t.sentences+1);      /*  nb caractäres par 
	                                                                       phrase  */
	   t.slenw = (float) t.words / (t.sentences+1);       /*  nb mots par phrase  */
	   printf("\n\nUne phrase fait en moyenne %.1f caractäres et %.1f mots.",
	   t.slenc, t.slenw);
	}

