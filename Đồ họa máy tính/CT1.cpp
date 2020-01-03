#include <graphics.h>

int main() {
	int gd=DETECT, gm;
	
	initgraph(&gd,&gm,"");
	setbkcolor(WHITE); setcolor(BLUE); cleardevice();
	line(0,0,200,200); circle(400,400,200);
	getch();
	return 0;
}
