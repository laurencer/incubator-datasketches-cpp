/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

// author Kevin Lang, Oath Research

// This is a highly specialized hash table that was designed
// to be part of the library's FM85 implementation.

#ifndef GOT_U32_TABLE_H
#include "common.h"

static const uint64_t u32TableUpsizeNumer = 3LL;
static const uint64_t u32TableUpsizeDenom = 4LL;

static const uint64_t u32TableDownsizeNumer = 1LL;
static const uint64_t u32TableDownsizeDenom = 4LL;

typedef struct u32_table_type {
  Short validBits;
  Short lgSize; // log2 of number of slots
  Long  numItems;
  U32* slots;
} u32Table;

u32Table* u32TableMake(Short initialLgSize, Short numValidBits);

u32Table* u32TableCopy(const u32Table* self);

void u32TableClear(u32Table* self);

void u32TableFree(u32Table* self);

void u32TableShow(const u32Table* self); // for debugging

bool u32TableMaybeInsert(u32Table* self, U32 item);

bool u32TableMaybeDelete(u32Table* self, U32 item);

// this one slightly breaks the abstraction boundary
u32Table* makeU32TableFromPairsArray(const U32* pairs, Long numPairs, Short sketchLgK);

U32* u32TableUnwrappingGetItems(const u32Table* self, Long* returnNumItems);

void printU32Array(const U32* array, Long arrayLength);

void u32KnuthShellSort3(U32 a[], Long l, Long r);

void introspectiveInsertionSort(U32 a[], Long l, Long r);

void u32Merge(
    const U32* arrA, Long startA, Long lengthA, // input
	  const U32* arrB, Long startB, Long lengthB, // input
	  U32* arrC, Long startC                      // output
);

#define GOT_U32_TABLE_H
#endif
