//
// Created by JinHai on 2022/9/9.
//

#pragma once

#include "storage/data_type.h"
#include "storage/chunk.h"

namespace infinity {

class VectorOperation {
public:
    static void VectorCast(const Chunk& source, Chunk& target);
    static void VectorCast(const Chunk& source, int64_t source_start, int64_t length, Chunk& target);
};

}