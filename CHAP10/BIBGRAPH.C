/*** BIBGRAPH produit une bibliographie de longueur quelconque.             ***/
/*** Les enregistrements sont rang‚s sous forme de structures dont la       ***/
/*** gestion est assur‚e par des fonctions sp‚cifiques.                     ***/

#include <stdio.h>                                                  /* printf */
#include <conio.h>                                                   /* getch */
#include <stdlib.h>                              /* realloc, free, atoi, atof */
#include <string.h>                                                 /* strcpy */

#define BACKSPACE   8
#define BLANK      32
#define ESC        27
#define T_LEFT    218                               /* cadre sup‚rieur gauche */
#define T_RIGHT   191                                /* cadre sup‚rieur droit */
#define B_LEFT    192                               /* cadre inf‚rieur gauche */
#define B_RIGHT   217                               /* cadre inf‚rieur droit  */
#define HZTL      196                                     /* trait horizontal */
#define VRTL      179                                       /* trait vertical */

#define F_YELL()   printf("\033[33m")                       /* texte en jaune */
#define F_NORM()   printf("\033[37m")                         /* texte normal */
#define REVERSE()  printf("\033[7m")                       /* inversion vid‚o */
#define NORMAL()   printf("\033[0m")                          /* ‚cran normal */
#define POS(x,y)   printf("\033[%d;%dH", x, y)      /* positionnement curseur */
#define CLEAR()    printf("\033[2J")                          /* efface ‚cran */
#define HEADER()   printf(" BIBLIOGRAPHIE ")
#define MESSAGE()   printf("<Entr‚e> pour continuer. Fin par <ECHAP> : ")

void box(int row, int col, int high, int wide);            /* dessin de cadre */
void menu(void);                                    /* affiche menu de saisie */
void handle_error(void);                                 /* gestion d'erreurs */
void readstruc(struct livre4 *b);                         /* saisie structure */
void writestruc(struct livre4 *b);                    /* affichage structure  */
void cleanup(void);                               /* efface saisie pr‚c‚dente */
char *check_input(int len);                             /* contr“le de saisie */

struct livre4                        /* d‚clare structure des enregistrements */
	{
		 char nom[21];                                    /* d‚clar‚e globalement */
		 char prenom[21];                                          /* afin que le */
		 char titre[51];                                  /* type de donn‚es soit */
		 char editeur[21];                                           /* connu par */
		 char ville[21];                                            /* toutes les */
		 short an;                                                   /* fonctions */
		 float prix;                                                /* concern‚es */
	};

main()
	{
		 struct livre4 *blist = NULL;                 /* NULL … cause de realloc. */
		 struct livre4 *bkp;         /* sauve adr. du bloc au cas o— blist = NULL */
		 int i, k, rep;                                  /* variables de contr“le */
		 menu();                                   /* affiche le masque de saisie */

		 /***  saisie des enregistrements  ********/

		 i = 0;
		 do
			 {
				 bkp = blist;                                /* sauve adresse du bloc */
				 if ((blist = (struct livre4 *) realloc(blist, (i+1) *
											 sizeof(struct livre4))) == NULL)
						 {
								handle_error();        /* traitement d'erreur si pointeur nul */
								break;
						 }

				 cleanup();                               /* efface saisie pr‚c‚dente */
				 POS(3,69);
				 printf("%d", i+1);                    /* affiche no d'enregistrement */
				 readstruc(&blist[i]);                       /* saisie enregistrement */
				 i++;
				 POS(21,57);
				 rep = getch();
			 } while (rep != ESC);

	 /***  affichage des enregistrements ************/

			 if(i > 0)                                 /* au moins une fiche saisie */
					{
						 box(23,5,3,70);
						 POS(24, 8);
             printf("Afficher les enregistrements ? (O/N) ");
             rep = getch();
             if (rep == 'o' || rep == 'O')
                {
                   CLEAR();
                   if(blist == NULL)
                      blist = bkp;
                      
                      for (k = 0; k < i; k++)
                          {
                            printf("\n");
                            writestruc(&blist[k]);
                            if (((k+1)%3 == 0) && k != i-1)  /* nouvelle page */
                               {
                                 POS(24,50);
                                 printf("<Entr‚e> pour continuer : ");
																 getch();
																 CLEAR();
                               }
                          }                                        /* fin for */
                }                                          /* fin if (rep...) */
             free(blist);                                   /* libŠre m‚moire */
          }                                                 /* fin if (i > 0) */
	}                                                               /* fin main */

void menu(void)                                   /* cr‚e le masque de saisie */
  {
     CLEAR();
     box(2, 5, 19, 70);                                              /* cadre */
     POS(2,30);
     HEADER();                                                       /* titre */
     POS(21,20);
     MESSAGE();                                              /* message guide */
     POS(3,65);
     printf("No");
     POS(6,8);
		 printf("NOM :");
     POS(6, 40);
     printf("PRENOM :");
     POS(9,8);
     printf("TITRE :");
     POS(12,8);
     printf("EDITEUR :");
     POS(15, 8);
     printf("VILLE :");
     POS(15, 40);
     printf("AN :");
     POS(18, 8);
     printf("PRIX :");
  }

