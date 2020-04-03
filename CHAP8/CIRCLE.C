/*     CIRCLE montre comment utiliser des constantes symboliques pour des nombres rÇels, des caractäres isolÇs et des suites de caractäres. Ce programme calcule la surface d'un cercle.     */
#include <stdio.h>     /* printf, scanf */
#include <conio.h>     /* getche */
/*     Constantes symboliques pour :
	      constante rÇelle (PI),
	      constantes caractäre (YES),
	      caractäres isolÇs (BEGIN, END),
	      suites de caractäres (PRINT, SCAN)
	      constante chaåne (MESSAGE, QUESTION)     */
#define     PI     3.141529
#define     YES     'y'
#define     BEGIN     {
#define     END     }
#define     PRINT     printf
#define     SCAN     scanf
#define     MESSAGE     "\n\nVotre cercle n'a pas de surface."
#define     QUESTION     "\n\nAutre calcul de cercle ? (y/n)"
main()
BEGIN
     float rayon;
     char reply = YES;
     while (reply == YES)
     BEGIN
     PRINT("\033[2J");
     PRINT("\n\nCalcul de surface de cercle. Entrez le rayon : ");
     SCAN("%f", &rayon);
     if (rayon)                                   /*     si rayon != 0     */
     PRINT("\n\nVotre cercle a une surface de %f.", rayon * rayon * PI);
     else
     PRINT(MESSAGE);
     PRINT(QUESTION);
     reply = getche();
     END
END

