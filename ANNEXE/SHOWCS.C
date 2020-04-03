	extern char buffer[11];
	extern int fd;
	extern STRLEN=10;        
	
	void showcs(void)                           /*  affiche strings no x … no y  */
	{
	   long startno, endno;                       /*  num‚ros de d‚but et de fin  */
	   int bytes, result, count;
	   do
	   {
	   count = 0;
	   printf("\n\nNum‚ros des strings (format de saisie : d‚but-fin) : ");
	   result = scanf("%ld-%ld", &startno, &endno);
	   } while((startno<1 || startno > 500)  || (endno < startno || endno > 500)  || (result != 2));
	   lseek(fd, (startno-1)*10, 0);
	   while (startno <= endno)
	   {
	   bytes = read(fd, buffer, STRLEN);
	   printf("\n");
	   write(1, buffer, bytes);
	   startno++;
	   count++;
	   if (count == 20)
	   count = nextpage();
	   }
	}


