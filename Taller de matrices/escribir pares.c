#include <stdio.h> //Incluye la librería.
int main()
{

    int matriz[2][5];

    printf("Introduce los elementos de la matriz de 2 x 5: \n"); // Pido ingresar los elementos de la matriz
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("Elemento [%d][%d]: ", i, j); // Escibre lo siguiente Elemento [0][0] y asi para ingresar cada elemento de la matriz
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nLa matriz es : \n"); // Aviso que se va a imprimir la matriz.
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nLos numeros pares de la matriz de 2 x 5 son : \n"); // Imprime los números pares de la matriz de 2 x 5
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matriz[i][j] % 2 == 0)
            {
                printf("%d ", matriz[i][j]);
            }
        }
    }
    printf("\n");

    return 0; // Finaliza la ejecución del programa.
}