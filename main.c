#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 1000

typedef int TipoApontador;
typedef struct
{
int num;

} TipoItem;
typedef struct
{

TipoItem Item[MAXTAM];
TipoApontador Topo;
} TipoPilha;


void FPVazia(TipoPilha *Pilha){ Pilha -> Topo = 0; }

int Vazia(TipoPilha Pilha){ 
   return ( Pilha .Topo == 0); }

void Empilha(TipoItem x, TipoPilha *Pilha){ 
    if ( Pilha -> Topo == MAXTAM) printf ( "Erro : pilha esta cheia\n" );
    else { Pilha -> Topo++; 
    Pilha -> Item[Pilha -> Topo - 1] = x ; }

}
void Desempilha(TipoPilha *Pilha , TipoItem *Item){ 
if (Vazia(*Pilha )) printf ( "Erro : pilha esta vazia\n" );
else{ 
*Item = Pilha->Item[Pilha->Topo- 1]; 
Pilha->Topo --; 
}
}

void Imprime_baixoCima (TipoPilha *Pilha){
    int i;
    if (Vazia(*Pilha)) {
        printf("A pilha está vazia!\n");
    }else{
    for (i = 0; i < Pilha->Topo; i++) {
        printf("%d\n",Pilha->Item[i].num);

    }
    }
}

void Imprime_cimaBaixo (TipoPilha *Pilha){
    int i;
    if (Vazia(*Pilha)) {
        printf("A pilha está vazia!\n");
    }else{

    for (i = Pilha->Topo-1; i >= 0; i--) {
        printf("%d\n",Pilha->Item[i].num);

    }
    }
}


int main(int argc, char** argv) {
    int menu = 0;
    TipoPilha pilhaN;
    TipoItem Numero;
    
    while (menu != 56) {
    printf("======MENU=========\n");
    
    printf("1 - Cria Pilha\n");
    printf("2 - Empilha\n");
    printf("3 - Desempilha\n");
    printf("4 - Imprime de baixo pra cima Pilha\n");
    printf("5 - Imprime de cima pra baixo Pilha\n");
    printf("56 - Sai do progama\n");
    scanf("%d",&menu);
    
    switch(menu){
        case 1:
            FPVazia(&pilhaN);
            printf("Pilha criada =D\n\n");
            break;
            
        case 2:
            printf("Qual numero deseja empilhar?\n");
            scanf("%d", &Numero.num);
            Empilha(Numero,&pilhaN);
            printf("Numero Empilhado! =D\n\n");
            break;
            
        case 3:
            Desempilha(&pilhaN, &Numero);
            printf("Item removido da pilha =D\n\n");
            
            break;
            
        case 4:
            printf("===PILHA===\n\n");
            Imprime_baixoCima(&pilhaN);
            break;
            
        case 5:
            printf("===PILHA===\n\n");
            Imprime_cimaBaixo(&pilhaN);
            break;
                
            
    
    
    }
    }
    return (EXIT_SUCCESS);
}

