/* PRAGMESS montre comment fonctionne un pragma. Le pragma 'message' n'existe
					pas sur tous les compilateurs.     */
#pragma message("Compilation d'un programme d'essai de pragma")
#pragma message("Ces messages sont produits par le pragma 'message'")
#include <stdio.h>
main()
{
     printf("Essai de pragma");
}
#pragma message("Dernier message et fin de la compilation")

