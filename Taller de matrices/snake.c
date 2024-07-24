#include <stdio.h>   // Librería estándar para entrada/salida.
#include <stdlib.h>  // Librería estándar de utilidades.
#include <conio.h>   // Librería para funciones de consola (no estándar, específica de Windows).
#include <windows.h> // Librería para las API de Windows.
#include <time.h>    // Librería para manipulación del tiempo y la fecha.

// Definición de constantes para la altura y el ancho del campo de juego, y la longitud máxima de la serpiente
#define V 21  // Altura del campo de juego (21 filas)
#define H 65  // Ancho del campo de juego (65 columnas)
#define N 100 // Longitud máxima de la serpiente

// Definición de una estructura para representar cada segmento de la serpiente
typedef struct
{
    int x, y;       // Coordenadas del segmento de la serpiente
    int Modx, Mody; // Dirección de movimiento del segmento de la serpiente
    char imagen;    // Carácter para representar el segmento de la serpiente
} snk;

// Definición de una estructura para representar la fruta
typedef struct
{
    int x, y; // Coordenadas de la fruta
} fruta;

// Declaración de variables globales
snk snake[N];       // Array para almacenar los segmentos de la serpiente
fruta fruta_actual; // Variable para almacenar la posición actual de la fruta

// Declaración de funciones
void Inicio_Campo(char campo[V][H]);
void Inicio_Datos(char campo[V][H], int tamaño);
void dibujar(char campo[V][H]);
void movimiento(char campo[V][H], int tamaño);
void ocaciones_de_muerte(int *tamaño, int *muerto);
void update(char campo[V][H], int tamaño);
void Inicio_Datos2(char campo[V][H], int tamaño);
void inicio(int *tamaño, char campo[V][H]);

// Función principal
int main()
{
    int tamaño;       // Variable para almacenar el tamaño de la serpiente
    char campo[V][H]; // Matriz para representar el campo de juego

    // Inicializar el juego
    inicio(&tamaño, campo);
    // Iniciar el movimiento de la serpiente
    movimiento(campo, tamaño);

    return 0;
}

// Función para inicializar el campo de juego
void Inicio_Campo(char campo[V][H])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < H; j++)
        {
            // Crear bordes en los límites del campo de juego
            if (i == 0 || i == V - 1 || j == 0 || j == H - 1)
            {
                campo[i][j] = '#'; // Bordes del campo de juego
            }
            else
            {
                campo[i][j] = ' '; // Espacio vacío dentro del campo de juego
            }
        }
    }
}

// Función para inicializar los datos de la serpiente y la fruta
void Inicio_Datos(char campo[V][H], int tamaño)
{
    for (int i = 1; i < tamaño; i++)
    {
        snake[i].x = snake[i - 1].x - 1;
        snake[i].y = snake[i - 1].y;
        snake[i].imagen = 'X'; // Representación de los segmentos del cuerpo de la serpiente
    }

    snake[0].imagen = 'O'; // Representación de la cabeza de la serpiente

    // Colocar la serpiente en el campo de juego
    for (int i = 0; i < tamaño; i++)
    {
        campo[snake[i].y][snake[i].x] = snake[i].imagen;
    }
    campo[fruta_actual.y][fruta_actual.x] = '*'; // Representación de la fruta
}

// Función para inicializar el juego
void inicio(int *tamaño, char campo[V][H])
{
    // Inicializar la cabeza de la serpiente en una posición específica
    snake[0].x = 32;
    snake[0].y = 10;

    // Inicializar el tamaño de la serpiente
    *tamaño = 4;

    // Inicializar la posición aleatoria de la fruta
    srand(time(NULL));

    fruta_actual.x = rand() % (H - 1);
    fruta_actual.y = rand() % (V - 1);

    // Asegurarse de que la fruta no esté en el borde del campo
    while (fruta_actual.x == 0)
    {
        fruta_actual.x = rand() % (H - 1);
    }

    while (fruta_actual.y == 0)
    {
        fruta_actual.y = rand() % (V - 1);
    }

    // Inicializar la dirección de movimiento de la serpiente
    for (int i = 0; i < *tamaño; i++)
    {
        snake[i].Modx = 1;
        snake[i].Mody = 0;
    }

    // Inicializar el campo de juego y los datos de la serpiente
    Inicio_Campo(campo);
    Inicio_Datos(campo, *tamaño);
}

