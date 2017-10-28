//Thaina Pires
//Cefet-RJ
//Monitora de estrutura de dados

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<conio.h>

using namespace std;

struct no{
    struct no*ant;
    int info;
    struct no*prox;
};

typedef struct no* noPtr;
noPtr inicio = NULL;

int menu();
void apagarLista();
void retirarnofinal();
void retirarnocomeco();
void retirar();
void listar();
void inserirnofinal();
void inserirnocomeco();
void consultar();
void inserirdecres();
bool listaVazia();

int main(){
    int op;
    do {
        op = menu();
        switch (op) {
            case 1: inserirnocomeco(); break;
            case 2: inserirnofinal(); break;
            case 3: inserirdecres(); break;
            case 4: retirar(); break;
            case 5: retirarnocomeco(); break;
            case 6: retirarnofinal(); break;
            case 7: listar(); break;
            case 8: consultar(); break;
            case 9: apagarLista(); break;
        }
    } while (op != 0);
}

int menu(){
    int opcao;
    cout<< "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout<< "*                  Lista duplamente encadeada                     *\n";
    cout<< "*                                                                 *\n";
    cout<< "*                    1: Inserir no comeco                         *\n";
    cout<< "*                    2: Inserir no final                          *\n";
    cout<< "*                    3: Inserir decrescente                       *\n";
    cout<< "*                    4: Retirar elemento especifico               *\n";
    cout<< "*                    5: Retirar no comeco                         *\n";
    cout<< "*                    6: Retirar no final                          *\n";
    cout<< "*                    7: Listar elementos                          *\n";
    cout<< "*                    8: Consultar elementos                       *\n";
    cout<< "*                    9: Apagar lista                              *\n";
    cout<< "*                    0: Sair                                      *\n";
    cout<< "*                                                                 *\n";
    cout<< "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "\n\t\tDigite a opcao (0 - 8): ";
    cin >> opcao;
    return opcao;
}

void apagarLista(){
    system("cls");
    noPtr aux, p = inicio;
    while (p != NULL){
        aux = p;
        p = p -> prox;
        delete aux;
    }
    inicio = NULL;
    cout << "\n\t\t\t   LISTA DELETADA!\n" << endl;
}

bool listaVazia (){
    if (inicio)
        return false;
    else
        return true;
}

//Listar elementos
void listar(){
    noPtr p;
    p = inicio;
    if (!listaVazia()){
        system("cls");
        cout << "\nOs elementos da lista sao:\n" << endl;
        cout<<"Inicio->";
        while (p != NULL){
            cout << p->info<<"->";
            p = p -> prox;
        }
        cout<<"NULL"<<endl;
        fflush(stdin);
        cout<<"\nClique em qualquer tecla para voltar ao menu";
        getch();
        system("cls");
    }
    else{
        system("cls");
        cout << "\n\t\t\t   LISTA VAZIA!\n" << endl;
    }
}

//Consultar elemento na lista
void consultar(){
    noPtr p = inicio;
    int x;
    bool achei = false;
    if(!listaVazia()){
        cout <<"\n Digite o elemento que voce quer encontrar: ";
        cin>>x;
        system("cls");
        cout <<"\nCONSULTA DE ELEMENTO"<<endl;
        while(p!=NULL && achei == false){
            if(p->info == x){
                cout <<"\nElemento "<<p->info<<" possui endereco "<<p<<endl;
                achei = true;
            }
            p = p->prox;
        }
        if(achei){
            fflush(stdin);
            cout<<"\nClique em qualquer tecla para voltar ao menu";
            getch();
            system("cls");
        }

        if(!achei){
            cout << "\n\t\t   ELEMENTO NAO ENCONTRADO!\n" << endl;
        }
    }
    else{
        system("cls");
        cout << "\n\t\t\t   LISTA VAZIA!\n" << endl;
    }
}

//Inserir no final da lista
void inserirnofinal(){
    noPtr p, aux = inicio;
    int valor;
    p = new no;
    cout <<"\nDigite o elemento que voce deseja inserir: ";
    cin >> valor;
    system("cls");
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
    cout << "\n\t\t\tELEMENTO INSERIDO!\n" << endl;
}

void inserirnocomeco(){
    noPtr p, aux = inicio;
    int valor;
    p = new no;
    cout <<"\nDigite o elemento que voce deseja inserir: ";
    cin >> valor;
    system("cls");
    p->info = valor;
    p->prox = NULL;
    p->ant = NULL;
    if(listaVazia()){
        inicio = p;
    }
    else{
        inicio = p;
        inicio->prox = aux;
        aux->ant = inicio;
    }
    cout << "\n\t\t\tELEMENTO INSERIDO!\n" << endl;
}


//Retirar em qualquer lugar da lista
void retirar(){

    noPtr p = inicio;
    int valor;
    bool achei = false;

    if(listaVazia()){
        system("cls");
        cout << "\n\t\t\t   LISTA VAZIA!\n" << endl;
    }
    else {
        cout <<"\n Digite o valor a ser retirado: ";
        cin>>valor;
        system("cls");
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
            if(!achei){
                cout << "\n\t\t   ELEMENTO NAO ENCONTRADO!\n" << endl;
            }else{
                cout << "\n\t\t\tELEMENTO RETIRADO!\n" << endl;
            }
        }
    }
}

//Retirar no final
void retirarnofinal(){
    noPtr p = inicio;
    if(listaVazia()){
        system("cls");
        cout << "\n\t\t\t   LISTA VAZIA!\n" << endl;
    }
    else{
        system("cls");
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
        cout << "\n\t\t\tELEMENTO RETIRADO!\n" << endl;
    }
}

void retirarnocomeco(){
    noPtr p = inicio, aux;
    if(listaVazia()){
        system("cls");
        cout << "\n\t\t\t   LISTA VAZIA!\n" << endl;
    }
    else{
        system("cls");
        aux = inicio->prox;
        delete p;
        inicio = aux;
        aux->ant = NULL;
        cout << "\n\t\t\tELEMENTO RETIRADO!\n" << endl;
    }
}

//Inserir descrescente
void inserirdecres(){
    noPtr aux, p, anterior;
    int x;
    p = new no;
    cout<<"\nInsira o valor a ser inserido decrescentemente: ";
    cin>>x;
    system("cls");
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
    cout << "\n\t\t\tELEMENTO INSERIDO!\n" << endl;
}

