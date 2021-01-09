#include "interpretacja.h"


int daj_x(cJSON *cus)
{
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(cus, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "current_x");
    return atof(cJSON_Print(name));
}

int daj_y(cJSON *cus)
{
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(cus, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "current_y");
    return atof(cJSON_Print(name));
}

char * daj_pole(cJSON *cus)
{
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(cus, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "field_type");
    return cJSON_Print(name);
}

char * daj_kier(cJSON *cus)
{
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(cus, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "direction");
    return cJSON_Print(name);
}

int daj_xe(cJSON *cus)
{
    cJSON *name = cJSON_GetObjectItemCaseSensitive(cus, "x");
    return atof(cJSON_Print(name));
}

int daj_ye(cJSON *cus)
{
    cJSON *name = cJSON_GetObjectItemCaseSensitive(cus, "y");
    return atof(cJSON_Print(name));
}

char * daj_type(cJSON *cus)
{
    cJSON *name = cJSON_GetObjectItemCaseSensitive(cus, "type");
    return cJSON_Print(name);
}

int zwroc_nr_pola(cJSON *a)
{
    if(strcmp(daj_pole(a), "\"grass\"" )==0)
        {
            return 1;
        }
        else if(strcmp(daj_pole(a),"\"sand\"")==0)
        {
            return 2;
        }
        else if(strcmp(daj_pole(a),"\"wall\"")==0)
        {
            return 3;
        }
}

int zwroc_enr_pola(cJSON *a)
{
    if(strcmp(daj_type(a), "\"grass\"" )==0)
        {
            return 1;
        }
        else if(strcmp(daj_type(a),"\"sand\"")==0)
        {
            return 2;
        }
        else if(strcmp(daj_type(a),"\"wall\"")==0)
        {
            return 3;
        }
}

void wypisz(int a,int b,int tab[a][b])
{
    for( int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
            printf("%d ",tab[i][j]);
            }
            printf("\n");
        }
}