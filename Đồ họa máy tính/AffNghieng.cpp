#include <stdio.h>
#include <winbgim.h>
#include "Affine.h"

#define MAX 20

typedef struct {int x, y;} POINTTYPE ;

int main() 
{
	int A[MAX][MAX]={0},x1,y1,x2,y2,a=0,b=0,n,i,j,k;
	char s[10];
	POINTTYPE V[MAX], W[MAX]; //toa do nguyen
	Point v[MAX], w[MAX];  // toa do thuc
	int P[2*MAX], Q[2*MAX];
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
	setcolor(4);
	i=0;
	while (i<n){
		delay(1);
		if (ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick (WM_LBUTTONDOWN,x1,y1);
			V[i].x=x1; V[i].y=y1;
			//itoa(i+1,s,10);
			//outtextxy(x1,y1+3,s);
			circle(x1,y1,3);
			i++;
		}
	}
	setcolor(1);
	printf("\nToa do %d dinh:\n",n);
	for (i=0; i<n;i++) printf("V%d(%d,%d)\n",i+1,V[i].x,V[i].y);
	
	for (i=0; i<n; i++) {P[2*i]=V[i].x; P[2*i+1]=V[i].y;}
	//P[2*i]=V[0].x; P[2*i+1]=V[0].y;
	drawpoly(n,P);
	//system("pause");
	cleardevice();
	Nghieng(T, h, g);
	for (i=0; i<n; i++){
		v[i].x=float(V[i].x);	
		v[i].y=float(V[i].y);
	} 
	for (i=0; i<n; i++) Biendoi(T, v[i], &w[i]);
	for (i=0; i<n; i++) {Q[2*i]=int(w[i].x); Q[2*i+1]=int(w[i].y);}
	//Q[2*n]=Q[0]; Q[2*n+1]=Q[1];
	setcolor(4);
	drawpoly(n,Q);
	system("pause");
	
}
