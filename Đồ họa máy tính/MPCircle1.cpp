#include <winbgim.h>
#include <time.h>
#include <stdlib.h>

void MPCircle(int x0, int y0, int R);
	
main()
{
	int x, y, R, c;
	
	initwindow(1300,700);	
	setbkcolor(15); cleardevice();
	srand(time(NULL));
	while (!kbhit()){
		x=rand()%1300; y=rand()%700; R=10+rand()%100; 
		c=rand()%16; setcolor(c);
		MPCircle(x,y,R); 	
	}
	getch(); 
	closegraph();
}

void MPCircle(int x0, int y0, int R){
		int x, y, c, p; 
		x = 0; y = R; p = 1 - R ;
		c = getcolor() ;
		while (x <= y){
			putpixel(x0+x, y0+y, c); putpixel(x0-x, y0+y, c); 
			putpixel(x0+x, y0-y, c); putpixel(x0-x, y0-y, c); 
			putpixel(x0+y, y0+x, c); putpixel(x0+y, y0-x, c);
			putpixel(x0-y, y0+x, c); putpixel(x0-y, y0-x, c);
			delay(2);
			if (p<0) p += 2*x + 3;
			else { p += 2*(x - y) + 5; y-- ;}
			x++ ;
	}
}

