#include "mutex.h"
#include "VideoDriver.h"
#include "lib.h"
Colour colour5 = {255, 255, 255};
Colour red2 = {100, 100, 255};
char buff5[8];
static queueADT myMutexs;


int cmpMutex(mutex * m1, mutex * m2) {
    return strcmp(m1->name, m2->name);
}

/**
 Crea un mutex dado un nombre y retorna un puntero al mismo
 */
mutex * initMutex(char * mutexName) {
    mutex * m = mallocMemory(sizeof(mutex));
    m->queue = newQueue(sizeof(int), NULL);
    m->value = 0;
    m->name = mutexName;
    return m;
}

/**
 Se fija si el mutex con ese nombre existe, si existe retorna un puntero a el sino crea un mutex dado un nombre y retorna un puntero al mismo
 */
mutex * getMutex(char * mutexName) {
    if (myMutexs == NULL) {
        myMutexs = newQueue(sizeof(mutex), cmpMutex);
    }
    mutex * elem = mallocMemory(sizeof(mutex));
    elem->name = mutexName;
    mutex * aux = getElem(myMutexs, elem);
    if (aux == NULL) {
        aux = initMutex(mutexName);
        push(myMutexs, aux);
    }
    return aux;
}

/**
 Elmina el mutex y  libera sus recursos
 */
void destroyMutex(mutex * m) {
    mutex * elem = mallocMemory(sizeof(mutex));
    elem->name = m->name;
    mutex * aux = removeElem(myMutexs, elem);
    if (aux != NULL) {
        freeMemory(aux);
    }
}

/**
 El proceso que llama toma el mutex
 si algun otro proceso llama a la funcion y no es el dueño actual del mismo este sera bloqueado
 funcion atomica
 */
void adquire(mutex * m) {
    if(swapLock(&(m->value))) { // si no entramos al lock bloqueamos al proceso hasta que esta sea liberada
        int pid = getRunningPid();
        push(m->queue, pid);
        blockProcess(pid);
    }
    m->mutex_holder = getRunningPid();
}

/**
 El proceso que es dueño del mutex es el unico que puede liberarlo
 si algun otro proceso llama a la funcion y no es el dueño actual del mismo este no sera liberado
 funcion atomica
 */
void release(mutex * m) {
    if (m->mutex_holder == getRunningPid()) {
        int pid = pop(m->queue);
        if (pid != NULL) {
            m->mutex_holder = pid;
            unblockProcess(pid);
        } else {
            swapUnLock(&(m->value));
        }
    }
}

