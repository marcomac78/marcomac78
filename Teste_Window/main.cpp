#include <iostream>
#include <windows.h>

using namespace std;


//int main() {
//  int choise = MessageBox( 0, "Voce tem certeza que deseja continuar?", "Aviso!", MB_YESNO + MB_ICONEXCLAMATION );
//    if ( choise == IDYES ) {
//      cout << "yes" << endl;
//    }
//    else {
//      cout << "no" << endl;
//    }
//}

//int main( int argc, char *argv[] ) {
//  int btn = MessageBox( 0,
//               argc > 1 ? argv[1] : "" ,
//               argc > 2 ? argv[2] : "Question" ,
//               MB_YESNO + MB_ICONQUESTION );
//  if ( btn == IDYES ) {
//    cout << "yes" << endl;
//  }
//  else {
//    cout << "no" << endl;
//  }
//}

//int soma (int argc, char* argv) {
//   cout << "This program has " << argc << " arguments:" << endl;
//   for (int i = 0; i < argc; ++i) {
//      cout << argv[i] << endl;
//   }
//   return 0;
//}

char *funcMens(char);
int main ()
{
    char *mensagem = (char *)malloc(sizeof(char)*a);
    printf("Digite uma mensagem:\n\n");
    scanf("%s",mensagem);
    funcMens(mensagem);
    printf("\n\n");
    system("pause");
    return 0;
}

void funcMens (char a[])
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
