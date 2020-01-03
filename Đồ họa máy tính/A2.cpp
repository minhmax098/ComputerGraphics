#include <winbgim.h>

main()
{
	int n=10,d=10,i;
	
	initwindow(1000,600);
	setviewport(500,300,1000,600,0);
	while (!kbhit()){
		setcolor(15); 
		for (i=1;i<=n;i++){
			rectangle(-i*d,-i*d,i*d,i*d); delay(50);
		} 
		delay(500);
		setcolor(0); 
		for (i=n;i>0;i--){
			rectangle(-i*d,-i*d,i*d,i*d); delay(50);
		} 
		delay(500);
	}
}
