#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


int main (int argc, char **argv ) {
	
	pila a=NULL;
	int i,d;
	
	a = p_nueva ( sizeof ( int ));
	if ( p_vacia ( a ) ) printf ( "La pila esta vacia.\n" );
	else {
		printf ( "La pila no se creo adecuadamente.\n" );
		exit ( 1 );
	}
	
	printf ( "Insercion de 10 elementos en la pila.\n" );
	for ( i=10; i>0; i-- ) {
		p_insertar ( a, &i );
	}
	
	printf ( "Sacamos cinco elementos de la pila.\n");
	for ( i=1; i<=5; i++ ) {
		p_eliminar ( a, &d );
		printf ( "El elemento %d estaba contenido en la pila.\n", d );
	}
	
	printf ( "Liberamos los recursos ocupados por la pila.\n" );
	p_destruir ( &a );
	
	return 0;
}

