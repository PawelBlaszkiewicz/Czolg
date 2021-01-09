#ifndef _LOGIKA_H
#define _LOGIKA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "../cJSON/cJSON.h"

#define N 20
#define K 20

int zero (int a,int b,int taba[a][b]);
void zapisz(FILE *fout,int a, int b, int taba[N][K]);
int krance (int taba[N][K]);
void odwroc(int a,int b, int taba[a][b]);

int ykoniec (int taba[N][K]);
void przepisz(int a, int b, int mapa[a][b], int taba[N][K]);
int xkoniec (int taba[N][K]);

void ruchkoniec(int a, int b, int mapa[a][b]);
void ruchzero( int a, int b, int mapa[a][b]);

#endif