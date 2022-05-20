#include <iostream>
using namespace std;
void Teste1(int);
void Teste2(int &);
int Teste3(int);
int x = 20;
int main(void)
{
    int numero = 10, outroNumero;
    Teste1(numero);
    cout << "Valor de numero (após Teste1) = " << numero << endl;
    cout << "X = " << x << endl;
    Teste2(numero);
    cout << "Valor de numero (após Teste2) = " << numero << endl;
    cout << "X = " << x << endl;
    outroNumero = Teste3(numero);
    cout << "Valor de outro numero (após Teste3) = " << outroNumero << endl;
    cout << "X = " << x << endl;
}
void Teste1(int numero)
{
    numero = numero + x;
    x++;
}
void Teste2(int &numero)
{
    int valor = 100;
    numero = numero + valor;
    x++;
}
int Teste3(int n)
{
    int valor = 200;
    n = n + valor;
    x--;
    return n;
}