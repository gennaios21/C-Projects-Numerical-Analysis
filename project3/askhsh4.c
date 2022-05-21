#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define L 10                        //���� ������
#define C 5*pow(10,-5)               //���� �������

double q(double t){                    //��������� q(t)
	double a;                   //������� a
	a=pow( ((1/(L*C))-pow(R/(2*L),2)), 0.5 );
	return q0*exp((-R*t)/(2*L))*cos(a*t);
}




////////////////////////////////////////////////////////////////
int main() {
	
	
	int i=0;                                   //������������ ���������� i
	
	double q0=q(0);              //������ ���� ��� q ��� t=0
	double v0=q0/C;            //q0=v0*C, ��� ���� v0=q0/C
	double t, error;                     //����� x, ������ ����������
	double x0=1.0;                             //������ �������
	printf("   i		x	   f(x)	     error\n\n");
	do{                                                //��������� ��� �� ������ >= 0.5x10^-6 (�������� 6 ���������)
		i=i+1;                                      //������ ���������� ���� 1
		t=t - q(t)/df(x0);                          //������� N-R
		error=fabs(x-x0);                                //������� ���������
		printf("\n %3d %14.8f %14.8f %14.8f",i,x,f(x),error);     //�������� ����������, �����������, ����� ��� f ���� ����������, ������
		x0=x;                                                           //��� x0=����������� ����������
	}while(   (error>=0.5*pow(10.0,-6.0)) && ()       );
	
	printf("\n\n ROOT: %14.8f \n\n",x);                        //�������� �����
	return 0;
}
