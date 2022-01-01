#ifndef WORLD_UTILS_H
#define WORLD_UTILS_H

#include <ivec3.h>
#include <linmath.h>

#include "block.h"
#include "vertex.h"

// Size of chunk in blocks
#define CHUNK_X_SIZE 32
#define CHUNK_Y_SIZE 32
#define CHUNK_Z_SIZE 32

// contains block data for the chunk
typedef struct {
  BlockIndex blocks[CHUNK_X_SIZE][CHUNK_Y_SIZE][CHUNK_Z_SIZE];
} ChunkData;

void worldChunkCoords_to_iBlockCoords( //
    ivec3 iBlockCoords,                //
    const ivec3 worldChunkCoords       //
);

void blockCoords_to_worldChunkCoords( //
    ivec3 chunkCoord,                 //
    const vec3 blockCoord             //
);

void worldChunkCoords_to_blockCoords( //
    vec3 blockCoords,                 //
    const ivec3 worldChunkCoords      //
);

bool wu_loadChunkData(ChunkData* pC, const char* filename);

uint32_t wu_countChunkDataVertexes( //
    const ChunkData *pCd                        //
);


uint32_t wu_getVertexesChunkData( //
    Vertex *pVertexes,                //
    const vec3 offset,                //
    const ChunkData *pCd              //
);

#endif
