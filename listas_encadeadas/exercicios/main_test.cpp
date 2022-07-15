#include <iostream>
using namespace std;

int main()
{

    int *p;
    // "p" armazena um endereco de memoria
    // Alocacao de memoria com o "new". "p" recebe uma instancia de "int"
    p = new int;
    //*p armazena o valor vinculado ao endereco "p"
    *p = 10;
    cout << "Aqui o p: " << p << endl;
    cout << "Aqui o *p: " << *p << endl;

    // desaloca o espaco na memoria antes ocupado por "p"
    delete p;

    return 0;
}