#include <stdio.h>
// Ordenar de menor a mayor el arreglo de 13 cartas
int main()
{
    int cartas[13] = {1, 7, 2, 12, 13, 5, 9, 11, 10, 3, 6, 4, 8};
    int nt;

    // Usando el metodo de la burbuja intercambiamos los lugares de los valores
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12 - i; j++)
        {
            if (cartas[j] > cartas[j + 1])
            {
                nt = cartas[j];
                cartas[j] = cartas[j + 1];
                cartas[j + 1] = nt;
            }
        }
    }

    // Imprimir el arreglo ordenado
    printf("Numero de mayor a menor: ");
    for (int i = 0; i < 13; i++)
    {
        printf("%d ", cartas[i]);
    }
    printf("\n");

    return 0;
}