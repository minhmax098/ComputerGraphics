#include <stdio.h>
#include <winbgim.h>

main()
{
	initwindow(1000, 500);
	setbkcolor(15); setcolor(1);
	cleardevice();
	circle(500,250,100);
	printf("Cua so van ban...");
	getch();
}
