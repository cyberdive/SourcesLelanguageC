/*  Ce programme montre comment d‚finir et utiliser des variables.
Le programme n'affichant rien, on omet ici l'inclusion du header d'entr‚e-sortie STDIO.H via l'instruction pr‚processeur : #include <<stdio.h>>  */

main()
 {
	char c;     /*  D‚finition d'une variable char */
	int i, j;   /*  D‚finition de deux variables int */
	float f;    /*  D‚finition d'une variable float */
	c = 'Z';    /*  la  variable c re‡oit comme valeur le code ASCII du
                        caractŠre 'Z', donc la valeur 90  */
	i = 1;      /*  la variable i prend la valeur 1  */
	j = 2;      /*  la variable j prend la valeur 2  */
	f = 3.14;   /*  la variable f prend la valeur 3.14  */
	c = 'A';    /*  la variable c prend comme nouvelle valeur le code ASCII
                        du caractŠre 'A', donc la valeur 65. L'ancienne valeur
                        de la variable c, … savoir 65, est ‚cras‚e et
                        d‚finitivement perdue.  */
	i = j;       /* la variable i re‡oit comme nouvelle valeur la valeur
                        actuelle de la variable j, donc 2. L'ancienne valeur 1
                        de la variable i est ‚cras‚e et d‚finitivement perdue.*/
	f = -3.14;   /*  la variable f prend comme nouvelle valeur -3.14.
                         L'ancienne valeur 3.14 est ‚cras‚e et d‚finitivement
                         perdue. */ 
}
