#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi M_PI


///////////////////// τιμες αποστασεων ra,R,za, γωνιων φα=xa, φορτιου Q, σταθερα k
double ra=0.1;     
double xa=35.0*pi/180.0;
double R=0.05;
double za=0.4;
double Q=pow(10.0,-6.0);
double k=9.0*pow(10.0,9.0);
	
//////////////////////////////////////////// συνιστωσα Ez (με x=φ)
double Ez(double x){ 

	double A=pow(ra,2.0)+pow(R,2.0)+pow(za,2.0);
	double B=A-2*ra*R*cos(x-xa);
	double C=k*Q*za;
	
	return C/(2*pi*pow(B,1.5));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////// main
int main() {
	
    
	int n=0;	           //n= αριθμος υποδιαστηματων του διαστηματος [a,β]
	int i,j;                  //i,j για τους 2 επαναληπτικους βρογχους
	double E1a,E2a,E1b,E2b, Ea,Eb;   //μεταβλητες Εα,Ε1α,Ε2α για Εz με βημα h, μεταβλητες Εb,Ε1b,Ε2b για Εz με βημα h/2,
	double a=0.0;        //αριστερο ακρο διαστηματος  α=0
	double b=2.0*pi;     //δεξί ακρο διαστηματος β=2π
	double h,h2;         //βημα h, h2=h/2
	double xi,xj;       //xi=a+i*h, xj=a+i*h2
	double error;       //σφαλμα
	
	do{
		n++;                //αυξηση αριθμου υποδιαστηματων κατα 1 καθε φορα
		printf("------- n=%d -------\n",n);          //εκτυπωση τρεχοντος n
	////////////////////////////////////////////////////////////////////////////////////////////// κωδικας για h
		h=(b-a)/n;                            //βημα h=(b-a)/n
		E1a=h*0.5*( Ez(a) + Ez(b) );          //απο τον κανονα τραπεζιου, υπολογιζω ξεχωριστα τα h*( f(x0)/2 + f(xn)/2)
		E2a=0.0;
		Ea=0.0;
		
		for(i=1;i<n;i++){             //υπολογισμος των υπολοιπων τιμων του κανονα τραπεζιου
			xi=a+i*h;
			E2a=E2a+Ez(xi);
		}
		E2a=h*E2a;
		Ea=E1a+E2a;                  //συνολικο πεδίο σε N/C
		Ea=Ea*pow(10.0,-3.0);              //μετατροπη σε kN/C
		printf("Ez = %.8f kN/C \n",Ea);          //εκτυπωση του πεδιου με βημα h
	///////////////////////////////////////////////////////////////////////////////////////////////// κωδικας για h/2		
		h2=h*0.5;                               //ομοιως η ιδια διαδικασια, για βημα h2=h/2
		E1b=h2*0.5*( Ez(a) + Ez(b) );
		E2b=0.0;
		Eb=0.0;
		
		for(j=1;j<2*n;j++){
			xj=a+j*h2;
			E2b=E2b+Ez(xj);
		}
		E2b=h2*E2b;
		Eb=E1b+E2b;
		Eb=Eb*pow(10.0,-3.0);
		printf("Ez = %.8f kN/C \n\n",Eb);	  //εκτυπωση του πεδιου με βημα h/2
	////////////////////////////////////////////////////
		error=fabs(Ea-Eb);                 //σφαλμα=απολυτη τιμη της διαφορας των 2 υπολογισμων του πεδιου Εz
		printf("error = %.8f \n\n",error);     //εκτυπωση σφαλματος
		
	}while(error>=0.5*pow(10.0,-8.0));                 //ακριβεια 8 δεκαδικων
	
	printf("Telikh timh Ez = %.8f kN/C \n",Eb);           //εκτυπωση τελικης τιμης του πεδιου
return;
}



