#include "TXLib.h"

void car(int x, int y, int kapot, int kuzov, int koleso, int kabina);
void drawMountain();

int main()
{
    txCreateWindow(1000, 700);

    // движение
    for(int i = 0; i < 1100; i++)
    {
        // фон
        txSetFillColour(TX_GREEN);
        txClear();
        drawMountain();
        car(20+i,200, 0, 0, 0, 0);
        car(20+i,500, 50, 70, 20, 40);
        txSleep(100);
        i = i + 10;
    }



    return 0;
}

void drawMountain()
{
    txLine(100, 100, 200, 200);
    txLine(300, 100, 200, 200);
    txLine(100, 100, 300, 100);

}

void car(int x, int y, int kapot, int kuzov, int koleso, int kabina)
{
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

    // колеса
    txSetColour(TX_BLACK, 5);
    txSetFillColour(TX_GRAY);
    txCircle(    x+60,      y+10,      30+koleso);
    txCircle(    x+300,     y+10,      30+koleso);

    // диски
    txCircle(    x+60,      y+10,      10);
    txCircle(    x+300,     y+10,      10);

    // фара
   // txSetColour(TX_ORANGE, 2);
   // txSetFillColour(TX_YELLOW);
   // txEllipse(x+380, y-20, x+390, y);
}
