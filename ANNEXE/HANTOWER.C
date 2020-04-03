	/*  HANTOWER simule le jeu ''Tour de Hano‹''. A l'aide d'une fonction 
	     r‚cursive, on d‚place une pile de disques d'un endroit … un autre.  */
	#include <stdio.h>
	#include <conio.h>                                               /*  getch  */
	#include <stdlib.h>                                               /*  exit  */
	int count = 0;                      /*  compte les op‚rations de d‚placement  */
	main()
	{
	   void movedisk(short disks, short from, short to, short via);
	   short d, one = 1, two = 2, three = 3;
	   printf("\033[2J");
	   printf("\nTOUR DE HANOI : Combien de disques … d‚placer (minimum : 1) ?");
	   scanf("%hd", &d);
	   if (d < 1)
	   exit(1);
	   else
	   movedisk(d, one, three, two);
	}
	void movedisk(short disks, short from, short to, short via)
	{
	   if (disks == 1)                      /*  disque 1 : fin de la r‚cursivit‚  */
	   {
	   printf("\nDisque %d\tde la baguette %hd vers la baguette %hd", count+1, from, to);
	   count++;
	   if (count % 21 == 0)                         /*  Stop aprŠs 21 op‚rations  */
	   {
	   printf("\n\n<Entr‚e> pour continuer.\n");
	   getch();
	   }
	   }
	   else
	   {
	   movedisk(disks-1, from, via, to);               /*  pile de n-1 sur baguette 
	                                                                interm‚diaire */
	   printf("\nDisque %d\tde la baguette %hd vers la baguette %hd", count+1, from, to);
	   count++;
	   if (count % 21 == 0)
	   {
	   printf("\n\n<Entr‚e> pour continuer.\n");
	   getch();
	   }
	   movedisk(disks-1, via, to, from);     /*  pile de n-1 sur position finale  */
	   }
	}


