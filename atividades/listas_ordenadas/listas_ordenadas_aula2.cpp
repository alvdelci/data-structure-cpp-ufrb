#include <iostream>
using namespace std;

void listar(int v[], int n);
void ordenaSelecao(int v[], int n);
void ordenaInsercao(int v[], int n);

int main(void)
{
    // Declara as cartas (desordenadas)
    int cartas[9] = {1, 7, 8, 3, 2, 9, 6, 4, 5};

    // ordenaSelecao(cartas, 9);
    ordenaInsercao(cartas, 9);
    // Mostra as cartas todas
    listar(cartas, 9);
}

// Apresenta elementos da lista
// Entrada:
//  v: vetor com elementos da lista
//  n: número de elementos na lista
void listar(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << v[i];
        if (i < n - 1)
            cout << ", ";
        else
            cout << "." << endl;
    }
}

// ordenacao por selecao
/*
void ordenaSelecao(int v[], int n)
{
    int initial, current, menor, aux;

    for (initial; initial < n - 1; initial++)
    {
        menor = initial;

        for (current = initial + 1; current <)
        // ver como faz completo. Tem que fazer guardando as posições
    }
}
*/
// ordenacao por insercao
void ordenaInsercao(int v[], int n)
{
    int inicial = 1;
    int atual = inicial - 1;
    int menor = inicial;

    for (int index = 0; index < n; index++)
    {
    }
}