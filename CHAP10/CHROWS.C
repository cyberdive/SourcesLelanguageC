/***  CHROWS montre comment accÇder aux lignes d'un tableau 2D.  ***/      
/***  Les diverses lignes du tableau peuvent àtre temporairement ***/
/***  modifiÇes par l'utilisateur.                               ***/

#include <stdio.h>                                                  /* printf */
#include <conio.h>                                                   /* getch */

#define START   0
#define TOP   5
#define BOTTOM   13
#define ESC   27
#define ARROW   80   /* scancode de la fläche */

#define CLEAR()   printf("\033[2J")                         /* efface l'Çcran */
#define REVERSE() printf("\033[7m")                        /* inversion vidÇo */
#define NORMAL()  printf("\033[0m")                       /* affichage normal */
#define SKIP()    printf("\n\n")                     /* gÇnäre une ligne vide */
#define POS(x,y)  printf("\033[%d;%dH", x, y)           /* positionne curseur */

int row = START;                                          /* variable globale */

void change_row(char m[][4]);                             /* dÇplace la barre */

void showall(char m[][4]);                         /* affiche tout le tableau */
void shownums(char *r);            /* affiche une ligne sous forme de nombres */
void showchars(char *r);        /* affiche une ligne sous forme de caractäres */

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
                    input = getch();                     /* rÇcupäre scancode */
                    if (input == ARROW)                 /* fläche vers le bas */
                        ok = 1;
                 }
              else if (input == ESC)                      /* fin du programme */
                 ok = 1;
            } while (!ok);
       } while (input != ESC);
  }

void change_row(char m[][4])       /* change et affiche la ligne sÇlectionnÇe */
  {
     
     static int i;
   
     if (row == START)                                     /* dÇbut programme */
       {
         POS(TOP, 10);
         showchars(m[0]);                     /* passage de la premiäre ligne */
         row = 5;                                /* premiäre ligne en ligne 5 */
       }
     else if (row == BOTTOM)                       /* derniäre ligne atteinte */
       {
         POS(row, 10);
         shownums(m[4]);                /* derniäre ligne en affichage normal */
         row = 5;
         POS(row, 10);
         showchars(m[0]);                /* premiäre ligne en inversion vidÇo */
         i = 0;                 /* continue avec 1äre ligne dans branche else */
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
  {                                      /* paramätre = pointeur vers char[4] */
     int i, k;
     
     for (i = 0; i < 5; i++)
        {
           for (k = 0; k < 4; k++)
               printf("%d  ", m[i][k]);
               SKIP();
        }
  }

void showchars(char *r)                                  /* affiche une ligne */
  {                                       /* paramätre : pointeur vers 'char' */
     int i;
   
     REVERSE();
     for (i = 0; i < 4; i++)
         printf(" %c  ", r[i]);
         NORMAL();
   }

void shownums(char *r)                                   /* affiche une ligne */
  {                                       /* paramätre : pointeur vers 'char' */
     int i;
  
     for (i = 0; i < 4; i++)
          printf("%d  ", r[i]);
  }
