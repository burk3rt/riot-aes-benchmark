#ifndef GENERATOR_HEADER
#define GENERATOR_HEADER

#include "stdint.h"
#include <stdlib.h>
#include <stdio.h>

#define BENCHMARK_RESULTS_DIR "benchmarkResultsTemp/"

void generateMessage(char* messageStorage, int messageLength);
FILE* createBenchmarkFile(char* name);
void benchmark_save_runtime(uint32_t time[], int currentRound, FILE* benchmarkFileName);

#endif