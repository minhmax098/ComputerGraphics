//Thuat toan MidPoint ke doan thang 
#include <winbgim.h>

void MLine(int x1, int y1, int x2, int y2);

main()
{
      int mx=1200, my=300;
      
      initwindow(1300,700);
      setbkcolor(15); setcolor(1); cleardevice();
	  MLine(0,0,mx,my);
	  delay(200);
	  setcolor(15);
	  line(0,0,mx,my);
	  delay(200);
	  outtextxy(100,100,"Xoa xong...");
	  delay(1200);
}

void MLine(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, p, pt, pkt, c;
	
	dx=x2-x1; dy=y2-y1; c=getcolor();
	p=dy-dx/2; pkt=dy;  pt=dy-dx;
	for (x=x1, y=y1; x<=x2; x++){
		putpixel(x, y, c); 
		delay(1);
		if (p<=0) p+=pkt;
		else {
			p+=pt;
			y++;
		}
	} 
}

