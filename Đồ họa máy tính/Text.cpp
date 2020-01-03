#include <winbgim.h>
#include <string.h>

int main() 
{
	int x=300,y=100,h,v,f,d,s,t;
	char a[100],b[10];
	
	initwindow(1200,600);
	setbkcolor(15);	setcolor(0); cleardevice(); 
	settextstyle(0,0,2); t=textheight("H");
	for (h=0; h<3; h++)
	  for (v=0; v<3; v++){
	  	circle(x,y,5);
	  	settextjustify(h,v);
		strcpy(a,"SetTextJustify ");
		itoa(h,b,10);  	  	
		strcat(a,b); strcat(a,","); 
		itoa(v,b,10);  	  	
		strcat(a,b);
		outtextxy(x,y,a); y+=t;		
	  }
	getch();
	closegraph();
}
