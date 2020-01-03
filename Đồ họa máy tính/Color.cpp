#include <winbgim.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
main()
{
	int mx, my, Radius, x, y, c, R, G, B;
	
	initwindow(1300, 700);
	setbkcolor(15); cleardevice(); 
	mx=getmaxx(); my=getmaxy();
	c=COLOR(R,G,B); 
	srand(time(NULL)); 
	for (R=0; R<256; R++) 
	  for (G=0; G<256; G++) 
	    for (B=0; B<256; B++){
		c=COLOR(R,G,B);//c=RGB(R,G,B);
		x=rand()%mx; y=rand()%my; Radius=5+rand()%100;
		setcolor(c); circle(x,y,Radius);printf("\n(%d,%d),%d,%d",x,y,Radius,c); delay(10);
		//Sleep(10);
	}
	getch();
	closegraph();	
	
}
