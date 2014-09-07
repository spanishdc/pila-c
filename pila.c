
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pila.h"

struct p_elemento {
	void *val;
	struct p_elemento *sig;
};

struct tip_pila {
	int tamanyo;
	struct p_elemento *p;
};

pila p_nueva ( int tamanyo ) {
	struct tip_pila *nueva;
	
	nueva = (struct tip_pila *) malloc ( sizeof ( struct tip_pila ));
	if ( !nueva ) {
		fprintf ( stderr, "p_nueva: no hay memora suficiente.\n" );
		exit ( 1 );
	}
	
	nueva->tamanyo = tamanyo;
	nueva->p = NULL;
	
	return nueva;
}

int p_vacia ( pila p ) {
	
	if ( !p ) {
		fprintf ( stderr, "p_vacia: la pila no existe\n" );
		exit ( 1 );
	}
	return (((struct tip_pila *)p)->p==NULL);
}

void p_insertar ( pila p, void *e ) {
	
	struct p_elemento *nuevo;
	
	if (!p) {
		fprintf ( stderr, "p_insertar: la pila no existe.\n" );
		exit ( 1 );
	}
	
	nuevo = ( struct p_elemento *) malloc (sizeof ( struct p_elemento ));
	if ( !nuevo ) {
		fprintf ( stderr, "p_insertar: no hay memoria suficiente.\n" );
		exit ( 1 );
	}
	
	nuevo->val = ( void * ) malloc (((struct tip_pila *)p)->tamanyo);
	if (!nuevo->val) {
		fprintf ( stderr, "p_insertar: no hay memoria disponible.\n" );
		exit ( 1 );
	}
	
	memcpy ( nuevo->val, e, ((struct tip_pila *)p)->tamanyo );
	nuevo->sig = (( struct tip_pila *)p)->p;
	(( struct tip_pila *)p)->p= nuevo;
	
}
void p_eliminar ( pila p, void *e ){
	
	struct p_elemento *viejo;
	
	if ( !p ) {
		fprintf ( stderr, "p_eliminar: la pila no existe.\n" );
		exit ( 1 );
	}
	
	if ( p_vacia ( p ) ) {
		fprintf ( stderr, "p_elemento: la pila está vacia, no tiene elementos.\n" );
		exit ( 1 );
	}
	
	viejo = (( struct tip_pila *)p)->p;
	memcpy ( e, viejo->val, (( struct tip_pila *)p)->tamanyo );
	(( struct tip_pila * )p)->p = viejo->sig;
	
	free ( viejo->val );
	free ( viejo );
}
void p_destruir ( pila *p ){

	struct p_elemento *viejo;
	
	if ( !*p ) {
		fprintf ( stderr, "p_destruir: la pila no existe.\n" );
		exit ( 1 );
	}
	
	while ((( struct tip_pila * )(*p))->p ) {
		viejo = (( struct tip_pila *)(*p))->p;
		(( struct tip_pila * )(*p))->p = viejo->sig;
		free ( viejo->val );
		free ( viejo );
	}
	
	free ( *p );
	*p = NULL;
	
}
pila p_copiar ( pila p ){
	
	pila b;
	struct p_elemento *corr, *nuevo, *corrp;
	
	if ( !p ) {
		fprintf ( stderr, "p_copiar: la pila no existe.\n" );
		exit ( 1 );
	}
	
	b = p_nueva ((( struct tip_pila * )p)->tamanyo);
	
	if ( !p_vacia ( p )) {
		nuevo = (struct p_elemento * ) malloc (sizeof ( struct p_elemento ));
		if ( !nuevo ) {
			fprintf ( stderr, "no hay memoria.\n" );
			exit ( 1 );
		}
		nuevo->val = ( void * ) malloc ((( struct tip_pila *)p)->tamanyo );
		if ( !nuevo->val ) {
			fprintf ( stderr, "p_copiar: no hay memoria.\n" );
			exit ( 1 );
		}
		memcpy ( nuevo->val, (( struct tip_pila *)p)->p->val, (( struct tip_pila *)p)->tamanyo); 
		(( struct tip_pila *)b)->p = corr = nuevo;
		corrp = (( struct tip_pila *)p)->p->sig;
		
		while ( corrp ) {
			nuevo = ( struct p_elemento * ) malloc ( sizeof (struct p_elemento ));
			if ( !nuevo ) {
				fprintf ( stderr, "p_copiar: no hay memoria.\n" );
				exit ( 1 );
			}
			nuevo->val = ( void * ) malloc ((( struct tip_pila *)p)->tamanyo);
			if ( !nuevo->val ) {
				fprintf ( stderr, "p_copiar: no hay memoria.\n" );
				exit ( 1 );
			}
			memcpy ( nuevo->val, corrp->val, (( struct  tip_pila * )p)->tamanyo);
			corr = corr->sig = nuevo;
			corrp = corrp->sig;
		}
		corr->sig = NULL;
	}
	
	return ( b );
}
