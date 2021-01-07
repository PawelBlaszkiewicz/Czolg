#ifndef _INTERPRETACJA_H
#define _INTERPRETACJA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include"siec.h"
#include "../cJSON/cJSON.h"

#define N 12
#define K 9

int daj_x(cJSON *cus);
int daj_y(cJSON *cus);
char * daj_pole(cJSON *cus);
char * daj_kier(cJSON *cus);
cJSON *  daj_exp(cJSON *cus, int i);
int daj_xe(cJSON *cus);
int daj_ye(cJSON *cus);
char * daj_type(cJSON *cus);
int zwroc_nr_pola(cJSON *a);
int zwroc_enr_pola(cJSON *a);
void wypisz(int tab[N][K]);
cJSON *cinfo(char *url);
cJSON *cex(char *url, int i);

cJSON * daj_xc(cJSON *cus);


#endif