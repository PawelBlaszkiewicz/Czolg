#include "interpretacja.h"


int daj_x(cJSON *cus)
{
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(cus, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "current_x");
    char *ah=cJSON_Print(name);
    int a=atoi(ah);
    cJSON_free(ah);
    return a;
}

int daj_y(cJSON *cus)
{
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(cus, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "current_y");
    char *ah=cJSON_Print(name);
    int a=atoi(ah);
    cJSON_free(ah);
    return a;
}

char * daj_pole(cJSON *cus)
{
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(cus, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "field_type");
    char *pol=cJSON_Print(name);
    return pol;
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
    char *ah=cJSON_Print(name);
    int a=atoi(ah);
    cJSON_free(ah);
    return a;
}

int daj_ye(cJSON *cus)
{
    cJSON *name = cJSON_GetObjectItemCaseSensitive(cus, "y");
    char *ah=cJSON_Print(name);
    int a=atoi(ah);
    cJSON_free(ah);
    return a;
}

char * daj_type(cJSON *cus)
{
    cJSON *name = cJSON_GetObjectItemCaseSensitive(cus, "type");
    return cJSON_Print(name);
}

int zwroc_nr_pola(cJSON *a)
{
    char *pol=daj_pole(a);
    if(strcmp(pol, "\"grass\"" )==0)
        {
            free(pol);
            return 1;
        }
        else if(strcmp(pol,"\"sand\"")==0)
        {
            free(pol);
            return 2;
        }
        else if(strcmp(pol,"\"wall\"")==0)
        {
            free(pol);
            return 3;
        }
}

int zwroc_enr_pola(cJSON *a)
{
        char *pol=daj_type(a);
        if(strcmp(pol, "\"grass\"" )==0)
        {
            cJSON_free(pol);
            return 1;
        }
        else if(strcmp(pol,"\"sand\"")==0)
        {
            cJSON_free(pol);
            return 2;
        }
        else if(strcmp(pol,"\"wall\"")==0)
        {
            cJSON_free(pol);
            return 3;
        }
}

int daj_krok(char *url)
{
    char *url_info =  url ;
    cJSON *cus=make_request(url_info);
    cJSON *c = cJSON_GetObjectItemCaseSensitive(cus, "payload") ;
    cJSON *name = cJSON_GetObjectItemCaseSensitive(c, "step");

    char *dd=cJSON_Print(name);

    int g=atoi(dd);

    cJSON_Delete(cus);
    cJSON_free(dd);
    
    return g;
}