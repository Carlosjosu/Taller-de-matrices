#include <stdio.h> //Incluye la librería.
int main()
{

    int matriz[2][5];

    printf("Introduce los elementos de la matriz de 2 x 5: \n"); // Pido ingresar los elementos de la matriz
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("Elemento [%d][%d]: ", i, j); // Imprimo cada elemento.
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

    printf("\nLos numeros impares de la matriz de 2 x 5 son : \n"); // Imprime los números impares de la matriz 2 x 5
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matriz[i][j] % 2 != 0)
            {
                printf("%d ", matriz[i][j]);
            }
        }
    }
    printf("\n");

    return 0; // Finaliza la ejecución del programa.
}