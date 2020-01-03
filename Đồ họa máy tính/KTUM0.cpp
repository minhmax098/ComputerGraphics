#include <graphics.h>

int main() 
{  
	int gd, gm;
	
	initgraph(&gd,&gm,"");
	setbkcolor(WHITE); setcolor(BLUE); cleardevice();
	outtextxy(250,250,"DO HOA");
	setwritemode(XOR_PUT);
	rectangle(0,0,200,200); getch(); rectangle(0,0,200,200);
	line(0,0,200,200); getch(); line(0,0,200,200); getch();
	circle(200,200,100); getch(); circle(200,200,100);
	getch();
	closegraph();
}
