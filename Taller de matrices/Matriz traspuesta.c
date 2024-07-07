#include <stdio.h>

void imprimir_Matriz(double matriz[3][3]) // Esta función imprime la matriz
{
    printf("La matriz es:\n"); // Mensaje que va a imprimir la matriz original
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void matriz_traspuesta(double matriz[3][3], double traspuesta[3][3]) // Imprime la matriz traspuesta
{
    for (int i = 0; i < 3; i++) // Este bucle  recrea cada fila y cada columna de la matriz.
    {
        for (int j = 0; j < 3; j++)
        {
            traspuesta[i][j] = matriz[j][i];
        }
    }
}

int main()
{
    double matriz[3][3];     // Declaramos la matriz
    double traspuesta[3][3]; // Declaramos la matriz traspuesta

    printf("Ingrese la matriz:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Elemento [%d][%d]: ", i + 1, j + 1); // Escibre lo siguiente Elemento [0][0] y asi para ingresar cada elemento de la matriz
            scanf("%lf", &matriz[i][j]);
        }
    }
    // Llamamos a las funciones
    matriz_traspuesta(matriz, traspuesta);
    imprimir_Matriz(matriz);
    printf("\n");
    imprimir_Matriz(traspuesta);
    return 0;
}
