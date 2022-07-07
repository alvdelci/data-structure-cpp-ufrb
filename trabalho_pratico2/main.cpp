#include <iostream>
using namespace std;

#define MAX 50

#include <iostream>
#include <string>

using namespace std;

#define MAX 50

// classe que define o perfil de um idoso
class Idoso
{
public:
    char name[MAX];
    int id;
    int idade;
};

// Prototipos
int findByName(Idoso lista[], int count, char name[]);    // OK
int findById(Idoso lista[], int count, int id);           // OK
void cadastrar(Idoso lista[], int &count);                // OK
void show(Idoso lista[], int count);                      // OK
void merge_sort(Idoso lista[], int inicio, int fim);      // OK
void merge(Idoso lista[], int inicio, int meio, int fim); // OK
void quick_sort(Idoso lista[], int inicio, int fim);      // OK
int partition(Idoso lista[], int inicio, int fim);        // OK

int main()
{
    int count_cadastro = 0, inicio = 0, meio, fim, input, found;
    Idoso cadastros_armazenados[MAX];
    char name[MAX];
    int id, idade;

    do
    {
        cout << "----------MENU---------" << endl;
        cout << "1 - Cadastrar" << endl
             << "2 - Buscar pelo Identificador" << endl
             << "3 - Buscar pelo Nome" << endl
             << "0 - Sair" << endl;

        cin >> input;

        switch (input)
        {
        case 1:
            cout << endl
                 << "------Cadastrar------" << endl;
            cadastrar(cadastros_armazenados, count_cadastro);

            // Ordena a lista de pessoas cadatradas por merge_sort ou quick_sort

            merge_sort(cadastros_armazenados, 0, count_cadastro - 1);
            // quick_sort(cadastros_armazenados, 0, count_cadastro - 1);

            break;
        case 2:
            // Chama o findById
            int inputId;
            cout << "-----BUSCA POR IDENTIFICADOR------" << endl
                 << "Informe o Identificador: ";
            cin >> inputId;

            found = findById(cadastros_armazenados, count_cadastro, inputId);
            if (found == -1)
            {
                cout << "Identificador nao encontrado!" << endl;
            }
            else
            {
                cout << "------Cadastro Encontrado------" << endl
                     << "Nome: " << cadastros_armazenados[found].name << endl
                     << "Idade: " << cadastros_armazenados[found].idade << endl
                     << "Identificador: " << cadastros_armazenados[found].id << endl;
            }

            break;
        case 3:
            // Chama o findByName
            char inputName[MAX];
            cout << "-----BUSCA POR NOME------" << endl
                 << "Informe o Nome: ";
            cin.getline(inputName, MAX);

            found = findByName(cadastros_armazenados, count_cadastro, inputName);
            if (found == -1)
            {
                cout << "Nome nao encontrado!" << endl;
            }
            else
            {
                cout << "------Cadastro Encontrado------" << endl
                     << "Nome: " << cadastros_armazenados[found].name << endl
                     << "Idade: " << cadastros_armazenados[found].idade << endl
                     << "Identificador: " << cadastros_armazenados[found].id << endl;
            }

            break;
        case 0:
            // EXIBIR TUDO QUANDO ENCERRAR
            show(cadastros_armazenados, count_cadastro);
            break;

        default:
            cout << "Opcao invalida!" << endl;
        }
    } while (input != 0);

    return 0;
}

/*
 * Recebe a lista de cadastros e um id de entrada e retorna o indice do elemento encontrado ou -1 caso não encontre
 */
int findById(Idoso lista[], int count, int id)
{
    for (int element = 0; element <= count; element++)
    {
        if (lista[element].id == id)
        {
            return element;
            break;
        }
    }
    return -1;
}

/*
 * Recebe a lista de cadastros e um nome de entrada e retorna o indice do elemento encontrado ou -1 caso não encontre
 */
int findByName(Idoso lista[], int count, char name[])
{
    for (int element = 0; element <= count; element++)
    {
        if (lista[element].name == name)
        {
            return element;
            break;
        }
    }
    return -1;
}

/*
 * Recebe a lista de cadastros e a quantidade de cadastros armazenados. Registra novos objetos do tipo Idoso na lista de cadastros
 */
void cadastrar(Idoso lista[], int &count)
{
    int loop = 1;
    do
    {
        Idoso pessoa;
        cout << "Insira o Nome: ";
        cin >> pessoa.name;
        cout << "Insira a Idade: ";
        cin >> pessoa.idade;
        cout << "Insira o Identificador: ";
        cin >> pessoa.id;

        if (findById(lista, count, pessoa.id) == -1)
        {
            lista[count + 1] = pessoa;
            count++;
            cout << "Cadastrado com Sucesso!" << endl;
        }
        else
        {
            cout << "O Identificador informado ja esta cadastrado no sistema." << endl
                 << "Cadastro nao realizado!" << endl;
        }

        cout << "Deseja cadastrar novamente?" << endl
             << "1 - Sim" << endl
             << "2 - Nao" << endl;
        cin >> loop;
    } while (loop == 1);
}

/**
 * Exibe todas as informações da lista
 */
void show(Idoso lista[], int count)
{
    for (int element = 0; element <= count; element++)
    {
        cout << "------Pessoa------" << endl
             << "Idade: " << lista[element].idade << endl
             << "Nome: " << lista[element].name << endl
             << "Identificador: " << lista[element].id << endl;
    }
}

/*
 * Algoritmos de Ordenação
 */
/**
 * Merge Sort
 */
void merge_sort(Idoso lista[], int inicio, int final)
{
    int meio;
    if (inicio < final)
    {

        meio = (inicio + final) / 2;
        merge_sort(lista, inicio, meio);
        merge_sort(lista, meio + 1, final);

        merge(lista, inicio, final, meio);
    }
}
void merge(Idoso lista[], int inicio, int final, int meio)
{
    int i, j, k;
    Idoso c[50];
    i = inicio;
    k = inicio;
    j = meio + 1;
    while (i <= meio && j <= final)
    {
        if (lista[i].idade < lista[j].idade)
        {
            c[k].idade = lista[i].idade;
            k++;
            i++;
        }
        else
        {
            c[k].idade = lista[j].idade;
            k++;
            j++;
        }
    }
    while (i <= meio)
    {
        c[k].idade = lista[i].idade;
        k++;
        i++;
    }
    while (j <= final)
    {
        c[k].idade = lista[j].idade;
        k++;
        j++;
    }
    for (i = inicio; i < k; i++)
    {
        lista[i].idade = c[i].idade;
    }
}

/**
 * Quick Sort
 */
void troca(Idoso *x, Idoso *y)
{
    Idoso aux = *x;
    *x = *y;
    *y = aux;
}
int partition(Idoso lista[], int inicio, int final)
{
    int pivot = lista[final].idade;
    int i = (inicio - 1);

    for (int j = inicio; j <= final - 1; j++)
    {

        if (lista[j].idade <= pivot)
        {
            i++;
            troca(&lista[i], &lista[j]);
        }
    }
    troca(&lista[i + 1], &lista[final]);
    return (i + 1);
}
void quickSort(Idoso lista[], int inicio, int final)
{
    if (inicio < final)
    {
        int pivot = partition(lista, inicio, final);

        quickSort(lista, inicio, pivot - 1);
        quickSort(lista, pivot + 1, final);
    }
}
