#include "TXLib.h"
//Добавіть параметров к фону
//Добавіть персонажей (человечков, которых собьет машіна ілі бутылок, в которых топліво ілі лужі ілі трампліны)
void car(int x, int y, int kapot, int kuzov, int koleso, int kabina);
void drawMountain();
void drawRoad();
void pervayaMashinaEdet();
void vtorayaMashinaEdet();

int main()
{
    txCreateWindow(1300, 600);

    pervayaMashinaEdet();
    //vtorayaMashinaEdet();

    return 0;
}

void pervayaMashinaEdet()
{
    int vx = 15;
    int vy = 15;
    int x = 20;
    int y = 310;
    for (int i = 0; i < 340; i++)
    {
        txSetFillColour(RGB(28,172,227));
        txClear();
        if (x < 20)
        {
            vx = -vx;
        }
        if (x > 900)
        {
            vx = -vx;
        }
        if (y < 150)
        {
            vy = -vy;
        }
        if (y > 560)
        {
            vy = -vy;
        }

        x = x + vx;
        y = y + vy;

        car(x, y, 0, 0, 0, 0);
        /*drawMountain();
        drawRoad();

        car(20 + 15*i, 500, 0, 0, 0, 0);
*/
        txSleep(10);
    }
}

void vtorayaMashinaEdet()
{
   for (int i = 0; i < 140; i++)
    {
        txSetFillColour(RGB(28,172,227));
        txClear();

        drawMountain();
        drawRoad();

        car(1400 - 15*i, 310, 0, 0, 0, 0);

        txSleep(10);
    }
}

void car (int x, int y, int kapot, int kuzov, int koleso, int kabina)
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
}


void drawMountain()
{
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
    txSetFillColour(TX_YELLOW);
    txCircle(680, 50, 35);
}

void drawRoad()
{
    txSetFillColour(RGB(128,128,128));
    txSetColour(TX_BLACK, 1);
    txRectangle(0, 250, 1500, 600);

    txSetColour(TX_WHITE, 3);
    txLine     ( 0, 400, 1500,400);
    txSetColour(TX_WHITE, 3);
    txLine     ( 0, 410, 1500,410);
}

