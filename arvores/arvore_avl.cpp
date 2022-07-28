#include <iostream>
using namespace std;

// No para a Arvore AVL
struct No
{
    int valor;
    No *left, *right;
    short height;
};

// Prototipos
No *novoNo(int);
int maior(int, int);
int alturaDoNo(No *);
int fatorDeBalanceamento(No *);
No *rotacaoEsquerda(No *);
No *rotacaoDireita(No *);
No *rotacaoEsquerdaDireita(No *);
No *rotacaoDireitaEsquerda(No *);
No *inserir(No *, int);
No *balancear(No *);
No *remover(No *, int);
void imprimir(No *, int);

int main()
{

    int opcao, valor;
    No *raiz = NULL;

    do
    {
        cout << endl
             << " 0 - Sair " << endl
             << " 1 - Inserir " << endl
             << " 2 - Remover " << endl
             << " 3 - Imprimir " << endl;
        cin >> opcao;

        switch (opcao)
        {
        case 0:
            cout << "Saindo!!!" << endl;
            break;
        case 1:
            cout << "Digite o valor a ser inserido: " << endl;
            cin >> valor;
            raiz = inserir(raiz, valor);
            break;
        case 2:
            cout << "Digite o valor a ser removido: " << endl;
            cin >> valor;
            raiz = remover(raiz, valor);
            break;
        case 3:
            imprimir(raiz, 1);
            break;
        default:
            cout << "Opcao invalida!!!" << endl;
        }

    } while (opcao != 0);

    return 0;
} // END MAIN

// Função que cria um novo no -> valor a ser inserido no no. Retorna: o endereço do no criado
No *novoNo(int x)
{
    No *novo = new No();

    if (novo)
    {
        novo->valor = x;
        novo->left = NULL;
        novo->right = NULL;
        novo->height = 0;
    }
    else
    {
        cout << "ERRO ao alocar nó em novoNo!"
             << endl;
    }
    return novo;
}

// Recebe dois numeros inteiros e retorna o maior
int maior(int a, int b)
{
    return (a > b) ? a : b;
}

// Retorna a altura de um no ou -1 caso ele seja null
int alturaDoNo(No *no)
{
    if (no == NULL)
        return -1;
    else
        return no->height;
}

// Calcula e retorna o fator de balanceamento de um no
int fatorDeBalanceamento(No *no)
{
    if (no)
        return (alturaDoNo(no->left) - alturaDoNo(no->right));
    else
        return 0;
}

// função para a rotação à esquerda
No *rotacaoEsquerda(No *r)
{
    No *y, *f;

    y = r->right; // y aponta para a subárvore direita da raiz r
    f = y->left;  // f aponta para o filho esquerdo de y

    y->left = r;  // o filho esquerdo de y passa a ser a raiz r
    r->right = f; // o filho direito de r passa a ser f

    // recalcula a altura dos nós que foram movimentados
    r->height = maior(alturaDoNo(r->left), alturaDoNo(r->right)) + 1;
    y->height = maior(alturaDoNo(y->left), alturaDoNo(y->right)) + 1;

    return y;
}

// função para a rotação à direita
No *rotacaoDireita(No *r)
{
    No *y, *f;

    y = r->left;
    f = y->right;

    y->right = r;
    r->left = f;

    r->height = maior(alturaDoNo(r->left), alturaDoNo(r->right)) + 1;
    y->height = maior(alturaDoNo(y->left), alturaDoNo(y->right)) + 1;

    return y;
}

// Funcao de rotacao esquerda direita
No *rotacaoEsquerdaDireita(No *r)
{
    r->left = rotacaoEsquerda(r->left);
    return rotacaoDireita(r);
}

// funcao de rotacao direita esquerda
No *rotacaoDireitaEsquerda(No *r)
{
    r->right = rotacaoDireita(r->right);
    return rotacaoEsquerda(r);
}

