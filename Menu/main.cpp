#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


using namespace std;

void borda (char a[])
{
    int largura = 0, interna, i, cont = 0;
    largura = strlen(a);

    while (a[cont] != '\0')
    {
        cont++;
    }

    largura = largura - cont;

    interna = largura + cont + 2;
    printf("\xC9"); //Canto superior esquerdo

    for (i = 1; i <= interna; i++)
    {
    printf("\xCD"); //Linha horizontal
    }

    printf("\xBB"); //Canto superior direito

    printf("\n\xBA"); //Linha vertical

    for (i = 1; i <= interna; i++)
    {
    printf(" ");
    }

    printf("\xBA"); //Linha vertical

    printf("\n\xBA"); //Linha vertical

    printf(" %s ", a);

    printf("\xBA"); //Linha vertical

    printf("\n\xBA"); //Linha vertical

    for (i = 1; i <= interna; i++)
    {
    printf(" ");
    }

    printf("\xBA"); //Linha vertical
    printf("\n\xC8"); //Canto inferior esquerdo
    for (i = 1; i <= interna; i++)
    {
    printf("\xCD"); //Linha horizontal
    }

    printf("\xBC"); //Canto inferior esquerdo
    printf("\n");

}

void gotoxy(int x, int y){
    COORD pos = {x, y};
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int main()
{
    borda("Menu 1");
    borda("Menu 2");
    return 0;
}
