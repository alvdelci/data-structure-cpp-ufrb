// Alocação Dinâmica com Variáveis Estruturas

#include <iostream>
using namespace std;

struct aluno {
    int matricula;
    float media;
};

int main(void) {

    // 1. Declaremos uma variável (alocação estática)
    aluno a;
    // Declaremos dois ponteiros para aluno
    aluno *p, *q;

    // Vamos guardar valores na estrutura aluno
    a.matricula = 10989;
    a.media = 9.5;
    // Apontemos p para a
    p = &a;

    // Vamos agora, alocar dinamicamente um espaço, usando q
    q = new aluno;

    // Vamos, finalmente, *copiar* o valor de p para q
    *q = *p;

    // Vamos imprimir os valores
    cout << "a.mat: " << a.matricula  << endl;
    cout << "a.media: " << a.media << endl;
    cout << "p->mat: " << p->matricula  << endl;
    cout << "p->media: " << p->media << endl;
    cout << "q->mat: " << q->matricula  << endl;
    cout << "q->media: " << q->media << endl;

    // 2. Agora vamos mudar o aluno Q
    q->matricula = 20895;
    q->media = 8.9;

    // Vamos imprimir os valores
    cout << "a.mat: " << a.matricula  << endl;
    cout << "a.media: " << a.media << endl;
    cout << "p->mat: " << p->matricula  << endl;
    cout << "p->media: " << p->media << endl;
    cout << "q->mat: " << q->matricula  << endl;
    cout << "q->media: " << q->media << endl;

    // 3. Vamos, agora, *liberar* o espaço usado para Q
    delete q;

    // É responsabilidade do programador liberar *toda* a memória que ele
    // alocar dinamicamente!

    // Observe que o valor *q agora é indefinido... para deixar isso claro,
    // costumamos armazenar o valor NULL em ponteiros que não apontam nada
    q = NULL;

}

