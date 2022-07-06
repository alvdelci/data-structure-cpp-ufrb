#include <iostream>
#include <string>

using namespace std;

#define MAX 50

// Prototipos
int findByName(Idoso lista, string name);
int findById(Idoso lista, int id);
Idoso getInfo();
void cadastrar(Idoso lista, Idoso pessoa);
void merge_sort(Idoso lista, int inicio, int fim);
void merge(Idoso lista, int inicio, int meio, int fim);
void quick_sort(Idoso lista, int inicio, int fim);

int main()
{
    int count_cadastro = 0, inicio = 0, meio, fim, input;
    Idoso cadastros_armazenados[MAX];
    string nome;
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
            // Chama Cadastrar dentro de um loop com menu
            int loop = 1;
            do
            {
                try
                {
                    Idoso objeto = getInfo();

                    if (findById(objeto.id) == -1)
                    {
                        cadastrar(cadastros_armazenados, objeto);
                        count_cadastro++;
                    }
                    else
                    {
                        throw 404;
                    }
                }
                catch (...)
                {
                    cout << "O Identificador informado já está cadastrado no sistema." << endl
                         << "Tente Novamente" << endl;
                }

                cout << "Deseja cadastrar novamente?" << endl
                     << "1 - Sim" << endl
                     << "2 - Não" << endl;
            } while (loop == 1);

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

            if (inputId == -1)
            {
                cout << "Não existe usuário cadastrado com esse identificador" << endl;
            }
            else
            {
                for (int element = 0; element < count_cadastro; element++)
                {
                    if (element == inputId)
                    {
                        cout << "****INFORMAÇÕES DO USUÁRIO****" << cadastros_armazenados[] << endl;
                        cout << "" << endl;
                        cout << "" << endl;
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

// classe que define o perfil de um idoso
class Idoso
{
public:
    string name;
    int id;
    int idade;
};

// FUNCTIONS
int findByName(Idoso lista, string name) {}
int findById(Idoso lista, int id) {}
int partition(Idoso lista, int inicio, int fim) {
    
    int pivot = lista[inicio];

    int count = 0;
    for (int i = inicio + 1; i <= fim; i++) {
        if (lista[i] <= pivot)
        cout++;
    }
    // Declara o elemento correto do pivot
    int pivotIndex = inicio + count;
    swap(lista[pivotIndex], lista[inicio]);

    // Ordena os elementos do pivot dos lados esquerdo e direito
    int i = inicio, j = fim;
    
    while (i < pivotIndex && j > pivotIndex) {
        
        while (lista[i] <= pivot) {
            i++;
        }
        while (lista[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(lista[i++], lista[j--]);
        }
    }
    return pivotIndex;
}
Idoso getInfo() {}
void cadastrar(Idoso lista, Idoso pessoa) {}
void merge_sort(Idoso lista, int inicio, int fim) {
    if (inicio >= fim);
    return;

    auto meio = inicio + (fim - inicio) / 2;
    merge_sort(lista, inicio, meio);
    merge_sort(lista, meio + 1, fim);
    merge(lista, inicio, meio, fim);
}
void merge(Idoso lista, int inicio, int meio, int fim) {
    int 
}
void quick_sort(Idoso lista, int inicio, int fim) {
    if (inicio >= fim);
    return;

    int p = partition(lista, inicio, fim);

    quick_sort(lista, inicio, p - 1);

    quick_sort(lista, p + 1, fim);
}