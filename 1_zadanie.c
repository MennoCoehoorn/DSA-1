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

void defrag(chunk *first){
    
    chunk *mover=first;
    chunk *allocated_first=NULL;
    chunk *allocated=NULL;
    chunk *free_chunk=NULL;
    free_chunk->free=true;
    
    unsigned int free_space;
    
    while (mover!=NULL){
        if(mover->free){
            if(free_chunk==NULL){
                free_chunk=mover;
                free_chunk->next=NULL;
            }else{
                mover->prev->next=mover->next;
                free_chunk->chunk_size+=mover->chunk_size;
            }
        }else{
            if(allocated_first==NULL){
                allocated_first=mover;
            }else{
                if(allocated==NULL){
                    allocated=mover;
                    allocated->prev=allocated_first;
                    allocated_first->next=allocated;
                }else{
                    allocated->next=mover;
                    allocated=mover;
                }
            }
        }
        if(mover->next==NULL){
            allocated->next=free_chunk;
            free_chunk->prev=allocated;
        }
    }
    
}

void *split_chunk(chunk *chunk_to_split,unsigned int size){
    
    chunk *new_chunk;
    new_chunk->prev=chunk_to_split;
    new_chunk->next=NULL;
    new_chunk->chunk_size=chunk_to_split->chunk_size-size;
    chunk_to_split->chunk_size=size;
    
}

void *memory_alloc(unsigned int size){
    
    defrag(first);
    
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
        
    }else{
        if(chunk_to_alloc->chunk_size>needed_size){
            split_chunk(chunk_to_alloc,needed_size);
        }
        chunk_to_alloc->free=false;
    }
    
}

chunk *first;

void main(){
    
}