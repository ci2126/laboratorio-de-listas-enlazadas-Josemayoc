/*NOMBRE: Jose Mayo
Carnet: 16-10702*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int val;
    struct nodo *sig;
} Nodo;

typedef Nodo * Lista;

Lista newList(){
    return NULL;
}

void inserta(int x, Lista *L){
    Nodo *p = malloc(sizeof(Nodo));
    p->val = x;
    p->sig = *L;
    *L = p;
}

int esVacia(Lista L){
    return L==NULL;
}

int firstInList(Lista L){
	return L->val;
}

int estaEn(int x, Lista L){
    Nodo *p = L;
    while(p != NULL && p->val != x) p = p->sig;
    return p != NULL;
}

void writeList(Lista L, char name[]){
    printf("\n%s = [",name);
    if (L == NULL) printf("].");
    else {
    	while (L->sig != NULL) {
    		printf("%d, ", L->val);
    		L = L->sig;
    	}
    	printf("%d].",L->val);
    }
}

/*void insertaT(int x, Lista *L){
    Nodo *p = malloc(sizeof(Nodo)), *q = *L;
    p->val = x;
    p->sig = NULL;
    if (*L == NULL){
    	*L = p;
    }
    else {
    	while (q->sig!=NULL){
			q = q->sig;
            q->sig = malloc(sizeof(Nodo));
            (q->sig)->val = x;
            (q->sig)->sig = NULL;
        }
    }
}*/

void elimina(int x, Lista *L){
	Nodo *p = *L, *q;
	if (p != NULL){
		if (p->val == x){
			*L = p->sig;
			free(p);
		} else {
			while (p->sig != NULL && (p->sig)->val != x) p = p->sig; 
				if (p->sig != NULL) {
					q = p->sig;
					p->sig = q->sig;
					free(q);
				}
		}
	}
}

/*void clona(Lista L, Lista *N){
	*N = NULL;
	Nodo *q;
	if (L != NULL){
		*N = ;
		COMPLETAR;
		while(L != NULL){
			q->sig = malloc(sizeof(Nodo));
			COMPLETAR;
		}
		q->sig = NULL; 
	}
}*/

/*void concat(Lista *L, Lista *K){
	if (*L == NULL) *L = *K;
	else {
		Nodo *p = malloc(sizeof(Nodo));
		p->sig = *K ;
		p->val = ((*L)->sig)->val; 
		(*L)= p;
	}	
	*K = NULL;
}*/

int sizeR(Lista L){
	if(L == NULL) return 0;
	else return 1+ sizeR(L->sig);
}

void insertaTR(int x, Lista *L){
	if(*L == NULL) {
		Nodo *p = malloc(sizeof(Nodo));
		p->val = x;
		p->sig = NULL;
		*L = p;
	}
	else insertaTR(x, &((*L)->sig));
}


int main(){
    printf("\nProbando Lista...:");
    Lista L = newList(), L1 = newList();
    writeList(L, "L");
    inserta(4,&L);
    inserta(9,&L);
    inserta(5,&L);
    writeList(L, "L");
    printf("\nA la cabeza de L esta: %d",firstInList(L));
    if (esVacia(L1)) printf("\nL1 es vacia."); else printf("\nL1 NO es vacia.");
    int x = 7; char s[] = "L";
    if (estaEn(x, L)) printf("\n%d esta en %s.", x, s); else printf("\n%d NO esta en %s.", x, s);
    
    elimina(5,&L);
    printf("\n");
    writeList(L, "L");
    
    inserta(7,&L1);
    inserta(3,&L1);
    inserta(2,&L1);
    writeList(L1, "L1");
    
    /*printf("\n");
    concat(&L,&L1);
    writeList(L, "L");*/
    
    printf("\n");
    sizeR(L);
    insertaTR(6,&L);
    writeList(L, "L");
    
    return 0;
}
