#include <stdio.h>
#include <stdlib.h>
#include <math.h>

////////////////////////////////////////////////////////////////////// f1,f2,f3,f4

double f1(double x1,double x2,double x3,double x4){            //f1
	return 3.0*x2+x3*x4-7.9;
}

double f2(double x1,double x2,double x3,double x4){            //f2
	return x1+2.0*x2+x3+4.0*x4-20.7;
}

double f3(double x1,double x2,double x3,double x4){            //f3
	return pow(x1,3.0)+pow(x3,3.0)+x4-21.218;
}

double f4(double x1,double x2,double x3,double x4){            //f4
	return pow(x1,2.0)+2.0*x1*x2+pow(x4,3.0)-15.88;
}

//////////////////////////////////////////////////////////////////////// df1
double df1_x1(double x1,double x2,double x3,double x4){   //df1_x1
	return 0.0;
}

double df1_x2(double x1,double x2,double x3,double x4){  //df1_x2
	return 3.0;
}

double df1_x3(double x1,double x2,double x3,double x4){  //df1_x3
	return x4;
}

double df1_x4(double x1,double x2,double x3,double x4){  //df1_x4
	return x3;
}
///////////////////////////////////////////////////////////////////// df2
double df2_x1(double x1,double x2,double x3,double x4){  //df2_x1
	return 1.0;
}

double df2_x2(double x1,double x2,double x3,double x4){  //df2_x2
	return 2.0;
}

double df2_x3(double x1,double x2,double x3,double x4){  //df2_x3
	return 1.0;
}

double df2_x4(double x1,double x2,double x3,double x4){  //df2_x4
	return 4.0;
}
////////////////////////////////////////////////////////////////////// df3
double df3_x1(double x1,double x2,double x3,double x4){  //df3_x1
	return 3.0*pow(x1,2.0);  
}

double df3_x2(double x1,double x2,double x3,double x4){  //df3_x2
	return 0.0;
}

double df3_x3(double x1,double x2,double x3,double x4){  //df3_x3
	return 3.0*pow(x3,2.0);
}

double df3_x4(double x1,double x2,double x3,double x4){ //df3_x4
	return 1.0; 
}
/////////////////////////////////////////////////////////////////// df4
double df4_x1(double x1,double x2,double x3,double x4){  //df4_x1
	return 2.0*x1+2.0*x2;
}

double df4_x2(double x1,double x2,double x3,double x4){  //df4_x2
	return 2.0*x1;
}

double df4_x3(double x1,double x2,double x3,double x4){ //df4_x
	return 0.0;
}

double df4_x4(double x1,double x2,double x3,double x4){  //df4_x4
	return 3*pow(x4,2.0);
}


