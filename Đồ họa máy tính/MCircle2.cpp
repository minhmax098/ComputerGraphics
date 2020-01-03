#include <winbgim.h>

void MCircle(int x0, int y0, int R);
	
main()
{
	initwindow(1300,700);
	setbkcolor(15); cleardevice();
	setcolor(1);
	MCircle(650,350,200); 
	getch(); 
	setcolor(15);
	circle(650,350,200); 
	getch(); 
	closegraph();
}

void MCircle(int x0, int y0, int R){
		int x, y, c, d; 
		x = 0; y = R; d = 3 - 2*R ;
		c = getcolor() ;
		while (x <= y){
			putpixel(x0+x,y0+y,c); putpixel(x0-x,y0+y,c); delay(1);
			putpixel(x0+x,y0-y,c); putpixel(x0-x,y0-y,c); delay(1);
			putpixel(x0+y,y0+x,c); putpixel(x0+y,y0-x,c); delay(1);
			putpixel(x0-y,y0+x,c); putpixel(x0-y,y0-x,c); delay(1);
			if (d<0) d += 4*x + 6;
			else { d += 4*(x - y) + 10; y-- ;}
			x++ ;
	}
}

