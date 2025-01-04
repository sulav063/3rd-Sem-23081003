#include <stdio.h>
#include <graphics.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2, i;
    float x, y, dx, dy, length;
    int gd = DETECT, gm;

    printf("Enter first points: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter second points: ");
    scanf("%d %d", &x2, &y2);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    length = (abs(x2 - x1) > abs(y2 - y1)) ? abs(x2 - x1) : abs(y2 - y1);
    dx = (float)(x2 - x1) / length;
    dy = (float)(y2 - y1) / length;

    x = x1;
    y = y1;
    i = 1;

    while (i <= length) {
	putpixel(x, y, GREEN);
	x += dx;
	y += dy;
	i++;
    }

    getch();
    closegraph();
    return 0;
}