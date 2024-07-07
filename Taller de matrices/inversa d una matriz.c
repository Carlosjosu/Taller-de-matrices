#include <stdio.h>

void imprimir_Matriz(double matriz[3][3]) // Esta función me permite imprimir. Una matriz de 3 por 3
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%lf ", matriz[i][j]);
        }
        printf("\n");
    }
}

int Matriz_inversa(double matriz[3][3], double inversa[3][3]) // Ésta funcion me permite obtener laq inversa
{
    double det = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1]) - matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]) + matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);
    if (det == 0) // Calculo al determinante
    {
        return 0;
    }
    //

    inversa[0][0] = matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1];
    inversa[0][1] = matriz[0][2] * matriz[2][1] - matriz[0][1] * matriz[2][2];
    inversa[0][2] = matriz[0][1] * matriz[1][2] - matriz[0][2] * matriz[1][1];
    inversa[1][0] = matriz[1][2] * matriz[2][0] - matriz[1][0] * matriz[2][2];
    inversa[1][1] = matriz[0][0] * matriz[2][2] - matriz[0][2] * matriz[2][0];
    inversa[1][2] = matriz[0][2] * matriz[1][0] - matriz[0][0] * matriz[1][2];
    inversa[2][0] = matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0];
    inversa[2][1] = matriz[0][1] * matriz[2][0] - matriz[0][0] * matriz[2][1];
    inversa[2][2] = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];

    for (int i = 0; i < 3; i++) // Calculo la inversa
    // Si es diferente de 0 se procede a calcular la matriz de cofactores
    {
        for (int j = 0; j < 3; j++)
        {
            inversa[i][j] = inversa[i][j] / det;
        }
    }
    return 1;
}

int main()
{
    double matriz[3][3];  // Guardamos la matriz original
    double inversa[3][3]; // Guardarmos la inversa de la matriz original

    printf("Ingrese la matriz:\n"); // Pedimos que ingrese la matriz
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) // Con este for imprimimos Elemento [0][0] y asi para ingresar cada elemento de la matriz
        {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matriz[i][j]);
        }
    }
    if (Matriz_inversa(matriz, inversa))
    {
        printf("La matriz inversa es: \n"); // Imprime la matriz inversa
        imprimir_Matriz(inversa);
    }
    else
    {
        printf("La matriz no tiene inversa\n"); // Imprime si la matriz no tiene inversa
    }
    return 0;
}
