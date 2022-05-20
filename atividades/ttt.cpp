#include <iostream>
using namespace std;

void Teste1(int);
void Teste2(int &);
int Teste3(int);

int x = 20; // Variavel global

int main(void)
{
    int numero = 10, outroNumero; // Variaveis locais de main
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
    int valor = 100; // Variavel local de teste2
    numero = numero + valor;
    x++;
}
int Teste3(int n)
{
    int valor = 200; // Variavel local de teste3
    n = n + valor;
    x--;
    return n;
}

// Declarando os vetores
int A[10], B[10], C[20];

// Lendo o primeiro vetor
printf("=>VETOR A\n");
for (int i = 0; i < 10; ++i)
{
    printf("A[%i]: ", i);
    scanf("%d", &A[i]);
    C[i] = A[i];
}

// Lendo o segundo vetor
printf("\n=>VETOR B\n");
for (int i = 0; i < 10; ++i)
{
    printf("B[%i]: ", i);
    scanf("%d", &B[i]);
    C[10 + i] = B[i];
}

// Exibindo a concatenanção do vetor A e B
printf("\n=>CONCATENACAO DE A e B\n");
for (int i = 0; i < 20; ++i)
{
    printf("C[%i]: %d\n", i, C[i]);
}

system("pause");
}