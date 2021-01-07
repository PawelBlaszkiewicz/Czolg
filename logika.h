#ifndef _LOGIKA_H
#define _LOGIKA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "../cJSON/cJSON.h"

#define N 12
#define K 9

int zero (int taba[N][K]);
void zapisz(FILE *fout, int taba[N][K]);

#endif