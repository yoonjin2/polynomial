#include <stdio.h>
#include <stdlib.h>
#include "list.h"
// function that removes the item
element_t remove_item ( list * lst , node * element )
{	
	element_t val = { 0.0F , '\0' , 0.0F };
	if ( element == lst->front ) {
		return val;
		
	}	else if ( element == lst->rear ) {
		return val;
  } else if ( lst -> size == 0 ) {
	  return val;
  } else {
		node * x = element -> next;
		node * y = element -> prev;
        x -> prev = y;
		y -> next = x; 
		val = element -> key ;
    free ( element ) ;
    lst -> size -- ;
    }
	return val ;
}
element_t pop_item ( list * lst ) {
	element_t i = remove_item ( lst , lst -> rear -> prev ) ;
	return i;
}
