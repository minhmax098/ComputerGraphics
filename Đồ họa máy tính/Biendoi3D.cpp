#include <winbgim.h>
#include <math.h>


typedef struct {
  double x, y, z;
} Point3D;

double yaw, roll, pitch, depth;

static Point3D p[] = {
{-35.0, -35.0, 35.0},
{35.0, -35.0, 35.0},
{35.0, 35.0, 35.0},
{-35.0, 35.0, 35.0},
{-35.0, -35.0, 35.0},
{-35.0, -35.0, -35.0},
{35.0, -35.0, -35.0},
{35.0, 35.0, -35.0},
{-35.0, 35.0, -35.0},
{-35.0, -35.0, -35.0}
};

void show_3d(Point3D p[], int n);

int mx, my, c;

main()
{
      
      initwindow(1000,600);
      setbkcolor(15); setcolor(9); cleardevice();
      moveto(550, 150);
      mx=getmaxx(); my=getmaxy();
  yaw = 5.7;
  roll = 6.3;
  pitch = 5.9;
  depth = 360;
  while (c != 27)
  {
    show_3d(p, 10);
    c = getch();
    if (c==0)
      c = getch();
    switch (c)
    {
      case 75 : yaw -= 0.1;
                break;
      case 77 : yaw += 0.1;
                break;
      case 72 : pitch -= 0.1;
                break;
      case 80 : pitch += 0.1;
                break;
    }
  }
 closegraph();
}


void show_3d(Point3D p[], int n)
{
  double sinyaw, cosyaw, sinroll, cosroll, sinpitch, cospitch,
         yawx, yawy, rollx, rollz, pitchx, pitchy, pitchz, sx, sy;
  int r;

  cleardevice();

  sinyaw = sin(yaw);
  cosyaw = cos(yaw);
  sinroll = sin(roll);
  cosroll = cos(roll);
  sinpitch = sin(pitch);
  cospitch = cos(pitch);

  for (r=0; r<n; r++)
  {
    yawx = (cosyaw * p[r].x) - (sinyaw * p[r].y);
    yawy = (sinyaw * p[r].x) + (cosyaw * p[r].y);
    rollx = (cosroll * yawx) + (sinroll * p[r].z);
    rollz = (cosroll * p[r].z) - (sinroll * p[r].z);
    pitchy = (cospitch * yawy) - (sinpitch * rollz);
    pitchz = (sinpitch * yawy) + (cospitch * rollz);

    sx = depth * (rollx+5) / (pitchy+250);
    sy = depth * (pitchz-5) / (pitchy+250);
    if (r == 0)
      moveto(sx+mx / 2, sy + my/ 2);
    else
      lineto(sx+mx/ 2, sy+my/ 2);
  }
}
