#include <winbgim.h>
#include <stdio.h>

void 	MLine1(int x1, int y1, int x2, int y2),
		MLine2(int x1, int y1, int x2, int y2),
		MLine3(int x1, int y1, int x2, int y2),
		MLine4(int x1, int y1, int x2, int y2);
int c=1;

main()
{
      int mx=700, my=700,x1,y1,x2,y2,x,y,a=0,b=0,tam;
      float m;
      
      initwindow(mx,my);
      setbkcolor(15); setcolor(1); cleardevice();
      
      while (!kbhit()){
		if (ismouseclick(WM_LBUTTONDOWN)){
			a=1;
			getmouseclick (WM_LBUTTONDOWN,x1,y1);
			setcolor(1);circle(x1,y1,3);
			printf("\nA(%d,%d)",x1,y1);
		}
		if (ismouseclick(WM_RBUTTONDOWN)){
			b=1;
			getmouseclick (WM_RBUTTONDOWN,x2,y2);
			setcolor(4);circle(x2,y2,3);
			printf("\nB(%d,%d)",x2,y2);
		}
		if (a && b){
			if (x1>x2){
				tam=x1; x1=x2; x2=tam;
				tam=y1; y1=y2; y2=tam;
			}
		 	if (y1==y2){
		 		y=y1;
		 		for (x=x1; x<=x2;x++) putpixel(x,y,c); 
			}
			else if (x1==x2){
		 		x=x1;
		 		if (y1<y2) for (y=y1; y<=y2;y++) putpixel(x,y,c); 
		 		else for (y=y2; y<=y1;y++) putpixel(x,y,c); 
			 }
			else {
				m=float(y2-y1)/float(x2-x1);
				if (m==1) for (x=x1; x<=x2;x++,y++) putpixel(x,y,c); 
				if (m==-1) for (x=x1; x<=x2;x++,y--) putpixel(x,y,c); 
				if (m!=1 && m!=-1){
				  if (m>0 && m<1) MLine1(x1,y1,x2,y2);
				  if (m>1) MLine2(x1,y1,x2,y2);
				  if (m<0 && m>-1) MLine3(x1,y1,x2,y2);
				  if (m<-1) MLine4(x1,y1,x2,y2);
				}
			}
			a=0; b=0;
		}
	}
}

void MLine1(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, p, pt, pkt;
	
	dx=x2-x1; dy=y2-y1;
	p=dy-dx/2; pkt=dy;  pt=dy-dx;
	for (x=x1, y=y1; x<=x2; x++){
		putpixel(x, y,c); 
		delay(1);
		if (p<0) p+=pkt;
		else {
			p+=pt;
			y++;
		}
	} 
}

void MLine2(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, p, pt, pkt;
	
	dx=x2-x1; dy=y2-y1;
	p=dx-dy/2; pkt=dx;  pt=dx-dy;
	for (x=x1, y=y1; y<=y2; y++){
		putpixel(x, y, c); 
		delay(1);
		if (p<0) p+=pkt;
		else {
			p+=pt;
			x++;
		}
	} 
}

void MLine3(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, p, pg, pkg;
	
	dx=x2-x1; dy=y2-y1;
	p=-dy-dx/2; pkg=-dy;  pg=-dy-dx;
	for (x=x1, y=y1; x<=x2; x++){
		putpixel(x, y, c); 
		delay(1);
		if (p<0) p+=pkg;
		else {
			p+=pg;
			y--;
		}
	} 
}

void MLine4(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, p, pt, pkt;
	
	dx=x2-x1; dy=y2-y1;
	p=dx+dy/2; pkt=dx;  pt=dx+dy;
	for (x=x1, y=y1; y>=y2; y--){
		putpixel(x, y, c); 
		delay(1);
		if (p<0) p+=pkt;
		else {
			p+=pt;
			x++;
		}
	} 
}
