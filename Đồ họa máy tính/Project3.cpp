#include <winbgim.h>
#include <stdio.h>
main()
{
  
  initwindow(600,600);
  setbkcolor(15); setcolor(1); cleardevice();
  circle(200,200,100); line(0,0,100,100);
  getchar();
  closegraph();
}
