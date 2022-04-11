#include <iostream>
#include <windows.h>
#include <WindowsX.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <cmath>
#include <winuser.h>


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

    if (largura % 2 != 0) //Largura par
    {
    largura--;
    }

    interna = largura + cont + 2;
    system ("cls");
    printf("\n\n");
    printf("\n\xC9"); //Canto superior esquerdo

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

    for (i = 1; i <= largura / 2; i++)
    {
    printf("*");
    }

    printf(" %s ", a);


    for (i = 1; i <= largura  / 2; i++)
    {
    printf("*");
    }

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
    printf("\n\n");

}


void gotoxy(int x, int y){
    COORD pos = {x, y};
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void Mouse(){
    POINT point;
    while(true){
        GetCursorPos(&point);
        cout<<"x: "<<point.x<<"\ny: "<<point.y;
        cout<<"\n\n\n";
        borda("Clique dentro do quadrado");
        system("cls");
    }
}


void mouseRightClick ()
{
     // create an INPUT object named "Input"
     INPUT Input = {0};

     // simulate the right mouse button being pressed
     // specify the type of input as mouse
     Input.type = INPUT_MOUSE;
     // specify the action that was performed, "right down"
     Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
     // send the input to the system
     ::SendInput(1,&Input,sizeof(INPUT));

     // simulate release of the right mouse button
     // clear the the "Input" object rather than assign a more memory
     ::ZeroMemory(&Input,sizeof(INPUT));
     // specify type of input
     Input.type = INPUT_MOUSE;
     // indicate that the action "right up" was performed
     Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
     // send the input to the system
     ::SendInput(1,&Input,sizeof(INPUT));
}


void mouseLeftClick ()
{
     INPUT Input = {0};

     // left down
     Input.type = INPUT_MOUSE;
     Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
     ::SendInput(1,&Input,sizeof(INPUT));

     // left up
     ::ZeroMemory(&Input,sizeof(INPUT));
     Input.type = INPUT_MOUSE;
     Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
     ::SendInput(1,&Input,sizeof(INPUT));
}

LRESULT CALLBACK WndProc(_In_ HWND hWnd, _In_ UINT msg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
    POINT pt;

    switch (msg)
    {

    case WM_LBUTTONDOWN:
            {
                pt.x = GET_X_LPARAM(lParam);
                pt.y = GET_Y_LPARAM(lParam);
            }

        break;

    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }
    return 0;
}

int CheckMouseButtonStatus()
{
    POINT point;
    while(true){
        //Check the mouse left button is pressed or not
        if ((GetKeyState(VK_LBUTTON) & 0x80) != 0)
        {
            MessageBox (NULL, "VK_LBUTTON" , "titulo", 1);
            GetCursorPos(&point);
            system ("cls");
            cout<<"Botao Esquerda x: "<<point.x<<"\ny: "<<point.y;
            system ("pause");
        }
        //Check the mouse right button is pressed or not
        else
        {
            if ((GetKeyState(VK_RBUTTON) & 0x80) != 0)
            {
                MessageBox (NULL, "VK_RBUTTON" , "titulo", 1);
                GetCursorPos(&point);
                cout<<"Botao Direita x: "<<point.x<<"\ny: "<<point.y;
            }
        }
    }
return 0;
}

int main(){
	SetConsoleTitleA("Programa clicar dentro do quadrado");
    borda("Clique dentro do quadrado");
    Mouse();
//    CheckMouseButtonStatus();
//    mouseLeftClick ();
return 0;
}





