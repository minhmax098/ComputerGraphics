#include <winbgim.h>

int main() 
{
	int x=500, y=250, R=100;
	
	initwindow(1000,500);
	circle(x,y,R);
	getch();
	closegraph();
}
