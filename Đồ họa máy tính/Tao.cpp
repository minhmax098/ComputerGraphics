#include <winbgim.h>

main()
{
	
	initwindow(1000, 600);
	setbkcolor(15); cleardevice(); 
	setcolor(COLOR(255,0,0));
	line(100,100,300,300);
	circle(200,300,100);
	Sleep(2000);
	getch();
			
}
