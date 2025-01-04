#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main(){
	int gd=DETECT,gm;
	int x1,y1,x2,y2,tx,ty,x3,y3,x4,y4,a,t;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	printf("\nEnter the strating point of the line segment(x1,y1):");
	scanf("%d %d", &x1,&y1);
	printf("\nEnter the ending point of the line segment(x2,y2):");
	scanf("%d %d", &x2,&y2);
	printf("\nEnter the angle for rotation(degree):");
	scanf("%f",&a);
	setcolor(7);
	line(x1,y1,x2,y2);
	outtextxy(x2+5,y2,"Object");
		t=a*(3.14/180);
		x3=(x1*cos(t))-(y1*sin(t));
		y3=(x1*sin(t))+(y1*cos(t));
		x4=(x2*cos(t))-(y2*sin(t));
		y4=(x2*sin(t))+(y2*cos(t));
	setcolor(15);
	line(x3,y3,x4,y4);
	outtextxy(x4+5,y4,"Image");
	getch();

}