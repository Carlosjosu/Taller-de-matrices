#include <stdio.h>

void imprimir_Matriz(int matriz[3][3]) // Imprime la función 3 por 3
{
    printf("La matriz es:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("|%d| ", matriz[i][j]);
        }
        printf("\n");
    }
}

void generar_matriz_simetrica(int matriz[3][3]) // Genera la matriz simétrica
{
    // Se asignan valores a la matriz.

    matriz[0][0] = 1;
    matriz[1][0] = 2;
    matriz[1][1] = 3;
    matriz[2][0] = 4;
    matriz[2][1] = 5;
    matriz[2][2] = 6;

    for (int i = 0; i < 3; i++) // Bucle For anidado para asegurar que la matriz sea simetrica
    {
        for (int j = 0; j < 3; j++)
        {
            matriz[i][j] = matriz[j][i];
            if (i != j)
            {
                matriz[j][i] = matriz[i][j];
            }
            // Se imprime la matriz
            printf("|%d| ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int matriz[3][3]; // Se declara la matriz

    generar_matriz_simetrica(matriz);    // LLamada a la función
    printf("La matriz simetrica es:\n"); // Imprime un mensaje de que se va a imprimir la matriz simetrica
    imprimir_Matriz(matriz);
    return 0;
}