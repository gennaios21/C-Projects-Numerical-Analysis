#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define pi M_PI 


double f(double r){                 //συναρτηση f
	double k=0.01+r*r;
	return 2-(18*r)/(35.4*pi*pow(k,1.5));          
}


double df(double r){              //1η παραγωγος της f
	double k=0.01+r*r;
	return (-18/(35.4*pi*pow(k,3)))*(pow(k,1.5)-3*r*r*pow(k,0.5));
}


////////////////////////////////////////////////////////////////
int main() {
	
	
	int i=0;                                            //αρχικοποιηση επαναληψης i
	double r, error;                                 //οριζω r, σφαλμα επαναληψης
	double r0=0.0;                                    //αρχικη συνθηκη
	printf("   i		r	   f(r)	     error\n\n");
	do{                                                //επανελαβε οσο το σφαλμα >= 0.5x10^-10 (ακριβεια 10 δεκαδικων) και η αποσταση r ειναι θετικη
		i=i+1;                                           //αυξηση επαναληψης κατα 1
		r=r0 - f(r0)/df(r0);                              //μεθοδος N-R
		error=fabs(r-r0);                                //ορισμος σφαλματος
		printf("\n %3d %14.10f %14.10f %14.10f",i,r,f(r),error);     //εκτυπωση επαναληψης, προσεγγισης, τιμης της f στην προσεγγιση, σφαλματος
		r0=r;                                                           //νεο r0=προηγουμενη προσεγγιση
	}while(   (error>=0.5*pow(10.0,-10.0)) && r>0 );
	
	printf("\n\n ROOT 1: %14.10f \n\n",r);                        //εκτυπωση ριζας
	printf("\n\n");
	// διαφορετικη αρχικη τιμη για την ευρεση της 2ης ριζας
	i=0;
	r0=0.3;                                    
	printf("   i		r	   f(r)	     error\n\n");
	do{                                               
		i=i+1;                                       
		r=r0 - f(r0)/df(r0);                            
		error=fabs(r-r0);                               
		printf("\n %3d %14.10f %14.10f %14.10f",i,r,f(r),error);     
		r0=r;                                                          
	}while(   (error>=0.5*pow(10.0,-10.0)) && r>0);
	
	printf("\n\n ROOT 2: %14.10f \n\n",r);                      
	return 0;
}

