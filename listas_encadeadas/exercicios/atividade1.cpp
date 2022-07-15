// Atividade de Listas Encadeadas
#include <iostream>
using namespace std;

struct no
{
    int valor;
    no *ponteiro;
};

// Prototipos
no *inserirInicio(no *lista, int valor);
void imprimir(no *lista);
void substituir(no *lista, int pos, int valor);
no *removerInicio(no *lista);
no *buscar(no *lista, int valor);

int main()
{
    // Declara ponteiro para in�cio da lista
    no *lista = NULL;
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

// Insere um elemento na lista, retornando o ponteiro atualizado da lista
no *inserirInicio(no *lista, int valor)
{
    no *tmp;
    // Cria o n�
    tmp = new no;
    tmp->valor = valor;
    tmp->ponteiro = NULL;
    // Se a lista est� vazia... ajusta ponteiro
    if (lista == NULL)
        lista = tmp;
    // Se a lista n�o est� vazia, insere o elemento
    else
    {
        tmp->ponteiro = lista;
        lista = tmp;
    }
    return lista;
}

// Imprimir
void imprimir(no *lista)
{
    no *tmp;
    tmp = lista;
    while (tmp != NULL)
    {
        cout << tmp->valor << " ";
        tmp = tmp->ponteiro;
    }
}

// Substituir
void substituir(no *lista, int pos, int valor)
{
    int i;
    no *tmp;

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
        tmp = tmp->ponteiro;
        i++;
    }
}

no *removerInicio(no *lista)
{
    no *tmp;
    // Se lista est� vazia, vai embora sem fazer nada
    if (lista == NULL)
        return lista;
    // Se h� elementos, remove o primeiro...
    tmp = lista;
    lista = tmp->ponteiro;
    delete tmp;
    return lista;
}

// Buscar
no *buscar(no *lista, int valor)
{
    no *temp;
    temp = lista;
    while (temp != NULL)
    {
        if (temp->valor == valor)
        {
            return temp;
            break;
        }

        temp = temp->ponteiro;
    }
    return temp;
}