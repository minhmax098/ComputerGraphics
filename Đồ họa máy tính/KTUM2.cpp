#include <winbgim.h>

int main() 
{
	
	initwindow(1200,600);
	
	setbkcolor(15); setcolor(1); cleardevice();
	rectangle(0,0,200,200);
	circle(600,300,100);
	getch();
	closegraph();
}
