#include <winbgim.h>
#include <stdlib.h>
#include <time.h>

void MPCircle(int R);
	
main()
{

	int x,y,mx,my,Radius,R,G,B;
	
	initwindow(1300,700);
	mx=getmaxx(); my=getmaxy();
	setbkcolor(15); cleardevice();
	srand(time(NULL));
	while (!kbhit()){
		x=rand()%mx; y=rand()%my; Radius=5+rand()%100;
		setviewport(x,y,x+Radius,y+Radius,0);
		R=rand()%256;G=rand()%256;B=rand()%256;
		setcolor(COLOR(R,G,B));
		MPCircle(R); 
		//delay(10);	setcolor(15); circle(0,0,R);
	}
	closegraph();
}

void MPCircle(int R){
		int x, y, c, p; 
		x = 0; y = R; p = 1 - R ;
		c = getcolor() ;
		while (x <= y){
			putpixel(x,y,c); putpixel(-x,y,c);
			putpixel(x,-y,c); putpixel(-x,-y,c);
			putpixel(y,x,c); putpixel(y,-x,c);
			putpixel(-y,x,c); putpixel(-y,-x,c);
			//delay(1);
			if (p<0) p += 2*x + 3;
			else { p += 2*(x - y) + 5; y-- ;}
			x++ ;
	}
}
