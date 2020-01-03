#include <stdio.h>
#include <winbgim.h>

int main() 
{
  
  int x,y,x1,y1,x2,y2,a=0,b=0,done=0;
  
  initwindow(700,700);
  setbkcolor(15); setcolor(6); cleardevice();
  setwritemode(XOR_PUT);

  while (!done){
  		delay(1);
  		if (ismouseclick(WM_RBUTTONDOWN)) done=1;
		if (ismouseclick(WM_LBUTTONDOWN)){
			a=1;
			getmouseclick (WM_LBUTTONDOWN,x1,y1);
			x=x1; y=y1;
		}
		if (ismouseclick(WM_MOUSEMOVE)){
			b=1;
			getmouseclick (WM_MOUSEMOVE,x2,y2);
		}
		if (a&&b){
			line(x1,y1,x,y); delay(1);
		 	line(x1,y1,x2,y2);
		 	x=x2;y=y2;
		 	b=0;
		}
	}
  closegraph();
}
