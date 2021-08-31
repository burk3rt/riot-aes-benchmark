#include "generator.h"
#include <time.h>
#include <string.h>
#include <stdio.h>

void generateMessage(char* messageStorage, int messageLength){
    srand(time(0));
    char charset[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int index = 0; index < messageLength; index++){
        messageStorage[index] = charset[(rand() % (int) (sizeof charset - 1))];
    }
    messageStorage[messageLength] = '\0';
}

FILE* createBenchmarkFile(char* name) {
    FILE* filePointer = NULL;
    char* fullPath = malloc((strlen(BENCHMARK_RESULTS_DIR) + strlen(name) + 1) * sizeof(char));
    strcpy(fullPath, BENCHMARK_RESULTS_DIR);
    strcat(fullPath, name);
    strcat(fullPath, ".csv");
    filePointer = fopen(fullPath, "w");
    if(filePointer == NULL) {
        printf("Unable to create file.\n");
        exit(0);
    }
    fputs(name, filePointer);
    fputs(";Round Number; Encryption Duration; Decryption Duration", filePointer);
    fputs("\n", filePointer);
    //fclose(filePointer);
    return filePointer;
}

void benchmark_save_runtime(uint32_t time[], int currentRound, FILE* benchmarkFilePointer){
    char resultToWrite[(sizeof(time[0]) + sizeof(time[1])) + sizeof(currentRound) + 4];
    sprintf(resultToWrite, ";%d;%u;%u\n", currentRound, time[0], time[1]);
    if(benchmarkFilePointer == NULL) {
        printf("Unable to open file.\n");
        exit(0);
    }
    fputs(resultToWrite, benchmarkFilePointer);
}