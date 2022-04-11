#include<stdio.h>
#include<stdlib.h> // Para função srand() e system()
#include<windows.h> // Para função SetConsoleCursorPosition()
#include<conio.h> // Para função getch() e kbhit()
#include<time.h> // Para função rand()

// Variáveis Globais
int cobra[300][2], maca=0, tamanho=1, cx=2, cy=2;
int comida[1][2], obstaculo[5][2];
float pontos=0;

// FUNÇÕES
void gotoxy(short int x, short int y){ // Função
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

void desenha(){ // Desenha a cobrinha
    int i;
    for(i=0; i<tamanho; i++){
        gotoxy(cobra[i][0],cobra[i][1]);
        printf("%c",219);
    }
}

void atualiza(){ // Atualiza a posição da cobrinha
    int i;
    gotoxy(cobra[tamanho][0],cobra[tamanho][1]);
    printf(" ");
    for(i=tamanho; i>=0; i--){
        cobra[i+1][0] = cobra[i][0];
        cobra[i+1][1] = cobra[i][1];
    }
}

int analiza(){ // Vê se a cobrinha enconstou em seu próprio corpo
    int i, retorno=0;
    for(i=1; i<tamanho; i++){
        if(cx==cobra[i][0] && cy==cobra[i][1]){
            retorno=1;
        }
    }
    return retorno;
}

void geraComida(){ // Gera comida em local aleatório
    srand(time(NULL));
    comida[0][0] = (rand() % 48) +1;
    comida[0][1] = (rand() % 18) +1;
    gotoxy(comida[0][0],comida[0][1]);
    printf("%c",232);
}

void geraObstaculo(){ // Gera obstaculo em local aleatório
    int l;
    srand(time(NULL)+rand());
    for(l=0; l<5; l++) {
        obstaculo[l][0] = (rand() % 48) +1;
        obstaculo[l][1] = (rand() % 18) +1;
    }
    gotoxy(obstaculo[0][0],obstaculo[0][1]);
    printf("%c",88);
    gotoxy(obstaculo[1][0],obstaculo[1][1]);
    printf("%c",88);
    gotoxy(obstaculo[2][0],obstaculo[2][1]);
    printf("%c",88);
    gotoxy(obstaculo[3][0],obstaculo[3][1]);
    printf("%c",88);
    gotoxy(obstaculo[4][0],obstaculo[4][1]);
    printf("%c",88);

}

void moldura ()
{
    int horizontal = 50, vertical = 19, i, j;

    system ("cls");
    printf("\xC9"); //Canto superior esquerdo

    for (i = 0; i < horizontal; i++)
    {
    printf("\xCD"); //Linha horizontal
    }

    printf("\xBB"); //Canto superior direito

    printf("\n\xBA"); //Linha vertical

    for (j = 1; j < vertical; j++)
    {
      for (i = 1; i <= horizontal; i++)
      {
        printf(" ");
      }
      printf("\xBA"); //Linha vertical
      printf("\n\xBA"); //Linha vertical
    }

    printf("\n\xC8"); //Canto inferior esquerdo
    for (i = 1; i <= horizontal; i++)
    {
    printf("\xCD"); //Linha horizontal
    }

    printf("\xBC"); //Canto inferior direito
    gotoxy(horizontal+1,vertical);
    printf("\xBA"); //Linha vertical
    printf("\n\n");

}


int main(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int i, gameover=0;
    int tecla;
    float tempo;
    time_t t_ini, t_fim;

    printf("Jogo da Cobra\n");
    printf("==== == =====\n\n");
    printf("Objetivos --> Desviar dos obstaculos 'X' e da borda. Comer a maior quantidade de macas '%c'\n\n", 232);
    system("pause");
    system("CLS");

    moldura();
    geraComida(); // Gera a primeira comida
    geraObstaculo(); // Gera os obstaculos "X"
    desenha(); // Desenha a cobra
    tecla='d'; // A direção é para a direita
    t_ini = time(NULL);
    while(gameover==0){ // Enquanto o usuário não perder
        gotoxy(52,2); // Move o cursor para c: 52, l: 2
        printf("Macas: %d",maca);
        gotoxy(52,4);
        printf("cx = %2d, cy = %2d\t",cx, cy);
        gotoxy(52,6);
        printf("Posicao comida: %2d, %2d", comida[0][0], comida[0][1]);
        cobra[0][0]=cx;
        cobra[0][1]=cy;

        if(kbhit()) // Se alguma tecla for apertada, o valor
            tecla=getch(); // vai para a variável 'tecla'

        if(tecla=='w' || tecla=='W' || tecla==72){
            cy--;
            if(cy==0) break; // Se a cabeça da cobra estiver na parede superior,
        }                    // O jogo acaba
        if(tecla=='a' || tecla=='A' || tecla==75){
            cx--;
            if(cx==0) break; // Se a cabeça da cobra estiver na parede da esquerda,
        }                    // O Jogo acaba
        if(tecla=='s' || tecla=='S' || tecla==80){
            cy++;
            if(cy==20) break; // Se a cabeça da cobra estiver na parede de baixo,
        }                     // O jogo acaba
        if(tecla=='d' || tecla=='D' || tecla==77){
            cx++;
            if(cx==50) break; // Se a a cabeça da cobra estiver na parede da direida,
        }                     // O jogo acaba

        if(cx==comida[0][0] && cy==comida[0][1]){ // Se a cobra comer a comida
            maca++;
            tamanho++;
            //if(velocidade>50) velocidade-=10; // velocidadecidade em milissegundos abaixa
            geraComida();
        }

        if(cx==obstaculo[0][0] && cy==obstaculo[0][1]) break; // Se a cobra encostar no obstaculo
        if(cx==obstaculo[1][0] && cy==obstaculo[1][1]) break; // Se a cobra encostar no obstaculo
        if(cx==obstaculo[2][0] && cy==obstaculo[2][1]) break; // Se a cobra encostar no obstaculo
        if(cx==obstaculo[3][0] && cy==obstaculo[3][1]) break; // Se a cobra encostar no obstaculo
        if(cx==obstaculo[4][0] && cy==obstaculo[4][1]) break; // Se a cobra encostar no obstaculo

        gameover=analiza();
        atualiza(); // Atualiza a cobra
        desenha(); // Desenha a cobra
        gotoxy(50,20);
        Sleep(100);
    }
    system("cls"); // Quando o usuário perder, limpa a tela e exibe uma mensagem final
    t_fim = time(NULL);
    tempo = difftime(t_fim, t_ini);
    if (maca==0)
    {
        SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
        printf("Voce perdeu! Fez 0 pontos.\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else
    {
        pontos = (maca*5) + tempo;
        SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
        printf("Voce perdeu! Fez %.2f pontos.\n",pontos);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf("Tempo de %.2f s\n",tempo);
        printf("Total de macas: %d\n", maca);
    }

    system("pause");
}
