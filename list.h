#include <stdio.h>
#define NUM 1000000
#define LIM 1000000
typedef long long ll;
typedef struct element_t {
	int coef;
	int var;
  	int expo;
} element_t;

typedef struct node {
  element_t key;
	struct node * prev;
	struct node * next;
} node;

typedef struct list {
	node *front;
	node *rear;
	ll size; 
	_Bool is_sorted;
} list;

void init_list ( list * lst );
void reset_list ( list * lst );
void between  ( list * lst , element_t item , node * r , node * element ) ;
void regen_sorted ( list * lst );
void push ( list * lst , element_t item ) ;
void push_list ( list * lst , list * lst_target ) ;

element_t remove_item ( list * lst , node * element ) ;
element_t pop_item ( list * lst ) ;
ll size ( list *lst ) ;

void repair_size ( list *lst ) ;
_Bool empty ( list * lst ) ;
void show ( list * lst ) ;
void free_list ( list * lst ) ;
void empty_list ( list * lst ) ;
node * find ( list * lst , element_t key ) ;
node * index_node ( list * lst , ll i ) ;

void sort_func ( list * lst ) ;
void sortthree ( list * lst ) ;
void bubble_sort ( list * lst );
void beautify(list *lst) ;
void swap ( element_t * a, element_t * b ); 
