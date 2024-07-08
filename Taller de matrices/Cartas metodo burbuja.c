#include <stdio.h>  //Libreria estandar
#include <stdlib.h> // Libreria estándar que contiene funciones de utilidad, como memoria dinámica, control de procesos, conversiones y otras operaciones.
#include <time.h>   //Libreria que se usa par funciones del tiempo

// Definicion de los cada letra de la baraja
#define CORAZONES 'C'
#define DIAMANTES 'D'
#define TREBOLES 'T'
#define PICAS 'P'

// Definicion del struct para cada carta
struct Carta
{
    char valor; // Valor de cada carta
    char palo;  // Palo de carta (Corazones, Diamantes, Treboles, Picas)
};

// Genera un numero aleatorio entre min y max
int random_range(int min, int max)
{
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

// Funcion que imprimira una carta
void impresionCarta(struct Carta carta)
{
    printf("%c%c ", carta.valor, carta.palo);
}

// Esta funcion intercambia dos cartas
void intercambiarCartas(struct Carta *a, struct Carta *b)
{
    struct Carta temp = *a;
    *a = *b;
    *b = temp;
}

// Funcion que ordena con el metodo de burbuja el valor de cada carta
void ordenarCartasBurbuja(struct Carta cartas[], int n)
{
    for (int i = 0; i < n - 1; i++) // Recorre el atrreglo desdee el inicio hasta el final
    {
        for (int j = 0; j < n - i - 1; j++)
        // Se ejecuta desde el primer elemento hasta n-i-2
        // Se reduce en cada iteración porque los elementos mayores ya están en su posición final
        {
            // Se compara el valor de la carta en la posicion j con la carta en la posicion j+1
            if (cartas[j].valor > cartas[j + 1].valor)
            {
                // Si el valor de la carta en la posicion j es mayor que el valor de la carta en la posicion j+1
                // Se intercambian las cartas
                intercambiarCartas(&cartas[j], &cartas[j + 1]);
            }
        }
    }
}
int main()
{
    srand(time(NULL));       // Inicializacion de semilla para numeros aleatorios
    struct Carta baraja[52]; // Arreglo que contiene todas las cartas de la baraja

    char palos[] = {CORAZONES, DIAMANTES, TREBOLES, PICAS};
    char valores[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'Y', 'J', 'Q', 'k', 'A'};

    int index = 0; // Contador que rastrea la posicion actual dentro del arreglo
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
    for (int i = 0; i < 52; ++i)
    {
        int j = random_range(i, 51);
        intercambiarCartas(&baraja[i], &baraja[j]);
    }

    // Se ordena la baraja con el metodo de insercio haciendo un llamado ado a la funcion
    ordenarCartasInsercion(baraja, 52);

    // Se imprime la baraja ya ordenada
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            impresionCarta(baraja[i + j * 13]);
        }
        printf("\n");
    }
    return 0;
}