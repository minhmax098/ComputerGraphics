#include <winbgim.h>

main() 
{
	int x=500, y=300, R=100, sa=0, ea=90;
	
	initwindow(1000,600);
	arc(x, y, R, sa, ea);
	getch();
	closegraph();	
}
