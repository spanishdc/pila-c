#ifndef PILA_VOID_H
#define PILA_VOID_H

typedef void *pila;

pila p_nueva ( int tamanyo );
int p_vacia ( pila p );
void p_insertar ( pila p, void *e );
void p_eliminar ( pila p, void *e );
void p_destruir ( pila *p );
pila p_copiar ( pila p );

#endif
