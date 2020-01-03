#include <winbgim.h>

void MCircle(int R);
	
main()
{
	initwindow(1300,700);
	setviewport(650,350,1300,700,0);
	setbkcolor(15); cleardevice();
	setcolor(1); MCircle(200);
	delay(500);
	setcolor(14); circle(0,0,200);
	getch();
	//closegraph();
}

void MCircle(int R){
		int x, y, c, d; 
		x = 0; y = R; d = 3 - 2*R ;
		c = getcolor() ;
		while (x <= y){
			putpixel(x, y, c); putpixel(-x, y, c); delay(1);
			putpixel(x, -y, c); putpixel(-x, -y, c); delay(1);
			putpixel(y, x, c); putpixel(y, -x, c);delay(1);
			putpixel(-y, x, c); putpixel(-y, -x, c);delay(1);
			if (d<0) d += 4*x + 6;
			else { d += 4*(x - y) + 10; y-- ;}
			x++ ;
	}
}

