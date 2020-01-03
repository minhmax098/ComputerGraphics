#include <stdio.h>
#include <winbgim.h>

main()
{
  int mx,my,x=100,y=100,R=50;
  
  initwindow(1000,700);
  setbkcolor(15); setcolor(COLOR(0,0,255));
  cleardevice();
  line(x,y,x+300,y+300);
  circle(x,y,R);
  mx=getmaxx(); my=getmaxy();
  printf("maxx= %d\nmaxy=%d",mx,my);
  getch();
}
