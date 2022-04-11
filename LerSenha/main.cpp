#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>



using namespace std;
char *LerSenha(int);

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char *senha;
    char *descobre_senha;
    int posicao=0;
    int acerto=0;
    int erro=0;
    printf("Insira a sua senha de 4 digitos: ");
    senha = LerSenha(4);
    printf("*\nA senha inserida foi: %s", senha);
    printf("\n\n\nContinuando... ");
    printf("\n\n\nAdvinha a senha de 4 digitos: ");
    descobre_senha = LerSenha(4);
    printf("*\nA senha inserida foi: %s", descobre_senha);
    do
    {
        if(senha[posicao]==descobre_senha[posicao])
        {
            printf("\nVoce acertou a posicao %d",posicao+1);
            acerto++;
        }

        else
        {
            printf("\nVoce errou a posicao %d",posicao+1);
            erro++;
        }

        posicao++;
    } while (posicao<4);
    if (acerto==4)
    {
        SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
        printf("\n\nParabens!!!! Voce descobriu a senha\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }

    else
    {
        SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
        printf("\n\nTente novamente!!!\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    return 0;
}

char *LerSenha(int max)
{
    int i;
    char *senha = (char *)malloc(sizeof(char) * max);

    while( (*(senha + i++) = getch() ) != 13 && i<max ) putchar('*');
    return senha;
}
