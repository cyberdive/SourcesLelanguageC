	/*  PARTLST3 range un nombre quelconque de chaŒnes de caractŠres dans une liste 
	     chaŒn‚e double.  */
	#include <stdio.h>                                        /*  printf, gets  */
	#include <string.h>                                     /*  strcmp, strcpy  */
	#include <stdlib.h>                                 /*  malloc, free, exit  */
	#include <conio.h>                                       /*  getche, getch  */
	#define HEADER(s)   printf("LISTE PARTICIPANTS\t\t\t\t\tPage %d\n", s);\
	   for (j = 0; j < 57; j++) printf("_"); printf("\n")
	main()
	{
	   typedef struct chaine
	   {
	   char *s;
	   struct chaine *pre;
	   struct chaine *next;
	   } string;
	   string *base;                            /*  pointeur vers d‚but de liste  */
	   string *end;                               /*  pointeur vers fin de liste  */
	   string *new;                             /*  pointeur vers nouvel ‚l‚ment  */
	   string *lastin;                    /*  pointeur vers dernier ‚l‚ment tri‚  */
	   string *a;                                       /*  variable de contr“le  */
	   char buffer [128];                                   /*  buffer de saisie  */
	   int i;                                            /*  compteur de chaŒnes  */
	   int s = 1;                                          /*  compteur de pages  */
	   int j, k, rep;                                  /*  variables de contr“le  */
	   /****************  allocation d'espace pour premier ‚l‚ment ************/
	   if ((base = (string *) malloc(sizeof(string))) == NULL)
	   {
	   printf("\n\nPas de m‚moire !");
	   exit(1);                                          /*  sortie du programme  */
	   }
	   i = 0;                          /*  initialise compteur d'enregistrements  */
	   end = new = lastin = base;                   /*  avant lecture du premier  */
	   base->pre = base->next = NULL;       /*  ‚l‚ment : initialise pointeurs  */
	   printf("\033[2J");
	   printf("CREATION D'UNE LISTE TRIEE DE PARTICIPANTS\n");
	   printf("\nFormat de saisie :\tNom, Pr‚nom (R‚gion)\n\n");
	   do
	   {
	   printf("\n\nParticipant %d (Fin par <Entr‚e>) : ", i+1);
	   gets(buffer);
	   if (strlen(buffer))                                 /*  pas fin de saisie  */
	   {
	   /*************  allocation m‚moire  *********************/
	   if ((new->s = (char *) malloc(strlen(buffer) + 1)) == NULL)
	   {
	   printf("\n\nErreur m‚moire. DerniŠre saisie non m‚moris‚e.");
	   if (i > 0)                             /*  au moins 1 string a ‚t‚ saisi  */
	   {
	   printf("\n\nAfficher les participants d‚j… saisis ? (o/n)");
	   rep = getche();
	   if (rep == 'o')
	   break;                                                     /*  fin boucle  */
	   }
	   exit(1);                                          /*  sinon fin programme  */
	   }
	   strcpy(new->s, buffer);   /*  ranger string dans nouvel ‚l‚mt  */
	   /************  trier nouvel ‚l‚ment  ***********************/
	   if (strcmp(new->s, base->s) <= 0)     /*  nouvel ‚l‚ment <= premier ?  */
	   {
	   if (new != base)                              /*  seulement si au moins 1  */
	   {   /*  ‚l‚ment disponible  */
	   new->pre = NULL;                       /*  trier nouveau premier ‚l‚ment  */
	   new->next = base;
	   base->pre = new;
	   base = new;
	   }
	   }
	   else if (strcmp(new->s, end->s) >= 0)        /*  nouveau >= dernier ?  */
	   {
	   if (new != base)                                /*  seulement si au moins  */
	   {   /*  1 ‚l‚ment disponible  */
	   new->pre = end;                                /*  trier nouveau dernier  */
	   new->next = NULL;
	   end->next = new;
	   end = new;
	   }
	   }
	   else if (strcmp(new->s, lastin->s) >= 0) /*  nouveau >= dernier ins‚r‚ */
	   {
	   if (new != base)                                /*  seulement si au moins  */
	   {                                                /*  1 ‚l‚ment disponible  */
	   /***** d‚termine position du nouvel ‚l‚ment *****/
	   for (a=lastin; strcmp(a->next->s, new->s) < 0; a = a->next)
	   ;
	   new->pre = a;                                      /*  insertion nouveau  */
	   new->next = a->next;
	   a->next->pre = new;
	   a->next = new;
	   }
	   }
	   else                                        /*  nouveau < dernier ins‚r‚  */
	   {
	   /******** d‚termine position du nouvel ‚l‚ment ********/
	   for(a = lastin; strcmp(new->s, a->pre->s) < 0; a = a->pre)
	   ;
	   new->pre = a->pre;                                /*  insertion nouveau  */
	   new->next = a;
	   a->pre->next = new;
	   a->pre = new;
	   }
	   lastin = new;                 /*  actualise pointeur vers dernier ‚l‚ment  */
	   /********  allocation m‚moire pour ‚l‚ment suivant  *******/
	   if ((new = (string *) malloc(sizeof(string))) == NULL)
	   {
	   printf("\n\nPlus de place en m‚moire. <Entr‚e> pour continuer.");
	   getch();
	   i++;                                             /*  MAJ compteur enregs.  */
	   break;                                               /*  sortie de boucle  */
	   }
	   i++;
	   }                                               /*  Fin if(strlen(buffer)  */
	   } while (strlen(buffer));
	   /*************  affichage des enregistrements  *****************************/
	   if (i > 0)                          /*  au moins un enregistrement saisi  */
	   {
	   printf("\033[2J");
	   printf("\n\nNombre d'enregistrements saisis : %d", i);
	   printf("\n\nAFFICHER ENREGISTREMENTS :\n\n");
	   printf("Tri‚s par ordre ascendant\t\t(a)\n");
	   printf("Tri‚s par ordre descendant\t\t(d)\n");
	   printf("\nFin par appui sur une autre touche\n\n");
	   printf("Votre choix : ");
	   rep = getche();
	   switch (rep)
	   {
	   case 'a':
	   printf("\033[2J");
	   HEADER(s);                                                    /*  en-tˆte  */
	   for (a = base, k = 1; a != NULL; a = a->next, k++)
	   {
	   printf("\n\n%d\t%-s", k, a->s);
	   if ((k%9) == 0 && k != i)
	   {
	   printf("\n\nPage suivante par <Entr‚e>.");
	   getch();
	   printf("\033[2J");
	   s++;                                                /*  compteur de pages  */
	   HEADER(s);
	   }
	   }
	   break;
	   case 'd':   
	   printf("\033[2J");
	   HEADER(s);                                                    /*  en-tˆte  */
	   for (a = end, k = 1; a != NULL; a = a->pre, k++)
	   {
	   printf("\n\n%d\t%-s", k, a->s);
	   if ((k%9) == 0 && k != i)
	   {
	   printf("\n\n Page suivante par <Entr‚e>.");
	   getch();
	   printf("\033[2J");
	   s++;                                                /*  compteur de pages  */
	   HEADER(s);
	   }
	   }
	   break;
	   default:
	   ;
	   }
	   /*******************  lib‚ration m‚moire  ************************/
	   for (a = base; a != NULL; a = new)
	   {
	   new = a->next;                           /*  sauver prochaine adresse avant 
	                                        lib‚ration de l'‚l‚ment contenu … cette 
	                                    adresse. Sinon, cette adresse serait perdue 
	                                  et on ne pourrait plus acc‚der … la liste.  */
	   free(a);
	   }
	   }                                                       /*  Fin if i > 0  */
	}                                                              /*  Fin main  */


