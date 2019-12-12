#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

#include "computer.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void) {
    LinkedList* this= NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL) {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this) {
    int returnAux = -1;
    if(this != NULL) {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex) {
	int i;
	Node* pNode = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)) {
		pNode = this->pFirstNode;
		for(i = 0; i < nodeIndex; i++) {
			pNode = pNode->pNextNode;
		}
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex) {
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement) {
    int returnAux = -1;
    Node* pNewNode = NULL;
    Node* pAuxNode = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) {
    	pNewNode = (Node*)malloc(sizeof(Node)); // Reservo memoria para el nuevo nodo
    	if(nodeIndex == 0) { // Si es la primera posición se agregará el nodo al principio de la lista
    		pAuxNode = getNode(this, nodeIndex); // Obtengo el nodo del LinkedList
    		pNewNode->pElement = pElement; // Al nuevo nodo le guardo el elemento recibido por parametro
    		pNewNode->pNextNode = pAuxNode; // Al campo NextNode de Node le asigno el apuntador al nuevo nodo obtenido con getNode
    		this->pFirstNode = pNewNode; // Se asigna a la cabecera de la lista el nodo creado anteriormente
    		this->size++; // Al campo Size se le aumenta en 1 su longitud para saber la longitud exacta de la lista
    	} else { // Si no es la primera posición se agregará el nodo al final de la lista
    		pAuxNode = getNode(this, nodeIndex -1); // Obtengo el nodo al que le voy a agregar el nuevo nodo (nodeIndex - 1), lo guardo en una variable auxiliar para no perderlo.
    		pNewNode->pElement = pElement; // Al nuevo nodo le guardo el elemento recibido por parametro
    		pNewNode->pNextNode = pAuxNode->pNextNode; // Al nuevo nodo le apunto el nodo que antes apuntaba el nodo auxiliar y le asigno el apuntador al nodo siguiente que esta siendo apuntando desde el auxiliar
    		pAuxNode->pNextNode = pNewNode; // Al campo NextNode le asigno el nodo guardado en Node
    		this->size++; // Al campo Size se le aumenta en 1 su longitud para saber la longitud exacta de la lista
    	}
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement){
    int returnAux = -1;

    if(this != NULL && addNode(this, ll_len(this),pElement) == 0) {
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index) {
    void* returnAux = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this)) {
    	Node* auxNode = getNode(this, index);
    	returnAux = auxNode->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement) {
    int returnAux = -1;
    if(this != NULL &&  index >= 0 && index < ll_len(this)) {
        Node* auxNode = getNode(this, index);
        if(auxNode != NULL) {
			auxNode->pElement = pElement;
			returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index) {
    int returnAux = -1;

    if(this != NULL && index >= 0 && index < ll_len(this)) {
		Node* pPreviousNode = NULL;
		Node* pAuxNode = NULL;
		if(index == 0) { // Si es la primera posicion hago lo siguiente:
			pAuxNode = getNode(this, index); // Obtengo el nodo del LinkedList
		    this->pFirstNode = pAuxNode->pNextNode; // Al campo FirstNode le asigno lo guardado en el campo NextNode
		    free(pAuxNode); // Libero memoria del nodo que ya no necesito porque deseo borrar
		    this->size--; // Al campo Size se le disminuye en 1 su longitud
		    } else { // Si no es la primera posicion hago lo siguiente:
		    	pAuxNode = getNode(this, index); // Obtengo el nodo del Node
		    	pPreviousNode = getNode(this, index -1); // Obtengo el nodo del LinkedList -1 para llegar al nodo anterior
		    	pPreviousNode->pNextNode = pAuxNode->pNextNode; //Al nodo anterior le asigno lo que esta en el nodo siguiente
		    	this->size--; // Al campo Size se le disminuye en 1 su longitud
		    	}
		 	 	 returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this) {
    int returnAux = -1;

    if(this != NULL) {
    	while(ll_remove(this,0));
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this) {
    int returnAux = -1;
    if(this != NULL) {
    	ll_clear(this);
    	free(this);
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement) {
    int returnAux = -1;
    int i;
    Node* pAuxNode = NULL;

    if(this != NULL) {
    	for(i = 0; i < ll_len(this); i++) {
			pAuxNode = getNode(this, i);
			if(pAuxNode->pElement == pElement) {
				returnAux = i;
				break;
			}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this) {
    int returnAux = -1;

    if(this != NULL) {
    	returnAux = 1;
    	if(ll_len(this) > 0) {
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement) {
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this)) {
		returnAux = addNode(this, index, pElement);
    }
    return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index) {
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)) {
		returnAux = ll_get(this, index);
		ll_remove(this, index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement) {
    int returnAux = -1;
    int i;

    if(this != NULL) {
    	returnAux = 0;
    	for(i = 0; i < ll_len(this); i++) {
			if(pElement == ll_get(this, i)) {
				returnAux = 1;
				break;
			}
		}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2) {
	int returnAux = -1;
	int i;

	    if(this != NULL && this2 != NULL) {
	    	returnAux = 1;
	    	for(i = 0; i < ll_len(this2); i++) {
				if(!ll_contains(this, ll_get(this2, i))) {
					returnAux = 0;
					break;
				}
			}
	    }

	return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to) {
    LinkedList* cloneArray = NULL;
    int i;

    if(this != NULL && from >= 0 && from < ll_len(this) && to >= from && to <= ll_len(this)) {
    	cloneArray = ll_newLinkedList();
    	for(i = from; i < to; i++) {
    		ll_add(cloneArray, ll_get(this, i));
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this) {
    LinkedList* cloneArray = NULL;
    int i;

    if(this != NULL) {
        cloneArray = ll_newLinkedList();
        for(i = 0; i < ll_len(this); i++) {
        	ll_add(cloneArray, ll_get(this, i));
        }
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order) {
    int returnAux = -1;
    int i, swap;
    Node* buffer1;
    Node* buffer2;

    if(this != NULL && pFunc != NULL && ll_len(this) > 1 && (order == 1 || order == 0)) {
    	do {
    		swap = 0;
    		for(i = 0; i < ll_len(this)-1; i++) {
    			buffer1 = getNode(this, i);
    			buffer2 = getNode(this, i+1);

    			if(order == 0 && pFunc(buffer1->pElement, buffer2->pElement) < 0) {
    				swapNode(buffer1, buffer2);
    				swap = 1;
    			}
    			if( order == 1 && pFunc(buffer1->pElement, buffer2->pElement) > 0) {
    				swapNode(buffer1, buffer2);
    				swap = 1;
    			}
    		}
    	}while(swap != 0);

    	returnAux = 0;
    }

    return returnAux;

}

void swapNode(Node *a, Node *b) {
	void* temp = a->pElement;
	a->pElement = b->pElement;
	b->pElement = temp;
}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*)) {
    LinkedList* returnAux;
    int i;
    if(this != NULL && pFunc != NULL) {
        returnAux = ll_newLinkedList();
        for(i=0;i<ll_len(this);i++) {
            if(pFunc(ll_get(this,i))) {
                ll_add(returnAux,ll_get(this,i));
            }
        }
    }
    return returnAux;
}

int ll_map(LinkedList* this,void (*pFunc)(void*)) {

	int returnAux = -1;
	int i;

	if(this != NULL && pFunc != NULL) {
		for(i = 0; i < ll_len(this); i++) {
			pFunc(ll_get(this, i));
			returnAux = 0;
		}
	}
	return returnAux;
}
