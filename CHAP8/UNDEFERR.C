/* UNDEFERR montre une erreur produite par l'utilisation d'une constante
				    symbolique d‚j… effac‚e par #undef     */
#include <stdio.h>
#define PRINT printf
main()
{
     PRINT("\nCette instruction utilise la constante symbolique PRINT et non"
						  "la commande printf.\n\n");
#undef PRINT                          /* efface la d‚finition de PRINT     */
     PRINT("Cette instruction engendre une erreur car la constante symbolique "
     "PRINT n'est plus valable.");
}

