/* Chuong trinh xen mot doan thang vao trong hinh chu nhat */
#include <stdio.h>
#include <conio.h>
#include <winbgim.h>
#include <time.h>

#define NPOINTS 2
#define FALSE 0
#define TRUE 1

struct xycoord {
  double xcoord, ycoord;
} min, max, pt[NPOINTS];

#define LEFT_EDGE   0x1
#define RIGHT_EDGE  0x2
#define TOP_EDGE    0x4
#define BOTTOM_EDGE 0x8

#define INSIDE(a) (!a)
#define REJECT(a,b) (a&b)
#define ACCEPT(a,b) (!(a|b))

unsigned char encode(double x, double y )
{
  unsigned char code = 0x00;

  if (x < min.xcoord)
    code = code | LEFT_EDGE;
  if (x > max.xcoord)
    code = code | RIGHT_EDGE;
  if (y < min.ycoord)
    code = code | TOP_EDGE;
  if (y > max.ycoord)
    code = code | BOTTOM_EDGE;

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

void Clip(double x1, double y1, double x2, double y2)
{
  unsigned char code1, code2;
  int done = FALSE, draw = FALSE;
  double m;

  while (!done)
  {
    code1 = encode(x1, y1);
    code2 = encode(x2, y2);
    if (ACCEPT(code1, code2))
    {
      done = TRUE;
      draw = TRUE;
    }
    else
    {
      if (REJECT(code1, code2))
        done = TRUE;
      else
      {
        if (INSIDE(code1))
        {
          swap(x1, x2);
          swap(y1, y2);
          swapcode(code1, code2);
        }
        if (x2 == x1) if (code1 & BOTTOM_EDGE) y1 = max.ycoord;
        			  else y1 = min.ycoord;
        else {
		m = (y2 - y1) / (x2 - x1);
        if (code1 & LEFT_EDGE)
        {
          y1 += (min.xcoord - x1) * m;
          x1 = min.xcoord;
        }
        else
          if (code1 & RIGHT_EDGE)
          {
            y1 += (max.xcoord - x1) * m;
            x1 = max.xcoord;
          }
          else
            if (code1 & BOTTOM_EDGE)
            {
              x1 += (max.ycoord - y1) / m;
              y1 = max.ycoord;
            }
            else
              if (code1 & TOP_EDGE)
              {
                x1 += (min.ycoord - y1) / m;
                y1 = min.ycoord;
              }
    	}
      }
    }
  }
  printf("\n%.2f %.2f %.2f %.2f",x1,y1,x2,y2);
  setcolor(4);
  if (draw)
    line(int(x1), int(y1), int(x2), int(y2));
}

main()
{
  int mx, my, x, y, i;

  initwindow(1000,600);
  setbkcolor(15); cleardevice();
  
  mx=getmaxx(); my=getmaxy();
  setcolor(4); rectangle(10, 10, mx-10, my-10);
  
  min.xcoord = 100;
  min.ycoord = 100;
  max.xcoord = 900;
  max.ycoord = 900;
  setcolor(1);
  rectangle(200,200,800,500);
  
  srand(time(NULL));
  pt[0].xcoord = rand()%mx;
  pt[0].ycoord = rand()%my;
  pt[1].xcoord = rand()%mx;
  pt[1].ycoord = rand()%my;
  
  setcolor(1);
  line(int(pt[i].xcoord), int(pt[i].ycoord),int(pt[i].xcoord), int(pt[i].ycoord));
  printf("\n%.2f %.2f %.2f %.2f", pt[i].xcoord, pt[i].ycoord, pt[i+1].xcoord, pt[i+1].ycoord);
  getch();
  Clip(pt[i].xcoord, pt[i].ycoord, pt[i+1].xcoord, pt[i+1].ycoord);
    
  getch();
  closegraph();
}
