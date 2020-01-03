#include <stdio.h>
#include <winbgim.h>
#include "Affine.h"

#define MAX 20

typedef struct {int x, y;} POINTTYPE ;

int main() 
{
	int A[MAX][MAX]={0},x1,y1,x2,y2,a=0,b=0,n,i,j,k;
	POINTTYPE V[MAX];
	Point p[MAX], q[MAX];
	Affine T;
	float h=0.5, g=0;
	
	printf("So dinh n= "); scanf("%d",&n);
	initwindow(500,500);
	setbkcolor(15);
	setcolor(1);
	cleardevice(); 
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(0,0,2);
	//Nhap n dinh bang an nut trai
	i=0;
	while (i<n){
		delay(1);
		if (ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick (WM_LBUTTONDOWN,x1,y1);
			V[i].x=x1; V[i].y=y1;
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
	cleardevice();
	Nghieng(T, h, g);
	for (i=0; i<n;i++) {
		p[i].x=V[i].x;	
		p[i].y=V[i].y;	
	}
	for (i=0; i<n;i++) Biendoi(T, p[i], &q[i]);
	for (i=0; i<n;i++){
		V[i].x=int(q[i].x);
		V[i].y=int(q[i].y);
	}
	setcolor(4);
	for (i=0; i<n-1; i++)
	  for (j=i+1; j<n; j++)
	    if (A[i][j]) line(V[i].x, V[i].y, V[j].x, V[j].y);
	system("pause");
	closegraph();
}
