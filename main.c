#include <stdio.h>
#include <stdlib.h>

#define INICIOARRANJO 0
#define MAXTAM 1000 //definir o tamanho max

typedef int TipoApontador;

typedef struct
{
    int mat;
    char nome[90];
    char cargo[50];
    float salario;

} Funcionario;
typedef struct
{

Funcionario Item[MAXTAM];
TipoApontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista)

{ Lista->Primeiro = INICIOARRANJO;  Lista->Ultimo = Lista->Primeiro ; }

////////////////////////

int Vazia(TipoLista Lista)
{ return ( Lista.Primeiro == Lista.Ultimo ) ; 
}

void Insere(Funcionario x, TipoLista *Lista){
    
if ( Lista -> Ultimo > MAXTAM){
printf ( "Lista esta cheia\n" );
}else {
Lista -> Item[ Lista->Ultimo] = x;
Lista -> Ultimo++;
}

}

void Imprime(TipoLista Lista){
    if(Vazia(Lista)){
        printf(">>>A fila está vazia!<<<\n\n\n");
    }else{
 int Aux;
 for (Aux = Lista.Primeiro; Aux <= (Lista.Ultimo - 1); Aux++){
printf ( "MATRICULA: %d\n" , Lista.Item[Aux].mat);
printf ( "NOME: %s\n" , Lista.Item[Aux].nome);
printf ( "CARGO: %s\n" , Lista.Item[Aux].cargo);
printf ( "SALARIO:R$%.2f\n\n\n" , Lista.Item[Aux].salario);
 }
}
}

void Retira(TipoApontador p, TipoLista *Lista , Funcionario *Item){ 
int Aux;
if (Vazia(*Lista ) || p >= Lista -> Ultimo){ 
    printf ( "Erro : Posicao nao existe \n" );
    return;
}

*Item = Lista -> Item[p];

Lista -> Ultimo--;
for (Aux = p; Aux < Lista -> Ultimo ; Aux++){
Lista -> Item[Aux] = Lista -> Item[Aux] ;
}

}

int main(int argc, char** argv) {
    int menu = 0;
    int reg = 1;
    //int i = 0;
    Funcionario ref;
    TipoLista listaN;
    
    
    
    
    while (menu != 56) {

        printf("/******************/\n"
           "********MENU*******\n"
           "/******************/\n");
    printf("1 - Cria Lista\n");
    printf("2 - Insere Lista\n");
    printf("3 - Imprime Lista\n");
    printf("4 - Remove elementoo Lista\n");
    printf("56 - Sai do progama\n");
        
    printf("Insira a opção desejada:");
    scanf("%d",&menu);
    
    switch (menu)
{
   case 1:
       FLVazia(&listaN);
       printf("\n\nLISTA CRIADA!\n\n");
   break;

   case 2:
       ref.mat = reg;
       printf("Insira o nome do funcionario\n");
       scanf("%s",&ref.nome);
       printf("Insira o cargo do funcionario\n");
       scanf("%s",&ref.cargo);
       printf("Insira o salario do funcionario\n");
       scanf("%f",&ref.salario);    
       Insere(ref,&listaN);
       reg++; 
   break;
   
    case 3:
        Imprime(listaN);
        break;    
        
        case 4:
            int diresq = 0;
                Retira (listaN.Primeiro,&listaN,&ref); //não está funcionando ainda
                printf("Elemento Removido!\n\n");      
        break;
   
        case 56:
            printf("Tchau\n");
            break;

        default:
           printf("opção invalida");
}
    //i++;
    
    }
    return (EXIT_SUCCESS);
}
