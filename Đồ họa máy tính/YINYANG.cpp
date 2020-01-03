/* Yinyang */
#include <conio.h>
#include <winbgim.h>
#include <math.h>
#include <dos.h>

/* 1 / sqrt(2) */
#define FCT 0.7071067
/* he so doi tu do sang radian */
#define RADS 0.017453293
#define DELAY 100
#define RADIUS1 150.0
#define RADIUS2 10.0

double xc, yc, x1, y01, x2, y02, angle;

void xoa()
{
  setcolor(0);
  setfillstyle(SOLID_FILL, 0);
  fillellipse(xc, yc, RADIUS1, RADIUS1);
}

void ve()
{
  
  setcolor(15);
  setfillstyle(SOLID_FILL,15);
  circle(xc, yc, RADIUS1);
  arc(xc + (x1-xc)/2, yc + (y01-yc)/2, -angle, -angle + 180, RADIUS1 / 2);
  arc(xc + (x2-xc)/2, yc + (y02-yc)/2, 180-angle, 360-angle, RADIUS1 / 2);
  circle(xc + (x1-xc)/2, yc + (y01-yc)/2, RADIUS2);
  circle(xc + (x2-xc)/2, yc + (y02-yc)/2, RADIUS2);
  floodfill(xc + (x2-xc)/2, yc + (y02-yc)/2, 15);
  floodfill(xc + (x1-xc)/2 + RADIUS2 +5, y01 + (y02-yc)/2 + RADIUS2 + 5, 15);
}
void tinh()
{
  angle += 1.0;
  if (angle >= 360.0)
    angle = 0.0;
  x1 = xc - RADIUS1 * cos(angle * RADS);
  y01 = yc - RADIUS1 * sin(angle * RADS);
  x2 = xc + RADIUS1 * cos(angle * RADS);
  y02 = yc + RADIUS1 * sin(angle * RADS);
}

void yinyang()
{
  do {
    ve();
    delay(DELAY);
    xoa();
    tinh();
  } while (!kbhit());
}

main()
{
  
  initwindow(1000, 600);
  //setbkcolor(0); setcolor(19); cleardevice();
  xc = getmaxx() / 2;
  y01 = y02 = yc = getmaxy() / 2;
  x1 = xc - RADIUS1;
  x2 = xc + RADIUS1;
  angle = 0.0;
  yinyang();
  getch();
  closegraph();
}
