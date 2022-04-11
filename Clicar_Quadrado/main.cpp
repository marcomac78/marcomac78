#include <iostream>
#include <windows.h>
#include<stdio.h>
#include <conio.h>
#include<stdlib.h>

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

// click the mouse using "SendInput"
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

//int main(){
//	SetConsoleTitleA("Programa clicar dentro do quadrado");
//    borda("Clique dentro do quadrado");
//    printf("double clicked at x=%d, y=%d\n", mer.dwMousePosition.X, mer.dwMousePosition.Y);
//    Mouse();
//    Mouse.DoubleLeftClick(p);
//    gotoxy(0,0);
//    printf("l:7 c:3");
//    gotoxy(1,1);
//    printf("l:15 c:9");
//    gotoxy(2,2);
//    printf("l:3 c:20");
//    system("pause >nul");


//    while(true){
//            cout<<"====\n";

//if(POINT.x<400 && POINT.x>200 && POINT.y>100 && POINT.y<500){
//    cout<<"dentro";
//    }
//}


//	POINT pt;
//	BOOL bReturn = GetCursorPos(&pt); //Get the mouse pointer position to pt

//	 if (bReturn != 0) //If the function executes successfully
//		 cout << "Cursor postition is: " << pt.x << "," << pt.y << endl; //Show data in pt
//	 else // if the function did not execute successfully
//		 cout << "Error!" << endl; //Report error

//	cout << "Press any key to exit ...";
//return 0;
//}

int main()
{
    HANDLE hIn;
    HANDLE hOut;
    COORD MouseWhere  = {30, 20};
    COORD DClickWhere = {30, 20};





    bool Continue = TRUE;
    DWORD EventCount;
    int LoopCount = 0;
    int KeyEvents = 0;
    INPUT_RECORD InRec;
    DWORD NumRead;

    hIn = GetStdHandle(STD_INPUT_HANDLE);
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "Mouse is at     : " << endl;
    cout << "Double Click at : " << endl;




    while (Continue)
    {



        Sleep(10); // To slow it down!!

        GetNumberOfConsoleInputEvents(hIn,&EventCount);
        while (EventCount > 0)
        {
           ReadConsoleInput(hIn,&InRec,1,&NumRead);

            if (InRec.EventType == KEY_EVENT)
            {
                if (InRec.Event.KeyEvent.uChar.AsciiChar == 'x')
                {


                            cout << "Exiting..." << endl;
                            Continue = FALSE;
                }
            }
            else if (InRec.EventType == MOUSE_EVENT)
            {

                 if (InRec.Event.MouseEvent.dwEventFlags == MOUSE_MOVED)
                {
                    SetConsoleCursorPosition(hOut,
                                             MouseWhere);
                    cout << InRec.Event.MouseEvent.dwMousePosition.X << "," <<
                            InRec.Event.MouseEvent.dwMousePosition.Y << "  " << flush;
                }
                else if (InRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
                {
                    SetConsoleCursorPosition(hOut,
                                             DClickWhere);
                    cout << InRec.Event.MouseEvent.dwMousePosition.X << "," <<
                            InRec.Event.MouseEvent.dwMousePosition.Y << "  " << flush;
                }
             }

          GetNumberOfConsoleInputEvents(hIn,&EventCount);
        }
    }

    return 0;
}

