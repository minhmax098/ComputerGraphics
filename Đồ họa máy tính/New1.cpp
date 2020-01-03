#include <winbgim.h>

main() 
{
	int x=500, y=300, R=100, sa=0, ea=180;
	
	initwindow(1000,600);
	setbkcolor(15); setcolor(1); cleardevice();
	arc(x, y, sa, ea, R);
	getch();
	closegraph();	
}
