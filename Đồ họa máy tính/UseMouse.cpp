#include <stdio.h>
#include <winbgim.h>

int main() 
{
	int x1,y1,x2,y2,a=0,b=0;

	initwindow(1200,600);
	setbkcolor(15);
	setcolor(1);
	cleardevice(); 
	while (!kbhit()){
		if (ismouseclick(WM_LBUTTONDOWN)){
			a=1;
			getmouseclick (WM_LBUTTONDOWN,x1,y1);
			circle(x1,y1,3);
			printf("\n(x1,y1)=(%d,%d)",x1,y1);
		}
		if (ismouseclick(WM_RBUTTONDOWN)){
			b=1;
			getmouseclick (WM_RBUTTONDOWN,x2,y2);
			circle(x2,y2,3);
			printf("\n(x2,y2)=(%d,%d)",x2,y2);
		}
		if (a && b){
		 	line(x1,y1,x2,y2);
		 	a=0; b=0;
		}
	}
}
