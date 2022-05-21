#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi M_PI


///////////////////// ����� ���������� ra,R,za, ������ ��=xa, ������� Q, ������� k
double ra=0.1;     
double xa=35.0*pi/180.0;
double R=0.05;
double za=0.4;
double Q=pow(10.0,-6.0);
double k=9.0*pow(10.0,9.0);
	
//////////////////////////////////////////// ��������� Ez (�� x=�)
double Ez(double x){ 

	double A=pow(ra,2.0)+pow(R,2.0)+pow(za,2.0);
	double B=A-2*ra*R*cos(x-xa);
	double C=k*Q*za;
	
	return C/(2*pi*pow(B,1.5));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////// main
int main() {
	
    
	int n=0;	           //n= ������� �������������� ��� ����������� [a,�]
	int i,j;                  //i,j ��� ���� 2 �������������� ��������
	double E1a,E2a,E3a, E1b,E2b,E3b, Ea,Eb;   //���������� ��,�1�,�2�,E3a ��� �z �� ���� h, �b,�1b,�2b,E3b ��� �z �� ���� h/2
	double a=0.0;        //�������� ���� �����������  �=0
	double b=2.0*pi;     //���� ���� ����������� �=2�
	double h,h2;         //���� h, h2=h/2
	double xi,xj;       //xi=a+i*h, xj=a+i*h2
	double error;       //������
	
	do{
		n++;                //������ ������� �������������� ���� 1 ���� ����
		printf("------- n=%d -------\n",n);          //�������� ��������� n
	////////////////////////////////////////////////////////////////////////////////////////////// ������� ��� h
		h=(b-a)/n;                            //���� h=(b-a)/n
		E1a=(h/3.0)*( Ez(a) + Ez(b) );         //������ ��� ���������� �� 3 �������� E1a,E2a,E3a, ���� �1� ����� ��� f(x0),f(xn) ��� ������ Simpson
		E2a=0.0;
		E3a=0.0;
		Ea=0.0;
		
		for(i=1;i<=n-1;i=i+2){             //����������� ��� f(x1),f(x3),...,f(xn-1) ��� ������ Simpson
			xi=a+i*h;
			E2a=E2a+Ez(xi);
		}
		
		for(i=2;i<=n-2;i=i+2){             //����������� ��� f(x2),f(x4),...,f(xn-2) ��� ������ Simpson
			xi=a+i*h;
			E3a=E3a+Ez(xi);
		}
		
		
		E2a=4*(h/3.0)*E2a;                 
		E3a=2*(h/3.0)*E3a;
		
		Ea=E1a+E2a+E3a;                  //�������� ����� �� N/C
		Ea=Ea*pow(10.0,-3.0);              //��������� �� kN/C
		printf("Ez = %.8f kN/C \n",Ea);          //�������� ��� ������ �� ���� h
	///////////////////////////////////////////////////////////////////////////////////////////////// ������� ��� h/2		
		h2=h*0.5;                               //������ � ���� ����������, ��� ���� h2=h/2
		E1b=(h2/3.0)*( Ez(a) + Ez(b) );         
		E2b=0.0;
		E3b=0.0;
		Eb=0.0;
		
		for(j=1;j<=2*n-1;j=j+2){             
			xj=a+j*h2;
			E2b=E2b+Ez(xj);
		}
		
		for(j=2;j<=2*n-2;j=j+2){             
			xj=a+j*h2;
			E3b=E3b+Ez(xj);
		}
		
		
		E2b=4*(h2/3.0)*E2b;
		E3b=2*(h2/3.0)*E3b;
		
		Eb=E1b+E2b+E3b;                  //�������� ����� �� N/C
		Eb=Eb*pow(10.0,-3.0);
		printf("Ez = %.8f kN/C \n\n",Eb);	  //�������� ��� ������ �� ���� h/2
	//////////////////////////////////////////////////////////////////////////////////////
		error=fabs(Ea-Eb);                 //������=������� ���� ��� �������� ��� 2 ����������� ��� ������ �z
		printf("error = %.8f \n\n",error);     //�������� ���������
	}while(error>=0.5*pow(10.0,-8.0));                 //�������� 8 ���������
	
	printf("Telikh timh Ez = %.8f kN/C \n",Ea);           //�������� ������� ����� ��� ������
return;
}



