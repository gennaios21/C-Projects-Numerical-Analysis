#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100.0


//////////////////////////////////////////////////             / f1,f2,f3

double f1(double x1,double x2,double x3,int k){                  //f1
	return pow(x1,3)+4*x1*pow(x2,2)+3*pow(x3,3)-10.0 +2.0*(1-k/N);
}

double f2(double x1,double x2,double x3,int k){                  //f2
	return pow(x1,2)+5*pow(x1,2)*pow(x2,2)-3*pow(x3,2)+5.0-8.0*(1-k/N);
}

double f3(double x1,double x2,double x3,int k){                  //f3
	return pow(x1,4)+5*x1*x2+2*x3-2.0 -6*(1-k/N);
}

//////////////////////////////////////////////////////         /// df1
double df1_x1(double x1,double x2,double x3){  //df1_x1
	return 3.0*pow(x1,2)+4.0*pow(x2,2);
}

double df1_x2(double x1,double x2,double x3){  //df1_x2
	return 8.0*x1*x2;
}

double df1_x3(double x1,double x2,double x3){  //df1_x3
	return 9.0*pow(x3,2);
}

////////////////////////////////////////////////////////////// df2
double df2_x1(double x1,double x2,double x3){  //df2_x1
	return 2.0*x1+10*x1*pow(x2,2);
}

double df2_x2(double x1,double x2,double x3){ //df2_x2
	return 10.0*pow(x1,2)*x2;
}

double df2_x3(double x1,double x2,double x3){ //df2_x3
	return -6.0*x3;
}

////////////////////////////////////////////////////////////// df3
double df3_x1(double x1,double x2,double x3){  //df3_x1
	return 4.0*pow(x1,3)+5*x2;
}

double df3_x2(double x1,double x2,double x3){   //df3_x2
	return 5.0*x1;
}

double df3_x3(double x1,double x2,double x3){   //df3_x3
	return 2.0;
}

/////////////////////////////////////////////////////////////////////////////////////// det2x2
double det2x2(double a11,double a12,double a21, double a22){
	return a11*a22-a12*a21;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////// det3x3
double det3x3(double a11,double a12,  double a13, double a21, double a22,  double a23,double a31,double a32,double a33){
	
	return a11*det2x2(a22,a23,a32,a33) - a12*det2x2(a21,a23,a31,a33) + a13*det2x2(a21,a22,a31,a32);
}

//////////////////////////////////////////////////////

int main() {
	double error,DET,DETdx1,DETdx2,DETdx3;    //σφαλμα, οριζουσες Κραμερ      
	double dx1,dx2,dx3;           //διορθωσεις dx1,dx2,dx3
	double x1=1.0;       //αρχικες τιμες x1,x2,x3
	double x2=1.0;
	double x3=1.0;
	int i=0,k=0;
	do{
		k=k+1; //επιλυση κ-συστηματος
		i=0;
		printf("\n\n\n k =%3d",k); //εκτυπωση του τρεχοντος κ-συστηματος
		printf("\n x1=%10.5f 	x2=%10.5f	 x3=%10.5f\n",x1,x2,x3); //εκτυπωση των τρεχοντων αρχικων τιμων
		do{
			i=i+1;                   //οριζουσες μεθοδου Κραμερ
			DET=det3x3( df1_x1(x1,x2,x3),df1_x2(x1,x2,x3),df1_x3(x1,x2,x3),
						df2_x1(x1,x2,x3),df2_x2(x1,x2,x3),df2_x3(x1,x2,x3),
						df3_x1(x1,x2,x3),df3_x2(x1,x2,x3),df3_x3(x1,x2,x3));
						
			DETdx1=det3x3( -f1(x1,x2,x3,k),df1_x2(x1,x2,x3),df1_x3(x1,x2,x3),
						   -f2(x1,x2,x3,k),df2_x2(x1,x2,x3),df2_x3(x1,x2,x3),
						   -f3(x1,x2,x3,k),df3_x2(x1,x2,x3),df3_x3(x1,x2,x3));
						   
			DETdx2=det3x3( df1_x1(x1,x2,x3),-f1(x1,x2,x3,k),df1_x3(x1,x2,x3),
						   df2_x1(x1,x2,x3),-f2(x1,x2,x3,k),df2_x3(x1,x2,x3),
						   df3_x1(x1,x2,x3),-f3(x1,x2,x3,k),df3_x3(x1,x2,x3));
			
			DETdx3=det3x3( df1_x1(x1,x2,x3),df1_x2(x1,x2,x3),-f1(x1,x2,x3,k),
						   df2_x1(x1,x2,x3),df2_x2(x1,x2,x3),-f2(x1,x2,x3,k),
						   df3_x1(x1,x2,x3),df3_x2(x1,x2,x3),-f3(x1,x2,x3,k));
			
			
			
			dx1=DETdx1/DET;      //μεθοδος Κραμερ για ευρεση των διορθωσεων
			dx2=DETdx2/DET;
			dx3=DETdx3/DET;
		
			x1=x1+dx1;                 //η επομενη λυση ισουται με την προηγουμενη+διορθωση
			x2=x2+dx2;
			x3=x3+dx3;
		
			error=fabs(dx1) + fabs(dx2)+ fabs(dx3);     //συνολικο σφαλμα απο τις 3 διορθωσεις
			
			printf("\n i=%3d  x1=%10.5f   x2=%10.5f  x3=%10.5f  f1=%10.5f  f2=%10.5f  f3=%10.5f  error=%10.1e",
						i,x1,x2,x3,f1(x1,x2,x3,k),f2(x1,x2,x3,k),f3(x1,x2,x3,k),error);  //εκτυπωση λυσεων-τιμη των συναρτησεων στις λυσεις-σφαλματος
			
		}while(error>=0.5*pow(10.0,-5.0));     //ακριβεια 5 δεκαδικων
	}while (k<N);  //μεχρι k=N
	printf("\n\n\n Telikes Lyseis Systhmatos: x1=%10.5f  x2=%10.5f  x3=%10.5f",x1,x2,x3);   //εκτυπωση τελικων λυσεων
	printf("\n");
	return 0;
	
}
