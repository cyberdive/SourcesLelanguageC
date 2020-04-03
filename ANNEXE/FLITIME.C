	/*  flitime calcule … partir des saisies : 
	        distance de vol
	        vitesse de vol
	        vitesse du vent
	        la dur‚e du vol et l'affiche au format HH:MM  */
	
	#include <stdio.h>                                    /*  pour printf, scanf  */
	
	main()
	  {
	       long d_km;                                         /*  distance en km  */
	       long d_m;                                      /*  distance en mŠtres  */
	       long v_km;                                        /*  vitesse en km/h  */
	       long v_ms;                                       /*  vitesse en m/sec  */
	       long vv_km;                               /*  vitesse du vent en km/h  */
	       long vv_ms;                              /*  vitesse du vent en m/sec  */
	       long t_sec;                                     /*  dur‚e en secondes  */
	       long t_hour;                                       /*  dur‚e : heures  */
	       long t_min;                                       /*  dur‚e : minutes  */
	
	   printf("\033[2J");
	
	   printf("Distance en km : ");
	   scanf("%ld", &d_km);
	   printf("Vitesse en km/h : ");
	   scanf("%ld", &v_km);
	   printf("Vitesse du vent km/h (n‚gative pour vent contraire) : ");
	   scanf("%ld", &vv_km);
	
	   d_m = d_km * 1000;                                 /*  distance en mŠtres  */
	   v_ms = 1000 * v_km / 3600;                             /*  vitesse en m/s  */
	   vv_ms = 1000 * vv_km /3600;                  /*  vitesse du vent en m/sec  */
	
	   t_sec = d_m / (v_ms - vv_ms);                       /*  dur‚e en secondes  */
	   t_min = t_sec / 60;                                  /*  dur‚e en minutes  */
	   t_hour = t_min / 60;                                   /*  dur‚e : heures  */
	   t_min = t_min % 60;                                   /*  dur‚e : minutes  */
	   printf("\n\nDur‚e : %ld:%ld", t_hour, t_min);
	}

