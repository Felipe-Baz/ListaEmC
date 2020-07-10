/* Programa: Lab 1
   Autor: Felipe Baz Mitsuishi
   Versao: 1.0 - 05/09/2019
*/
// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
// ########################## TAD X.h ######################################
#define N 10
struct listaES
{
    int ultimo;
    int tamanhoLista;
    int lista[N];
};
typedef struct listaES tipoListaES;
void InicializaLista(tipoListaES *listaAux)
{
    listaAux->tamanhoLista = 0;
    int i;
    for (i = 0; i < N; i++)
    {
        listaAux->lista[i] = 0;
    }
    listaAux->ultimo = 0;
}
void insereElemento(tipoListaES *listaAux, int number)
{
    listaAux->tamanhoLista++;
    listaAux->lista[listaAux->tamanhoLista - 1] = number;
}
int buscaLista(tipoListaES *listaAux, int elemento)
{
    int i;
    for (i = 0; i < listaAux->tamanhoLista; i++)
    {
        if (listaAux->lista[i] == elemento)
        {
            return 1;
        }
    }
    return 0;
}
int buscaListapos(tipoListaES *listaAux, int elemento)
{
    int tamanho;
    tamanho = listaAux->tamanhoLista;
    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (listaAux->lista[i] == elemento)
        {
            return i;
        }
    }
}
// ###################### Funcoes e Procedimentos do programa ##############
int listaCheia(tipoListaES *listaAux)
{
    if (listaAux->tamanhoLista == N)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void removeElemento(tipoListaES *listaAux, int num)
{
    int pos, i;
    pos = buscaListapos(listaAux, num);
    listaAux->lista[pos] = 0;
    for (i = pos; i < listaAux->tamanhoLista; i++)
    {
        listaAux->lista[i] = listaAux->lista[i + 1];
    }
    listaAux->tamanhoLista--;
}
// ############################ Principal ###################################
int main()
{
    int moviments, escolha, book, i, retiradas = 0, reservados = 0;
    tipoListaES myList;
    InicializaLista(&myList);
    scanf("%d", &moviments);
    for (i = 0; i < moviments; i++)
    {
        scanf("%d %d", &escolha, &book);
        if (escolha == 1)
        {
            int resultado = listaCheia(&myList);
            if (resultado == 0)
            {
                insereElemento(&myList, book);
                printf("Sua reserva foi realizada\n");
                reservados++;
            }
            else
            {
                printf("Lista de reserva cheia\n");
            }
        }
        else if (escolha == 2)
        {
            int resp;
            resp = buscaLista(&myList, book);
            if (resp == 0)
            {
                printf("Voce nao possui reserva desse livro\n");
            }
            else if (resp == 1)
            {
                removeElemento(&myList, book);
                printf("O livro foi retirado com sucesso\n");
                retiradas++;
            }
        }
    }
    printf("Voce realizou %d reservas e %d retiradas\n", reservados, retiradas);
    return 0;
}
