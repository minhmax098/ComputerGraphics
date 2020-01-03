/* Chuong trinh xen mot doan thang vao cua so chu nhat co canh song song cac truc toa do */

#include <winbgim.h>
#include <time.h>

#define LEFT_EDGE   0x1
#define RIGHT_EDGE  0x2
#define TOP_EDGE    0x4
#define BOTTOM_EDGE 0x8

#define INSIDE(a) (!a)
#define REJECT(a,b) (a&b)
#define ACCEPT(a,b) (!(a|b))

double  minx,maxx,miny,maxy; //le cua so

unsigned char encode(double x, double y )
{
  unsigned char code = 0x00;

  if (x < minx)
    code =  LEFT_EDGE;
  if (x > maxx)
    code = RIGHT_EDGE;
  if (y < miny)
    code = code | BOTTOM_EDGE;
  if (y > maxy)
    code = code | TOP_EDGE;

  return code;
}

void swap(double &a, double &b)
{
  double tmp;

  tmp = a;
  a = b;
  b = tmp;
}

void swapcode(unsigned char &a, unsigned char &b)
{
  unsigned char tmp;

  tmp = a;
  a = b;
  b = tmp;
}

int Clip(double &x1, double &y1, double &x2, double &y2)
{
  unsigned char code1, code2;
  double m;

  while (1){
    code1 = encode(x1, y1);
    code2 = encode(x2, y2);
    if (ACCEPT(code1, code2)) return 1;
    else
      if (REJECT(code1, code2)) return 0;
      else
      {
        if (INSIDE(code1)){
          swap(x1, x2);
          swap(y1, y2);
          swapcode(code1, code2);
        }
        if (x2 == x1) if (code1 & TOP_EDGE) y1 = maxy;
        			  else y1 = miny;
        else {
		  m = (y2 - y1) / (x2 - x1);
          if (code1 & LEFT_EDGE){
          	y1 += (minx - x1) * m;
          	x1 = minx;
          }
          else
            if (code1 & RIGHT_EDGE){
              y1 += (maxx - x1) * m;
              x1 = maxx;
          	}
          else
            if (code1 & TOP_EDGE){
              x1 += (maxy - y1) / m;
              y1 = maxy;
            }
            else
              if (code1 & BOTTOM_EDGE){
                x1 += (miny - y1) / m;
                y1 = miny;
              }
    	}
      }
    }
}

main()
{
  int mx, my, draw;
  double x1, y1, x2, y2;

  initwindow(1300,700);
  setbkcolor(15); cleardevice();
  
  mx=getmaxx(); my=getmaxy();
    
  minx = 200;
  miny = 200;
  maxx = 1000;
  maxy = 500;
  setcolor(5);
  rectangle(minx,miny,maxx,maxy);
  
  srand(time(NULL));
    
  while (getch()!=27){
    x1 = rand()%mx;
    y1 = rand()%my;
    x2 = rand()%mx;
    y2 = rand()%my;	
    //setcolor(2);  line(int(x1), int(y1),int(x2), int(y2)); getch();
    draw=Clip(x1, y1, x2, y2);
    setcolor(4);  if (draw) line(int(x1), int(y1), int(x2), int(y2));  
  }
  closegraph();
}
