#include <iostream>
using namespace std;

// Protótipos
void inserir(float v[], float n, int &pos, int max);
void inserirSemRepetir(float v[], float n, int &pos, int max);
void listar(float v[], int quantidade);
int buscar(float v[], int quantidade, int n);
void remover(float v[], int &quantidade, int n);

// Programa Principal
int main(void)
{
    // Declaração da lista de notas
    float notas[10];
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
             << "1 - Inserir" << endl
             << "2 - Inserir sem repetir" << endl
             << "3 - Listar" << endl
             << "4 - Buscar" << endl
             << "5 - Remover" << endl
             << "0 - Sair" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Executa Inserir" << endl
                 << endl;
            break;
        case 2:
            cout << "Executa Inserir Sem Repetir" << endl
                 << endl;
            ;
            break;
        case 3:
            cout << "Executa Listar" << endl
                 << endl;
            ;
            break;
        case 4:
            cout << "Executa Buscar" << endl
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

    // Imprime vetor
    listar(notas, quantidade);

    // Busca valor
    cout << "Digite valor a buscar na lista: ";
    cin >> n;
    pos = buscar(notas, quantidade, n);
    if (pos >= 0)
        cout << "Encontrado em pos= " << pos << endl;
    else
        cout << "Valor nao encontrado na lista!";

    // Revover um valor
    cout << "Digite valor a remover da lista: ";
    cin >> n;
    remover(notas, quantidade, n);

    // Imprime vetor
    listar(notas, quantidade);
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

// Insere os valores sem repetir na lista
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
