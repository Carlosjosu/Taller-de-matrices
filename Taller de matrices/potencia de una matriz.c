#include <stdio.h>

// Funcion para imprimir la matriz
void imprimir_matriz(int n, int matriz[n][n])
{
    for (int i = 0; i < n; i++) // Recorre cada fila
    {
        for (int j = 0; j < n; j++) // Recorre cada columna
        {
            printf("|%d| ", matriz[i][j]); // Imprime el elmento de la matriz
        }
        printf("\n");
    }
}
// Funcion para multiplicar dos matices de tamaño n
void multiplicar_matriz(int n, int matriz[n][n], int matriz2[n][n], int resultado[n][n])
{
    int temp[n][n];             // Matriz donde se guarda temporalmente una copia del resultado
    for (int i = 0; i < n; i++) // Recorre cada fila
    {
        for (int j = 0; j < n; j++) // Recorre cada columna
        {
            temp[i][j] = 0;             // Inicializa en 0
            for (int k = 0; k < n; k++) // Realiza el producto escalar de la fila i de la primera matriz por la columna j de la segunda matriz
            {
                temp[i][j] += matriz[i][k] * matriz2[k][j];
            }
        }
    }
    // Copia los valores de temp a resultado
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            resultado[i][j] = temp[i][j];
        }
    }
}

// Funcion para calcular la potencia de una matriz
void potencia(int n, int matriz_base[n][n], int exponente, int resultado[n][n])
{
    // Inicializa la matriz resultado con la identidad
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            resultado[i][j] = (i == j) ? 1 : 0; // Se usa el operador para establecer 1 en la diagonal  y 0 en otros lugares
        }
    }

    // Bucle para calcular la potencia
    while (exponente > 0)
    {
        // Si exponente es impar, multiplica resultado con matriz_base
        if (exponente % 2 == 1)
        {
            int temp[n][n];                                      // Guarda los del resultado de la multiplicacion
            multiplicar_matriz(n, resultado, matriz_base, temp); // Multicacion de resiltado por matriz_base
            // Los valores de temp se copian a resultado
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    resultado[i][j] = temp[i][j];
                }
            }
        }
        // Cuadrado de la matriz_base
        int temp[n][n];                                        // Almacena el resultado de la multiplicacion.
        multiplicar_matriz(n, matriz_base, matriz_base, temp); // Multicacion de matriz_base por si misma
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matriz_base[i][j] = temp[i][j]; // Se copian los valores de temp a matriz_base
            }
        }
        exponente /= 2;
    }
}

int main()
{
    int n;
    printf("Ingrese el tamaño de la matriz cuadrada: ");
    scanf("%d", &n);

    int matriz_base[n][n];
    printf("Ingrese los elementos de la matriz base:\n");
    for (int i = 0; i < n; i++) // Recorre cada fila
    {
        for (int j = 0; j < n; j++) // Recorre cada columna
        {
            printf("Elemento [%d][%d]: ", i, j); // Escibre lo siguiente Elemento [0][0] y asi para ingresar cada elemento de la matriz
            scanf("%d", &matriz_base[i][j]);
        }
        printf("\n");
    }

    int exponente;
    // Solicita al usuario ingresar el exponente
    printf("Ingrese el exponente: ");
    scanf("%d", &exponente);

    printf("Matriz base:\n"); // Imnprime la matriz base que ingresa el usuario
    imprimir_matriz(n, matriz_base);

    int resultado[n][n]; // Se declara la matriz resultado
    // Se calcula la potencia de la matriz base
    potencia(n, matriz_base, exponente, resultado);

    printf("Resultado de la potencia:\n"); // Imprime el resultado de matriz elevado a la potencia
    imprimir_matriz(n, resultado);

    return 0;
}