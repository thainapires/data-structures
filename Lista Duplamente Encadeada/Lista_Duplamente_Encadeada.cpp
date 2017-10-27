//Thaina Pires
//Cefet-RJ
//Monitora de estrutura de dados

#include <iostream>
#include <stdlib.h>

using namespace std;

struct no{
    struct no*ant;
    int info;
    struct no*prox;
};

typedef struct no* noPtr;
noPtr inicio = NULL;

int menu();
void retirarnofinal();
void retirar();
void listar();
void inserirnofinal();
void consultar();
void inserirdecres();
bool listaVazia();

int main(){
    int op;
    do {
        op = menu();
        switch (op) {
            case 1: listar(); break;
            case 2: consultar(); break;
            case 3: inserirnofinal(); break;
            case 4: retirar(); break;
            case 5: retirarnofinal(); break;
            case 6: inserirdecres(); break;
        }
    } while (op != 0);
}

int menu(){
    int opcao;
    cout << "\n1: Listar elementos" << endl;
    cout << "2: Consultar elementos" << endl;
    cout << "3: Inserir no final" << endl;
    cout << "4: Retirar" << endl;
    cout << "5: Retirar no final " << endl;
    cout << "6: Inserir de forma Descrecente" << endl;
    cout << "0: Sair" << endl;
    cout << "\nDigite a opcao (0 - 6): ";
    cin >> opcao;
    return opcao;
}

bool listaVazia ()
{
    if (inicio)
    return false;
    else
    return true;
}

//Listar elementos
void listar(){
    noPtr p;
    p = inicio;
    if (!listaVazia())
    {
        cout << "\nOs elementos da lista sao:" << endl;
        while (p != NULL){
        cout << p->info << endl;
        p = p -> prox;
        }
    }
    else cout << "\nLista Vazia!" << endl;

}

//Consultar elemento na lista
void consultar(){
    noPtr p = inicio;
    int x;
    bool achei = false;
    if(!listaVazia()){
        cout <<"\n Digite o elemento que você quer encontrar: ";
        cin>>x;
        while(p!=NULL && achei == false){
            if(p->info == x){
                cout <<"Elemento"<<p->info<<"possui endereco"<<p;
                achei = true;
            }
            p = p->prox;
        }
        if(!achei){
        cout <<"\nNao foi encontrado";
     }
    }
    else{
        cout<<"Lista Vazia";
    }
}

//Inserir no final da lista
void inserirnofinal(){
    noPtr p, aux = inicio;
    int valor;
    p = new no;
    cout <<"Digite o elemento que você quer inserir: ";
    cin >> valor;
    p->info = valor;
    p->prox = NULL;
    p->ant = NULL;
    if(listaVazia()){
        inicio = p;
    }
    else{
           while(aux->prox != NULL){
                aux = aux->prox;
           }
           aux->prox = p;
           p->ant = aux;
    }
}


//Retirar em qualquer lugar da lista
void retirar(){

    noPtr p = inicio;
    int valor;
    bool achei = false;

    if(listaVazia()){
        cout<<"\n Lista Vazia";
    }
    else {
        cout <<"\n Digite o valor a ser retirado: ";
        cin>>valor;
        if(p->info == valor){
            if(p->prox != NULL){
            inicio = inicio->prox;
            inicio->ant = NULL;
            delete p;
            achei = true;
            }
            else{
            inicio = NULL;
            delete p;
            achei = true;
            }
        }
        else{
            while(p!=NULL && achei == false){
                    if(p->info == valor){
                            if(p->prox == NULL){
                                p->ant->prox = NULL;
                                p->ant = NULL;
                                delete p;
                                achei = true;
                            }
                            else{
                                p->ant->prox = p->prox;
                                p->prox->ant = p->ant;
                                delete p;
                                achei = true;
                            }
                    }
                    p = p->prox;
            }
            if(!achei)
                cout<<"Não encontrado";
        }
    }
}

//Retirar no final
void retirarnofinal(){
    noPtr p = inicio;
    if(listaVazia()){
        cout<<"\n Lista Vazia";
    }
    else{
            while(p->prox != NULL){
                p = p->prox;
            }
            if(inicio->prox == NULL){
                inicio = NULL;
                delete p;
            }
            else{
            p->ant->prox = NULL;
            p->ant = NULL;
            delete p;
            }
    }
}

//Inserir descrescente
void inserirdecres(){
    noPtr aux, p, anterior;
    int x;
    p = new no;
    cout<<"\nInsira o valor a ser inserido decrescentemente: ";
    cin>>x;
    p->info = x;
    p->ant = NULL;
    p->prox = NULL;
    if(inicio == NULL){
        inicio = p;

    }
    else{
        anterior = NULL;
        aux = inicio;
        if(aux->info < x){
            inicio = p;
            p->prox = aux;
            aux->ant = p;
        }
        else{
            while (aux != NULL && aux->info > x){
                anterior = aux;
                aux = aux->prox;
            }
            if( aux == NULL){
                anterior->prox = p;
                p->ant= anterior;
            }
            else{
                p->prox = aux;
                aux->ant = p;
                p->ant= anterior;
                anterior->prox = p;
            }
        }
    }
}
