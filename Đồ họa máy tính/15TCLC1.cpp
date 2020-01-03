#include <winbgim.h>

int main() 
{
  initwindow(1000,500);
  setbkcolor(15); setcolor(1); cleardevice();
  circle(500,250,100);
  getch();
  closegraph();
}
