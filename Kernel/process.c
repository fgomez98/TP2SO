#include "process.h"
#include "scheduler.h"
#include "syscalls.h"
#include "lib.h"
#include "readwrite.h"

char buff2[8];
Colour colour2 = {255, 255, 255};
Colour yellow2 = {100, 1000, 255};
static int nextPid = 1; //Esta variable le asigna a cada proceso un pid distinto

tProcess* createProcess(char* processName,void* startingPoint, int parentPid, int argc, char* argv[]){
    /*Se reserva espacio para la estructura del proceso*/
    tProcess* process = mallocMemory(sizeof(tProcess));
    /*Se completan los campos del nuevo proceso*/
    process->pid = nextPid++;
    process->parentPid = parentPid;
    process->name = processName;
    process->processMemoryLowerAddress = mallocMemory(PROCESS_SIZE);
    process->code = startingPoint;
    //esto tiene q ser uint64_t y no void*!!!!!!!!!! CAMBIARLO
    void* processMemoryUpperAddress = process->processMemoryLowerAddress + PROCESS_SIZE -1;
    process->stackPointer = processMemoryUpperAddress - sizeof(tStackFrame) + 1;
    initializeStack(process->stackPointer, argc, argv, startingPoint);
    process->memoryAllocated = PROCESS_SIZE;
    process->state = READY;
    process->heap = NULL;
    process->priority = 1;
    process->quantumTime = 0;
    process->stdIn = 0;
    process->stdOut = 1;
    process->nice = 0;
    return process;
}

tProcess * createProcessWithDup(char* processName,void* startingPoint, int parentPid, int argc, char* argv[], int newFd, int fdToReplace) {
    tProcess * proc = createProcess(processName, startingPoint, parentPid, argc, argv);
    openWithPid(newFd, proc->pid);
    if (fdToReplace == 0) {
        proc->stdIn = newFd;
    }
    else if(fdToReplace == 1){
        proc->stdOut = newFd;
    }
    return proc;
}

void runProcess(int argc, char * argv[], void * startingPoint) { // por orden de como se levantan los argumentos
    ((int (*)(int, void**))(startingPoint))(argc, argv);
    _killCurrentProcess();
}

//RowDaBoat
void initializeStack(tStackFrame * stackFrame, int argc, char* argv[], void * startingPoint) {
    stackFrame->gs= 0x001;
    stackFrame->fs= 0x002;
    stackFrame->r15= 0x003;
    stackFrame->r14= 0x004;
    stackFrame->r13= 0x005;
    stackFrame->r12= 0x006;
    stackFrame->r11= 0x007;
    stackFrame->r10= 0x008;
    stackFrame->r9=	0x009;
    stackFrame->r8= 0x00A;
    stackFrame->rsi= (uint64_t)argv;
    stackFrame->rdi= (uint64_t)argc;
    stackFrame->rbp= 0x00D;
    stackFrame->rdx= startingPoint;
    stackFrame->rcx= 0x00F;
    stackFrame->rbx= 0x010;
    stackFrame->rax= 0x011;
    stackFrame->rip= (void *) &runProcess;//(uint64_t)//startingPoint;
    stackFrame->cs=	0x008;
    stackFrame->eflags= 0x202;
    stackFrame->rsp= (uint64_t)&(stackFrame->base); //el rsp apunta a la direccion en la que esta el base
    stackFrame->ss= 0x000;
    stackFrame->base= 0x000;
}

void printStackFrame(tStackFrame * stackFrame) {
    putStr("Stack Frame ", colour2);
    putStr("rsi: ", colour2);
    uintToBase(stackFrame->rsi, buff2, 10);
    putStr(buff2, colour2);
    putChar('\n', colour2);

    putStr(" rdi: ", colour2);
    uintToBase(stackFrame->rdi, buff2, 10);
    putStr(buff2, colour2);
    putChar('\n', colour2);

    putStr(" rip: ", colour2);
    uintToBase(stackFrame->rip, buff2, 10);
    putStr(buff2, colour2);
    putChar('\n', colour2);

    putStr(" rsp: ", colour2);
    uintToBase(stackFrame->rsp, buff2, 10);
    putStr(buff2, colour2);
    putChar('\n', colour2);
}

