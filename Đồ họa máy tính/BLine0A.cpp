#include <winbgim.h>
#include <math.h>


void BLine(int x1, int y1, int x2, int y2);

main()
{
      int mx,my;
      
      initwindow(1300,700);
      setbkcolor(15); setcolor(1); cleardevice();
      mx=getmaxx(); my=getmaxy();
	  BLine(0, 0, mx, my); delay(100);
	  setcolor(15); line(0, 0, mx, my);
	  getch();
      closegraph();
}

void BLine(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, e, et, ekt, c;
	
	dx=x2-x1; dy=y2-y1; c=getcolor();
	ekt=dy+dy; e=ekt-dx; et=e-dx;
	for (x=x1, y=y1; x<=x2; x++){
		putpixel(x, y, c); 
		delay(1);
		if (e<0) e+=ekt;
		else {
			e+=et;
			y++;
		}
	} 
}
