#include <stdio.h>
#include <winbgim.h>
#include "Affine.h"

#define MAX 20

typedef struct {int x, y;} POINTTYPE ;

int main() 
{
	int A[MAX][MAX]={0},x1,y1,x2,y2,a=0,b=0,n,i,j,k,mx,my;
	POINTTYPE V[MAX];
	Point p[MAX];
	Affine T;
	float theta=0;
	
	printf("So dinh n= "); scanf("%d",&n);
	initwindow(500,500);
	setbkcolor(15);
	setcolor(1);
	cleardevice(); 
    
	//Nhap n dinh bang an nut trai
	i=0;
	while (i<n){
		delay(1);
		if (ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick (WM_LBUTTONDOWN,x1,y1);
			V[i].x=x1; V[i].y=y1;
			printf("\n(%d,%d)",x1,y1);
			circle(x1,y1,3);
			i++;
		}
	}
	
	//Ve cac canh
	while (!kbhit()){
		delay(1);
		if (ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick (WM_LBUTTONDOWN,x1,y1);
			for (k=0; k<n;k++)
				if (abs(x1-V[k].x)<10 && abs(y1-V[k].y)<10){
					i=k;
					a=1;
				} 
		}
		if (ismouseclick(WM_RBUTTONDOWN)){
			getmouseclick (WM_RBUTTONDOWN,x2,y2);
			for (k=0; k<n;k++)
				if (abs(x2-V[k].x)<10 && abs(y2-V[k].y)<10){
					j=k;
					b=1;
				} 
		}
		if (a && b && i!=j){
		 	line(V[i].x,V[i].y,V[j].x,V[j].y);
		 	A[i][j]=A[j][i]=1;
		 	printf("\n%d---%d",i+1,j+1);
		 	a=0; b=0;
		}
	}
	printf("\nMa tran ke:\n");
	for (i=0; i<n;i++){
		for (j=0; j<n;j++) printf("%3d",A[i][j]);
		 printf("\n");
	}
	
	setviewport(mx/2,my/2,mx,my,0); mx/=2; my/=2;
    line(-mx,0,mx,0); line(0,-my,0,my);
	//setwritemode(XOR_PUT);
	setcolor(2);
		for (i=0; i<n-1; i++)
	  		for (j=i+1; j<n; j++)
	    		if (A[i][j]) line(V[i].x, V[i].y, V[j].x, V[j].y);
	delay(1000);    		
	while (1){
		delay(1000);
		for (i=0; i<n-1; i++)
	  		for (j=i+1; j<n; j++)
	    		if (A[i][j]) line(V[i].x, V[i].y, V[j].x, V[j].y);
		theta+=M_PI/180;
		Quay(T, theta);
		for (i=0; i<n;i++) {
			p[i].x=V[i].x;	
			p[i].y=V[i].y;	
		}
		printf("\n");
		for (i=0; i<n;i++) Biendoi(T, p[i], &p[i]);
		for (i=0; i<n;i++){
			V[i].x=int(p[i].x);
			V[i].y=int(p[i].y);
			printf("(%d,%d) ",V[i].x,V[i].x);
		}
		for (i=0; i<n-1; i++)
	  		for (j=i+1; j<n; j++)
	    		if (A[i][j]) line(V[i].x, V[i].y, V[j].x, V[j].y);
	}
	system("pause");
	closegraph();
}
