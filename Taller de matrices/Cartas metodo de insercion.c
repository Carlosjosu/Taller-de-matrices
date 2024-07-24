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
void ordenarCartasInsercion(struct Carta cartas[], int n)
{
    for (int i = 1; i < n; i++)
    {
        struct Carta temp = cartas[i];
        int j = i - 1;

        // Se mueve la carta hacia la izquierda hasta que se encuentra en su lugar correcto
        while (j >= 0 && (cartas[j].palo > temp.palo || (cartas[j].palo == temp.palo && cartas[j].valor > temp.valor)))
        {
            cartas[j + 1] = cartas[j];
            j--;
        }
        // Inserta la carta en su posición
        cartas[j + 1] = temp;
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
        // Se crean las cartas del palo y se almacenan en el arreglo
        for (int v = 0; v < 13; v++)
        {
            baraja[index].palo = palos[p];
            baraja[index].valor = valores[v];
            index++;
        }
    }

    // Se mezcla la baraja
    for (int i = 0; i < 52; ++i)
    {
        // Se elige un número aleatorio entre i y 51 y se intercambia la carta en la posición i con la carta en la posición j
        int j = random_range(i, 51);
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

    // Se ordena la baraja con el método de inserción haciendo un llamado a la función
    ordenarCartasInsercion(baraja, 52);

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
