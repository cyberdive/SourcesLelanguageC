/***  CHROWS montre comment acc�der aux lignes d'un tableau 2D.  ***/      
/***  Les diverses lignes du tableau peuvent �tre temporairement ***/
/***  modifi�es par l'utilisateur.                               ***/

#include <stdio.h>                                                  /* printf */
#include <conio.h>                                                   /* getch */

#define START   0
#define TOP   5
#define BOTTOM   13
#define ESC   27
#define ARROW   80   /* scancode de la fl�che */

#define CLEAR()   printf("\033[2J")                         /* efface l'�cran */
#define REVERSE() printf("\033[7m")                        /* inversion vid�o */
#define NORMAL()  printf("\033[0m")                       /* affichage normal */
#define SKIP()    printf("\n\n")                     /* g�n�re une ligne vide */
#define POS(x,y)  printf("\033[%d;%dH", x, y)           /* positionne curseur */

int row = START;                                          /* variable globale */

void change_row(char m[][4]);                             /* d�place la barre */

void showall(char m[][4]);                         /* affiche tout le tableau */
void shownums(char *r);            /* affiche une ligne sous forme de nombres */
void showchars(char *r);        /* affiche une ligne sous forme de caract�res */

main()
  {
     char matrix [5][4] = { {67, 79, 76, 68}, {67, 79, 82, 68}, 
                            {87, 79, 82, 68}, {87, 65, 82, 68}, 
                            {87, 65, 82, 77} };
   
     int ok, input;
   
     CLEAR();
     showall(matrix);                                      /* affiche tableau */
     
     do
       {
         ok = 0;
         change_row(matrix);       /* transforme et affiche la ligne actuelle */
         
         do
            {
              POS(17,10);
              printf("Touche \031 change la ligne. Fin par <ECHAP> : ");
              input = getch();
              if (input == 0)                    /* touche fonction/direction */
                 {
                    input = getch();                     /* r�cup�re scancode */
                    if (input == ARROW)                 /* fl�che vers le bas */
                        ok = 1;
                 }
              else if (input == ESC)                      /* fin du programme */
                 ok = 1;
            } while (!ok);
       } while (input != ESC);
  }

void change_row(char m[][4])       /* change et affiche la ligne s�lectionn�e */
  {
     
     static int i;
   
     if (row == START)                                     /* d�but programme */
       {
         POS(TOP, 10);
         showchars(m[0]);                     /* passage de la premi�re ligne */
         row = 5;                                /* premi�re ligne en ligne 5 */
       }
     else if (row == BOTTOM)                       /* derni�re ligne atteinte */
       {
         POS(row, 10);
         shownums(m[4]);                /* derni�re ligne en affichage normal */
         row = 5;
         POS(row, 10);
         showchars(m[0]);                /* premi�re ligne en inversion vid�o */
         i = 0;                 /* continue avec 1�re ligne dans branche else */
       }
     else                                                    /* autres lignes */
       {
         POS(row, 10);
         shownums(m[i++]);
         POS(row+2, 10);
         showchars(m[i]);
         row = row + 2;
       }
  }

void showall(char m[][4])                          /* affiche tout le tableau */
  {                                      /* param�tre = pointeur vers char[4] */
     int i, k;
     
     for (i = 0; i < 5; i++)
        {
           for (k = 0; k < 4; k++)
               printf("%d  ", m[i][k]);
               SKIP();
        }
  }

void showchars(char *r)                                  /* affiche une ligne */
  {                                       /* param�tre : pointeur vers 'char' */
     int i;
   
     REVERSE();
     for (i = 0; i < 4; i++)
         printf(" %c  ", r[i]);
         NORMAL();
   }

void shownums(char *r)                                   /* affiche une ligne */
  {                                       /* param�tre : pointeur vers 'char' */
     int i;
  
     for (i = 0; i < 4; i++)
          printf("%d  ", r[i]);
  }
