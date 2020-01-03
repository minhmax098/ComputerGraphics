#include <winbgim.h>
#include <math.h>
#include "Affine.h"

#define RADS  0.017453

main()
{
      int mx, my, angle;
	  float theta, d=230.0;
      Point A={d,0}, B={d,d}, C={0,d};
      Affine T;
      
      initwindow(1300,700);
      setbkcolor(15); setcolor(2); cleardevice();
      mx=getmaxx(); my=getmaxy();
      setviewport(mx/2,my/2,mx,my,0);
      theta=RADS;
      Quay(T, theta);
      for (angle=0; angle<=360; angle++){
      	  line(0,0,int(A.x), int(A.y)); 
		  line(int(A.x), int(A.y),int(B.x), int(B.y)); 
		  line(int(B.x), int(B.y),int(C.x), int(C.y)); 
		  line(int(C.x), int(C.y),0, 0); 
		  delay(100);
		  Biendoi(T,A,&A);
		  Biendoi(T,B,&B);
		  Biendoi(T,C,&C);
	  } 
 	  getch();
      closegraph();
}

