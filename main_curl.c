#include"siec.h"
#include"logika.h"
#include "../cJSON/cJSON.h"
#include"interpretacja.h"

#define N 12
#define K 9

int main(int argc, char **argv)
{
    int mapa[N][K] ; // 1 - grass , 2 - sand , 3 - wall
    for( int i=0;i<N;i++)
    {
        for(int j=0;j<K;j++)
        {
            mapa[i][j]=0;
        }
    }

    FILE *fout=fopen("mapa.txt","w");

    char *url_info =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/info/qwerty_1" ; // potem numer świata strcatem
    char *url_rleft =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/rotate/qwerty_1/left" ;
    char *url_rright =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/rotate/qwerty_1/right" ;
    char *url_move =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/move/qwerty_1" ;
    char *url_exp =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/explore/qwerty_1" ;

    cJSON *cus = make_request(url_info);
    mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);

    int i=0;
    while(zero(mapa)!=0) 
    {

if(strcmp(daj_kier(cus), "\"N\"") == 0)
{
    if(mapa[N-2-daj_y(cus)][daj_x(cus)]==0 || mapa[N-2-daj_y(cus)][daj_x(cus)-1]==0 || mapa[N-2-daj_y(cus)][daj_x(cus)+1]==0)
    {
        cJSON *zmienna = make_request(url_exp);
        cJSON *pay = cJSON_GetObjectItemCaseSensitive(zmienna, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "list");

    cJSON *ex1= name->child;
    cJSON *ex2=name->child->next;
    cJSON *ex3=name->child->next->next;
    
    mapa[N-1-daj_ye(ex1)][daj_xe(ex1)]=zwroc_enr_pola(ex1);
    mapa[N-1-daj_ye(ex2)][daj_xe(ex2)]=zwroc_enr_pola(ex2);
    mapa[N-1-daj_ye(ex3)][daj_xe(ex3)]=zwroc_enr_pola(ex3);

    cJSON_Delete(zmienna);
    }
}
else if(strcmp(daj_kier(cus), "\"E\"") == 0)
{
    if(mapa[N-2-daj_y(cus)][daj_x(cus)+1]==0 || mapa[N-1-daj_y(cus)][daj_x(cus)+1]==0 || mapa[N-daj_y(cus)][daj_x(cus)+1]==0)
    {
    cJSON *zmienna = make_request(url_exp);
        cJSON *pay = cJSON_GetObjectItemCaseSensitive(zmienna, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "list");

    cJSON *ex1= name->child;
    cJSON *ex2=name->child->next;
    cJSON *ex3=name->child->next->next;
    
    mapa[N-1-daj_ye(ex1)][daj_xe(ex1)]=zwroc_enr_pola(ex1);
    mapa[N-1-daj_ye(ex2)][daj_xe(ex2)]=zwroc_enr_pola(ex2);
    mapa[N-1-daj_ye(ex3)][daj_xe(ex3)]=zwroc_enr_pola(ex3);

    // cJSON_Delete(ex1);
    // cJSON_Delete(ex2);
    // cJSON_Delete(ex3);
    cJSON_Delete(zmienna);
    }
}
else if(strcmp(daj_kier(cus), "\"S\"") == 0)
{
    if(mapa[N-daj_y(cus)][daj_x(cus)+1]==0 || mapa[N-daj_y(cus)][daj_x(cus)-1]==0 || mapa[N-daj_y(cus)][daj_x(cus)]==0)
    {
    cJSON *zmienna = make_request(url_exp);
        cJSON *pay = cJSON_GetObjectItemCaseSensitive(zmienna, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "list");

    cJSON *ex1= name->child;
    cJSON *ex2=name->child->next;
    cJSON *ex3=name->child->next->next;
    
    mapa[N-1-daj_ye(ex1)][daj_xe(ex1)]=zwroc_enr_pola(ex1);
    mapa[N-1-daj_ye(ex2)][daj_xe(ex2)]=zwroc_enr_pola(ex2);
    mapa[N-1-daj_ye(ex3)][daj_xe(ex3)]=zwroc_enr_pola(ex3);

    cJSON_Delete(zmienna);
    }
}
else if(strcmp(daj_kier(cus), "\"W\"") == 0)
{
    if(mapa[N-2-daj_y(cus)][daj_x(cus)-1]==0 || mapa[N-1-daj_y(cus)][daj_x(cus)-1]==0 || mapa[N-daj_y(cus)][daj_x(cus)-1]==0)
    {
    cJSON *zmienna = make_request(url_exp);
        cJSON *pay = cJSON_GetObjectItemCaseSensitive(zmienna, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "list");

    cJSON *ex1= name->child;
    cJSON *ex2=name->child->next;
    cJSON *ex3=name->child->next->next;
    
    mapa[N-1-daj_ye(ex1)][daj_xe(ex1)]=zwroc_enr_pola(ex1);
    mapa[N-1-daj_ye(ex2)][daj_xe(ex2)]=zwroc_enr_pola(ex2);
    mapa[N-1-daj_ye(ex3)][daj_xe(ex3)]=zwroc_enr_pola(ex3);

    cJSON_Delete(zmienna);
    }
}
    
    
    if(strcmp(daj_kier(cus), "\"N\"") == 0)
    {
        if(mapa[N-2-daj_y(cus)][1+daj_x(cus)] == 3 && mapa[N-2-daj_y(cus)][daj_x(cus)] == 3)
        {
            cus=make_request(url_rleft);
        }
        else if(mapa[N-2-daj_y(cus)][1+daj_x(cus)] != 3 && mapa[N-1-daj_y(cus)][1+daj_x(cus)] != 3 && mapa[N-2-daj_y(cus)][daj_x(cus)] == 3)
        {
            cus=make_request(url_rright);
            mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);
        }
        else if(mapa[N-2-daj_y(cus)][1+daj_x(cus)] != 3 && mapa[N-1-daj_y(cus)][1+daj_x(cus)] != 3)
        {
            cus=make_request(url_move);
            mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);
        }
        else if(mapa[N-2-daj_y(cus)][1+daj_x(cus)] == 1 || mapa[N-2-daj_y(cus)][1+daj_x(cus)] == 2)
        {
            cus=make_request(url_move);
            mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);
            cus=make_request(url_rright);
        }
        else if(mapa[N-2-daj_y(cus)][1+daj_x(cus)] == 3)
        {
            cus=make_request(url_move);
            mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);
        }
    }
    else if( strcmp(daj_kier(cus), "\"E\"") == 0)
    {
        if(mapa[N-daj_y(cus)][1+daj_x(cus)] != 3 && mapa[N-daj_y(cus)][daj_x(cus)] != 3 && mapa[N-1-daj_y(cus)][1+daj_x(cus)] == 3)
        {
            cus=make_request(url_rright);
            mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);
        }
        else if(mapa[N-daj_y(cus)][1+daj_x(cus)] != 3 && mapa[N-daj_y(cus)][daj_x(cus)] != 3)
        {
            cus=make_request(url_move);
            mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);
        }
        else if(mapa[N-daj_y(cus)][1+daj_x(cus)] == 1 || mapa[N-daj_y(cus)][1+daj_x(cus)] == 2)
        {
            cus=make_request(url_move);
            mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);
            cus=make_request(url_rright);
        }
        else if(mapa[N-1-daj_y(cus)][1+daj_x(cus)] == 3 && mapa[N-daj_y(cus)][1+daj_x(cus)] == 3)
        {
            cus=make_request(url_rleft);
        }
        else if(mapa[N-daj_y(cus)][1+daj_x(cus)] == 3)
        {
            cus=make_request(url_move);
            mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);
        }
    }
    else if(strcmp(daj_kier(cus), "\"S\"") == 0)
    {
        if(mapa[N-daj_y(cus)][-1+daj_x(cus)] == 3 && mapa[N-daj_y(cus)][daj_x(cus)] == 3)
        {
            cus=make_request(url_rleft);
        }
        else if(mapa[N-daj_y(cus)][-1+daj_x(cus)] != 3 && mapa[N-1-daj_y(cus)][-1+daj_x(cus)] != 3 && mapa[N-2-daj_y(cus)][daj_x(cus)] == 3)
        {
            cus=make_request(url_rright);
            mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);
        }
        else if(mapa[N-daj_y(cus)][-1+daj_x(cus)] != 3 && mapa[N-1-daj_y(cus)][-1+daj_x(cus)] != 3)
        {
            cus=make_request(url_move);
            mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);
        }
        else if(mapa[N-daj_y(cus)][-1+daj_x(cus)] == 1 || mapa[N-daj_y(cus)][-1+daj_x(cus)] == 2)
        {
            cus=make_request(url_move);
            mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);
            cus=make_request(url_rright);
        }
        else if(mapa[N-daj_y(cus)][-1+daj_x(cus)] == 3)
        {
            cus=make_request(url_move);
            mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);
        }
    }
    else if( strcmp(daj_kier(cus), "\"W\"") == 0)
    {
        if(mapa[N-2-daj_y(cus)][-1+daj_x(cus)] != 3 && mapa[N-2-daj_y(cus)][daj_x(cus)] != 3 && mapa[N-1-daj_y(cus)][-1+daj_x(cus)] == 3)
        {
            cus=make_request(url_rright);
            mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);
        }
        else if(mapa[N-2-daj_y(cus)][-1+daj_x(cus)] != 3 && mapa[N-2-daj_y(cus)][daj_x(cus)] != 3)
        {
            cus=make_request(url_move);
            mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);
        }
        if(mapa[N-2-daj_y(cus)][-1+daj_x(cus)] == 1 || mapa[N-2-daj_y(cus)][-1+daj_x(cus)] == 2)
        {
            cus=make_request(url_move);
            mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);
            cus=make_request(url_rright);
        }
        else if(mapa[N-1-daj_y(cus)][-1+daj_x(cus)] == 3 && mapa[N-2-daj_y(cus)][-1+daj_x(cus)] == 3)
        {
            cus=make_request(url_rleft);
        }
        else if(mapa[N-2-daj_y(cus)][-1+daj_x(cus)] == 3)
        {
            cus=make_request(url_move);
            mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);
        }
    }
    
    i++;
    }
    cJSON *c = cJSON_GetObjectItemCaseSensitive(cus, "payload") ;
    cJSON *name = cJSON_GetObjectItemCaseSensitive(c, "step");
    printf("STEP : %s\n", cJSON_Print(name));
    cJSON_Delete(cus);
    wypisz(mapa);
    zapisz(fout , mapa);
    fclose(fout);

  return 0;
}