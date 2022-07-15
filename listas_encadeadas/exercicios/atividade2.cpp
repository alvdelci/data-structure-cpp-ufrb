// Atividade de Listas Duplamente Encadeadas
#include <iostream>
using namespace std;

struct element
{
    int valor;
    element *next;
    element *previous;
};

// Prototipos
element *inserirInicio(element *lista, int valor);
void imprimir(element *lista);
void substituir(element *lista, int pos, int valor);
element *removerInicio(element *lista);
element *buscar(element *lista, int valor);

int main()
{
    // Declara next para in�cio da lista
    element *lista = NULL;
    int n, i, val;

    bool loop = true;
    while (loop)
    {
        cout << "------ Opcoes ------" << endl
             << "1 - Inserir valores" << endl
             << "2 - Buscar" << endl
             << "0 - Sair e exibir resultados" << endl;
        int opcao;
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            cout << "Quantos valores pretende digitar? ";
            cin >> n;

            for (i = 0; i < n; i++)
            {
                cout << "Digite o valor " << i + 1 << ": ";
                cin >> val;
                lista = inserirInicio(lista, val);
            }
            break;
        case 2:
            int value;
            cout << "Digite o valor: ";
            cin >> value;
            if (buscar(lista, value) == NULL)
            {
                cout << "Valor Nao existe na lista!" << endl;
                cout << buscar(lista, value) << endl;
            }
            else
            {
                cout << "Valor encontrado" << endl;
                cout << buscar(lista, value) << endl;
            }

            break;
        case 0:
            loop = false;
            break;
        }
    }

    cout << "------ Lista de entrada ------" << endl;
    imprimir(lista);
    cout << "----- Lista substituido o terceiro valor ------" << endl;
    substituir(lista, 3, 666);
    imprimir(lista);
    cout << "------ Lista removido o elemento do inicio ------" << endl;
    lista = removerInicio(lista);
    imprimir(lista);

    return 0;
}

// Insere um elemento na lista, retornando o next atualizado da lista
element *inserirInicio(element *lista, int valor)
{
    element *tmp;
    // Cria o n�
    tmp = new element;
    tmp->valor = valor;
    tmp->next = NULL;

    // Se a lista est� vazia... ajusta next
    if (lista == NULL)
        lista = tmp;
    // Se a lista n�o est� vazia, insere o elemento
    else
    {
        tmp->next = lista;
        lista = tmp;
    }
    return lista;
}

// Imprimir
void imprimir(element *lista)
{
    element *tmp;
    tmp = lista;
    while (tmp != NULL)
    {
        cout << tmp->valor << " ";
        tmp = tmp->next;
    }
}

// Substituir
void substituir(element *lista, int pos, int valor)
{
    int i;
    element *tmp;

    // Se n�mero de n� for inv�lido, vai embora
    if (pos < 1)
        return;
    // Caso contr�rio, procura e susbstitui elemento
    tmp = lista;
    i = 1;
    while (tmp != NULL)
    {
        if (i == pos)
        {
            tmp->valor = valor;
            break;
        }
        tmp = tmp->next;
        i++;
    }
}

element *removerInicio(element *lista)
{
    element *tmp;
    // Se lista est� vazia, vai embora sem fazer nada
    if (lista == NULL)
        return lista;
    // Se h� elementos, remove o primeiro...
    tmp = lista;
    lista = tmp->next;
    delete tmp;
    return lista;
}

// Buscar
element *buscar(element *lista, int valor)
{
    element *temp;
    temp = lista;
    while (temp != NULL)
    {
        if (temp->valor == valor)
        {
            return temp;
            break;
        }

        temp = temp->next;
    }
    return temp;
}