#include <stdio.h>

void imprimir_Matriz(double matriz[3][3]) // Imprime la función 3 por 3
{
    printf("La matriz es:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void generar_matriz_simetrica(double matriz[3][3]) // Genera la matriz simétrica
{
    // Se asignan valores a la matriz.

    matriz[0][0] = 1.0;
    matriz[1][0] = 2.0;
    matriz[1][1] = 3.0;
    matriz[2][0] = 4.0;
    matriz[2][1] = 5.0;
    matriz[2][2] = 6.0;

    for (int i = 0; i < 3; i++) // Bucle For anidado para asegurar que la matriz sea simetrica
    {
        for (int j = 0; j < 3; j++)
        {
            matriz[i][j] = matriz[j][i];
        }
    }
}

int main()
{
    double matriz[3][3]; // Se declara la matriz

    generar_matriz_simetrica(matriz);    // LLamada a la función
    printf("La matriz simetrica es:\n"); // Imprime un mensaje de que se va a imprimir la matriz simetrica
    imprimir_Matriz(matriz);
    return 0;
}