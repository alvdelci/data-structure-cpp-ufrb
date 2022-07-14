// Lista Encadeada
#include <iostream>
using namespace std;

struct no {
    int valor;
    no * ptr;
};

no * inserirInicio(no * lista, int valor);
void imprimir(no * lista);
void substituir(no * lista, int pos, int valor);
no * removerInicio(no * lista);

int main(void) {
    // Declara ponteiro para início da lista
    no * lista = NULL;
    int n, i, val;

    cout << "Quantos valores pretende digitar? ";
    cin >> n;

    for(i=0; i<n; i++) {
        cout << "Digite o valor " << i+1 << ": ";
        cin >> val;
        lista = inserirInicio(lista, val);
    }

    imprimir(lista);
    cout << "***" << endl;
    substituir(lista, 3, 666);
    imprimir(lista);
    cout << "***" << endl;
    lista = removerInicio(lista);
    imprimir(lista);

}

// Insere um elemento na lista, retornando o ponteiro atualizado da lista
no * inserirInicio(no * lista, int valor) {
    no * tmp;
    // Cria o nó
    tmp = new no;
    tmp->valor = valor;
    tmp->ptr = NULL;
    // Se a lista está vazia... ajusta ponteiro
    if (lista == NULL) lista = tmp;
    // Se a lista não está vazia, insere o elemento
    else {
        tmp->ptr = lista;
        lista = tmp;
    }
    return lista;
}

// Imprimir
void imprimir(no * lista) {
    no * tmp;
    tmp = lista;
    while(tmp != NULL) {
        cout << tmp->valor << endl;
        tmp = tmp->ptr;
    }
}

// Substituir
void substituir(no * lista, int pos, int valor) {
    int i;
    no * tmp;

    // Se número de nó for inválido, vai embora
    if (pos < 1) return;
    // Caso contrário, procura e susbstitui elemento
    tmp = lista;
    i = 1;
    while(tmp != NULL) {
        if (i==pos) {
            tmp->valor = valor;
            break;
        }
        tmp = tmp->ptr;
        i++;
    }
}

no * removerInicio(no * lista) {
    no * tmp;
    // Se lista está vazia, vai embora sem fazer nada
    if (lista == NULL) return lista;
    // Se há elementos, remove o primeiro...
    tmp = lista;
    lista = tmp->ptr;
    delete tmp;
    return lista;
}
