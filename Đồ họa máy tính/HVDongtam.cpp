#include <winbgim.h>

main()
{
	int n=10,D=10,i;
	
	initwindow(1000,600);
	setviewport(500,300,1000,600,0);
	for (i=1;i<=n;i++){
		rectangle(-D*i,-D*i,D*i,D*i); delay(50);
	} 
	getch();
	closegraph();
}
