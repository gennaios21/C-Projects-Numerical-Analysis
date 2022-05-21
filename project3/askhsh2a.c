#include <stdlib.h>
#include <math.h>
#include <stdio.h>

double f(double x){                 //��������� f
	return pow(x,4)+2*pow(x,3)+pow(x,2)+12*x+20;          
}


double df(double x){              //1� ��������� ��� f
	return 4*pow(x,3)+6*pow(x,2)+2*x+12;
}

double df2(double x){                    //2� ��������� ��� f
	return 12*pow(x,2)+12*x+2;
}

////////////////////////////////////////////////////////////////
int main() {
	
	
	int i=0;                                   //������������ ���������� i
	double x, error,krit;                     //����� x, ������ ����������, 2� ��������
	double x0=1.0;                             //������ �������
	printf("   i		x	   f(x)	     error\n\n");
	do{                                                //��������� ��� �� ������ >= 0.5x10^-8 ��� |f(x0)|>= 0.5x10^-8 (�������� 8 ���������)
		i=i+1;                                      //������ ���������� ���� 1
		x=x0 - f(x0)/df(x0);                          //������� N-R
		error=fabs(x-x0);                                //������� ���������
		krit=fabs(f(x0));                                 //������� 2�� ���������
		printf("\n %3d %14.8f %14.8f %14.8f",i,x,f(x),error);     //�������� ����������, �����������, ����� ��� f ���� ����������, ������
		x0=x;                                                           //��� x0=����������� ����������
	}while(   (error>=0.5*pow(10.0,-8.0)) && (krit>=0.5*pow(10.0,-8.0))       );
	
	printf("\n\n ROOT: %14.8f \n\n",x);                        //�������� �����
	return 0;
}

