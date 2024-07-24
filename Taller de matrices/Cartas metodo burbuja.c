#include <stdio.h>  // Librería estándar
#include <stdlib.h> // Librería estándar que contiene funciones de utilidad, como memoria dinámica, control de procesos, conversiones y otras operaciones.
#include <time.h>   // Librería que se usa para funciones del tiempo

// Definición de los cada letra de la baraja
#define CORAZONES 'C'
#define DIAMANTES 'D'
#define TREBOLES 'T'
#define PICAS 'P'

// Definición del struct para cada carta
struct Carta
{
    char valor; // Valor de cada carta
    char palo;  // Palo de carta (Corazones, Diamantes, Treboles, Picas)
};

// Genera un número aleatorio entre min y max
int random_range(int min, int max)
{
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

// Función que imprimirá una carta
void impresionCarta(struct Carta carta)
{
    printf("|%c%c| ", carta.valor, carta.palo);
}

// Esta función intercambia dos cartas
void intercambiarCartas(struct Carta *a, struct Carta *b)
{
    struct Carta temp = *a;
    *a = *b;
    *b = temp;
}

// Función que ordena las cartas primero por palo y luego por valor
void ordenarCartasBurbuja(struct Carta cartas[], int n)
{
    // Ordenamiento por burbuja para ordenar las cartas por palo y luego por valor
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // Se intercambian las cartas si el palo es mayor que el siguiente, o si el palo es igual y el valor es mayor.
            if (cartas[j].palo > cartas[j + 1].palo)
            {
                intercambiarCartas(&cartas[j], &cartas[j + 1]);
            }
            else if (cartas[j].palo == cartas[j + 1].palo && cartas[j].valor > cartas[j + 1].valor)
            {
                intercambiarCartas(&cartas[j], &cartas[j + 1]);
            }
        }
    }
}

int main()
{
    srand(time(NULL));       // Inicialización de semilla para números aleatorios
    struct Carta baraja[52]; // Arreglo que contiene todas las cartas de la baraja

    char palos[] = {CORAZONES, DIAMANTES, TREBOLES, PICAS};
    char valores[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'E', 'F'}; // A = 10, B = 11, E = 12, F = 13

    int index = 0; // Contador que rastrea la posición actual dentro del arreglo
    for (int p = 0; p < 4; p++)
    {
        for (int v = 0; v < 13; v++)
        {
            baraja[index].palo = palos[p];
            baraja[index].valor = valores[v];
            index++;
        }
    }

    // Se mezcla la baraja
    for (int i = 0; i < 52; i++)
    {
        int j = random_range(0, 51);
        intercambiarCartas(&baraja[i], &baraja[j]);
    }

    // Se imprime la baraja desordenada
    printf("Cartas desordenadas:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            impresionCarta(baraja[i * 13 + j]);
        }
        printf("\n");
    }

    // Se ordena la baraja con el método de burbuja haciendo un llamado a la función
    ordenarCartasBurbuja(baraja, 52);

    // Se imprime la baraja ya ordenada
    printf("\nCartas ordenadas:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            impresionCarta(baraja[i * 13 + j]);
        }
        printf("\n");
    }

    return 0;
}