/*
    Insere um novo nó na árvore
    Retorna o endereço do novo no ou nova raiz após o balanceamento
*/
No *inserir(No *raiz, int x)
{
    if (raiz == NULL) // árvore vazia
        return novoNo(x);
    else
    { // inserção será à esquerda ou à direita
        if (x < raiz->valor)
            raiz->left = inserir(raiz->left, x);
        else if (x > raiz->valor)
            raiz->right = inserir(raiz->right, x);
        else
            cout << "Insercao nao realizada!O elemento " << x << " ja existe!" << endl;
    }

    // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
    raiz->height = maior(alturaDoNo(raiz->left), alturaDoNo(raiz->right)) + 1;

    // verifica a necessidade de rebalancear a árvore
    raiz = balancear(raiz);

    return raiz;
}

/*
    Função para realizar o balanceamento da árvore após uma inserção ou remoção
    Recebe o nó que está desbalanceado e retorna a nova raiz após o balanceamento
*/
No *balancear(No *raiz)
{
    short fb = fatorDeBalanceamento(raiz);

    // Rotação à esquerda
    if (fb < -1 && fatorDeBalanceamento(raiz->right) <= 0)
        raiz = rotacaoEsquerda(raiz);

    // Rotação à direita
    else if (fb > 1 && fatorDeBalanceamento(raiz->left) >= 0)
        raiz = rotacaoDireita(raiz);

    // Rotação dupla à esquerda
    else if (fb > 1 && fatorDeBalanceamento(raiz->left) < 0)
        raiz = rotacaoEsquerdaDireita(raiz);

    // Rotação dupla à direita
    else if (fb < -1 && fatorDeBalanceamento(raiz->right) > 0)
        raiz = rotacaoDireitaEsquerda(raiz);

    return raiz;
}

/*
    Função para remover um nó da Árvore binária balanceada
    Pode ser necessário rebalancear a árvore e a raiz pode ser alterada, por isso precisamos retornar a raiz
*/
No *remover(No *raiz, int chave)
{
    if (raiz == NULL)
    {
        cout << "Valor nao encontrado!"
             << endl;
        return NULL;
    }
    else
    { // procura o nó a remover
        if (raiz->valor == chave)
        {
            // remove nós folhas (nós sem filhos)
            if (raiz->left == NULL && raiz->right == NULL)
            {
                free(raiz);
                cout << "Elemento folha removido: "
                     << chave << endl;
                return NULL;
            }
            else
            {
                // remover nós que possuem 2 filhos
                if (raiz->left != NULL && raiz->right != NULL)
                {
                    No *aux = raiz->left;
                    while (aux->right != NULL)
                        aux = aux->right;
                    raiz->valor = aux->valor;
                    aux->valor = chave;
                    cout << "Elemento trocado: "
                         << chave << endl;
                    raiz->left = remover(raiz->left, chave);
                    return raiz;
                }
                else
                {
                    // remover nós que possuem apenas 1 filho
                    No *aux;
                    if (raiz->left != NULL)
                        aux = raiz->left;
                    else
                        aux = raiz->right;
                    free(raiz);
                    cout << "Elemento com 1 filho removido: "
                         << chave << endl;
                    return aux;
                }
            }
        }
        else
        {
            if (chave < raiz->valor)
                raiz->left = remover(raiz->left, chave);
            else
                raiz->right = remover(raiz->right, chave);
        }

        // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
        raiz->height = maior(alturaDoNo(raiz->left), alturaDoNo(raiz->right)) + 1;

        // verifica a necessidade de rebalancear a árvore
        raiz = balancear(raiz);

        return raiz;
    }
}

// Imprime a arvore
void imprimir(No *raiz, int nivel)
{
    int i;
    if (raiz)
    {
        imprimir(raiz->right, nivel + 1);
        cout << ""
             << endl;

        for (i = 0; i < nivel; i++)
        {
            cout << "  ";
        }

        cout << raiz->valor;
        imprimir(raiz->left, nivel + 1);
    }
}