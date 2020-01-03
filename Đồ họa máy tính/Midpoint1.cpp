 #include <winbgim.h>

void MLine(int x1, int y1, int x2, int y2);


main()
{
      int mx, my;
      
      initwindow(1300,700);
      setbkcolor(15); setcolor(1); cleardevice();
      mx=getmaxx(); my=getmaxy();
	  MLine(0, 0, mx, my);
      getch(); setcolor(15);
      line(0, 0, mx, my);
      getch(); 
      closegraph();
}

void MLine(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, c, p;
	
	dx=x2-x1; dy=y2-y1; c=getcolor();
	p=dy-dx/2;
	for (x=x1, y=y1; x<=x2; x++){
		putpixel(x, y, c); delay(2);
		if (p<=0) p+=dy;
		else {
			y++;
			p+=dy-dx;
		}
	} 
}
