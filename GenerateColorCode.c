#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ColorCode_prv.h"

#define MAX_LINE_LENGTH 100
#define INITIAL_BUFFER_SIZE 1024

char* generateColorReferenceManual()
{
    int bufferSize = INITIAL_BUFFER_SIZE;
    char* buffer = (char*)malloc(bufferSize);
    if (buffer == NULL) 
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    strcpy(buffer, "Color Code Reference Manual:\n");
    strcat(buffer, "-----------------------------\n");

    for (int i = 1; i <= numberOfMajorColors * numberOfMinorColors; ++i) 
    {
        ColorPair colorPair = GetColorFromPairNumber(i);
        char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
        ColorPairToString(&colorPair, colorPairNames);

        char line[MAX_LINE_LENGTH];
        snprintf(line, MAX_LINE_LENGTH, "%2d: %s\n", i, colorPairNames);

        if (strlen(buffer) + strlen(line) + 1 > bufferSize) 
        {
            bufferSize *= 2;
            buffer = (char*)realloc(buffer, bufferSize);
            if (buffer == NULL) 
            {
                fprintf(stderr, "Memory reallocation failed\n");
                return NULL;
            }
        }
        strcat(buffer, line);
    }
    strcat(buffer, "-----------------------------\n");
    return buffer;
}
