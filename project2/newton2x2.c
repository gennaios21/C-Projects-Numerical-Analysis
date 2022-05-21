#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Ασκηση 1,μεθοδος Newton για 2χ2 συστημα

double f1(double x1,double x2){
	return pow(x1,3)+2.0*x2;
}

double f2(double x1,double x2){
	return pow(x2,2)+7.0*x1-30;
}

double df1_x1(double x1,double x2){
	return 3.0*pow(x1,2);
}

double df1_x2(double x1,double x2){
	return 2.0;
}

double df2_x1(double x1,double x2){
	return 7.0;
}

double df2_x2(double x1,double x2){
	return 2.0*x2;
}

double det(double a11,double a12, double a21, double a22){
	return a11*a22-a12*a21;
}

//////////////////////////////////////////////////////

int main() {
	double error,DET,DETdx1,DETdx2;
	double dx1,dx2;
	double x1=3.0;
	double x2=-3.0;
	int i=0;
	
	do{
		i=i+1;
		DET=det(df1_x1(x1,x2),df1_x2(x1,x2),df2_x1(x1,x2),df2_x2(x1,x2));
		DETdx1=det(-f1(x1,x2),df1_x2(x1,x2),-f2(x1,x2),df2_x2(x1,x2));
		DETdx2=det(df1_x1(x1,x2),-f1(x1,x2),df2_x1(x1,x2),-f2(x1,x2));
		dx1=DETdx1/DET;
		dx2=DETdx2/DET;
		x1=x1+dx1;
		x2=x2+dx2;
		error=fabs(dx1) + fabs(dx2);
		printf("\n %3d %10.5f %10.5f %10.5f %10.5f %10.1e",i,x1,x2,f1(x1,x2),f2(x1,x2),error);
		
	}while(error>=0.5*pow(10.0,-5));
	printf("\n");
	return 0;
	
}
