#include <graphics.h>

int main() 
{
	int gd=0,gm;
	
	initgraph(&gd,&gm,"");
	circle(100,100,50);
	getch();
	closegraph();
}
