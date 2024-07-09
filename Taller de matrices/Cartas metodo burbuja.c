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
    printf("|%c%c| ", carta.valor, carta.palo);
}

// Esta funcion intercambia dos cartas
void intercambiarCartas(struct Carta *a, struct Carta *b)
{
    struct Carta temp = *a;
    *a = *b;
    *b = temp;
}

// Función que ordena las cartas primero por palo y luego por valor
void ordenarCartasBurbuja(struct Carta cartas[], int n)
{
    for (int i = 0; i < n - 1; i++)
    { // Recorre el arreglo desde el inicio hasta el final
        for (int j = 0; j < n - i - 1; j++)
        {
            // Si el palo de la carta en la posición j es menor que el palo de la carta en la posición j+1
            // Se intercambian las cartas
            if (cartas[j].palo > cartas[j + 1].palo)
            {
                // Si los palos son iguales pero el valor es menor
                // Se intercambian las cartas
                intercambiarCartas(&cartas[j], &cartas[j + 1]);
            }
            else if (cartas[j].palo == cartas[j + 1].palo && cartas[j].valor < cartas[j + 1].valor)
            // Si los palos son iguales y el valor es mayor que el valor de la carta en la posición j+1
            // Se intercambian las cartas
            {
                intercambiarCartas(&cartas[j], &cartas[j + 1]);
            }

            {
                // Si el palo de la carta en la posición j es mayor que el palo de la carta en la posición j+1
                // O si los palos son iguales pero el valor es mayor
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
    char valores[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'J', 'Q', 'k'}; // A = 10, J = 11, Q = 12, K = 13

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
    for (int i = 0; i < 52; i++)
    {
        int j = random_range(i, 51);
        intercambiarCartas(&baraja[i], &baraja[j]);
    }

    // Se ordena la baraja con el metodo de burbuja haciendo un llamado a la funcion
    ordenarCartasBurbuja(baraja, 52);

    // Se imprime la baraja ya ordenada
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