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
    pbuffer = realloc (pbuffer, (20 + sizeof (int))* 3 + (sizeof (struct pessoa)) * (*n));
    i = (int*) pbuffer;
    a = i + 1;
    n = a + 1;
    p = (struct pessoa*) n + (*n);
    puts ("diga nome e idade: ");
    scanf ("%s", (p->nome));
    scanf ("%d", &(p->idade));
}
void exclui (struct pessoa *p){
    p = (struct pessoa*) n + 1;
    for (*i = 0; *i < *n; (*i)++, p++){
        if (p->idade == *a){
            for(*a = *i; *a < ((*n) - 1); (*a)++){
              *p = *(p+1);
              p++;
            }
            (*n)--;
            pbuffer = realloc (pbuffer, (20 + sizeof (int))* 3 + (sizeof (struct pessoa)) * (*n));
            return;
        }
    }
    puts ("\npessoa inexistente na agenda\n");
}
void busca (struct pessoa *p){
    p = (struct pessoa*) n + 1;
    for (*i = 0; *i < (*n); (*i)++, p++){
        if (p->idade == *a){
            printf ("\n%s encontrad@!\n", p->nome);
            return;
        }
    }
    printf ("\nnao encontrad@!");
}
void lista (struct pessoa *p){
    p = (struct pessoa*) n + 1;
    if (*n == 0){
        puts ("agenda vazia\n");
        return;
    }
    for (*i = 0; *i < (*n); (*i)++){
        printf ("nome: %s", p->nome);
        printf ("\tidade: %d\n", p->idade);
        p++;
    }
}
int main (){
    struct pessoa *p;
    char *aux;
    pbuffer = malloc ((sizeof (int)) * 3);
    if (pbuffer == NULL) printf ("erro ao alocar!");
    i = (int*) pbuffer;
    a = i + 1;
    n = a + 1;
    *a = 2000;
    *n = 0;
    while (*a != 1000){
        printf ("1.add   2.exclui   3.lista   4.busca   1000.sair\nescolha: ");
        scanf("%d", a);
        switch (*a){
        case 1:
            adiciona(p);
            break;
        case 2:
            puts ("idade da pessoa: ");
            scanf ("%d", a);
            exclui(p);
            break;
        case 3:
            lista(p);
            break;
        case 4:
            puts ("idade da pessoa: ");
            scanf ("%d", a);
            busca(p);
            break;
        case 1000:
            free(pbuffer);
            exit(1);
            break;
        default:
            puts("\n???\n");
            break;
        }
    }
}