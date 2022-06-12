#include <iostream>
using namespace std;

#define MAX 10

int enfileirar(int v[], int &fim, int &num, int valor);
int desenfileirar(int v[], int &ini, int fim, int &num, int &valor);

int main(void) {
    // Declara a fila
    int fila[MAX];
    int ini = 0;
    int fim = -1;
    int nfila = 0;

    // Variável para armazenar dado digitado
    int dado, dado2, input;
    // Variável que indica se acabaram valores da fila
    int vazia;

    // Lê valores e os enfileira, se forem >= 0
    do {
        cout <<"MENU"<<endl<<"1 - Enfileirar Positivo"<<endl<<"2 - Desenfileirar Valor"<<endl<<"3 - Desenfileirar Tudo"<<endl<<"4 - Sair"<<endl;
        cin >> input;
        switch(input) {
            case 1:
                //Enfileirar aqui
                do{
                    cout<<"Insira valores POSITIVOS ou -1 para sair: ";
                    cin >> dado;
                    
                    if(dado >= 0) {
                        enfileirar(fila, fim, nfila, dado);
                    }
                }while(dado >= 0);
                cout<<input;
                break;
            case 2:
                //desenfileirar
                do {
                    cout<<"Insira 1 para DESENFILEIRAR ou 0 para SAIR: ";
                    cin >>dado2;
                    
                    if(dado2 == 1) {
                        vazia = desenfileirar(fila, ini, fim, nfila, dado2);
                        if(vazia == 0) {
                            cout<<"Dobro do numero desenfileirado"<<endl;
                            cout<<dado2*2<<endl;
                        }
                    }
                } while(dado2 != 0);
                cout<<input;
                break;
                
            case 3:
                //Desenfileirar tudo
                cout<<"Valores Desenfileirados"<<endl;
                do {
                    vazia = desenfileirar(fila, ini, fim, nfila, dado);
                    if (vazia == 0) {
                        cout << dado << endl;
                    }
                }while(vazia == 0);
                
                break;
            
            default:
                cout<<"Opção inválida"<<endl;
        }
        
    }while(input != 4);
    return 0;
}

// Enfileirar
int enfileirar(int v[], int &fim, int &num, int valor) {
    
    if(num == MAX) {
        cout<<"Lista Cheia"<<endl;
        return 1;
    }
    
    fim++;
    if(fim == MAX) {
        fim = fim - MAX;
    }
    
    v[fim] = valor;
    num++;
    
    return 0;
}

//Desenfileirar
int desenfileirar(int v[], int &ini, int fim, int &num, int &valor) {
    if(num == 0) {
        cout<<"Lista vazia"<<endl;
        return 1;
    }
    
    valor = v[ini];
    ini++;
    if(ini >= MAX) {
        ini = ini - MAX;   
    }
    num--;
    return 0;
}