#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct pessoa{
    int idade;
    char nome[20];
};

int *i, *a, *n;
//i: contador pra laços
//a: menu
//n: numero de pessoas
void *pbuffer = NULL;

void adiciona (struct pessoa *p){
    (*n)++;
    pbuffer = realloc (pbuffer, (sizeof (int))* 3 + (sizeof (struct pessoa)) * (*n));
    i = (int*) pbuffer;
    a = i + 1;
    n = a + 1;
    p = (struct pessoa*) n + (*n);
    puts ("diga nome e idade: ");
    scanf ("%s", (p->nome));
    scanf ("%d", &(p->idade));
}

void lista (struct pessoa *p){
    p = (struct pessoa*) n + 1;
    for (*i = 0; *i < *n; (*i)++){
        printf ("nome: %s", p->nome);
        printf ("\tidade: %d\n", p->idade);
        p++;
    }
}

int main (){
    struct pessoa *p;
    pbuffer = malloc ((sizeof (int)) * 3);
    i = (int*) pbuffer;
    a = i + 1;
    n = a + 1;
    *a = 2000;
    *n = 0;
    while (*a != 0){
        printf ("1.add\t2.lista\t0.sair\na: ");
        scanf("%d", a);
        switch (*a){
        case 1:
            adiciona(p);
            break;
        case 2:
            lista(p);
            break;
        default:
            break;
        }
    }
}