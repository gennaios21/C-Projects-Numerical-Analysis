#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define pi M_PI 


double f(double r){                 //��������� f
	double k=0.01+r*r;
	return 2-(18*r)/(35.4*pi*pow(k,1.5));          
}


double df(double r){              //1� ��������� ��� f
	double k=0.01+r*r;
	return (-18/(35.4*pi*pow(k,3)))*(pow(k,1.5)-3*r*r*pow(k,0.5));
}


////////////////////////////////////////////////////////////////
int main() {
	
	
	int i=0;                                            //������������ ���������� i
	double r, error;                                 //����� r, ������ ����������
	double r0=0.0;                                    //������ �������
	printf("   i		r	   f(r)	     error\n\n");
	do{                                                //��������� ��� �� ������ >= 0.5x10^-10 (�������� 10 ���������) ��� � �������� r ����� ������
		i=i+1;                                           //������ ���������� ���� 1
		r=r0 - f(r0)/df(r0);                              //������� N-R
		error=fabs(r-r0);                                //������� ���������
		printf("\n %3d %14.10f %14.10f %14.10f",i,r,f(r),error);     //�������� ����������, �����������, ����� ��� f ���� ����������, ���������
		r0=r;                                                           //��� r0=����������� ����������
	}while(   (error>=0.5*pow(10.0,-10.0)) && r>0 );
	
	printf("\n\n ROOT 1: %14.10f \n\n",r);                        //�������� �����
	printf("\n\n");
	// ����������� ������ ���� ��� ��� ������ ��� 2�� �����
	i=0;
	r0=0.3;                                    
	printf("   i		r	   f(r)	     error\n\n");
	do{                                               
		i=i+1;                                       
		r=r0 - f(r0)/df(r0);                            
		error=fabs(r-r0);                               
		printf("\n %3d %14.10f %14.10f %14.10f",i,r,f(r),error);     
		r0=r;                                                          
	}while(   (error>=0.5*pow(10.0,-10.0)) && r>0);
	
	printf("\n\n ROOT 2: %14.10f \n\n",r);                      
	return 0;
}

