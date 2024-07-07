
#include <stdio.h> //Incluyo la libreria

int main()
{
    int num_filas;    // Guardo el numero de filas
    int num_columnas; // Guardo el numero de columnas

    printf("Ingrese el numero de filas: "); // Pido al usuario ingresar al número de filas.
    scanf("%d", &num_filas);
    printf("Ingrese el numero de columnas: "); // Pido al usuario ingresar el número de columnas
    scanf("%d", &num_columnas);

    int matriz[num_filas][num_columnas];

    printf("Ingrese los elementos de la matriz:\n"); // Pido al usuario ingresar los elementos de la matriz.
    for (int i = 0; i < num_filas; i++)
    {

        for (int j = 0; j < num_columnas; j++)
        {
            printf("Elemento [%d][%d]: ", i, j); // Escibre lo siguiente Elemento [0][0] y asi para ingresar cada elemento de la matriz
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("La matriz es:\n"); // Imprimo la matriz en su totalidad
    for (int i = 0; i < num_filas; i++)
    {
        for (int j = 0; j < num_columnas; j++)
        {
            printf("|%d| ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Numero de filas: %d\n", num_filas);
    printf("Numero de columnas: %d\n", num_columnas);

    return 0;
}