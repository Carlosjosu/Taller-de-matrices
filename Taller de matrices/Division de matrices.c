#include <stdio.h> // Incluye la libreria estandar

// Esta funcion calcula la inversa de una matriz cuadrada usando el metodo de eliminacion de Gaus Jhordan
int inversa(int n2, float matriz2[n2][n2], float inversa[n2][n2])
{
    float temp;              // Variable Guarda una copia de los valores de la matriz
    float identidad[n2][n2]; // Se declara la matriz identidad donde se guardara valores de la misma

    for (int i = 0; i < n2; i++) // Este for anidado itera sobre la matriz identidad
    {
        for (int j = 0; j < n2; j++)
        {
            identidad[i][j] = (i == j) ? 1 : 0; // Operador ternario para establecer 1 en la diagonal principal y 0 en los otros lugares
        }
    }

    for (int i = 0; i < n2; i++) // Realiza la elimacion gausiana para transformar la matriz matriz original en la identidad
    {
        temp = matriz2[i][i];

        if (temp == 0) // Si la condicion se cumple presenta el siguiente mensaje
        {
            printf("La matriz no tiene inversa.\n");
            return 0;
        }

        // Divide toda la fila para el elemento diagonal
        for (int j = 0; j < n2; j++)
        {
            matriz2[i][j] /= temp;
            identidad[i][j] /= temp;
        }

        // Eliminacion hacia abajo para transformar la matriz en la identidad los ceros que faltan en la columna actual
        for (int k = 0; k < n2; k++)
        {
            if (k != i) // No opera sobre la fila actual
            {
                temp = matriz2[k][i];        // Guarda el valor de la posicion que se quiere hacer cero
                for (int l = 0; l < n2; l++) //
                {
                    matriz2[k][l] -= matriz2[i][l] * temp;
                    identidad[k][l] -= identidad[i][l] * temp;
                }
            }
        }
    }

    for (int i = 0; i < n2; i++) // La inversa sera igual que identidad osea se hace una copia
    {
        for (int j = 0; j < n2; j++)
        {
            inversa[i][j] = identidad[i][j];
        }
    }
    return 1;
}

void multiplicacion_de_matrices(int filas1, int columnas1, int filas2, int columnas2, float matriz1[filas1][columnas1], float matriz2[filas2][columnas2], float resultado[filas1][columnas2])
{
    // Itera sobre cada elemento de la matriz resultado
    for (int i = 0; i < filas1; i++)
    {
        for (int j = 0; j < columnas2; j++)
        {
            resultado[i][j] = 0;
            for (int k = 0; k < columnas1; k++) // Calcula el producto escalar de la fila i de la primera matriz por la columna j de la segunda matriz
            {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j]; // Calcula el producto de las dos matrices y le suma el resultado
            }
        }
    }
}

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

    float matriz1[num_filas1][num_columnas1];

    printf("Ingrese los elementos de la matriz:\n"); // Pido al usuario ingresar los elementos de la matriz.
    for (int i = 0; i < num_filas1; i++)
    {

        for (int j = 0; j < num_columnas1; j++)
        {
            printf("Elemento [%d][%d]: ", i, j); // Escibre lo siguiente Elemento [0][0] y asi para ingresar cada elemento de la matriz
            scanf("%f", &matriz1[i][j]);
        }
        printf("\n");
    }

    printf("La matriz es 1:\n"); // Imprimo la matriz en su totalidad
    for (int i = 0; i < num_filas1; i++)
    {
        for (int j = 0; j < num_columnas1; j++)
        {
            printf("|%0.2f| ", matriz1[i][j]);
        }
        printf("\n");
    }

    float matriz2[num_filas2][num_columnas2];
    printf("Ingrese los elementos de la segunda matriz:\n"); // Pido al usuario ingresar los elementos de la segunda matriz.
    for (int i = 0; i < num_filas2; i++)
    {
        for (int j = 0; j < num_columnas2; j++)
        {
            printf("Elemento [%d][%d]: ", i, j); // Escibre lo siguiente Elemento [0][0] y asi para ingresar cada elemento de la matriz
            scanf("%f", &matriz2[i][j]);
        }
        printf("\n");
    }
    printf("La matriz es 2:\n"); // Imprimo la matriz en su totalidad
    for (int i = 0; i < num_filas2; i++)
    {
        for (int j = 0; j < num_columnas2; j++)
        {
            printf("|%0.2f| ", matriz2[i][j]);
        }
        printf("\n");
    }

    if (num_filas1 != num_columnas1)
    {
        printf("Las segunda matriz no es cuadrada, asi que no es pósible calcular inversa.\n");
        return 0;
    }

    float inversa2[num_filas2][num_columnas2];
    if (!inversa(num_filas2, matriz2, inversa2))
    {
        printf("Las segunda matriz no puede ser invertida.\n");
        return 0;
    }

    float resultado[num_filas1][num_columnas2];
    multiplicacion_de_matrices(num_filas1, num_columnas1, num_filas2, num_columnas2, matriz1, inversa2, resultado);
    printf("El resultado de la supuesta division es:\n"); // Imprimo el resultado de la multiplicación
    for (int i = 0; i < num_filas1; i++)
    {
        for (int j = 0; j < num_columnas2; j++)
        {
            printf("|%0.2f| ", resultado[i][j]);
        }
        printf("\n");
    }
    return 0;
}