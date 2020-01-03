#include <graphics.h>

int main() 
{
	int gd=DETECT, gm;
	
	initgraph(&gd,&gm,"");
	circle(500,250,7);
	getch();
	closegraph();
}
