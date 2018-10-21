#include "linkedList.h"

linkedList newList(size_t bytes, int (*cmp)(void *, void *)) {
    linkedList new = mallocMemory(sizeof(*new));
    new->bytes = bytes;
    new->first = NULL;
    new->last = NULL;
    new->cmp = cmp;
    new->dim = 0;
    return new;
}

void addToList(linkedList l, void * elem) {
    if (l == NULL) {
        return;
    }
    l->dim++;
    if (l->first == NULL) {
        ListNode * new = mallocMemory(sizeof(*new));
        new->elem = elem;
        new->next = NULL;
        l->first = l->last = new;
        return;
    } else {
        ListNode * new = mallocMemory(sizeof(*new));
        new->elem = elem;
        new->next = NULL;
        l->last->next = new;
        l->last = new;
        return;
    }
}

static
ListNode * geListNode(linkedList l, int i){
    if (l == NULL || l->first == NULL) {
        return NULL;
    }
    int j = 0;
    ListNode * aux = l->first;
    while(j != i && aux != NULL) {
        aux = aux->next;
        j++;
    }

    if(aux == NULL)
        return NULL;

    return aux;
}

void * getFromList(linkedList l, int i) {
    ListNode * resp = geListNode(l,i);
    if(resp == NULL)
        return NULL;
    return resp->elem;
}

void * getElemFromList(linkedList l, void * elem) {
    if(l == NULL)
        return NULL;
    ListNode * aux = l->first;
    while(aux != NULL) {
        if((l->cmp)(aux->elem,elem) == 0)
            return aux->elem;
        aux = aux->next;
    }
    return NULL;
}

int getListSize(linkedList l) {
    return l->dim;
}

static
ListNode * removeREC(ListNode * current, ListNode * prev, void * elem, linkedList l, void * aux, char * found) {
    if (current == NULL) {
        return NULL;
    } else if ((*(l->cmp))(current->elem, elem) == 0) {
        *(found) = 1;
        memcpy(aux, current->elem, l->bytes);
        if (current == l->last) {
            l->last = prev;
        }
        ListNode * next = current->next;
        freeMemory(current->elem);
        freeMemory(current);
        return next;;
    } else {
        current->next = removeREC(current->next, current, elem, l, aux, found);
        return current;
    }
}

void * removeElemList(linkedList l, void * elem) {
    if (l == NULL || l->cmp == NULL) {
        return NULL;
    }
    void * aux = mallocMemory(l->bytes);
    char found = 0;
    l->first = removeREC(l->first, NULL, elem, l, aux, &found);
    if (found) {
        (l->dim)--;
        return aux;
    } else {
        freeMemory(aux);
        return NULL;
    }
}

int removeElemListAt(linkedList l, int i) {
    if(l == NULL)
        return 0;
    if(i == 0){
        ListNode * remAux = l->first;
        l->first = l->first->next;
        if(l->dim == 1)
            l->last = l->first;
        freeMemory(remAux);
        l->dim--;
        return 1;
    }

    ListNode * aux = geListNode(l,i-1);
    if(aux == NULL || aux->next == NULL)
        return 0;

    ListNode * remAux = aux->next;
    aux->next = remAux->next;
    freeMemory(remAux);
    l->dim--;
    return 1;
}

static
int containsREC(ListNode * node, void * elem, int (*cmp)(void *, void *)) {
    if (node == NULL) { // llego al final y no lo encontro
        return 0;
    } if (!(*cmp)(node->elem, elem)) { // si son iguales entonces lo encontre
        return 1;
    } else
        return 0 + containsREC(node->next, elem, cmp);
}

int containsList(linkedList l, void * elem) {
    if (l == NULL) {
        return 0;
    }
    if (l->cmp == NULL) {
        return 0;
    }
    return containsREC(l->first, elem, l->cmp);
}

void freeList(linkedList l) {
    if (l == NULL) {
        return;
    }
    ListNode * list = l->first;
    while (list != NULL) {
        ListNode * aux = list;
        list = list->next;
        freeMemory(aux->elem);
        freeMemory(aux);
    }
    freeMemory(l);
}

void freeLisListNodes(linkedList l) {
    if (l == NULL) {
        return;
    }
    ListNode * list = l->first;
    while (list != NULL) {
        ListNode * aux = list;
        list = list->next;
        freeMemory(aux);
    }
    freeMemory(l);
}
