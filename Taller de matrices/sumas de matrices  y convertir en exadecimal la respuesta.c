#include <stdio.h>

int main()
{

    int num_filas1;
    int num_columnas1;
    int num_filas2;
    int num_columnas2;

    printf("Ingrese el número de filas de la primera matriz: ");
    scanf("%d", &num_filas1);
    printf("Ingrese el número de columnas de la primera matriz: ");
    scanf("%d", &num_columnas1);
    printf("Ingrese el número de filas de la segunda matriz: ");
    scanf("%d", &num_filas2);
    printf("Ingrese el número de columnas de la segunda matriz: ");
    scanf("%d", &num_columnas2);

    int matriz1[num_filas1][num_columnas1];

    printf("Ingrese los elementos de la matriz:\n"); // Pido al usuario ingresar los elementos de la matriz.
    for (int i = 0; i < num_filas1; i++)
    {

        for (int j = 0; j < num_columnas1; j++)
        {
            printf("Elemento [%d][%d]: ", i, j); // Imprimo los dichos elementos de la matriz
            scanf("%d", &matriz1[i][j]);
        }
        printf("\n");
    }

    printf("La matriz es:\n"); // Imprimo la matriz en su totalidad
    for (int i = 0; i < num_filas1; i++)
    {
        for (int j = 0; j < num_columnas1; j++)
        {
            printf("|%d| ", matriz1[i][j]);
        }
        printf("\n");
    }
    int matriz2[num_filas2][num_columnas2];

    printf("Ingrese los elementos de la segunda matriz:\n"); // Pido al usuario ingresar los elementos de la segunda matriz.
    for (int i = 0; i < num_filas2; i++)
    {
        for (int j = 0; j < num_columnas2; j++)
        {
            printf("Elemento [%d][%d]: ", i, j); // Imprimo los dichos elementos de la segunda matriz
            scanf("%d", &matriz2[i][j]);
        }
        printf("\n");
    }
    printf("La matriz es:\n"); // Imprimo la matriz en su totalidad
    for (int i = 0; i < num_filas2; i++)
    {
        for (int j = 0; j < num_columnas2; j++)
        {
            printf("|%d| ", matriz2[i][j]);
        }
        printf("\n");
    }
    int matriz_suma[num_filas1][num_columnas1];
    printf("La suma de las matrices es:\n"); // Imprimo la matriz en su totalidad
    for (int i = 0; i < num_filas1; i++)
    {
        for (int j = 0; j < num_columnas1; j++)
        {
            matriz_suma[i][j] = matriz1[i][j] + matriz2[i][j];
            printf("|%d| ", matriz_suma[i][j]);
        }
        printf("\n");
    }

    int conversion_a_hexadecimal[num_filas1][num_columnas1];
    printf("La matriz en hexadecimal es:\n"); // Imprimo la matriz en su totalidad pra el hexadecimal
    for (int i = 0; i < num_filas1; i++)      /* For anidado para iterar tanto en las filas y en las columnas*/
    {
        for (int j = 0; j < num_columnas1; j++)
        {
            conversion_a_hexadecimal[i][j] = matriz_suma[i][j] & 0xFF; /* Convertimos a exadecimal el cual nos asegura el resultado es un byte*/
            printf("|%2X| ", conversion_a_hexadecimal[i][j]);
            printf("%c", conversion_a_hexadecimal[i][j] >= 32 && conversion_a_hexadecimal[i][j] <= 126 ? conversion_a_hexadecimal[i][j] : ' '); /*Imprime el valor ASCII correspondiente al valor hexadecimal si esta dentro del rango.*/
        }
        printf("\n");
    }

    return 0;
}