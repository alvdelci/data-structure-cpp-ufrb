#include <iostream>
using namespace std;

// Protótipos
void inserir(float v[], float n, int &pos, int max);
void inserirSemRepetir(float v[], float n, int &pos, int max);
void listar(float v[], int quantidade);
int buscar(float v[], int quantidade, int n);
void remover(float v[], int &quantidade, int n);
void intercalar(float v1[], float v2[], float v3[], int tamanho);
void intersecao(float v1[], float v2[], float v3[], int tamanho);
void uniao(float v1[], float v2[], float v3[], int tamanho);

// Programa Principal
int main(void)
{
    // Declaração da lista de notas
    float lista1[10];
    float lista2[10];

    int quantidade;
    // Valor a ser lido
    float n;
    // Posição do resultado
    int pos;

    // Inicializa a Lista: contém, inicialmente, zero elementos
    quantidade = 0;

    // Leitura de N dado
    do
    {
        int option;
        cout << "Enter a option:" << endl
             << "1 - Criar listas" << endl
             << "2 - Intercalar listas" << endl
             << "3 - Fazer interseção das listas" << endl
             << "4 - Unir listas" << endl
             << "5 - Remover" << endl
             << "0 - Sair" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Executa criar listas" << endl
                 << endl;
            break;
        case 2:
            cout << "Executa Intercalar listas" << endl
                 << endl;
            ;
            break;
        case 3:
            cout << "Executa Insterseção" << endl
                 << endl;
            ;
            break;
        case 4:
            cout << "Executa Unir listas" << endl
                 << endl;
            ;
            break;
        case 5:
            cout << "Executa Remover" << endl
                 << endl;
            ;
            break;
        case 0:
            cout << "Executa Sair" << endl
                 << endl;
            ;
            n = 0;
            break;

        default:
            cout << "Opção Inválida!" << endl
                 << endl;
            break;
        }

    } while (n != 0);
}

// Insere N na posição POS da lista V
void inserir(float v[], float n, int &pos, int max)
{
    if (pos >= max)
        cout << "ERRO: Lista cheia!" << endl;
    else
    {
        v[pos] = n;
        pos++;
    }
}

// Analisa os valores para inserir sem repetir
void inserirSemRepetir(float v[], float n, int &pos, int max)
{
    int index = buscar(v, pos, n);

    if (index != -1)
    {
        cout << "Numero ja existe" << endl;
    }
    else
    {
        inserir(v, n, pos, max);
    }
}

// Imprime os valores de um vetor
void listar(float v[], int quantidade)
{
    int i;
    for (i = 0; i < quantidade; i++)
    {
        cout << v[i] << endl;
    }
}

// Busca por um elemento e retorna sua posição
int buscar(float v[], int quantidade, int n)
{
    int i;
    for (i = 0; i < quantidade; i++)
    {
        if (v[i] == n)
            return i;
    }
    return -1;
}

// Remove o elemento desejado da lista
void remover(float v[], int &quantidade, int n)
{
    int pos;
    if (quantidade == 0)
        cout << "ERRO: Lista Vazia!" << endl;
    else
    {
        pos = buscar(v, quantidade, n);
        if (pos < 0)
            cout << "ERRO: Elemento inexistente!" << endl;
        else
        {
            v[pos] = v[quantidade - 1];
            quantidade--;
        }
    }
}

// Recebe duas listas e as intercala
void intercalar(float v1[], float v2[], float v3, int tamanho)
{
}

// Recebe duas listas e constroi uum lista com os valores em comum nas duas
void intersecao(float v1[], float v2[], float v3, int tamanho)
{
}

// Recebe as duas listas e as une
void uniao(float v1[], float v2[], float v3, int tamanho)
{
}