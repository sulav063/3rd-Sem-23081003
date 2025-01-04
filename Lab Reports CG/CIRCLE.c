//bresenham's circle
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>

int main(){
	int r,h,k,x,y,p0;
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
	printf("h=");
	scanf("%d",&h);
	printf("k=");
	scanf("%d",&k);
	printf("r=");
	scanf("%d",&r);

	x=0;
	y=r;
	p0=1-r;

	while(x<=y){
		putpixel(x+h,y+k,4);
		putpixel(-x+h,y+k,4);
		putpixel(x+h,-y+k,4);
		putpixel(-x+h,-y+k,4);
		putpixel(y+h,x+k,4);
		putpixel(-y+h,x+k,4);
		putpixel(y+h,-x+k,4);
		putpixel(-y+h,-x+k,4);

		if(p0<0){
			p0=p0+2*x+1;
			x=x+1;
		} else{
			p0=p0+2*x+1-2*y;
			x=x+1;
			y=y-1;
		}
	}


	getch();
	closegraph();
	return 0;
}