/////////////////////////////////////////////////////////////////////////////////////// det2x2
double det2x2(double a11,double a12,double a21, double a22){
	return a11*a22-a12*a21;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////// det3x3
double det3x3(double a11,double a12,double a13, double a21, double a22,double a23,double a31,double a32,double a33){
	
	return a11*det2x2(a22,a23,a32,a33) - a12*det2x2(a21,a23,a31,a33) + a13*det2x2(a21,a22,a31,a32);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////// det4x4
double det4x4(double a11,double a12,double a13,double a14,
 			  double a21, double a22,double a23,double a24,
			  double a31,double a32,double a33,double a34,
			  double a41,double a42,double a43,double a44){
			  	
	return   a11*det3x3(a22,a23,a24,a32,a33,a34,a42,a43,a44) -
			 a12*det3x3(a21,a23,a24,a31,a33,a34,a41,a43,a44) +
			 a13*det3x3(a21,a22,a24,a31,a32,a34,a41,a42,a44) -
			 a14*det3x3(a21,a22,a23,a31,a32,a33,a41,a42,a43) ;
}


///////////////////////////////////////////////////////////////////////////////////////////////////// main
////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
	double error,DET,DETdx1,DETdx2,DETdx3,DETdx4;   //σφαλμα, οριζουσες Κραμερ
	double dx1,dx2,dx3,dx4;          //διορθωσεις dx1,dx2,dx3,dx4
	
	double x1=1.0;                   //αρχικες τιμες x1,x2,x3,x4
	double x2=1.0;
	double x3=1.0;
	double x4=1.0;
	int i=0;
	
	do{
		i=i+1;              //οριζουσες μεθοδου Κραμερ
		DET=det4x4( df1_x1(x1,x2,x3,x4),df1_x2(x1,x2,x3,x4),df1_x3(x1,x2,x3,x4),df1_x4(x1,x2,x3,x4),
					df2_x1(x1,x2,x3,x4),df2_x2(x1,x2,x3,x4),df2_x3(x1,x2,x3,x4),df2_x4(x1,x2,x3,x4),
					df3_x1(x1,x2,x3,x4),df3_x2(x1,x2,x3,x4),df3_x3(x1,x2,x3,x4),df3_x4(x1,x2,x3,x4),
					df4_x1(x1,x2,x3,x4),df4_x2(x1,x2,x3,x4),df4_x3(x1,x2,x3,x4),df4_x4(x1,x2,x3,x4));
		
		DETdx1=det4x4(  -f1(x1,x2,x3,x4),df1_x2(x1,x2,x3,x4),df1_x3(x1,x2,x3,x4),df1_x4(x1,x2,x3,x4),
						-f2(x1,x2,x3,x4),df2_x2(x1,x2,x3,x4),df2_x3(x1,x2,x3,x4),df2_x4(x1,x2,x3,x4),
						-f3(x1,x2,x3,x4),df3_x2(x1,x2,x3,x4),df3_x3(x1,x2,x3,x4),df3_x4(x1,x2,x3,x4),
						-f4(x1,x2,x3,x4),df4_x2(x1,x2,x3,x4),df4_x3(x1,x2,x3,x4),df4_x4(x1,x2,x3,x4));
		
		DETdx2=det4x4(  df1_x1(x1,x2,x3,x4),-f1(x1,x2,x3,x4),df1_x3(x1,x2,x3,x4),df1_x4(x1,x2,x3,x4), 
						df2_x1(x1,x2,x3,x4),-f2(x1,x2,x3,x4),df2_x3(x1,x2,x3,x4),df2_x4(x1,x2,x3,x4),
						df3_x1(x1,x2,x3,x4),-f3(x1,x2,x3,x4),df3_x3(x1,x2,x3,x4),df3_x4(x1,x2,x3,x4),
						df4_x1(x1,x2,x3,x4),-f4(x1,x2,x3,x4),df4_x3(x1,x2,x3,x4),df4_x4(x1,x2,x3,x4));
						
		DETdx3=det4x4(  df1_x1(x1,x2,x3,x4),df1_x2(x1,x2,x3,x4),-f1(x1,x2,x3,x4),df1_x4(x1,x2,x3,x4), 
						df2_x1(x1,x2,x3,x4),df2_x2(x1,x2,x3,x4),-f2(x1,x2,x3,x4),df2_x4(x1,x2,x3,x4),
						df3_x1(x1,x2,x3,x4),df3_x2(x1,x2,x3,x4),-f3(x1,x2,x3,x4),df3_x4(x1,x2,x3,x4),
						df4_x1(x1,x2,x3,x4),df4_x2(x1,x2,x3,x4),-f4(x1,x2,x3,x4),df4_x4(x1,x2,x3,x4));
						
		DETdx4=det4x4(  df1_x1(x1,x2,x3,x4),df1_x2(x1,x2,x3,x4),df1_x3(x1,x2,x3,x4),-f1(x1,x2,x3,x4), 
						df2_x1(x1,x2,x3,x4),df2_x2(x1,x2,x3,x4),df2_x3(x1,x2,x3,x4),-f2(x1,x2,x3,x4),
						df3_x1(x1,x2,x3,x4),df3_x2(x1,x2,x3,x4),df3_x3(x1,x2,x3,x4),-f3(x1,x2,x3,x4),
						df4_x1(x1,x2,x3,x4),df4_x2(x1,x2,x3,x4),df4_x3(x1,x2,x3,x4),-f4(x1,x2,x3,x4));
		
	
		
		dx1=DETdx1/DET;      //μεθοδος Κραμερ για ευρεση των διορθωσεων
		dx2=DETdx2/DET;
		dx3=DETdx3/DET;
		dx4=DETdx4/DET;
		
		x1=x1+dx1;                 //η επομενη προσεγγιση λυσης ισουται με την προηγουμενη+διορθωση
		x2=x2+dx2;
		x3=x3+dx3;
		x4=x4+dx4;
		error=fabs(dx1) + fabs(dx2)+ fabs(dx3)+ fabs(dx4);     //συνολικο σφαλμα απο τις 4 διορθωσεις
		
		printf("\n i=%3d  x1=%10.5f  x2=%10.5f  x3=%10.5f  x4=%10.5f  f1=%10.5f  f2=%10.5f  f3=%10.5f  f4=%10.5f  error=%10.1e",
				i,x1,x2,x3,x4,f1(x1,x2,x3,x4),f2(x1,x2,x3,x4),
				f3(x1,x2,x3,x4),f4(x1,x2,x3,x4),error); //εκτυπωση λυσεων-τιμη των συναρτησεων στις λυσεις-σφαλματος
		
	}while(error>=0.5*pow(10.0,-5));    //ακριβεια 5 δεκαδικων ψηφιων
	
	printf("\n\n Telikes Lyseis Systhmatos: x1=%10.5f  x2=%10.5f  x3=%10.5f  x4=%10.5f",x1,x2,x3,x4);   //εκτυπωση τελικων λυσεων
	printf("\n");
	return 0;	
}
