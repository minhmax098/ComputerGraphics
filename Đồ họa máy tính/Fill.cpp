#include <winbgim.h>

void BoundaryFill(int x, int y, int FillColor, int BoundryColor);

main()
{
      int mx, my;
    
      initwindow(1300,700);
      mx=getmaxx(); my=getmaxy();
      setcolor(1);
      //arc(mx/2,my/2,0,350,150);
      circle(mx/2,my/2,160); //RMAX = 167
      delay(1000);
      //setcolor(14); khong tac dung cho floodfill()
	  floodfill(mx/2,my/2,1); // ham chuan
      delay(1000);
      BoundaryFill(mx/2,my/2,2,1);
      delay(1000);
      getch();
      closegraph();
}

void BoundaryFill(int x, int y, int FillColor, int BoundryColor)
{
	int CurrentColor=getpixel(x,y);
	if((CurrentColor!=BoundryColor) &&(CurrentColor!=FillColor)){
		putpixel(x,y,FillColor); //delay(1);
		BoundaryFill(x-1,y,FillColor,BoundryColor);
		BoundaryFill(x+1,y,FillColor,BoundryColor);
		BoundaryFill(x,y-1,FillColor,BoundryColor);
		BoundaryFill(x,y+1,FillColor,BoundryColor);
	}
}
