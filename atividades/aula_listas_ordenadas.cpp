#include <iostream>
using namespace std;

void listar(float v[], int n);
void inserirCresc(float v[], int &n, int max, float valor);
int buscaBinaria(float v[], int n, float valor);
void remover(float v[], int &n, float valor);
void bubbleSort(float v[], int n);

int main(void)
{

    float notas[50], nota;
    int n = 0;
    int pos;

    do
    {
        cout << "Digite uma nota: ";
        cin >> nota;
        if (nota >= 0)
            inserirCresc(notas, n, 50, nota);
    } while (nota >= 0);

    listar(notas, n);

    cout << "Procurar qual nota? ";
    cin >> nota;
    pos = buscaBinaria(notas, n, nota);
    if (pos == -1)
        cout << "Valor nao encontrado!" << endl;
    else
        cout << "Encontrado na posicao: " << pos << endl;
} // end main

// Busca um valor informado por busca binária
int buscaBinaria(float v[], int n, float valor)
{
    // Marca início e fim
    int ini = 0;
    int fim = n - 1;
    int meio;

    while (ini <= fim)
    {
        meio = (ini + fim) / 2;
        if (valor == v[meio])
            return meio;
        if (valor < v[meio])
            fim = meio - 1;
        if (valor > v[meio])
            ini = meio + 1;
    }

    return -1;
}

// insere os valores na lista ordenada em ordem crescente
void inserirCresc(float v[], int &n, int max, float valor)
{
    int i, pos;
    // Verifica se há espaço na lista
    if (n == max)
    {
        cout << "ERRO: Lista cheia!" << endl;
        return;
    }
    // Encontrar posição de inserção
    i = 0;
    while (v[i] < valor && i < n)
        i++;
    pos = i;
    // Move para frente tudo que estiver após a posição
    for (i = n; i > pos; i--)
        v[i] = v[i - 1];
    // Insere o elemento na posição
    v[pos] = valor;
    n++;
}

// Remove um elemento da lista e move os maiores para a esquerda para preencher na ordem
void remover(float v[], int &n, float valor)
{
    int i, pos;
    // Verifica se há algum elemento na lista
    if (n == 0)
    {
        cout << "ERRO: Lista vazia!" << endl;
        return;
    }
    // Encontra posição do elemento a remover
    pos = buscaBinaria(v, n, valor);
    if (pos < 0)
    {
        cout << "ERRO: Elemento nao encontrado!" << endl;
        return;
    }
    // Remove com sobreposição
    for (i = pos; i < n - 1; i++)
        v[i] = v[i + 1];
    // Atualiza quantidade de elementos na lista
    n--;
}

// Organiza a lista através de permutações
void bubbleSort(float v[], int n)
{
    int i;
    bool inversao;
    float aux;

    // Repete rotina de inversões enquanto alguma inversão ocorrer
    // Finaliza quando nenhuma inversão for feita na rotina anterior
    do
    {
        inversao = false;
        // Percorre os valores
        for (i = 0; i < n - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                inversao = true;
            }
        }
    } while (inversao);
}

//
void listar(float v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << v[i] << endl;
}