void printProcess(tProcess * p) {
    putStr("Process ", colour2);
    putStr("pid: ", colour2);
    uintToBase(p->pid, buff2, 10);
    putStr(buff2, colour2);
    putChar('\n', colour2);
    putStr("name: ", colour2);
    putStr(p->name, colour2);
    putChar('\n', colour2);
    putStr("state: ", colour2);
    switch (p->state) {
        case READY:
            putStr("Ready", colour2);
            break;
        case RUNNING:
            putStr("Running", colour2);
            break;
        case WAITING:
            putStr("Waiting", colour2);
            break;
        case DEAD:
            putStr("Dead", colour2);
            break;
    }
    putChar('\n', colour2);
    putStr("stack pointer: ", colour2);
    uintToBase(p->stackPointer, buff2, 10);
    putStr(buff2, colour2);
    putChar('\n', colour2);

    putStr("memory low: ", colour2);
    uintToBase(p->processMemoryLowerAddress, buff2, 10);
    putStr(buff2, colour2);
    putChar('\n', colour2);

    printStackFrame(p->stackPointer);
}

void endProcess(int pid) {
    //_cli();
    changeProcessState(pid, DEAD);
    //yield(); //TODO: si no es el que estaba corriendo es al pedo hacer _yield(); hacer el chequeo de si hacer yield o no aca o en el scheduler
    //_hlt();
}

void deleteProcess(tProcess* process) {
    freeMemory(process->processMemoryLowerAddress);
    freeProcessHeap(process->heap);
    freeMemory(process);
}

void freeProcessHeap(queueADT heap){
  while(heap!=NULL && (getSize(heap) > 0)){
    freeMemory(pop(heap)); //libera lo q quedo reservado y sin liberar y tamb el pop va borrando los nodos de la cola
  }
}

int cmpPointers(uint64_t  p1, uint64_t  p2) {
    return p1 - p2;
}

void* mallocMemoryInProcess(size_t request, tProcess* process){
  void* p = mallocMemory(request);
  if(process->heap == NULL){
      process->heap = newQueue(sizeof(uint64_t), cmpPointers);
  }
  push(process->heap, p);
  process->memoryAllocated +=size_of_level(findLevel(p));

 return p;
}

void freeMemoryInProcess(void* memoryAdr, tProcess* process){

    process->memoryAllocated -= size_of_level(findLevel(memoryAdr));
    uint64_t * aux = removeElem(process->heap, memoryAdr);
    freeMemory(aux);

}


void* callocMemoryInProcess(size_t request, tProcess* process){
  void* p = callocMemory(request);
  if(process->heap == NULL){
      process->heap = newQueue(sizeof(uint64_t), cmpPointers);
  }
  process->memoryAllocated +=size_of_level(findLevel(p));
  push(process->heap, p);

return p;
}

void* reallocMemoryInProcess(size_t request, tProcess* process, uint64_t oldPtr){
  process->memoryAllocated -= size_of_level(findLevel(oldPtr));
  removeElem(process->heap, oldPtr);
  void* p = reallocMemoryAlreadyFreed(oldPtr, request);
  if(process->heap == NULL){
      process->heap = newQueue(sizeof(uint64_t), cmpPointers);
  }
  process->memoryAllocated +=size_of_level(findLevel(p));

  push(process->heap, p);

return p;
}


int stateIdentifier(pState state){
  if(state == READY){
     return 0;
  }
  else if(state == RUNNING){
    return 1;
  }
  else if(state == WAITING){
    return 2;
  }
    return 3;

}
