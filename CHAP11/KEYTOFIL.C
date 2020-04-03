/*   KEYTOFIL Çcrit dans un fichier un texte de longueur quelconque saisi au clavier, puis l'affiche Ö la demande. Les opÇrations d'E/S sur le fichier utilisent les fonctions fgetc et fputc.   */
#include <stdio.h>   /*   fgetc, fputc, getchar, printf   */
#include <conio.h>   /*   getche, getch   */
#include <ctype.h>   /*   toupper   */
#include <stdlib.h>   /*   exit   */
#define END 64   /*   caractäre @   */
main()
{
   FILE *fp;                           /*   pointeur vers structure FILE   */
   char filename[81];                                /*   nom du fichier   */
   int i, rep1, rep2;                         /*   variables de contrìle   */
   int c;                                          /*   tampon caractäre   */
   printf("\033[2J");
   printf("Enregistrement de texte. Nom du fichier ?");
   do
   {
   printf("\n\nFichier (avec chemin) : ");
   gets(filename);
   if ((fp = fopen(filename, "r")) != NULL)
     {
     printf("\n\nFichier existant. Le remplacer ? (o/n)");
     rep1 = toupper(getche());
     if (rep1 != 'O')
       fclose(fp);
     }
   else                                 /*   fichier n'existe pas encore   */
   break;                                             /*   fin de boucle   */
   } while (rep1 != 'O');

   if (fp != NULL)                      /*   fichier Ö remplacer, donc :   */
     fclose(fp);                  /*   on ferme et on rouvre en Çcriture   */
     if ((fp = fopen(filename, "w")) == NULL)
       {
       printf("\n\nImpossible d'Çcrire dans le fichier.");
       exit(1);
       }
     printf("\n\nEntrez votre texte (fin par <@> + <EntrÇe> :\n\n");
     while ((c = getchar()) != END)        /*   Çcrit texte dans fichier   */
     fputc(c, fp);
     fclose(fp);


   /***  affichage du contenu du fichier  *************/

   printf("\n\nAfficher le fichier ? (o/n)");
   rep2 = toupper(getche());
   if (rep2 == 'O')
     {
     if ((fp = fopen(filename, "r")) == NULL)
       {
       printf("\n\nErreur d'ouverture du fichier.");
       exit(2);
       }
     printf("\033[2J");
     printf("Contenu du fichier %s :\n\n", filename);
     i = 0;
     while ((c = fgetc(fp)) != EOF)               /*   lecture d'un caractäre
							 dans le fichier   */
       {
       putchar(c);                 /* (ou putch : affichage du caractäre   */
       if (c == '\n')                           /*   comptage des lignes   */
	 i++;
	 if (i == 20)            /*   nouvelle page toutes les 20 lignes   */
	 {
	 printf("\n\n<EntrÇe> pour page suivante.");
	 getch();
	 printf("\033[2J");
	 i = 0;
	 }
       }                                                    /*   fin while */
       fclose(fp);
   }                                               /*   fin if rep2 == 'O' */
}
