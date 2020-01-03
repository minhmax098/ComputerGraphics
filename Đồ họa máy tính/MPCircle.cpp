#include <winbgim.h>

void MPCircle(int R);
	
main()
{
	initwindow(1300,700);
	setviewport(650,350,1300,700,0);
	setbkcolor(15); cleardevice();
	setcolor(0);
	MPCircle(100);  delay(500);
	setcolor(14);
	circle(0,0,100); delay(1000);
	closegraph();
}

void MPCircle(int R){
		int x, y, c, p; 
		x = 0; y = R; p = 1 - R ;
		c = getcolor() ;
		while (x <= y){
			putpixel(x, y, c); putpixel(-x, y, c); 
			putpixel(x, -y, c); putpixel(-x, -y, c); 
			putpixel(y, x, c); putpixel(y, -x, c);
			putpixel(-y, x, c); putpixel(-y, -x, c);
			delay(2);
			if (p<0) p += 2*x + 3;
			else { p += 2*(x - y) + 5; y-- ;}
			x++ ;
	}
}

