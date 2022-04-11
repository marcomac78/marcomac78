#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>


using namespace std;

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int digito=0;
    int aux=0;
    int aleatorio=0;
    void delay(int);
    //system("CLS");
    printf("Programa descobre digito\n");
    printf("======== ======== ======\n\n");
    srand (time(NULL));
    aleatorio = (rand() %6);
    printf("\nSistema gerando numero aleatorio.");
    delay(2);
    system("CLS");
    printf("Programa descobre digito\n");
    printf("======== ======== ======\n\n");
    printf("\nSistema gerando numero aleatorio..");
    delay(2);
    system("CLS");
    printf("Programa descobre digito\n");
    printf("======== ======== ======\n\n");
    printf("\nSistema gerando numero aleatorio...");
    printf("\nNumero aleatorio gerado!\n\n");
    do
    {
        if(aux>0)
        {
            system("CLS");
            printf("Programa descobre digito\n");
            printf("======== ======== ======\n\n");
            printf("O numero digitado foi: %d. Por favor insira um digito de 0 a 6: ", digito);
            scanf("%d",&digito);
            aux++;
        }
        else
        {
            printf("Insira um digito de 0 a 6 e pressione <ENTER>: ");
            scanf("%d",&digito);
            aux++;
        }
    }
    while ((digito<0) || (digito>6));
    if (digito == aleatorio)
    {
        SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
        printf("\nParabens! Voce descobriu o numero aleatorio gerado pelo sistema --> %d", digito);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else
    {
        SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
        printf("\nVoce errou!! O numero aleatorio gerado pelo sistema foi o %d e o numero que voce digitou foi o %d!!\nPor favor tente novamente", aleatorio, digito);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }

    printf("\n\n\nFim... \n");
    return 0;

}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}
