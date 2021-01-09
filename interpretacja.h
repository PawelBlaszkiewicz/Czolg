#ifndef _INTERPRETACJA_H
#define _INTERPRETACJA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include"siec.h"
#include "../cJSON/cJSON.h"

#define N 20
#define K 20

int daj_x(cJSON *cus);
int daj_y(cJSON *cus);
char * daj_pole(cJSON *cus);
char * daj_kier(cJSON *cus);
int daj_xe(cJSON *cus);
int daj_ye(cJSON *cus);
char * daj_type(cJSON *cus);
int zwroc_nr_pola(cJSON *a);
int zwroc_enr_pola(cJSON *a);
void wypisz(int a, int b, int tab[N][K]);


#endif