#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi M_PI
#define N 9


/////////////////////////////////////////////// pinakas A me 9 times x
double A[N]={0.0,pi/6.0,pi/4.0,pi/3.0,pi/2.0,2.0*pi/3.0,3.0*pi/4.0,5.0*pi/6.0,pi};


/////////////////////////////////////////////// pinakas f me 9 times sin(x)
double f[N]={0.0, 0.5, pow(2.0,0.5)/2.0, pow(3.0,0.5)/2.0, 1.0, pow(3.0,0.5)/2.0, pow(2.0,0.5)/2.0, 0.5, 0.0};


//////////////////////////////////////////////////////////////////////////////// syntelesths Lagrange L0(x)
double L0(double x){
	
	double n,m;		//n= arithmiths, m=paronomasths
	n=(x-A[1])*(x-A[2])*(x-A[3])*(x-A[4])*(x-A[5])*(x-A[6])*(x-A[7])*(x-A[8]);
	m=(A[0]-A[1])*(A[0]-A[2])*(A[0]-A[3])*(A[0]-A[4])*(A[0]-A[5])*(A[0]-A[6])*(A[0]-A[7])*(A[0]-A[8]);
	return n/m;	
}

//////////////////////////////////////////////////////////////////////////////// syntelesths Lagrange L1(x)
double L1(double x){
	
	double n,m;		//n= arithmiths, m=paronomasths	
	n=(x-A[0])*(x-A[2])*(x-A[3])*(x-A[4])*(x-A[5])*(x-A[6])*(x-A[7])*(x-A[8]);
	m=(A[1]-A[0])*(A[1]-A[2])*(A[1]-A[3])*(A[1]-A[4])*(A[1]-A[5])*(A[1]-A[6])*(A[1]-A[7])*(A[1]-A[8]);
	return n/m;	
}

//////////////////////////////////////////////////////////////////////////////// syntelesths Lagrange L2(x)
double L2(double x){
	
	double n,m;		//n= arithmiths, m=paronomasths		
	n=(x-A[1])*(x-A[0])*(x-A[3])*(x-A[4])*(x-A[5])*(x-A[6])*(x-A[7])*(x-A[8]);
	m=(A[2]-A[1])*(A[2]-A[0])*(A[2]-A[3])*(A[2]-A[4])*(A[2]-A[5])*(A[2]-A[6])*(A[2]-A[7])*(A[2]-A[8]);
	return n/m;	
}

//////////////////////////////////////////////////////////////////////////////// syntelesths Lagrange L3(x)
double L3(double x){
	
	double n,m;		//n= arithmiths, m=paronomasths	
	n=(x-A[1])*(x-A[2])*(x-A[0])*(x-A[4])*(x-A[5])*(x-A[6])*(x-A[7])*(x-A[8]);
	m=(A[3]-A[1])*(A[3]-A[2])*(A[3]-A[0])*(A[3]-A[4])*(A[3]-A[5])*(A[3]-A[6])*(A[3]-A[7])*(A[3]-A[8]);
	return n/m;	
}

//////////////////////////////////////////////////////////////////////////////// syntelesths Lagrange L4(x)
double L4(double x){
	
	double n,m;		//n= arithmiths, m=paronomasths	
	n=(x-A[1])*(x-A[2])*(x-A[3])*(x-A[0])*(x-A[5])*(x-A[6])*(x-A[7])*(x-A[8]);
	m=(A[4]-A[1])*(A[4]-A[2])*(A[4]-A[3])*(A[4]-A[0])*(A[4]-A[5])*(A[4]-A[6])*(A[4]-A[7])*(A[4]-A[8]);
	return n/m;	
}

//////////////////////////////////////////////////////////////////////////////// syntelesths Lagrange L5(x)
double L5(double x){
	
	double n,m;		//n= arithmiths, m=paronomasths	
	n=(x-A[1])*(x-A[2])*(x-A[3])*(x-A[4])*(x-A[0])*(x-A[6])*(x-A[7])*(x-A[8]);
	m=(A[5]-A[1])*(A[5]-A[2])*(A[5]-A[3])*(A[5]-A[4])*(A[5]-A[0])*(A[5]-A[6])*(A[5]-A[7])*(A[5]-A[8]);
	return n/m;	
}

//////////////////////////////////////////////////////////////////////////////// syntelesths Lagrange L6(x)
double L6(double x){
	
	double n,m;		//n= arithmiths, m=paronomasths	
	n=(x-A[1])*(x-A[2])*(x-A[3])*(x-A[4])*(x-A[5])*(x-A[0])*(x-A[7])*(x-A[8]);
	m=(A[6]-A[1])*(A[6]-A[2])*(A[6]-A[3])*(A[6]-A[4])*(A[6]-A[5])*(A[6]-A[0])*(A[6]-A[7])*(A[6]-A[8]);
	return n/m;	
}

//////////////////////////////////////////////////////////////////////////////// syntelesths Lagrange L7(x)
double L7(double x){
	
	double n,m;		//n= arithmiths, m=paronomasths	
	n=(x-A[1])*(x-A[2])*(x-A[3])*(x-A[4])*(x-A[5])*(x-A[6])*(x-A[0])*(x-A[8]);
	m=(A[7]-A[1])*(A[7]-A[2])*(A[7]-A[3])*(A[7]-A[4])*(A[7]-A[5])*(A[7]-A[6])*(A[7]-A[0])*(A[7]-A[8]);
	return n/m;	
}

//////////////////////////////////////////////////////////////////////////////// syntelesths Lagrange L8(x)
double L8(double x){
	
	double n,m;		//n= arithmiths, m=paronomasths	
	n=(x-A[1])*(x-A[2])*(x-A[3])*(x-A[4])*(x-A[5])*(x-A[6])*(x-A[7])*(x-A[0]);
	m=(A[8]-A[1])*(A[8]-A[2])*(A[8]-A[3])*(A[8]-A[4])*(A[8]-A[5])*(A[8]-A[6])*(A[8]-A[7])*(A[8]-A[0]);
	return n/m;	
}

////////////////////////////////////////////////// polywnymo Lagrange P(x)
double P(double x){
	
	return L0(x)*f[0]+ L1(x)*f[1]+ L2(x)*f[2]+ L3(x)*f[3]+ L4(x)*f[4]+ 
			L5(x)*f[5]+ L6(x)*f[6]+ L7(x)*f[7]+ L8(x)*f[8] ;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////// main
int main() {
	
	int i;  //epanalhpseis i
	double x;  //metavlhth x
	for(i=0;i<=180;i++)  //apo i=0 mexri kai i=180 moires
		printf("sin(%d) = P(%d) = %f \n",i,i,P(i*pi/(180)) ); //ektypwsh P(i), me metatroph apo moires se rad
	return;
}


