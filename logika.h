#ifndef _LOGIKA_H
#define _LOGIKA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "../cJSON/cJSON.h"

#define N 50
#define K 50

int zwroc_x (int a, int b, int tab[a][b]);
int zwroc_y (int a, int b, int tab[a][b]);

int zero (int a,int b,int taba[a][b]);
void zapisz(FILE *fout,int a, int b, int taba[N][K]);
int krance (int a,int b,int taba[a][b]);
void odwroc(int a,int b, int taba[a][b]);

int ykoniec (int a,int b,int taba[a][b]);
void przepisz(int a, int b, int mapa[a][b], int taba[N][K]);
int xkoniec (int a,int b,int taba[a][b]);

void exploruj(cJSON *zmienna, int a, int b, int mapa[a][b]);
void exploruj_jesli_musisz(int a, int b, int mapa[a][b], char *kierunek, int x, int y, int bilans_skrety, cJSON *cus, char *url1, char *url2);

void ruch_do_utworzenia_krawedzi_mapy(int a, int b, int mapa[a][b]);
void ruch_dopoki_nowa_mapa_jest_nieodkryta( int a, int b, int mapa[a][b]);

cJSON *ruszaj(int a, int b, int mapa[a][b], char *kierunek, int x, int y, int bilans_skrety, cJSON *cus, char *url1, char *url2, char *url3);

int zwroc_x_zera(int a, int b, int mapa[a][b]);
int zwroc_y_zera(int a, int b, int mapa[a][b]);
cJSON *ruszaj_do_zera(int a, int b, int mapa[a][b], char *kierunek, int x, int y, int bilans_skrety, cJSON *cus, char *url1, char *url2, char *url3);

void wypisz(int a,int b,int tab[a][b]);

#endif