#include <stdio.h>
#include <stdbool.h>

void getTable(char table[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            table[i][j] = ' ';
        }
    }
}

void printBoard(char table[3][3])
{
    printf("  1   2   3\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d %c | %c | %c \n", i + 1, table[i][0], table[i][1], table[i][2]);
        if (i != 2)
        {
            printf("  ---------\n");
        }
    }
}

void changePlayer(bool* playerX)
{
    *playerX = !(*playerX);
}

void drawPlay(char table[3][3], int row, int col, bool playerX)
{
    if (playerX)
        table[row - 1][col - 1] = 'X';
    else
        table[row - 1][col - 1] = 'O';
}

bool checkVictory(char table[3][3])
{
    // Verificar linhas
    for (int i = 0; i < 3; i++)
    {
        if (table[i][0] != ' ' && table[i][0] == table[i][1] && table[i][1] == table[i][2])
            return true;
    }

    // Verificar colunas
    for (int i = 0; i < 3; i++)
    {
        if (table[0][i] != ' ' && table[0][i] == table[1][i] && table[1][i] == table[2][i])
            return true;
    }

    // Verificar diagonais
    if (table[0][0] != ' ' && table[0][0] == table[1][1] && table[1][1] == table[2][2])
        return true;

    if (table[0][2] != ' ' && table[0][2] == table[1][1] && table[1][1] == table[2][0])
        return true;

    return false;
}

bool checkPlay(char table[3][3], int row, int col)
{
    if (row > 3 || row < 1 || col > 3 || col < 1)
    {
        printf("Posicao fora do intervalo entre 1 e 3!\n\n");
        return false;
    }

    if (table[row - 1][col - 1] != ' ')
    {
        printf("Posicao ja utilizada!\n\n");
        return false;
    }

    return true;
}

int main()
{
    char table[3][3];
    bool playerX = true;
    getTable(table);
    int cont = 0;

    while (true)
    {
        printf("\n");

        int row, col;
        do
        {
            if (playerX)
            {
                printf("Jogador X, digite as coordenadas da sua jogada! (i|j) \n");
            }
            else
            {
                printf("Jogador O, digite as coordenadas da sua jogada! (i|j) \n");
            }
            scanf("%d%d", &row, &col);
            
        } while (!checkPlay(table, row, col));

        drawPlay(table, row, col, playerX);
        printBoard(table);
        cont++;

        if (checkVictory(table))
        {
            if (playerX)
                printf("O JOGADOR X GANHOU!\n");
            else
                printf("O JOGADOR O GANHOU!\n");
            break;
        }

        if (cont == 9)
        {
            printf("EMPATE!\n");
            break;
        }

        changePlayer(&playerX);
    }

    return 0;
}
