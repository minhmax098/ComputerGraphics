#include <winbgim.h>

int main() 
{
	int x=500, y=250, R=100;
	
	initwindow(1000,500);
	setbkcolor(15); cleardevice();
	setcolor(0);	circle(x,y,R);
	getch();
	closegraph();
}
