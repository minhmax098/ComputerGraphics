#include <graphics.h>
#include <stdio.h>
#include <math.h>

main()
{
  int mx,my,x,y,dx=10,magx=400,magy=300;
  float i,j;
  
  initwindow(1300,700);
  setbkcolor(15); setcolor(0);
  cleardevice();
  mx=getmaxx(); my=getmaxy();
  setviewport(mx/2,my/2,mx,my,0);
  line(-mx,0,mx,0);
  line(0,-my,0,my);
  x=-magx; y=int(sin(i)*magy);
  moveto(x,y);
  for(x=-magx; x<=magx; x+=dx){
    i=x*M_PI/magx;
    j=sin(i);
    y=-int(j*magy);
	lineto(x,y);
	circle(x,y,2);
  }
  getch();
}