// Función para dibujar el campo de juego en la pantalla
void dibujar(char campo[V][H])
{
    system("cls"); // Limpiar la pantalla
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < H; j++)
        {
            printf("%c", campo[i][j]); // Imprimir cada carácter del campo
        }
        printf("\n"); // Nueva línea después de cada fila
    }
}

// Función para manejar las ocasiones de muerte y comer fruta
void ocaciones_de_muerte(int *tamaño, int *muerto)
{
    // Comprobación de la muerte de la serpiente por colisión con los bordes
    if (snake[0].x == 0 || snake[0].x == H - 1 || snake[0].y == V - 1 || snake[0].y == 0)
    {
        *muerto = 1;
    }

    // Comprobación de la muerte de la serpiente por colisión consigo misma
    for (int i = 1; i < *tamaño && *muerto == 0; i++)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
        {
            *muerto = 1;
        }
    }

    // Comprobación de comer la fruta
    if (snake[0].x == fruta_actual.x && snake[0].y == fruta_actual.y)
    {
        *tamaño += 1;
        snake[*tamaño - 1].imagen = 'X';

        // Generar una nueva posición aleatoria para la fruta
        fruta_actual.x = rand() % (H - 1);
        fruta_actual.y = rand() % (V - 1);

        // Asegurarse de que la fruta no esté en el borde del campo
        while (fruta_actual.x == 0)
        {
            fruta_actual.x = rand() % (H - 1);
        }

        while (fruta_actual.y == 0)
        {
            fruta_actual.y = rand() % (V - 1);
        }
    }

    // Manejo del input del usuario para cambiar la dirección de la serpiente
    if (*muerto == 0 && kbhit())
    {
        char key = getch();

        // Cambiar la dirección de la serpiente según la tecla presionada
        if (key == '2' && snake[0].Mody != -1)
        {
            snake[0].Mody = 1;
            snake[0].Modx = 0;
        }
        if (key == '8' && snake[0].Mody != 1)
        {
            snake[0].Mody = -1;
            snake[0].Modx = 0;
        }
        if (key == '4' && snake[0].Modx != 1)
        {
            snake[0].Mody = 0;
            snake[0].Modx = -1;
        }
        if (key == '6' && snake[0].Modx != -1)
        {
            snake[0].Mody = 0;
            snake[0].Modx = 1;
        }
    }
}

// Función para actualizar los datos de la serpiente
void Inicio_Datos2(char campo[V][H], int tamaño)
{
    // Mover cada segmento de la serpiente al lugar del segmento anterior
    for (int i = tamaño - 1; i > 0; i--)
    {
        snake[i].x = snake[i - 1].x;
        snake[i].y = snake[i - 1].y;
    }
    // Actualizar la posición de la cabeza de la serpiente
    snake[0].x += snake[0].Modx;
    snake[0].y += snake[0].Mody;

    // Colocar la serpiente en el campo de juego
    for (int i = 0; i < tamaño; i++)
    {
        campo[snake[i].y][snake[i].x] = snake[i].imagen;
    }
    // Colocar la fruta en el campo de juego
    campo[fruta_actual.y][fruta_actual.x] = '*';
}

// Función para actualizar el campo de juego
void update(char campo[V][H], int tamaño)
{
    // Inicializar el campo de juego y actualizar los datos de la serpiente
    Inicio_Campo(campo);
    Inicio_Datos2(campo, tamaño);
}

// Función para manejar el movimiento de la serpiente
void movimiento(char campo[V][H], int tamaño)
{
    int muerto = 0; // Variable para indicar si la serpiente está muerta

    // Bucle principal del juego
    do
    {
        dibujar(campo);                        // Dibujar el campo de juego
        ocaciones_de_muerte(&tamaño, &muerto); // Comprobar ocasiones de muerte y comer fruta
        update(campo, tamaño);                 // Actualizar el campo de juego
        Sleep(100);                            // Pausa para hacer el movimiento más visible
    } while (muerto == 0);

    // Imprimir mensaje de "Game Over" cuando la serpiente muera
    printf("Game Over\n");
}
