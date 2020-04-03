	/*  MORSE lit des caractäres Morse et les traduit en clair. Le texte en clair 
	     est rangÇ dans un tampon dynamique. Un mot non cryptÇ est ajoutÇ Ö la fin 
	     du texte dÇjÖ prÇsent.  */
	#include <stdio.h>                                        /*  printf, gets  */
	#include <string.h>                                     /*  strcmp, strcat  */
	#include <stdlib.h>                                /*  realloc, free, exit  */
	main()
	{
	   struct alphabet
	   {
	   char *morse;                                         /*  caractäres Morse  */
	   char symbol;                                       /*  caractäre en clair  */
	   } list [46] = {                               /*  Table de correspondance  */
	   /*  1 ÇlÇment   */	".", 'e', "-", 't',
	   /*  2 ÇlÇments  */	"..", 'i', ".-", 'a', "-.", 'n', "--", 'm',
	   /*  3 ÇlÇments  */	"...", 's', "..-", 'u', ".-.", 'r', ".--", 'w',
	                    	"-..", 'd', "--.", 'g', "-.-", 'k', "---", 'o',
	   /*  4 ÇlÇments  */	"....", 'h', "...-", 'v', "..-.", 'f', ".-..", 'l',
	   				".-.-", 'Ñ', ".--.", 'p', "..--", 'Å', ".---", 'j',
	   				"-...", 'b', "-.-.", 'c', "-..-", 'x', "--..", 'z',
	   				"---.", 'î', "--.-", 'q', "-.--", 'y',
	   /*  5 ÇlÇments  */	".----", '1', "..---", '2', "...--", '3', "....-", '4',
	   				".....", '5', "-....", '6', "--...", '7', "---..", '8',
	   				"----.", '9', "-----", '0',
	   /*  6 ÇlÇments  */	".-.-.-", '.', "--..--", ',', "---...", ':',
	   				"-....-", '-', "..--..", '?', "...-.-", '\0',
	   NULL, '\0'
	   };
	   struct alphabet *p [7];           /*  tableau de pointeurs vers le dÇbut des 
	                                   sous-ensembles Ö 1, 2, 3, 4, 5 et 6 ÇlÇments 
	                                               de la table de correspondance  */
	   struct alphabet *start;                          /*  variable de contrìle  */
	   char *text = NULL;            /*  pointeur vers tableau textuel dynamique  */
	   char letter [20];                                 /*  tampon pour lettres  */
	   char cword [129];                            /*  tampon pour mot en Morse  */
	   char decword [130];                /*  tampon pour mot en clair. 1 caractäre 
	                                        de plus pour l'espace entre les mots  */
	   int i, j, k, m, n;                              /*  variables de contrìle  */
	   unsigned bloc = 0;                          /*  taille du bloc de mÇmoire  */
	   int ok;                                     /*  Flag pour saisie correcte  */
	   printf("\033[2J");
	   printf("DECODAGE DE MORSE.\n\n");
	   printf("SÇparateur entre lettres : <ESPACE>\n");
	   printf("SÇparateur entre mots : <EntrÇe>\n");
	   printf("Fin par \"...-.-\" sur ligne sÇparÇe.\n\n");
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
	   
	   for (i = 0; cword[ i ] != '\0'; i++)            /*  contrìle de la saisie  */
	   if (cword[ i ] != ' '  &&  cword[ i ] != '.'  && cword[ i ] != '-')
	   {
	   printf("\n\nLa saisie contient des caractäres invalides.\n\n");
	   ok = 0;
	   break;
	   }
	   if (!ok)                                            /*  si saisie erronÇe  */
	   continue;                                                /*  nouvel essai  */
	   /*******************   lecture du Morse ******************/
	   for (i = 0; cword[ i ] != '\0'; (cword[j] != '\0') ? (i = j+1) : (i = j))
	   {
	   /**************  dÇcodage lettre  ************/
	   for (j = i, k = 0; cword[j] != ' '  &&  cword[j] != '\0'; k++, j++)
	   letter[k] = cword[j];
	   letter[k] = '\0';
	   start = p[strlen(letter)];    /*  ptr vers dÇbut du sous-tableau concernÇ  */
	   /****************  recherche dans la table  **********/
	   while (strcmp(letter, start->morse)  &&  start->morse != NULL)
	   start++;
	   if (start->morse)                           /*  le caractäre est contenu  */
	   decword[n] = start->symbol;
	   else                                   /*  le caractäre n'est pas contenu  */
	   decword[n] = '*';                       /*  symbole pour caractäre erronÇ  */
	   n++;
	   }                                                     /*  Fin for externe  */
	   decword[n] = ' ';          /*  ajout symbole de sÇparation au mot suivant  */
	   decword[n+1] = '\0';                                  /*  fin du dÇcodage  */
	   /**************  allocation mÇmoire pour texte dÇcodÇ  */
	   if ((text = (char *) realloc(text, bloc + strlen(decword) + 1)) == NULL)
	   {
	   printf("\n\nErreur mÇmoire");
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


