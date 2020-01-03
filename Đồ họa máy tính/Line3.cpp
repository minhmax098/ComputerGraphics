#include <winbgim.h>
#include <stdio.h>

void BLine(int x1, int y1, int x2, int y2); 
// m<-1

main()
{
      int mx,my;
      
      initwindow(1300,700);
      setbkcolor(15); setcolor(1); cleardevice();
      mx=getmaxx(); my=getmaxy();
      printf("\nLine...");
	  BLine(0, 600, 200, 0);
	  getch();
      closegraph();
}

void BLine(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, e, et, ekt, c;
	
	dx=x2-x1; dy=y2-y1; c=getcolor();
	e=2*dx+dy; ekt=2*dx;  et=2*dx+2*dy;
	for (y=y1, x=x1 ; y>=y2; y--){
		putpixel(x,y,c); 
		delay(1);
		if (e<0) e+=ekt;
		else {
			e+=et;
			x++;
		}
	} 
}
