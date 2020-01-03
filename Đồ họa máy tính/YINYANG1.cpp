/* Yinyang */
#include <stdio.h>
#include <winbgim.h>

main()
{
  int x=500,y=300,R=100,r=10;

  initwindow(1000, 600);
  circle(x,y,R);
  arc(x-R/2,y,0,180,R/2);
  arc(x+R/2,y,180,360,R/2);
  circle(x-R/2,y,r);
  circle(x+R/2,y,r+1);
  floodfill(x+R/2,y-r-2,15);
  floodfill(x-R/2,y,15); 
  getchar(); 
}
