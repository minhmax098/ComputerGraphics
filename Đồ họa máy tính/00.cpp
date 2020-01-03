#include <stdio.h>
#include <winbgim.h>

main() 
{
	initwindow(1300,700);
	setbkcolor(15); cleardevice();
	setcolor(0);
	circle(650,350,100);
	getch();
	closegraph();
	printf("Tam biet...");
}
