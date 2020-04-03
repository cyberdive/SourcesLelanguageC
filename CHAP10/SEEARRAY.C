/*** SEEARRAY utilise des pointeurs de fonctions comme paramŠtres ***/

#include <stdio.h>                                                  /* printf */
#include <stdlib.h>                                            /* srand, rand */
#include <conio.h>                                            /* getch, kbhit */
#include <time.h>                                                     /* time */

unsigned  init;                                   /* variable d'initialisation */

main()
	{

	/* fonctions de saisie sp‚cifiques pour les tableaux */

	 void fillchar(char *a, long len);
	 void fillshort(short *a, long len);
	 void fillong(long *a, long len);
	 void fillfloat(float *a, long len);
	 void filldouble(double *a, long len);

/* fonctions d'affichage sp‚cifiques pour les tableaux */

	 void printchar(char *a, long s, long e);
	 void printshort(short *a, long s, long e);
	 void printlong(long *a, long s, long e);
	 void printfloat(float *a, long s, long e);
	 void printdouble(double *a, long s, long e);

/* fonctions d'E/S g‚n‚rales pour les tableaux */

  /*	 void fill_array(void *arr, long len, void (*fill) (void * , long));*/

	 void fill_array(void *arr, long len, void (*fill) ());
	 /*void display_array(void *arr, long start, long end, void (*d)(void*, long, long));*/

	 void display_array(void *arr, long start, long end, void (*d)());

	 void wait(long sec);                                 /* fonction de pauses */


	 char c[1000];
	 short s[100];
	 long l[100];
	 float f[100];
	 double d[100];
	 int number, i;
	 long index[2];                   /* valeurs al‚a. pour bornes sous-tableau */

	 while (!kbhit())
		 {
			 srand(++init);            /* initialise le g‚n‚rateur al‚atoire 'rand' */
			 if(init == 65535)
					init = 1;
					number = rand() % 5 + 1;
														/* tirage entre 1 et 5 (1 = char, 2 = short, etc. */

					do                             /* bornes al‚atoires du sous-tableau */
						 {
							 for (i = 0; i < 2; i++)
								 index[i] = (number != 1) ? rand()%100 : rand()%1000;
						 } while (index[0] >= index[1]);

					wait(3);                     /* 3 secondes avant prochain affichage */
					printf("\033[2J\n");

											/* changement al‚atoire d'affichage : \033[3xm = texte, */
																													 /* \033[4xm = fond */
					printf("\033[%d;%dm", 31+number, 42+number);

					switch(number)                       /* choix du tableau … afficher */
						{
						 case 1: printf("C H A R :\n\n");
												fill_array(c, 1000, fillchar);
												display_array(c, index[0], index[1], printchar);

												break;

						 case 2:
										 printf("S H O R T :\n\n");
										 fill_array(s, 100, fillshort);
										 display_array(s, index[0], index[1], printshort);

										 break;

						 case 3:
										 printf("L O N G :\n\n");
										 fill_array(l, 100, fillong);
										 display_array(l, index[0], index[1] ,printlong);

										 break;

						 case 4:
										 printf("F L O A T :\n\n");
										 fill_array(f, 100, fillfloat);
										 display_array(d, index[0], index[1], printfloat);

										 break;

						 case 5:
										 printf("D O U B L E :\n\n");
										 fill_array(d, 100, filldouble);
										 display_array(d, index[0], index[1], printdouble);
						}
		 }
	 printf("\033[0m");   /* ‚cran normal */
	}
/* saisie de valeurs dans tableaux de types divers */

/*void fill_array(void *arr, long len,void (*fill)(void *, long))*/

void fill_array(void *arr, long len,void (*fill)(void *, long))

 {
	 (*fill)(arr, len);
 }

void fillchar(char *a, long len)   /* remplit tableau 'char' avec valeurs al‚a. */
 {
	 long i;
	 srand(++init);
	 for (i = 0; i < len; i++)
		 {
			 a[i] = (rand() % 96) + 32;
		 }
 }

void fillshort(short *a, long len)   /* remplit tableau 'short' avec valeurs al‚a. */
 {
	 long i;
	 srand(++init);
	 for (i = 0; i < len; i++)
			 a[i] = rand();
 }

void fillong(long *a, long len)   /* remplit tableau 'long' avec valeurs al‚a. */
 {
	 long i;
	 srand(++init);
	 for (i = 0; i < len; i++)
			 a[i] = (long) rand() * rand();
 }

void fillfloat(float *a, long len)   /* remplit tableau 'float' avec valeurs al‚a. */
 {
	 long i;
	 srand(++init);
	 for (i = 0; i < len; i++)
			a[i] = (float) rand() / 32767;
 }

void filldouble(double *a, long len)   /* remplit tableau 'double' avec valeurs al‚a. */
 {
	 long i;
	 srand(++init);
	 for (i = 0; i < len; i++)
		 a[i] = (double) rand() / 32767;
 }

/* affiche diff‚rents types de tableaux */
void display_array(void *arr, long start, long end, void (*f)(void*, long, long))
 {
	 (*f)(arr,start, end);
 }

void printchar(char *a, long s, long e)   /* affiche tableau char */
 {
	 long i;
	 for (i = s;  i <= e; i++)
			 printf("%c", a[i]);
 }

void printshort(short *a, long s, long e)   /* affiche tableau short  */
 {
	 long i;
	 for (i = s;  i <= e; i++)
		 {
			 printf("%5hd  ", a[i]);
			 if (((i+1)%10) == 0)
				 printf("\n");
		 }
 }

void printlong(long *a, long s, long e)   /* affiche tableau long */
 {
	 long i;
	 for (i = s;  i <= e; i++)
			{
				printf("%10ld  ", a[i]);
				if (((i+1)%6) == 0)
					 printf("\n");
			}
 }

void printfloat(float *a, long s, long e)   /* affiche tableau float  */
 {
	 long i;
	 for (i = s;  i <= e; i++)
			{
				printf("%f  ", a[i]);
				if (((i+1)%6) == 0)
					 printf("\n");
			}
 }

void printdouble(double *a, long s, long e)   /* affiche tableau double */
 {
	 long i;
	 for (i = s;  i <= e; i++)
				printf("%.12f  ", a[i]);
 }

void wait(long sec)   /* fonction d'attente */
 {
	 long start, current;
	 time(&start);
	 do
		 {
			 time(&current);
		 } while ((current - start) < sec);
 }
