#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>

int main(){
	int x1,y1,x2,y2;
	float m,abs,xin,yin;
	int x,y,i;
	int gdriver= DETECT, gmode;
	initgraph(&gdriver,&gmode, "C:\\TURBOC3\\BGI");
	printf("Enter first points: ");
	scanf("%d%d",&x1,&y1);
	printf("Enter second points: ");
	scanf("%d%d",&x2,&x2);

	m=(y2-y1)/(x2-x1);

	if(m<1){
		abs=x2-x1;
	} else{
		abs=y2-y1;
	}
	if(abs<0){
		abs=abs*(-1);
	}

	xin=(x2-x1)/abs;
	yin=(y2-y1)/abs;

	for(i=0;i<abs;i++){
		x=x1+xin;
		y=y1+yin;
		putpixel(x,y,5);
		x1=x;
		y1=y;
	}



	getch();
	closegraph();
return 0;
}