#include "TXLib.h"

void car(int x, int y, int kapot, int kuzov, int koleso, int kabina);
void drawMountain();

int main()
{
    txCreateWindow(1300, 600);

    for(int i = 0; i < 1100; i++)
    {

        txSetFillColour(RGB(28,172,227));
        txSetColour(TX_BLACK, 1);
        txRectangle(0, 0, 1000, 250);


        txClear();
        car(20+i,500, 0, 0, 0, 0);
        //car(20+i,500, 50, 70, 20, 40);
        txSleep(100);
        i = i + 10;
    }
    return 0;
}

void car(int x, int y, int kapot, int kuzov, int koleso, int kabina)
{

    // дорога
    txSetFillColour(RGB(128,128,128));
    txSetColour(TX_BLACK, 1);
    txRectangle(0, 250, 1500, 600);

    // разделительная полоса
    txSetColour(TX_WHITE, 3);
    txLine     ( 0, 400, 1500,400);
    txSetColour(TX_WHITE, 3);
    txLine     ( 0, 410, 1500,410);

    // все квадраты
    txSetFillColour(TX_RED);
    txSetColour(TX_BLACK, 1);
    txLine     ( x- 20,  y-70-kapot,   x+180,         y-70);
    txRectangle( x- 20,  y- 70,        x+180,         y+10);
    txRectangle( x+180,  y-150-kabina, x+280,         y+10);
    txRectangle( x+280,  y- 80,        x+380+kuzov,   y+10);

    // окно
    txSetFillColour(TX_LIGHTCYAN);
    txRectangle( x+190,  y-140,        x+270,         y-80);

    // ручка двери
    txSetColour(TX_BLACK, 3);
    txSetFillColour(TX_LIGHTGRAY);
    txEllipse(   x+190,     y-60,      x+210,         y-50);

    // колёса
    txSetColour(TX_BLACK, 5);
    txSetFillColour(TX_GRAY);
    txCircle(    x+60,      y+10,      30+koleso);
    txCircle(    x+300,     y+10,      30+koleso);

    // диски
    txCircle(    x+60,      y+10,      10);
    txCircle(    x+300,     y+10,      10);

    // фары
    txSetColour(TX_ORANGE, 2);
    txSetFillColour(TX_YELLOW);
    txEllipse(   x+380,     y-20,      x+390,          y);

    // горы
    txSetColour(TX_BLUE, 5);
    txLine(10, 250, 110, 90);
    txLine(110, 90, 150, 250);

    txLine(130, 180, 200, 60);
    txLine(200, 60, 240, 150);

    txLine(150, 250, 320, 70);
    txLine(320, 70, 380, 160);

    txLine(330, 250, 420, 100);
    txLine(420, 100, 540, 250);

    txLine(460, 150, 520, 80);
    txLine(520, 80, 650, 250);

    // солнце
    txSetColour(TX_ORANGE, 2);
    txCircle(680, 50, 35);
}
