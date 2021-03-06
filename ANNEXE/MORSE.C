	/*  MORSE lit des caract�res Morse et les traduit en clair. Le texte en clair 
	     est rang� dans un tampon dynamique. Un mot non crypt� est ajout� � la fin 
	     du texte d�j� pr�sent.  */
	#include <stdio.h>                                        /*  printf, gets  */
	#include <string.h>                                     /*  strcmp, strcat  */
	#include <stdlib.h>                                /*  realloc, free, exit  */
	main()
	{
	   struct alphabet
	   {
	   char *morse;                                         /*  caract�res Morse  */
	   char symbol;                                       /*  caract�re en clair  */
	   } list [46] = {                               /*  Table de correspondance  */
	   /*  1 �l�ment   */	".", 'e', "-", 't',
	   /*  2 �l�ments  */	"..", 'i', ".-", 'a', "-.", 'n', "--", 'm',
	   /*  3 �l�ments  */	"...", 's', "..-", 'u', ".-.", 'r', ".--", 'w',
	                    	"-..", 'd', "--.", 'g', "-.-", 'k', "---", 'o',
	   /*  4 �l�ments  */	"....", 'h', "...-", 'v', "..-.", 'f', ".-..", 'l',
	   				".-.-", '�', ".--.", 'p', "..--", '�', ".---", 'j',
	   				"-...", 'b', "-.-.", 'c', "-..-", 'x', "--..", 'z',
	   				"---.", '�', "--.-", 'q', "-.--", 'y',
	   /*  5 �l�ments  */	".----", '1', "..---", '2', "...--", '3', "....-", '4',
	   				".....", '5', "-....", '6', "--...", '7', "---..", '8',
	   				"----.", '9', "-----", '0',
	   /*  6 �l�ments  */	".-.-.-", '.', "--..--", ',', "---...", ':',
	   				"-....-", '-', "..--..", '?', "...-.-", '\0',
	   NULL, '\0'
	   };
	   struct alphabet *p [7];           /*  tableau de pointeurs vers le d�but des 
	                                   sous-ensembles � 1, 2, 3, 4, 5 et 6 �l�ments 
	                                               de la table de correspondance  */
	   struct alphabet *start;                          /*  variable de contr�le  */
	   char *text = NULL;            /*  pointeur vers tableau textuel dynamique  */
	   char letter [20];                                 /*  tampon pour lettres  */
	   char cword [129];                            /*  tampon pour mot en Morse  */
	   char decword [130];                /*  tampon pour mot en clair. 1 caract�re 
	                                        de plus pour l'espace entre les mots  */
	   int i, j, k, m, n;                              /*  variables de contr�le  */
	   unsigned bloc = 0;                          /*  taille du bloc de m�moire  */
	   int ok;                                     /*  Flag pour saisie correcte  */
	   printf("\033[2J");
	   printf("DECODAGE DE MORSE.\n\n");
	   printf("S�parateur entre lettres : <ESPACE>\n");
	   printf("S�parateur entre mots : <Entr�e>\n");
	   printf("Fin par \"...-.-\" sur ligne s�par�e.\n\n");
	   printf("Morse :\n\n");
	   p[1] = &list[0];
	   p[2] = &list[2];
	   p[3] = &list[6];
	   p[4] = &list[14];
	   p[5] = &list[29];
	   p[6] = &list[39];
	   do
	   {
	   ok = 1;
	   n = 0;
	   gets(cword);
	   
	   for (i = 0; cword[ i ] != '\0'; i++)            /*  contr�le de la saisie  */
	   if (cword[ i ] != ' '  &&  cword[ i ] != '.'  && cword[ i ] != '-')
	   {
	   printf("\n\nLa saisie contient des caract�res invalides.\n\n");
	   ok = 0;
	   break;
	   }
	   if (!ok)                                            /*  si saisie erron�e  */
	   continue;                                                /*  nouvel essai  */
	   /*******************   lecture du Morse ******************/
	   for (i = 0; cword[ i ] != '\0'; (cword[j] != '\0') ? (i = j+1) : (i = j))
	   {
	   /**************  d�codage lettre  ************/
	   for (j = i, k = 0; cword[j] != ' '  &&  cword[j] != '\0'; k++, j++)
	   letter[k] = cword[j];
	   letter[k] = '\0';
	   start = p[strlen(letter)];    /*  ptr vers d�but du sous-tableau concern�  */
	   /****************  recherche dans la table  **********/
	   while (strcmp(letter, start->morse)  &&  start->morse != NULL)
	   start++;
	   if (start->morse)                           /*  le caract�re est contenu  */
	   decword[n] = start->symbol;
	   else                                   /*  le caract�re n'est pas contenu  */
	   decword[n] = '*';                       /*  symbole pour caract�re erron�  */
	   n++;
	   }                                                     /*  Fin for externe  */
	   decword[n] = ' ';          /*  ajout symbole de s�paration au mot suivant  */
	   decword[n+1] = '\0';                                  /*  fin du d�codage  */
	   /**************  allocation m�moire pour texte d�cod�  */
	   if ((text = (char *) realloc(text, bloc + strlen(decword) + 1)) == NULL)
	   {
	   printf("\n\nErreur m�moire");
	   exit(1);
	   }
	   if (bloc == 0)
	   strcpy(text, decword);
	   else
	   strcat(text, decword);                           /*  ajout du nouveau mot  */
	   bloc = bloc + strlen(decword) + 1;           /*  actualise taille du bloc  */
	   } while (strcmp(cword, "...-.-"));
	   if (strlen(text))                                    /*  tableau non vide  */
	   {
	   printf("\n\nLe texte donne en clair :\n\n");
	   printf("%s", text);
	   }
	   free(text);
	}


