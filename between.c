#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>
// add number between two nodes
void between( list * lst , element_t item , node * b , node * n ) {
    node * element ;
    if ( ( element = ( node * ) malloc ( sizeof ( node ) ) ) == NULL ) {
        return ;
	}
	if ( ( b != n -> prev ) ) {
		free( element );
		return ;
	}
    else {
        element -> key = item ;
        b -> next = element ;
        element -> prev = b;
        element -> next = n ;
	n -> prev = element ;
    	lst -> size ++ ;
    }
}
void push ( list * lst , element_t item ) {
	if ( lst -> size != 0 )	{
		if ( lst -> rear -> prev -> key.expo > item.expo ) {
			lst -> is_sorted = 0;
		} 
	}	
	between ( lst , item , lst -> rear -> prev , lst -> rear ) ;
}
void push_list ( list * lst , list * lst_target ) {
	node * nd;
	for ( nd = lst_target -> front -> next ; nd != lst_target -> rear ; nd = nd -> next ) {
		push ( lst , nd -> key );
	}
}
void regen_sorted ( list * lst ) {
	node * p;
	for ( p = lst -> front -> next; p != lst -> rear; p = p -> next ) {
		if ( p -> key.expo > p -> next -> key.expo ) {
			lst -> is_sorted = 0 ;
			return ;
		}
	}
	lst -> is_sorted = 1;
}
