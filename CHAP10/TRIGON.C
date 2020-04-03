/*** TRIGON fait de la trigonom‚trie … l'aide de fonctions sp‚cifiques qui  ***/
/*** ne sont pas appel‚es par leurs noms, mais par un pointeur.             ***/
/*** Les adresses des fonctions sont rang‚es dans un tableau de pointeurs   ***/
/*** vers fonctions. */

#include <stdio.h>                                                  /* printf */
#include <math.h>                                            /* sin, cos, tan */
#include <stdlib.h>                                                   /* exit */
#include <conio.h>                                                   /* getch */
#include <ctype.h>                                                 /* isdigit */

#define BLANK     32
#define Enter     13
#define ESC       27
#define BACKSPACE  8
#define T_LEFT   218                        /* coin sup‚rieur gauche du cadre */
#define T_RIGHT  191                         /* coin sup‚rieur droit du cadre */
#define B_LEFT   192                        /* coin inf‚rieur gauche du cadre */
#define B_RIGHT  217                         /* coin inf‚rieur droit du cadre */
#define HZTL     196                                      /* trait horizontal */
#define VRTL     179                                        /* trait vertical */
#define TOP        6                              /* ligne de menu sup‚rieure */
#define BOTTOM    18                              /* ligne de menu inf‚rieure */
#define START      0
#define ARROW     80                                 /* scancode : flŠche bas */
#define PI    3.1416

#define F_CYAN()   printf("\033[36m")                   /* texte couleur cyan */
#define F_NORM()   printf("\033[37m")                         /* texte normal */
#define REVERSE()  printf("\033[7m")                       /* inversion vid‚o */
#define NORMAL()   printf("\033[0m")                          /* ‚cran normal */
#define POS(x,y)   printf("\033[%d;%dH", x, y)          /* positionne curseur */
#define CLEAR()    printf("\033[2J")                        /* efface l'‚cran */
#define ERASE(lines)   for(i = 1; i <= lines; i++)\
														{\
															POS(i+8,35);\
																for(k = 0; k < 40; k++)\
																		printf("%c", BLANK);\
														}                                /* efface lignes */


void box(int row, int col, int high, int wide);              /* dessine cadre */
void trigmenu(char *opt[]);                                   /* affiche menu */
void getangle(void);                                          /* saisie angle */
void sinus(double ang);                                      /* calcule sinus */
void cosinus(double ang);                                  /* calcule cosinus */
void tangente(double ang);                                /* calcule tangente */
void cotangente(double ang);                            /* calcule cotangente */
int select_option(char *opt[]);               /* s‚lectionne commande de menu */

/* tableau de pointeurs vers fonctions */

void (*t[5])() = {sinus, cosinus, tangente, cotangente, exit};

	int row = START;
	double angle;                                            /* angle en degr‚s */
	int i, k;                               /* variables de contr“le pour ERASE */

	main()
		{
		 /* lignes du menu */
		 char *options[ ] = {"Sinus", "Cosinus", "Tangente", "Cotangente", "Fin"};

		 int input;
		 int ok;
		 int n;                                /* no de la ligne de menu courante */
		 trigmenu(options);                                       /* affiche menu */
		 for(;;)                                                /* boucle infinie */
				{
					 ok = 0;
					 n = select_option(options);    /* s‚lection d'une commande de menu */
					 do
						 {
							 POS(21, 66);
							 input = getch();
							 if (input == 0)                             /* touche sp‚ciale */
									{
										input = getch();                     /* r‚cupŠre scancode */
										if (input == ARROW)                         /* flŠche bas */
												ok = 1;
									}
							 else if (input == Enter)
									{
										if(n != 4)                          /* pas commande "Fin" */
											 {
													getangle();                         /* saisie angle */
													(*t[n])(angle);    /* appelle fonction via pointeur */
											 }
										else
													(*t[n])(0);            /* appelle exit via pointeur */
									}
						 } while (!ok);
				}   /* fin for(;;) */
		}   /* fin main */

void trigmenu(char *opt[])                                    /* affiche menu */
	{
		 int i;

		 CLEAR();
		 box(2,8,3,61);
		 POS(3,21);
		 printf("CALCULS TRIGONOMETRIQUES");
		 for (i = 0; i < 5; i++)
				{
					box(3 * i + 5, 8, 3, 15);
					POS(3 * i + 6, 10);
					printf("%s", opt[i]);
				}

		 box(20,17,3,47);
		 POS(21,19);
		 printf("S‚lection par touche \031 suivie de <Entr‚e>=>");
		 box(20,64,3,5);
	}