void box(int row, int col, int high, int wide)               /* dessine cadre */
  {
     int i, k;
     
     F_YELL();                                              /* cadre en jaune */
		 POS(row, col);                             /* partie sup‚rieure du cadre */
     printf("%c", T_LEFT);
		 for (i = 1; i < wide-2; i++)
				 printf("%c", HZTL);
				 printf("%c", T_RIGHT);

		 for (i = 1; i <= high-2; i++)                 /* partie m‚diane du cadre */
				 {
					 POS(row+i, col);
					 printf("%c", VRTL);
					 for (k = 1; k < wide-2; k++)
							 printf("%c", BLANK);
							 printf("%c", VRTL);
				 }

		 POS(row+high-1, col);                       /* partie inf‚rieur du cadre */
		 printf("%c", B_LEFT);
		 for (i = 1; i < wide-2; i++)
				 printf("%c", HZTL);
				 printf("%c", B_RIGHT);
				 F_NORM();                                            /* texte normal */
	}

void handle_error(void)                       /* routine de gestion d'erreurs */
	{
		 box(12, 18, 5, 44);
     POS(13, 19);
     REVERSE();                                            /* inversion vid‚o */
     printf("                                         ");
     POS(14, 19);
     printf(" Plus assez de m‚moire. ");
     POS(15, 19);
		 printf("                                         ");
		 NORMAL();                                            /* affichage normal */
	}

void readstruc(struct livre4 *b)                /* saisie des enregistrements */
	{
		 char *input;
		 POS(6,8);
		 REVERSE();                    /* met en ‚vidence champ de saisie courant */
		 printf("NOM :");
		 NORMAL();                                 /* saisie en couleurs normales */
		 POS(6,14);
		 input = check_input(20);             /* contr“le : maximum 20 caractŠres */
		 strcpy(b->nom, input);                               /* stockage donn‚es */
		 POS(6,8);
		 printf("NOM :");                            /* champ de saisie en normal */

		 /***  idem pour autres champs de saisie  ***/

		 POS(6,40); REVERSE(); printf("PRENOM :");
		 NORMAL(); POS(6,49); input = check_input(20);
		 strcpy(b->prenom, input); POS(6,40); printf("PRENOM :");
		 POS(9,8); REVERSE(); printf("TITRE :");
		 NORMAL(); POS(9,16); input = check_input(50);
		 strcpy(b->titre, input); POS(9,8); printf("TITRE :");
		 POS(12,8); REVERSE(); printf("EDITEUR :");
		 NORMAL(); POS(12,18); input = check_input(20);
		 strcpy(b->editeur, input); POS(12,8); printf("EDITEUR :");
		 POS(15,8); REVERSE();printf("VILLE :");
		 NORMAL(); POS(15,16); input = check_input(20);
		 strcpy(b->ville, input); POS(15,8); printf("VILLE :");
		 POS(15,40); REVERSE(); printf("ANNEE :");
		 NORMAL(); POS(15,48); input = check_input(4);
		 b->an = atoi(input);                              /* convertit et stocke */
		 POS(15,40); printf("ANNNE :");
		 POS(18,8); REVERSE(); printf("PRIX :");
		 NORMAL(); POS(18,15); input = check_input(10);
		 b->prix = atof(input);                            /* convertit et stocke */
		 POS(18,8); printf("PRIX :");
	}

void writestruc(struct livre4 *b)                  /* affiche enregistrements */
	{
		 printf("\n\n%s %s", b->prenom, b->nom);
		 printf("\n%s", b->titre);
		 printf("\n%s", b->editeur);
		 printf("\n%s %hd", b->ville, b->an);
		 printf("\n%.2f", b->prix);
	}

void cleanup(void)                                /* efface saisie pr‚c‚dente */
	{
		 int i, k;

		 struct coo                      /* conserve les coordonn‚es d'effacement */
			 {
				 int row;                                                    /* ligne */
				 int col;                                                  /* colonne */
				 int blanks;                           /* nb. de caractŠres … effacer */
			 } c[7] = { {6,14,25}, {6,49,20}, {9,15,50},
									{12,16,50}, {15,13,25}, {15,46,20}, {18,15,50} };

		 for (i = 0; i < 7; i++)
			 {
				 POS(c[i].row, c[i].col);
				 for (k = 0; k < c[i].blanks; k++)
            printf("%c", BLANK);
       }
	}

char *check_input(int len)                                /* saisie contr“l‚e */
  {
     int i = 0;
     int c;
     int func_or_cursorkey = 0;                  /* flag pour touche sp‚ciale */
     static char buffer[81];       /* 'static' car l'adresse de ce buffer est */
                                          /* renvoy‚e comme valeur de retour. */
                                     /* Une variable 'auto' serait inad‚quate */
                                     /* car d‚truite … la fin de la fonction. */
   
     while ((i < len) &&  ((c = getch()) != '\r'))
        {
          if (func_or_cursorkey)       /* saisie pr‚c‚dente = touche sp‚ciale */
            {
              func_or_cursorkey = 0;
              continue;                        /* ignorer saisie (= scancode) */
            }
    
					if (c == 0)                                      /* touche sp‚ciale */
            {
              func_or_cursorkey = 1;                      /* positionner flag */
            }
          else if (c == BACKSPACE)                        /* <RETOUR ARRIERE> */
            {
               if(i > 0)                        /* au moins 1 caractŠre saisi */
                 {            /* curseur ne peut reculer plus loin que pos. 1 */
                    printf("\b \b");            /* efface car. … gauche, puis */ 
                                                            /* recule curseur */
                    i--;         /* pour effacer le car. dans le buffer aussi */
                 }
            }
          else                                            /* caractŠre valide */
            {
               buffer[i++] = c;                           /* stocke caractŠre */
               putchar(c);                               /* affiche caractŠre */
            }
        }
     buffer[i] = '\0';                                    /* fin de la saisie */
   
     return (buffer);                     /* renvoie adresse buffer de saisie */
  }
