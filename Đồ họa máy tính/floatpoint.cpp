#include <winbgim.h>

int main() 
{
	float x=500.789, y=250.678;
	
	initwindow(1200,600);
	setbkcolor(15);
	setcolor(1);
	cleardevice(); 
	circle(x,y,100);
	delay(100);
	setcolor(4);
	circle(500,250,100);
	delay(100);
	for (x=500;x<600; x+=0.3)	putpixel(x,y,1); delay(1000);
	for (x=500;x<600; x+=0.3)	putpixel(int(x),int(y),4);
		
	getch();
	closegraph();
}