void box(int row, int col, int high, int wide)              /* dessine cadre  */
	{
		 int i, k;
		 F_CYAN();                                          /* cadre couleur cyan */
		 POS(row, col);                                      /* partie sup‚rieure */
		 printf("%c", T_LEFT);
		 for (i = 1; i <= wide-2; i++)
				printf("%c", HZTL);
		 printf("%c", T_RIGHT);
		 for (i = 1; i <= high-2; i++)                          /* partie m‚diane */
				{
					 POS(row+i, col);
					 printf("%c", VRTL);
					 for (k = 1; k <= wide-2; k++)
							 printf("%c", BLANK);
							 printf("%c", VRTL);
				}

		 POS(row+high-1, col);                               /* partie inf‚rieure */
		 printf("%c", B_LEFT);
		 for (i = 1; i <= wide-2; i++)
				printf("%c", HZTL);
		 printf("%c", B_RIGHT);
		 F_NORM();                                                /* texte normal */
	}

int select_option(char *opt[])                  /* s‚lection commande de menu */
	{
		 static int i;
		 if (row == START)                                  /* d‚but de programme */
			 {
					POS(TOP, 10);
          REVERSE();
					printf("%s", opt[0]);
          NORMAL();
          row = 6;
          return(0);                    /* retourne no ligne de menu courante */
       }
     else if (row == BOTTOM)               /* position derniŠre ligne de menu */
       {
          POS(row, 10);
          printf("%s", opt[4]);
          row = 6;
          POS(row, 10);
          REVERSE();
          printf("%s", opt[0]);
          NORMAL();
          i= 0;
          return(4);                                                  /* idem */
       }
		 else                                                    /* autres lignes */
			 {
          POS(row, 10);
					printf("%s", opt[i]);
					POS(row+3, 10);
					REVERSE();
					printf("%s", opt[++i]);
					NORMAL();
					row = row + 3;
					return(i);                                                  /* idem */
			 }
	}

void getangle(void)                                           /* saisie angle */
	{
		 int c, i;
		 int func_or_cursor_key = 0;
		 char buffer[4];

		 box(8,35,9,34);
		 do
			 {
					i = 0;
					POS(10,54);
					printf("              ");
					POS(10,37);
					printf("Angle (0-360ø) : ");

					while ((i < 3) &&  ((c = getch()) != '\r'))
								{
									if (func_or_cursor_key)
										 {
												 func_or_cursor_key = 0;
												 continue;
										 }
									if(c == 0)
										 {
												 func_or_cursor_key = 1;
										 }
									else if (c == BACKSPACE)
										 {
												 if(i > 0)
														{
															 printf("\b \b");
															 i--;
														}
										 }
									else if (isdigit(c))
										 {
												 buffer[i++] = c;
												 putchar(c);
										 }
								}
					buffer[i] = '\0';
					angle = atof(buffer);
			 } while (angle > 360.0);
	}

void sinus(double ang)                                       /* calcule sinus */
	{
		 double rad;                                                   /* radians */

		 rad = PI / 180 * ang;                               /* degr‚s en radians */
		 POS(12,37);
		 printf("sinus %.1fø = %.4f", ang, sin(rad));
		 POS(14,37);
		 printf("<Entr‚e> pour continuer");
		 getch();
		 ERASE(9);                                            /* efface affichage */
	}

void cosinus(double ang)                                   /* calcule cosinus */
	{
		 double rad;

		 rad = PI / 180 * ang;
		 POS(12,37);
		 printf("cosinus %.1fø = %.4f", ang, cos(rad));
     POS(14,37);
		 printf("<Entr‚e> pour continuer");
     getch();
		 ERASE(9);
	}

void tangente(double ang)                                 /* calcule tangente */
	{
		 double rad;
		 if (ang == 90.0)                       /* tangente de 90ø: "infinie" */
				{
          POS(12, 37);
					printf("tangente %.1fø = y", ang);
        }
     else
        {
          rad = PI / 180 * ang;
          POS(12,37);
					printf("tangente %.1fø = %.4f", ang, tan(rad));
          POS(14,37);
					printf("<Entr‚e> pour continuer");
          getch();
          ERASE(9);
        }
	}

void cotangente(double ang)                             /* calcule cotangente */
  {
     double rad;
		 if (ang == 0.0)                          /* cotangente 0ø: "infinie" */
				{
          POS(12, 37);
					printf("cotangente %.1fø = y", ang);
        }
     else
        {
          rad = PI / 180 * ang;
          POS(12,37);
					printf("cotangente %.1fø = %.4f", ang, 1/tan(rad));
          POS(14,37);
					printf("<Entr‚e> pour continuer");
					getch();
					ERASE(9);
				}
	}
