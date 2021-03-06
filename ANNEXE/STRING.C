	void getstr(char *s)       /*  saisie string : version avec acc�s via index  */
	{
	   int i = 0, c;
	   do
	   {
	   c = getchar();
	   s[i++] = c;
	   } while (c != '\n');
	   s[--i] = '\0';
	}
	void getstr(char *s)                     /*  version avec acc�s via pointeur  */
	{
	   do
	   {
	   *s = getchar();
	   } while (*s++ != '\n');
	   *--s = '\0';
	}
	
	void putstr(char *s)                                 /*  affichage de cha�ne  */
	{
	   while (*s)
	   {
	   putchar(*s);
	   s++;
	   }
	}
	
	char *strcopy(char to[ ], char from[ ])           /*  copie de string : version 
	                                                                  avec index  */
	{
	   int i = 0;
	   while (from[ i ] != '\0')
	   {
	   to[ i ] = from[ i ];
	   i++;
	   }
	   to[ i ] = '\0';
	   return(to);
	}
	void strcopy(char *to, char *from)    /*  copie de strings : version concise  */
	{                                               /*  pas de valeur de retour   */
	   while (*to++ = *from++)
	   ;
	}
	
	int strlen(char *s)                      /*  calcul de longueur d'une cha�ne  */
	{
	   int n = 0;
	   while (s[n])
	   n++;
	   return (n);
	}
	
	char *strct(char first[ ], char second[ ])  /*  concat�ne 'second' � 'first'  */
	{
	   int i = 0, k = 0;
	   while (first[ i ])                          /*  aller � la fin de 'first'  */
	   i++;
	   while (first[i++] = second[k++])             /*  accrocher seconde cha�ne  */
	   ;
	   return (first);
	}
	
	int strcomp(char *first, char *second)            /*  compare strings : version 
	                                                                  avec index  */
	{
	   int i;
	   for (i = 0; first[ i ] == second[ i ]; i++)
	   if (first[ i ] == '\0')                                 /*  strings �gaux  */
	   return (0);
	   return (first[ i ] - second[ i ]);       /*  donne la diff�rence des valeurs 
	                           des deux caract�res pour lesquels first et second se 
	                                          diff�rencient pour la premi�re fois : 
	                         < 0 pour first < second > 0 pour first > second  */
	}
	int strcomp(char *first, char *second)       /*  compare strings : version avec 
	                                                                    pointeur  */
	{
	   while (*first == *second)
	   {
	   if (!*first)                                            /*  strings �gaux  */
	   return (0);
	   first++;
	   second++;
	   }
	   return (*first - *second);
	}


