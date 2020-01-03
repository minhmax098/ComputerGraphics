#include <winbgim.h>

void BoundaryFill(int x, int y, int FillColor, int BoundryColor);

main()
{
      int mx, my;
    
      initwindow(1300,700);
      mx=getmaxx(); my=getmaxy();
      setbkcolor(5);  setcolor(1); cleardevice();
      rectangle(100,100,mx-100,my-100); 
      delay(1000);
      setfillstyle(2,3);
	  floodfill(mx/2,my/2,1);//ham chuan
      getch();
      closegraph();
}

