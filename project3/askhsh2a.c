#include <stdlib.h>
#include <math.h>
#include <stdio.h>

double f(double x){                 //συναρτηση f
	return pow(x,4)+2*pow(x,3)+pow(x,2)+12*x+20;          
}


double df(double x){              //1η παραγωγος της f
	return 4*pow(x,3)+6*pow(x,2)+2*x+12;
}

double df2(double x){                    //2η παραγωγος της f
	return 12*pow(x,2)+12*x+2;
}

////////////////////////////////////////////////////////////////
int main() {
	
	
	int i=0;                                   //αρχικοποιηση επαναληψης i
	double x, error,krit;                     //οριζω x, σφαλμα επαναληψης, 2ο κριτηριο
	double x0=1.0;                             //αρχικη συνθηκη
	printf("   i		x	   f(x)	     error\n\n");
	do{                                                //επανελαβε οσο το σφαλμα >= 0.5x10^-8 και |f(x0)|>= 0.5x10^-8 (ακριβεια 8 δεκαδικων)
		i=i+1;                                      //αυξηση επαναληψης κατα 1
		x=x0 - f(x0)/df(x0);                          //μεθοδος N-R
		error=fabs(x-x0);                                //ορισμος σφαλματος
		krit=fabs(f(x0));                                 //ορισμος 2ου κριτηριου
		printf("\n %3d %14.8f %14.8f %14.8f",i,x,f(x),error);     //εκτυπωση επαναληψης, προσεγγισης, τιμης της f στην προσεγγιση, σφαλμα
		x0=x;                                                           //νεο x0=προηγουμενη προσεγγιση
	}while(   (error>=0.5*pow(10.0,-8.0)) && (krit>=0.5*pow(10.0,-8.0))       );
	
	printf("\n\n ROOT: %14.8f \n\n",x);                        //εκτυπωση ριζας
	return 0;
}

