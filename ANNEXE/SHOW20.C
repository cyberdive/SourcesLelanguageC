	#include <stdio.h>
	#include <io.h>
	#include <stdlib.h>
	#include <string.h>
	#include <conio.h>
	#include <ctype.h>

	extern int fd;
	extern char buffer[11];
	extern STRLEN;
	
	void show20(void)             /*  affiche 20 strings de num‚ros quelconques  */
	{
	   int check_entry(char *s);                          /*  contr“le de saisie  */
	   char inbuf[512];                                     /*  tampon de saisie  */
	   char abuf[11];                             /*  tampon alpha. pour nombres  */
	   long nums[20];                                    /*  num‚ros des strings  */
	   int i, k, n, ok;                                /*  variables de contr“le  */
	   int bytes;                                             /*  caractŠres lus  */
	   int result;                            /*  r‚sultat du contr“le de saisie  */
	   do
	   {
	   ok = 1;
	   fflush(stdin);                  /*  Prophylaxie : vidage tampon de saisie  */
	   printf("\n\nNum‚ros des strings (20 num‚ros maximum. "
	   "Format de saisie : no1+no2+no3+...) :\n\n");
	   gets(inbuf);
	   /*  contr“le de la saisie  */
	   if ((result = check_entry(inbuf)) < 0)
	   {
	   fprintf(stderr, "\nSaisie non valide.");
	   ok = 0;
	   continue;
	   }
	   i = n = 0;
	   while (inbuf[ i ])
	   {
	   k = 0;
	   /*  extraction du num‚ro de string  */
	   while (inbuf[ i ] != '+'  &&  inbuf[ i ] != '\0')
	   abuf[k++] = inbuf[i++];
	   abuf[k] = '\0';
	   if ((nums[n] = atol(abuf)) < 1  ||  nums[n] > 500)
	   {
	   fprintf(stderr, "\nNum‚ros 1 … 500 seulement !");
	   ok = 0;
	   break;
	   }
	   if (inbuf[ i ])
	   {
	   i++;
	   n++;
	   }
	   }
	   } while (! ok);
	   for (i = 0; i < n; i++)   /*  affiche strings  */
	   {
	   lseek(fd, (nums[ i ]-1)*10, 0);
	   bytes = read(fd, buffer, STRLEN);
	   printf("\n");
	   write(1, buffer, bytes);
	   }
	}
	
	int check_entry(char *s)    /*  contr“le validit‚ des caractŠres des strings  */
	{
	   int count, i;
	   if (! isdigit(s[0]))
	   return (-1);
	   count = i = 0;
	   while (s[ i ])
	   {
	   if (s[ i ] != '+'  &&  !isdigit(s[ i ]))
	   return (-1);
	   else if (s[ i ] == '+')
	   {
	   if (!isdigit(s[i+1]))
	   return (-1);
	   else
	   {
	   count++;
	   if (count > 19)
	   return (-1);
	   }
	   }
	   i++;
	   }
	   return(count);
	}


