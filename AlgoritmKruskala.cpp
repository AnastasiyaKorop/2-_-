#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//Туториал 
//сначало пишешь количество вершин, потом количество ребер (2 цыфры)
//затем пишешь N строчек - их столько сколько ребер, где 1 и 2 это пометки ребра от вершины к другой вершине, а 3 число это вес ребра
typedef struct {
    int from;       // начальная вершина ребра
    int to;         // вершина
    double w;       // вес края
} edge_t;   

typedef struct set_t {
    struct set_t *p; // link on parent 
} set_t; 


int NS;      // количество комплектов
set_t *sets; // массив наборов
int NE;      // количество ребер
edge_t *E;   // массив ребер
int NV;      // количество ребер 2

// функция сравнения для сортировки ребер по весу
int cmpw(edge_t *a, edge_t *b)
{
    if(a->w > b->w ) return 1;
    if(a->w < b->w ) return -1;
    return 0;
}    

set_t*
get_set_id(set_t* s)
{
    if(s == s->p )
        return s;
    else {
        set_t *p = get_set_id(s->p);
        s->p = p; 
        return p;
    }    
} 

set_t*
join_sets(set_t *a, set_t *b)
{
    a->p = b;
    return a;
}    


void
take_edge(int edge_id)
{
    printf("%d %d %lf\n", E[edge_id].from, E[edge_id].to, E[edge_id].w);
}    

int
main()
{
    int i;
    double W = 0;
    scanf("%d%d", &NV, &NE);
    E = (edge_t*) malloc(NE * sizeof(edge_t));
    sets = (set_t*) malloc(NV * sizeof(set_t));
    for(i = 0; i < NE ; i++)
    {
        scanf("%d%d%lf", &E[i].from, &E[i].to, &E[i].w);
    } 
    
    // Сортировка ребер по весу
    qsort(E, NE, sizeof(edge_t), (int (*)(const void*, const void*)) cmpw);

    // Создание набор одноточечных наборов, тупо, но так
    NS = NV;
    for(i = 0; i < NS ; i++)
        sets[i].p = &sets[i];
    
    // Извлечение следующего ребра с минимальным весом
    for(i=0; NS > 1 && i < NE; i++)       
    {
        // если ребро не может быть добавлено к дереву, то переход к следующему ребру
        if ( get_set_id ( &sets[E[i].from]) == get_set_id ( &sets[E[i].to]) )
                continue;
        // добавление ребра к дереву
        join_sets ( get_set_id (&sets[E[i].from] ),  get_set_id ( &sets[E[i].to]) );
        NS--;
        take_edge(i);
        W += E[i].w;
    }

    if(NS != 1)
       fprintf(stderr, "warning: Graph is not connected.\n");
    printf("Covering tree weight = %lf\n", W);
}    
