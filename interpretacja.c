#include "interpretacja.h"


int daj_x(cJSON *cus)
{
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(cus, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "current_x");
    return atof(cJSON_Print(name));
}

cJSON * daj_xc(cJSON *cus)
{
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(cus, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "current_x");
    cJSON_Delete(pay);
    return name;
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

cJSON *  daj_exp(cJSON *cus, int i) // można zrobić cjsona i dzieki temu łatwo zwalniać
{
    if(i==1)
    {
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(cus, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "list");
    return name->child;
    }
    else if(i==2)
    {
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(cus, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "list");
    return name->child->next;
    }
    else if(i==3)
    {
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(cus, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "list");
    return name->child->next->next;
    }
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

void wypisz(int tab[N][K])
{
    for( int i=0;i<N;i++)
        {
            for(int j=0;j<K;j++)
            {
            printf("%d ",tab[i][j]);
            }
            printf("\n");
        }
}

cJSON *cinfo(char *url)
{
    //Memory *pamiontka;
    //pamiontka=(Memory*)malloc(sizeof(Memory));
    //pamiontka->size=0;
    //char bufor[2048];
    //pamiontka->response = make_request(url);
    //strcpy(bufor,pamiontka->response);
    //free(pamiontka->response);

    //return cJSON_Parse(&bufor[178]);
}

cJSON *cex(char *url, int i)
{   
    cJSON *cus=make_request(url);
    if(i==1)
    {
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(cus, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "list");
    return name->child;
    }
    else if(i==2)
    {
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(cus, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "list");
    return name->child->next;
    }
    else if(i==3)
    {
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(cus, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "list");
    return name->child->next->next;
    }
}