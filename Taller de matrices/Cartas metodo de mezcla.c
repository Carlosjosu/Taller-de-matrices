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
    char valor;
    char palo;
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

// Esta funcion fusiona dos arreglos
void fusion(struct Carta cartas[], int izquierda, int medio, int derecha)
{
    // Calculo de longitud de de los arreglos
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;

    // Creacion de arreglos temporales
    struct Carta izq[n1], dere[n2];
    // Copia de los valores de los arreglos originales al arreglo temporales
    for (int i = 0; i < n1; i++)
        izq[i] = cartas[izquierda + i];
    for (int j = 0; j < n2; j++)
        dere[j] = cartas[medio + 1 + j];

    // Fusion de los arreglos temporales al arreglo original
    int i = 0, j = 0, k = izquierda;
    while (i < n1 && j < n2)
    {
        // Compara los valores las cartas de izquierda y derecha
        if (izq[i].valor <= dere[j].valor)
        {
            // Si la carta de la izquierda es menor o igual a la carta de la derecha, la copia la carta de la izquierda al arreglo original
            cartas[k] = izq[i];
            i++;
        }
        else
        {
            // Si la carta de la derecha es menor, la copia la carta de la derecha al arreglo original
            cartas[k] = dere[j];
            j++;
        }
        k++;
    }
    // Copia los elementos restantes de izquierda si hay alguno
    while (i < n1)
    {
        cartas[k] = izq[i];
        i++;
        k++;
    }
    // Copia los elementos restantes de derecha si hay alguno
    while (j < n2)
    {
        cartas[k] = dere[j];
        j++;
        k++;
    }
}
// Funcion que ordena con el metodo de mezcla el valor de cada carta
void ordenarCartasMezcla(struct Carta cartas[], int izquierda, int derecha)
{
    if (izquierda < derecha)
    {
        int medio = izquierda + (derecha - izquierda) / 2;
        ordenarCartasMezcla(cartas, izquierda, medio);
        ordenarCartasMezcla(cartas, medio + 1, derecha);
        fusion(cartas, izquierda, medio, derecha);
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
        int j = random_range(i, 51);
        intercambiarCartas(&baraja[i], &baraja[j]);
    }

    // Se ordena la baraja
    ordenarCartasMezcla(baraja, 0, 51);

    // Se imprime la baraja
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