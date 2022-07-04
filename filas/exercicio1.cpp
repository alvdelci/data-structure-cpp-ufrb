#include <iostream>
using namespace std;

#define MAX 10

int enfileirar(int v[], int &fim, int &num, int valor);
int desenfileirar(int v[], int &ini, int fim, int &num, int &valor);

int main(void)
{
    // Declara a fila
    int fila[MAX];
    int ini = 0;
    int fim = -1;
    int nfila = 0;

    // Variável para armazenar dado digitado
    int dado, dado2;
    // Variável que indica se acabaram valores da fila
    int vazia;

    // Lê valores e os enfileira, se forem >= 0
    do
    {
        cout << "Digite um numero inteiro a enfileirar (0 desenfileira um número, -1 termina): ";
        cin >> dado;
        if (dado > 0)
            enfileirar(fila, fim, nfila, dado);
        else if (dado == 0)
            desenfileirar(fila, ini, fim, nfila, dado2);
    } while (dado >= 0);

    // Agora mostra valores da pilha até que eles acabem...
    do
    {
        vazia = desenfileirar(fila, ini, fim, nfila, dado);
        if (vazia == 0)
            cout << dado << endl;
    } while (vazia == 0);
}

// Enfileirar
int enfileirar(int v[], int &fim, int &num, int valor)
{

    if (num == MAX)
    {
        cout << "Lista Cheia" << endl;
        return 1;
    }

    fim++;
    if (fim == MAX)
    {
        fim = fim - MAX;
    }

    v[fim] = valor;
    num++;

    return 0;
}

// Desenfileirar
int desenfileirar(int v[], int &ini, int fim, int &num, int &valor)
{
    if (num == 0)
    {
        cout << "Lista vazia" << endl;
        return 1;
    }

    valor = v[ini];
    ini++;
    if (ini >= MAX)
    {
        ini = ini - MAX;
    }
    num--;
    return 0;
}