#include <graphics.h>
#include <conio.h>
#include <math.h>

struct Point {
    int x, y;
};

Point bezier(Point p0, Point p1, Point p2, Point p3, float t) {
    Point p;
    float u = 1 - t;
    float tt = t * t;
    float uu = u * u;
    float uuu = uu * u;
    float ttt = tt * t;

    p.x = uuu * p0.x + 3 * uu * t * p1.x + 3 * u * tt * p2.x + ttt * p3.x;
    p.y = uuu * p0.y + 3 * uu * t * p1.y + 3 * u * tt * p2.y + ttt * p3.y;
    return p;
}

void drawBezierMountain() {
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);

    Point p0 = {50, 300}, p1 = {120, 100}, p2 = {200, 100}, p3 = {300, 300};
    int mountain1[100];
    int index = 0;
    for (float t = 0; t <= 1; t += 0.05) {
        Point pA = bezier(p0, p1, p2, p3, t);
        mountain1[index++] = pA.x;
        mountain1[index++] = pA.y;
    }
    mountain1[index++] = 300;
    mountain1[index++] = 300;
    mountain1[index++] = 50;
    mountain1[index++] = 300;
    fillpoly(index / 2, mountain1);

    Point p4 = {250, 300}, p5 = {320, 120}, p6 = {400, 120}, p7 = {500, 300};
    int mountain2[100];
    index = 0;
    for (float t = 0; t <= 1; t += 0.05) {
        Point pB = bezier(p4, p5, p6, p7, t);
        mountain2[index++] = pB.x;
        mountain2[index++] = pB.y;
    }
    mountain2[index++] = 500;
    mountain2[index++] = 300;
    mountain2[index++] = 250;
    mountain2[index++] = 300;
    fillpoly(index / 2, mountain2);
}

void drawTree(int x, int y) {
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    bar(x, y, x + 10, y + 40);

    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    int treePoints[] = {x - 15, y, x + 25, y, x + 5, y - 40, x - 15, y};
    fillpoly(4, treePoints);
}

void drawHouse() {
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    rectangle(250, 250, 400, 350);
    floodfill(300, 300, RED);

    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    rectangle(290, 300, 340, 350);
    floodfill(300, 320, BROWN);

    setcolor(BLUE);
    setfillstyle(HATCH_FILL, BLUE);
    rectangle(260, 270, 290, 300);
    floodfill(270, 280, BLUE);

    setcolor(BROWN);
    line(250, 250, 325, 200);
    line(325, 200, 400, 250);
    line(250, 250, 400, 250);
    setfillstyle(SOLID_FILL, DARKGRAY);
    floodfill(325, 220, BROWN);
}

void drawHuman(int x, int y) {
    setcolor(BLACK);
    circle(x, y, 10);
    line(x, y + 10, x, y + 30);
    line(x, y + 20, x - 10, y + 30);
    line(x, y + 20, x + 10, y + 30);
    line(x, y + 30, x - 10, y + 45);
    line(x, y + 30, x + 10, y + 45);
}

void drawCar(int x, int y) {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    rectangle(x, y, x + 60, y + 30);
    floodfill(x + 30, y + 15, WHITE);

    setcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    rectangle(x + 10, y + 5, x + 50, y + 20);
    floodfill(x + 30, y + 12, LIGHTBLUE);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(x + 15, y + 30, 7);
    floodfill(x + 15, y + 30, BLACK);
    circle(x + 45, y + 30, 7);
    floodfill(x + 45, y + 30, BLACK);
}

void drawCloud(int x, int y) {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(x, y, 20, 10);
    fillellipse(x + 20, y + 5, 20, 10);
    fillellipse(x + 40, y, 20, 10);
}

void drawBird(int x, int y) {
    setcolor(BLACK);
    arc(x, y, 0, 180, 10);
    arc(x + 20, y, 0, 180, 10);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setbkcolor(LIGHTBLUE);
    cleardevice();

    int sunRadius = 50;
    int sunY = 80;

    for (int i = 50; i <= getmaxx() - 100; i += 5) {
        cleardevice();

        setfillstyle(SOLID_FILL, GREEN);
        bar(0, 300, 640, 480);
        drawBezierMountain();
        drawTree(100, 300);
        drawHouse();
        drawHuman(180, 270);

        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        circle(i, sunY, sunRadius);
        floodfill(i, sunY, YELLOW);

        setfillstyle(SOLID_FILL, COLOR(139, 69, 19));
        bar(0, 430, 640, 480);

        drawCar(i + 50, 350);
        drawCloud(150, 100);
        drawCloud(300, 80);
        drawBird(400, 100);
        drawBird(450, 120);
        delay(50);
    }

    getch();
    closegraph();
    return 0;
}
