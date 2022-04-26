#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

#include <string.h>

char *strrem(char *orig, char *tok) {
  size_t len = strlen(tok);
  char *ptr = orig;
  while ((ptr = strstr(ptr, tok)) != NULL) {
      memmove(ptr, ptr + len, strlen(ptr + len) + 1);
  }
  return orig;
}
int main(int argc, char ** argv) { 
  list *lst =(list *) malloc ( sizeof ( list ));
	init_list (lst);
	int idx=1;
	for (idx = 1 ; idx < argc-1 ; idx ++) {
	  char *orig = argv[idx];
		int coef=0 , expo=0;
		char var;
		while(true) {
		  coef=0 ;
			expo=0;
			if (orig[0] =='+') {
				memmove(orig , orig+1 , strlen(orig+1)+1);
			}
		  sscanf(orig , "%d%c^%d" , &coef , &var , &expo );
			char * str = (char *)malloc (sizeof(char)*100);
		  	char * cache = (char *)malloc(sizeof(char)*100);
			sprintf (cache,"%d" , coef);
			strcat (str,cache);
		        str[strlen(str)]=var;
			str[strlen(str)]='^';
			sprintf (cache,"%d" , expo);
			strcat(str,cache);
			orig=strrem(orig,str);
			element_t value = {coef, var , expo };
			push ( lst , value );
			if (!strlen(orig)) {
		    break;
			}
		}

	}

	beautify (lst);
	sort_func(lst);
	show(lst);
	   char * str = argv[argc-1];
	   printf("str=%s\n",str);
	   char ch , tail ; int change;
	   while (strlen(str)>0) {
	  	sscanf(str , "%c=%d%c" ,&ch,&change , &tail);
	        char cut[50];
		sprintf (cut,"%c=%d%c" , ch , change , tail );
		str = strrem ( str , cut);
	  	
	  	node * nd ;
	  	for (nd = lst->front->next ; nd != lst -> rear ; nd=nd->next) {
	  		if ( nd->key.var == (int)ch ) {
	  			nd->key.var=change;	
	  		}
	  	}
	  }
  node * nd ;
  int result=0;
  for (nd = lst->front->next ; nd != lst -> rear ; nd =nd ->next) {
		result+=nd->key.coef*(int)(pow(nd->key.var,nd->key.expo));
   }

	printf("result is : %d\n" , result);
}

