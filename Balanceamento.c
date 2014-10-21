#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Lista{
    char c;
    struct Lista * proximo;
}lista;
lista* criar_lista()
{
    return NULL;
}
lista* enfileirar(lista * p,char d)
{
    lista* q=(lista*)malloc(sizeof(lista));
    q->c=d;
    q->proximo=p;
    return q;
}
lista* apagar(lista* p,char d)
{
    lista * anterior=NULL;
    lista * atual=p;
    while (atual != NULL && atual->c != d) {
    anterior = atual;
    atual = atual->proximo;
    }
    if (atual == NULL) {
    return p;
    }
    if (anterior == NULL) {
    p = atual->proximo;
    } else {
    anterior->proximo = atual->proximo;
    }
    free(atual);
return p;
}
void imprimir(lista *first) {
    lista *p;
    for(p = first; p != NULL; p = p->proximo) {
    printf("%c\n", p->c);
    }
}
int contar(lista *first) {
    lista *p;
    int contador=0;
    for(p = first; p != NULL; p = p->proximo)
        contador++;
        return contador;

}
int busca(lista *q, char c){
    lista*p;
    for (p = q; p != NULL; p = p->proximo)
    {
        if (p->c == c)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int contador=0,i,n,size;
    char a[260];
    scanf("%d",&n);
    getchar();
    while(contador!=n)
    {
        lista*p;
        gets(a);
        size=strlen(a);
        p=criar_lista();
        for(i=0;i<size;i++)
        {
            if(a[i] != ' ')
                p=enfileirar(p,a[i]);
        }
        size=contar(p);
        for(i=0;i<size/2;i++)
        {
            if(p->c == ')')
            {
                 if(busca(p,'('))
                 {
                     p=apagar(p,')');
                     p=apagar(p,'(');
                 }
             }
           else if(p->c == ']')
            {
                 if(busca(p,'['))
                 {
                     p=apagar(p,']');
                     p=apagar(p,'[');
                 }
             }


        }
        if(contar(p) == 0)
            printf("Yes\n");
        else
            printf("No\n");
        contador++;
    }
}
