#include <winbgim.h>
#include <math.h>


void BLine3(int x1, int y1, int x2, int y2);

main()
{
      int mx,my;
      
      initwindow(1300,700);
      setbkcolor(15); setcolor(1); cleardevice();
      mx=getmaxx(); my=getmaxy();
	  BLine3(100,600,300,0);
	  getch();
      closegraph();
}

void BLine3(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, e, et, ekt, c;
	
	dx=x2-x1; dy=y2-y1; c=getcolor();
	e=2*dx+dy; ekt=2*dx; et=2*dx+2*dy;
	for (x=x1, y=y1; y>=y2; y--){
		putpixel(x, y, c); 
		delay(10);
		if (e<0) e+=ekt;
		else {
			e+=et;
			x++;
		}
	} 
}
