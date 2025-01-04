#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

int main(){
    int x1, y1, x2, y2, i;
    float x, y, dx, dy, length;

    int gd = DETECT, gm;
    printf("Enter first points:");
    scanf("%d%d", &x1, &y1);
    printf("Enter second points:");
    scanf("%d%d", &x2, &y2);
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    if (abs(x2 - x1) > abs(y2 - y1)) {
        length = abs(x2 - x1);
        dx = (x2 - x1) / length;
        dy = (y2 - y1) / length;
        x = x1;
        y = y1;
        i = 1;
    } else {
        length = abs(y2 - y1);
        dx = (x2 - x1) / length;
        dy = (y2 - y1) / length;
        x = x1;
        y = y1;
        i = 1;
    }

    while (i <= length) {
	putpixel(x, y, BLUE);
        x = x + dx;
        y = y + dy;
        i++;
    }

    closegraph();
    getch();
    return 0;
}