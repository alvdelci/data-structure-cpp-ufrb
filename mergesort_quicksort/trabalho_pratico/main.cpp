#include <iostream>
#include <string>

using namespace std;

#define MAX 50

// classe que define o perfil de um idoso
class Idoso
{
public:
    char *name;
    int id;
    int idade;

public:
    char getName()
    {
        return *name;
    }
    void setName(char *inputName)
    {
        name = inputName;
    }

    int getIdade()
    {
        return idade;
    }
    void setIdade(int inputIdade)
    {
        idade = inputIdade;
    }

    int getId()
    {
        return id;
    }
    void setId(int inputId)
    {
        id = inputId;
    }
};

// Prototipos
int findByName(Idoso *lista, char *name);
int findById(Idoso *lista, int count, int id);
void cadastrar(Idoso *lista, int count);
void merge_sort(Idoso *lista, int inicio, int fim);
void merge(Idoso *lista, int inicio, int meio, int fim);
void quick_sort(Idoso *lista, int inicio, int fim);

int main()
{
    int count_cadastro = 0, inicio = 0, meio, fim, input;
    Idoso cadastros_armazenados[MAX];
    char *nome;
    int id, idade;

    do
    {
        cout << "----------MENU---------" << endl;
        cout << "1 - Cadastrar" << endl
             << "2 - Buscar pelo nome" << endl
             << "3 - Buscar pelo Identificador" << endl
             << "0 - Sair" << endl;

        cin >> input;

        switch (input)
        {
        case 1:

            // Chamando a função cadastrar
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

            int found = findById(cadastros_armazenados, count_cadastro, inputId);

            if (found == -1)
            {
                cout << "Não existe usuário cadastrado com esse identificador" << endl;
            }
            else
            {
                for (int element = 0; element < count_cadastro; element++)
                {
                    if (element == found)
                    {
                        cout << "****INFORMAÇÕES DO USUÁRIO****" << endl;
                        cout << "Idade: " << cadastros_armazenados[element].getIdade() << endl;
                        cout << "Nome: " << cadastros_armazenados[element].getName() << endl;
                        cout << "Identificador: " << cadastros_armazenados[element].getId() << endl;
                    }
                }
            }

            break;
        case 3:
            // Chama findByName
            break;
        case 0:
            break;

        default:
            cout << "Opção inválida!" << endl;
        }
    } while (input != 0);

    return 0;
}

// FUNCTIONS
/*
 * Recebe a lista de pessoas cadastradas e um nome de entrada. Retorna uma lista com os indices encontrados ou -1 caso não encontre o nome cadastrado
 */
int findByName(Idoso *lista, char *name) {}
/*;
 * Retorna o índice do elemento na lista de cadastros ou -1 caso o id não seja encontrado
 */
int findById(Idoso *lista, int count, int id)
{
    for (int element = 0; element < count; element++)
    {
        if (lista[element].getId() == id)
        {
            return id;
        }
    }
    return -1;
}
/*
 * Recebe as informações do usuário e realiza o cadastro caso não haja usuário com mesmo id cadastrado
 */
void cadastrar(Idoso *lista, int count)
{
    // Chama Cadastrar dentro de um loop com menu
    int loop = 1;
    do
    {
        char *name;
        int idade;
        int id;

        cout << "Insira o Nome: ";
        cin >> name;
        cout << "Insira a Idade: ";
        cin >> idade;

        try
        {
            cout << "Insira o Identificador: ";
            cin >> id;

            if (findById(lista, count, id) == -1)
            {
                continue;
            }
            else
            {
                throw 505;
            }
        }
        catch (...)
        {
            cout << "O Identificador informado já está cadastrado no sistema." << endl
                 << "Tente outro Identificador!" << endl;
        }

        // Define as informações do objeto pessoa
        Idoso pessoa;
        pessoa.setName(name);
        pessoa.setIdade(idade);
        pessoa.setId(id);

        // Adiciona o novo objeto com as informações na lista de cadastrados
        lista[count + 1] = pessoa;

        cout << "Deseja cadastrar novamente?" << endl
             << "1 - Sim" << endl
             << "2 - Não" << endl;
    } while (loop == 1);
}
void merge_sort(Idoso *lista, int inicio, int fim)
{
    if (inicio >= fim)
        ;
    return;

    auto meio = inicio + (fim - inicio) / 2;
    merge_sort(lista, inicio, meio);
    merge_sort(lista, meio + 1, fim);
    merge(lista, inicio, meio, fim);
}
void merge(Idoso *arr, int low, int high, int mid)
{
    int i, j, k;
    Idoso c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i].id < arr[j].idade)
        {
            c[k].idade = arr[i].idade;
            k++;
            i++;
        }
        else
        {
            c[k].idade = arr[j].idade;
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k].idade = arr[i].idade;
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k].idade = arr[j].idade;
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        arr[i].idade = c[i].idade;
    }
}
void quick_sort(Idoso *lista, int inicio, int fim)
{
    if (inicio >= fim)
        ;
    return;

    int p = partition(lista, inicio, fim);

    quick_sort(lista, inicio, p - 1);

    quick_sort(lista, p + 1, fim);
}
int partition(Idoso *lista, int inicio, int fim)
{

    int pivot = lista[inicio].getIdade();

    int count = 0;
    for (int i = inicio + 1; i <= fim; i++)
    {
        if (lista[i].getIdade() <= pivot)
            count++;
    }
    // Declara o elemento correto do pivot
    int pivotIndex = inicio + count;
    swap(lista[pivotIndex], lista[inicio]);

    // Ordena os elementos do pivot dos lados esquerdo e direito
    int i = inicio, j = fim;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (lista[i].getIdade() <= pivot)
        {
            i++;
        }
        while (lista[j].getIdade() > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(lista[i++], lista[j--]);
        }
    }
    return pivotIndex;
}