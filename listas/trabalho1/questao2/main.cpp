#include <iostream>
using namespace std;

// Protótipos
void inserir(float v[], float n, int &pos, int max);                                               // OK
void inserirSemRepetir(float v[], float n, int &pos, int max);                                     // OK
void listar(float v[], int quantidade);                                                            // OK
int buscar(float v[], int quantidade, int n);                                                      // OK
void remover(float v[], int &quantidade, int n);                                                   // OK
void intercalar(float v1[], int tamanhoV1, float v2[], int tamanhoV2, float v3[], int &tamanhoV3); // OK
void intersecao(float v1[], int tamanhoV1, float v2[], int tamanhoV2, float v3[], int &tamanhoV3); // OK
void uniao(float v1[], int tamanhoV1, float v2[], int tamanhoV2, float v3[], int &tamanhoV3);      // OK

// Programa Principal
int main(void)
{
    // Declaração da lista de entrada
    float lista_entrada1[10];
    float lista_entrada2[10];

    // lista dos valores das operacoes
    float lista_intercalada[20], lista_intersecao[10], lista_uniao[20];

    // quantidade de elementos nas listas declaradas
    int quantidade_lista_entrada1 = 0, quantidade_lista_entrada2 = 0,
        quantidade_lista_intercalada = 0, quantidade_lista_intersecao = 0,
        quantidade_lista_uniao = 0;

    // Posição do resultado
    int pos;

    // Leitura de N dados
    int n;
    do
    {
        cout << "Enter a option:" << endl
             << "1 - Criar listas" << endl
             << "2 - Intercalar listas" << endl
             << "3 - Fazer intersecao das listas" << endl
             << "4 - Unir listas" << endl
             << "5 - Remover" << endl
             << "0 - Sair" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Executa criar listas" << endl
                 << endl;

            float input;
            bool troca_lista;
            bool fim_lista2;
            do
            {
                fim_lista2 = false;

                cout << "Insira valores na lista: " << endl
                     << "Insira (0) para sair e (-1) para trocar de lista" << endl;
                cin >> input;

                if (input < 0)
                {
                    troca_lista = true;
                }

                if (!troca_lista)
                {
                    // Insere valores sem repetir na lista 1
                    inserirSemRepetir(lista_entrada1, input, quantidade_lista_entrada1, 10);
                }
                else if (troca_lista && input > 0)
                {
                    // insere valores sem repetir a lista 2
                    inserirSemRepetir(lista_entrada2, input, quantidade_lista_entrada2, 10);
                }
                else if (input < 0 && quantidade_lista_entrada2 > 0)
                {
                    fim_lista2 = true;
                }

            } while (!fim_lista2);

            cout << "lista 1" << endl;
            listar(lista_entrada1, quantidade_lista_entrada1);
            cout << "lista 2" << endl;
            listar(lista_entrada2, quantidade_lista_entrada2);

            break;

        case 2:
            intercalar(lista_entrada1, quantidade_lista_entrada1, lista_entrada2, quantidade_lista_entrada2, lista_intercalada, quantidade_lista_intercalada);

            cout << "Lista Intercalada" << endl
                 << endl;
            ;

            listar(lista_intercalada, quantidade_lista_intercalada);
            break;
        case 3:
            intersecao(lista_entrada1, quantidade_lista_entrada1, lista_entrada2, quantidade_lista_entrada2, lista_intersecao, quantidade_lista_intersecao);

            cout << endl
                 << "Lista de Intersecoes" << endl;
            listar(lista_intersecao, quantidade_lista_intersecao);
            break;
        case 4:
            uniao(lista_entrada1, quantidade_lista_entrada1, lista_entrada2, quantidade_lista_entrada2, lista_uniao, quantidade_lista_uniao);

            cout << endl
                 << "Lista de Uniao" << endl;

            listar(lista_uniao, quantidade_lista_uniao);
            break;
        case 5:
            float entrada_remover;

            cout << "Insira o elemento que deseja remover: ";
            cin >> entrada_remover;

            remover(lista_uniao, quantidade_lista_uniao, entrada_remover);

            cout << "Lista resultante" << endl;
            listar(lista_uniao, quantidade_lista_uniao);

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

// Insere o valor digitado na lista
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
        cout << v[i] << " ";
    }
    cout << endl;
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
void intercalar(float v1[], int tamanhoV1, float v2[], int tamanhoV2, float v3[], int &tamanhoV3)
{
    int posicao_final = 0;
    /*
        Percorre o v3 adicionando os elementos de cada vetor de entrada
        O maior vetor determina a quantidade repeticoes no for
    */
    for (int element = 0; element < (tamanhoV1 > tamanhoV2 ? tamanhoV1 : tamanhoV2); element++)
    {
        if (element < tamanhoV1)
        {
            v3[posicao_final] = v1[element];
            posicao_final++;
        }
        if (element < tamanhoV2)
        {
            v3[posicao_final] = v2[element];
            posicao_final++;
        }
    }
    tamanhoV3 = posicao_final;
}

// Recebe duas listas e constroi uum lista com os valores em comum nas duas
void intersecao(float v1[], int tamanhoV1, float v2[], int tamanhoV2, float v3[], int &tamanhoV3)
{
    for (int element_lista1 = 0; element_lista1 < tamanhoV1; element_lista1++)
    {
        for (int element_lista2 = 0; element_lista2 < tamanhoV1; element_lista2++)
        {
            if (v1[element_lista1] == v2[element_lista2])
            {
                v3[tamanhoV3] = v1[element_lista1];
                tamanhoV3++;
            }
        }
    }
}

// Recebe as duas listas e as une
void uniao(float v1[], int tamanhoV1, float v2[], int tamanhoV2, float v3[], int &tamanhoV3)
{
    // Insere os valores do vetor 1 no vetor união
    for (int element = 0; element < tamanhoV1; element++)
    {
        v3[element] = v1[element];
        tamanhoV3++;
    }

    // insere os valores do vetor 2 no vetor união
    for (int element = 0; element < tamanhoV2; element++)
    {
        v3[tamanhoV1 + element] = v2[element];
        tamanhoV3++;
    }
}