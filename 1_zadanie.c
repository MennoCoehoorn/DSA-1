#include <stdio.h>
#include <stdbool.h>

typedef struct chunk{
    
    unsigned int chunk_size;
    struct chunk *next, *prev;
    bool free;
    
}chunk;

chunk* find_free_chunk(unsigned int size){
    
    chunk mover = first;
    
    while(mover!=NULL){
        
        if(mover->chunk_size>=size&&mover->free){
            return mover;
            break;
        }
        
        mover=mover->next;
    }
    
    return NULL;
    
}


void *memory_alloc(unsigned int size){
    
    unsigned int needed_size = (((bytes-1)>>2)<<2) + 4;
    
    chunk *chunk_to_alloc =find_free_chunk(needed_size);
    
    if(chunk_to_alloc==NULL){
        
        chunk_to_alloc = chunk *new_chunk;
        
        chunk *mover=first;
        
        while(mover->next!=NULL){
            mover=mover->next;
        }
        
        mover->next=chunk_to_alloc;
        chunk_to_alloc->prev=mover;
        chunk_to_alloc->next=NULL;
        chunk_to_alloc->free=false;
        
    }
    
}

chunk *first;

void main(){
    
}