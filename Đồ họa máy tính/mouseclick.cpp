/* mouse example */ 

#include <winbgim.h>

#include <stdio.h>

main()

{

    int maxx, maxy;  // Maximum x and y pixel coordinates

    int x, y;        // Coordinates of the mouse click

    int divisor;     // Divisor for the length of a triangle side



    // Put the machine into graphics mode and get the maximum coordinates:

    initwindow(450, 300);         

    maxx = getmaxx( );

    maxy = getmaxy( );



    // Draw a white circle with red inside and a radius of 50 pixels:

    setfillstyle(SOLID_FILL, 4);

    setcolor(15);

    fillellipse(maxx/2, maxy/2, 50, 50);

    

    // Print a message and wait for a red pixel to be double clicked:

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    //outtextxy(20, 20, "Left click in to end.");

    setcolor(1);

    divisor = 2;

    while (!ismouseclick(WM_LBUTTONDOWN))

    {

        rectangle(0, 0, maxx/divisor, maxy/divisor);

        delay(500);

        divisor++;

    }



    getmouseclick(WM_LBUTTONDOWN, x, y);

    printf("The mouse was clicked at: ");

    printf( "x=%d" , x);

    printf( " y=5d" ,y);

    

    // Switch back to text mode:

    closegraph( );

}

