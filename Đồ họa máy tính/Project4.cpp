#include <winbgim.h>

main()
{
  	
  initwindow(1000,500);
  setbkcolor(15); setcolor(2); cleardevice();
  circle(300,300,150); line(0,0,100,100);
  getch();
  closegraph();
}
