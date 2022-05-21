#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 4
#define K 0.001
#define G 1000.0



////////////////////////////////////////////////////// πινακας P με 4 τιμες σε GW, P=xi
double P[N]={120*K,180*K,270*K,300*K};        // Με το Κ διαιρω καθε τιμη δια 1000


/////////////////////////////////////////////////////// πινακας H με 4 τιμες Tcal/h, H=yi
double H[N]={246*K,351*K,514*K,572*K};        // Με το Κ διαιρω καθε τιμη δια 1000 

/////////////////////////////////////////////////////////////////////////////////////////////////// Σxi 

double xi(){
	int i=0;
	double sum=0;
	for(i=0;i<N;i++)
		sum=sum+P[i];
	return sum;
}
//////////////////////////////////////////////////////////////////////////////// Σxi^2 

double xi2(){
	int i=0;
	double sum=0;
	for(i=0;i<N;i++)
		sum=sum+pow(P[i],2);
	return sum;
}
//////////////////////////////////////////////////////////////////////////////// Σxi^3

double xi3(){
	int i=0;
	double sum=0;
	for(i=0;i<N;i++)
		sum=sum+pow(P[i],3);
	return sum;
}
//////////////////////////////////////////////////////////////////////////////// Σxi^4 

double xi4(){
	int i=0;
	double sum=0;
	for(i=0;i<N;i++)
		sum=sum+pow(P[i],4);
	return sum;
}

//////////////////////////////////////////////////////////////////////////////// Σxi^5 

double xi5(){
	int i=0;
	double sum=0;
	for(i=0;i<N;i++)
		sum=sum+pow(P[i],5);
	return sum;
}
//////////////////////////////////////////////////////////////////////////////// Σxi^6

double xi6(){
	int i=0;
	double sum=0;
	for(i=0;i<N;i++)
		sum=sum+pow(P[i],6);
	return sum;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////// Σyi 

double yi(){
	int i=0;
	double sum=0;
	for(i=0;i<N;i++)
		sum=sum+H[i];
	return sum;
}
//////////////////////////////////////////////////////////////////////////////// Σyixi 

double yixi(){
	int i=0;
	double sum=0;
	for(i=0;i<N;i++)
		sum=sum+H[i]*P[i];
	return sum;
}
//////////////////////////////////////////////////////////////////////////////// Σyixi^2

double yixi2(){
	int i=0;
	double sum=0;
	for(i=0;i<N;i++)
		sum=sum+H[i]*pow(P[i],2);
	return sum;
}
//////////////////////////////////////////////////////////////////////////////// Σyixi^3

double yixi3(){
	int i=0;
	double sum=0;
	for(i=0;i<N;i++)
		sum=sum+H[i]*pow(P[i],3);
	return sum;
}

///////////////////////////////////////////////////////////////////////////////////////////////// det2x2
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

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////// main
int main() {
	
	double DET,DETa0,DETa1,DETa2,DETa3;   //οριζουσες Κραμερ 
	double a0,a1,a2,a3;          // 4 πολυωνυμικοι συντελεστες α0,α1,α2,α3 αφου εχω πολυωνυμο 3ου βαθμου
	
	double S=0;             //μεταβλητες M,S και επαναληψεις i για υπολογισμο του αθροισματος S των τετραγωνων των σφαλματων Μ
	double M=0;
	int i=0;
	
	//////////////////////// 5 οριζουσες Κραμερ 
	DET=det4x4( N,    xi(), xi2(),xi3(),
				xi(), xi2(),xi3(),xi4(),
				xi2(),xi3(),xi4(),xi5(),
				xi3(),xi4(),xi5(),xi6());
	
		
	DETa0=det4x4(   yi(),   xi(), xi2(),xi3(),
					yixi(), xi2(),xi3(),xi4(),
					yixi2(),xi3(),xi4(),xi5(),
					yixi3(),xi4(),xi5(),xi6());
		
	DETa1=det4x4(   N,    yi(),   xi2(),xi3(),
					xi(), yixi(), xi3(),xi4(),
					xi2(),yixi2(),xi4(),xi5(),
					xi3(),yixi3(),xi5(),xi6());
						
	DETa2=det4x4(   N,    xi(), yi(),   xi3(),
					xi(), xi2(),yixi(), xi4(),
					xi2(),xi3(),yixi2(),xi5(),
					xi3(),xi4(),yixi3(),xi6());
				
	DETa3=det4x4(   N,    xi(), xi2(),yi(),
					xi(), xi2(),xi3(),yixi(),
					xi2(),xi3(),xi4(),yixi2(),
					xi3(),xi4(),xi5(),yixi3());
		
		
	a0=DETa0/DET;      //μεθοδος Κραμερ για ευρεση των πολυωνυμικων συντελεστων
	a1=DETa1/DET;
	a2=DETa2/DET;
	a3=DETa3/DET;
	
	a0=a0*pow(10,3);         //μετατροπη στους σωστους συντελεστες για να μετραω σε MW και Gcal/h
	a1=a1*pow(10,0);
	a2=a2*pow(10,-3);
	a3=a3*pow(10,-6);
	
	printf("a0 = %f\na1 = %f\na2 = %f\na3 = %f\n\n",a0,a1,a2,a3);       //εκτυπωση των συντελεστων
	printf("Mazout: H(P) = P(x) = %f*x^3 %f*x^2 + %f*x + %f\n\n",a3,a2,a1,a0);        //εκτυπωση του πολυωνυμου P(x)
	
	//printf(" xi= %f\n xi2= %f\n xi3= %f\n xi4= %f\n xi5= %f\n xi6= %f\n yi= %f\n yixi= %f\n yixi2= %f\n yixi3= %f",
			//xi(),xi2(),xi3(),xi4(),xi5(),xi6(),yi(),yixi(),yixi2(),yixi3());
			
	for(i=0;i<N;i++){                //υπολογισμος σφαλματος
		M=H[i]*G - (a3*pow(P[i]*G,3) + a2*pow(P[i]*G,2) + a1*P[i]*G + a0);
		S=S+pow(M,2.0);                      
	}	
	printf("\nError S= %f \n",S);              //εκτυπωση σφαλματος
	
return;
}

