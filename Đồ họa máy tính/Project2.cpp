#include <winbgim.h>

main()
{
  int gd=0,gm;	
  initgraph(&gd,&gm,"");
  circle(300,300,150);
  getch();
  closegraph();
}
