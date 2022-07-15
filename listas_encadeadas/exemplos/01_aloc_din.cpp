// Aloca��o Din�mica com Vari�veis Simples

#include <iostream>
using namespace std;

int main(void)
{

    // 1. Declaremos uma vari�vel (aloca��o est�tica)
    int x;
    // Declaremos dois ponteiros e inteiros
    int *p, *q;

    // Vamos guardar 10 em x
    x = 10;
    // Apontemos p para x
    p = &x;

    // Vamos agora, alocar dinamicamente um espa�o, usando q
    q = new int;

    // Vamos, finalmente, *copiar* o valor de p para q
    *q = *p;

    // Vamos imprimir os valores
    cout << "X: " << x << "   P: " << *p << "   Q: " << *q << endl;

    // 2. Agora vou somar 1 em x e subtrar 1 em q
    x = x + 1;
    *q = *q - 1;

    // Vamos imprimir os valores novamente
    cout << "X: " << x << "   P: " << *p << "   Q: " << *q << endl;

    // Observe que o valor de X e P aumentaram em 1... mas o de Q diminuiu
    // Isso ocorre porque o valor Q est� em uma posi��o de mem�ria diferente!

    // 3. Vamos, agora, *liberar* o espa�o usado para Q
    delete q;

    // � responsabilidade do programador liberar *toda* a mem�ria que ele
    // alocar dinamicamente!

    // Observe que o valor *q agora � indefinido... para deixar isso claro,
    // costumamos armazenar o valor NULL em ponteiros que n�o apontam nada
    q = NULL;
}
