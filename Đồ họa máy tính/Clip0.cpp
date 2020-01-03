/* Xen cac doan thang vao cua so chu nhat co canh song song cac truc toa do */

#include <winbgim.h>
#include <stdio.h>
#include <time.h>

#define LEFT_EDGE   0x1
#define RIGHT_EDGE  0x2
#define TOP_EDGE    0x4
#define BOTTOM_EDGE 0x8

#define INSIDE(a) (!a)
#define REJECT(a,b) (a&b)
#define ACCEPT(a,b) (!(a|b))

int  minx,maxx,miny,maxy; //le cua so

unsigned char Encode(int, int);
void Swap(int &, int &);
void Swapcode(unsigned char &, unsigned char &);
int Clip(int &, int &, int &, int &);

main()
{
  int draw, a=0, b=0, x1, y1, x2, y2;

  initwindow(700,700);
  setbkcolor(15); cleardevice();
    
  minx = 200;
  miny = 200;
  maxx = 500;
  maxy = 500;
  setcolor(5);
  rectangle(minx,miny,maxx,maxy);
    
  while (!kbhit()){
		if (ismouseclick(WM_LBUTTONDOWN)){
			a=1;
			getmouseclick (WM_LBUTTONDOWN,x1,y1);
			setcolor(1);circle(x1,y1,3);
			printf("\nChua xen: A(%d,%d)",x1,y1);
		}
		if (ismouseclick(WM_RBUTTONDOWN)){
			b=1;
			getmouseclick (WM_RBUTTONDOWN,x2,y2);
			setcolor(4);circle(x2,y2,3);
			printf("  B(%d,%d)",x2,y2);
		}
		if (a && b){
			setcolor(2);  line(x1,y1,x2,y2);
    		draw=Clip(x1,y1,x2,y2);
    		printf("\nXen xong: A(%d,%d)  B(%d,%d)",x1,y1,x2,y2);
    		setcolor(4);  if (draw) line(x1,y1,x2,y2);  
    		a=0; b=0;
		}
  }
  closegraph();
}

unsigned char Encode(int x, int y )
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

void Swap(int &a, int &b)
{
  double tmp;

  tmp = a;
  a = b;
  b = tmp;
}

void Swapcode(unsigned char &a, unsigned char &b)
{
  unsigned char tmp;

  tmp = a;
  a = b;
  b = tmp;
}

int Clip(int &x1, int &y1, int &x2, int &y2)
{
  unsigned char code1, code2;
  double m;

  while (1){
    code1 = Encode(x1, y1);
    code2 = Encode(x2, y2);
    if (ACCEPT(code1, code2)) return 1;
    else
      if (REJECT(code1, code2)) return 0;
      else
      {
        if (INSIDE(code1)){
          Swap(x1, x2);
          Swap(y1, y2);
          Swapcode(code1, code2);
        }
        if (x2 == x1) if (code1 & TOP_EDGE) y1 = maxy;
        			  else y1 = miny;
        else {
		  m = float(y2 - y1) / (x2 - x1);
          if (code1 & LEFT_EDGE){
          	y1 += int((minx - x1) * m);
          	x1 = minx;
          }
          else
            if (code1 & RIGHT_EDGE){
              y1 += int((maxx - x1) * m);
              x1 = maxx;
          	}
          else
            if (code1 & TOP_EDGE){
              x1 += int((maxy - y1) / m);
              y1 = maxy;
            }
            else
              if (code1 & BOTTOM_EDGE){
                x1 += int((miny - y1) / m);
                y1 = miny;
              }
    	}
      }
    }
}
