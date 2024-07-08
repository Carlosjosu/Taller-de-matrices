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

// Funcion que ordena con el metodo de insercion el valor de cada carta
void ordenarCartasInsercion(struct Carta cartas[], int n)
{
    for (int i = 0; i < n; i++) // Recorre las cartas de principio a fin
    {
        // Guarda la carta actual
        struct Carta temp = cartas[i];
        /*Se mueve la carta actual hacia la izquierda en el arreglo,
        mientras que el valor de la carta en la posicion anterior es mayor que el actual.*/
        int j = i - 1;
        while (j >= 0 && cartas[j].valor > temp.valor)
        {

            cartas[j + 1] = cartas[j];
            j--;
        }
        // Inserta la carta en su posicion correcta
        cartas[j + 1] = temp;
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
        // Se crean las cartas del palo y se almacena en el arreglo
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
        // Se elige un numero aleatorio entre i y 51 y se intercambia la carta en la posicion i con la carta en la posicion j
        int j = random_range(i, 51);
        intercambiarCartas(&baraja[i], &baraja[j]);
    }

    // Se ordena la baraja con el metodo de insercion haciendo un llamado  a la funcion
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