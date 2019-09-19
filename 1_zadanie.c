#include <stdio.h>

typedef struct chunk{
    
    unsigned int chunk_size;
    struct chunk *next, *prev, *nex_free, *prev_free;
    bool free;
    
}chunk;

typedef struct sesh{
    
    chunk *first_chunk,*last_chunk,*first_free_chunk,*last_free_chunk;
    unsigned int alloc_cnt;
    
}sesh;

chunk* find_free_chunk(unsigned int size, sesh session){
    
    chunk *mover=session->first_free_chunk;
    
    while(mover!=NULL){
        if(mover->chunk_size>=size){
            return mover;
            break;
        }
    }
    return NULL;
    
}