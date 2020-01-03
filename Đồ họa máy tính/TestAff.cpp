#include <stdio.h>
#include <conio.h>
#include "Affine.h"
#include <windows.h>

main()
{
	Point P={10, 5}, Q;
	Vector V={4, 8};
	Affine T;
	int i, j;
	float theta=M_PI/6, h=0.5, Sx=0.5, Sy=1.5;
	
	system("Color F0");
	printf("\nPx=%.2f, Py=%.2f\n", P.x, P.y);	
	Tinhtien(T, V); Biendoi(T,P,&Q);	
	printf("\nTinh tien V=(%0.2f, %0.2f)\n",V.dx, V.dy); printf("\nQx=%.2f, Qy=%.2f\n", Q.x, Q.y); getch();
	Quay(T,theta); Biendoi(T,P,&Q);		
	printf("\nQuay goc theta=%0.0f do\n",theta*180/M_PI); printf("\nQx=%.2f, Qy=%.2f\n", Q.x, Q.y); getch();
	Nghieng(T, 0, h); Biendoi(T,P,&Q);	
	printf("\nNghieng theo Ox h=%0.2f\n",h);printf("\nQx=%.2f, Qy=%.2f\n", Q.x, Q.y); getch();
	Codan(T,Sx,Sy); Biendoi(T,P,&Q);	
	printf("\nCo dan S=(%0.2f, %0.2f)\n",Sx, Sy);printf("\nQx=%.2f, Qy=%.2f\n", Q.x, Q.y); getch();
}
