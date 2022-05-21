#include <stdlib.h>
#include <math.h>
#include <stdio.h>

double f(double x){
	return x+ exp(-10.0*pow(x,2) ) * cos(x);
}



double df(double x){
	return 1.0 - exp(-10.0*pow(x,2) ) * (20.0*x*cos(x)+sin(x) );
}

int main() {
	
	
	int i=0;
	double x,error;
	double x0=-0.7;
	double x1=-0.69;
	do{
		i=i+1;
		x=x1 - (x1-x0)/(f(x1)-f(x0))*f(x1);
		error=fabs(x-x1);
		printf("\n %3d %14.10f %14.10f %14.10f",i,x,f(x),error);
		x0=x1;
		x1=x;
	}while(error>=0.5*pow(10.0,-10));
	
	printf("\n\n ROOR: %14.10f \n\n",x);
	return 0;
}

