#include <winbgim.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <dos.h>



void MPCircle(int x0, int y0, int R);
	
main()
{

	int x,y,dx,dy,mx,my,c,R=20,n=0;
	
	initwindow(1300,700);
	mx=getmaxx(); my=getmaxy();
	setbkcolor(15); cleardevice();
	srand(time(NULL));
	while (n<50000){
		x=rand()%mx; y=rand()%my; c=rand()%16;
		setcolor(c);
		putpixel(x,y,c);
		n++;
	}
	//getchar();
	//fflush(stdin); delay(20); getchar();
	while (!kbhit()){
		dx=rand()%(6*R)-3*R; dy=rand()%(6*R)-3*R;
		x+=dx; y+=dy;
		if (x<0) x=0; if (x>mx) x=mx;
		if (y<0) y=0; if (y>my) y=my;
		setcolor(0);
		MPCircle(x,y,R);
		delay(50);
		setcolor(15);
		MPCircle(x,y,R);
	}
	closegraph();
}

void MPCircle(int x0, int y0, int R){
		int x, y, c, p; 
		x = 0; y = R; p = 1 - R ;
		c = getcolor() ;
		while (x <= y){
			putpixel(x0+x,y0+y,c); putpixel(x0-x,y0+y,c);
			putpixel(x0+x,y0-y,c); putpixel(x0-x,y0-y,c);
			putpixel(x0+y,y0+x,c); putpixel(x0+y,y0-x,c);
			putpixel(x0-y,y0+x,c); putpixel(x0-y,y0-x,c);
			if (p<0) p += 2*x + 3;
			else { p += 2*(x - y) + 5; y-- ;}
			x++ ;
	}
}
