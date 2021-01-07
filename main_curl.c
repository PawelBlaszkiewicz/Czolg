#include"siec.h"
#include"logika.h"
#include "../cJSON/cJSON.h"
#include"interpretacja.h"

#define N 12
#define K 9

//teraz ruch

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


    // cJSON *proba = daj_xc(cus);
    // printf("%d\n", proba->valueint);
    // cJSON_Delete(proba);
    


    int i=0;
    while(zero(mapa)!=0) 
    {
    //cus = make_request(url_info);
    

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

    //cJSON_Delete(ex1);
    //cJSON_Delete(ex2);
    //cJSON_Delete(ex3);
    cJSON_Delete(zmienna);
    //cJSON_Delete(pay);
    //cJSON_Delete(name);
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

    









































/*
    for(int i=1;i<argc;i++)
{
    if(strcmp(argv[i],"info")==0)
    {
        pamiontka->response = make_request(url_info);
        strcpy(bufor,pamiontka->response);
        cJSON *cus = cJSON_Parse(&bufor[178]);
        //printf("%s\n", bufor);
        free(pamiontka->response);
        printf("Współrzędne żólwwwia: [%d,%d], pole : %s, kierunek: %s\n",daj_x(cus), daj_y(cus), daj_pole(cus), daj_kier(cus));
        mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);
int i=0;
        while(i<10)
        {
        pamiontka->response = make_request(url_move);
        strcpy(bufor,pamiontka->response);
        cJSON *cus = cJSON_Parse(&bufor[178]);
        //printf("%s\n", bufor);
        free(pamiontka->response);
        printf("Współrzędne żólwwwia: [%d,%d], pole : %s, kierunek: %s\n",daj_x(cus), daj_y(cus), daj_pole(cus), daj_kier(cus));
        mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);
        cJSON_Delete(cus);

        pamiontka->response = make_request(url_exp);
         strcpy(bufor,pamiontka->response);
            cus = cJSON_Parse(&bufor[178]);
         //printf("%s\n", bufor);
         printf("Pola przed zolwwwiem:\n");
         printf("[%d,%d] - %s\n", daj_xe(daj_exp(cus,1)), daj_ye(daj_exp(cus,1)), daj_type(daj_exp(cus,1)));
         printf("[%d,%d] - %s\n", daj_xe(daj_exp(cus,2)), daj_ye(daj_exp(cus,2)), daj_type(daj_exp(cus,2)));
         printf("[%d,%d] - %s\n", daj_xe(daj_exp(cus,3)), daj_ye(daj_exp(cus,3)), daj_type(daj_exp(cus,3)));
         free(pamiontka->response);
         
        mapa[N-1-daj_ye(daj_exp(cus,1))][daj_xe(daj_exp(cus,1))]=zwroc_enr_pola(cus,1);
        mapa[N-1-daj_ye(daj_exp(cus,2))][daj_xe(daj_exp(cus,2))]=zwroc_enr_pola(cus,2);
        mapa[N-1-daj_ye(daj_exp(cus,3))][daj_xe(daj_exp(cus,3))]=zwroc_enr_pola(cus,3);
i++;
        cJSON_Delete(cus);
        }
        

        cJSON_Delete(cus);
    }
    else if(strcmp(argv[i],"rotate_left")==0)
    {
        pamiontka->response = make_request(url_rleft);
        strcpy(bufor,pamiontka->response);
        cJSON *cus = cJSON_Parse(&bufor[178]);
        //printf("%s\n", bufor);
        free(pamiontka->response);
        printf("Współrzędne żólwwwia: [%d,%d], kierunek: %s\n",daj_x(cus), daj_y(cus), daj_kier(cus));
    }
    else if(strcmp(argv[i],"rotate_right")==0)
    {
        pamiontka->response = make_request(url_rright);
        strcpy(bufor,pamiontka->response);
        cJSON *cus = cJSON_Parse(&bufor[178]);
        //printf("%s\n", bufor);
        free(pamiontka->response);
        printf("Współrzędne żólwwwia: [%d,%d], kierunek: %s\n",daj_x(cus), daj_y(cus), daj_kier(cus));
    }
    else if(strcmp(argv[i],"move")==0)
    {
        pamiontka->response = make_request(url_move);
        strcpy(bufor,pamiontka->response);
        cJSON *cus = cJSON_Parse(&bufor[178]);
        //printf("%s\n", bufor);
        free(pamiontka->response);
        printf("Współrzędne żólwwwia: [%d,%d], pole : %s, kierunek: %s\n",daj_x(cus), daj_y(cus), daj_pole(cus), daj_kier(cus));
        mapa[N-1-daj_y(cus)][daj_x(cus)]=zwroc_nr_pola(cus);
        cJSON_Delete(cus);
    }
    else if(strcmp(argv[i],"explore")==0)
    {
         pamiontka->response = make_request(url_exp);
         strcpy(bufor,pamiontka->response);
         cJSON *cus = cJSON_Parse(&bufor[178]);
         //printf("%s\n", bufor);
         printf("Pola przed zolwwwiem:\n");
         printf("[%d,%d] - %s\n", daj_xe(daj_exp(cus,1)), daj_ye(daj_exp(cus,1)), daj_type(daj_exp(cus,1)));
         printf("[%d,%d] - %s\n", daj_xe(daj_exp(cus,2)), daj_ye(daj_exp(cus,2)), daj_type(daj_exp(cus,2)));
         printf("[%d,%d] - %s\n", daj_xe(daj_exp(cus,3)), daj_ye(daj_exp(cus,3)), daj_type(daj_exp(cus,3)));
         free(pamiontka->response);
         
        mapa[N-1-daj_ye(daj_exp(cus,1))][daj_xe(daj_exp(cus,1))]=zwroc_enr_pola(cus,1);
        mapa[N-1-daj_ye(daj_exp(cus,2))][daj_xe(daj_exp(cus,2))]=zwroc_enr_pola(cus,2);
        mapa[N-1-daj_ye(daj_exp(cus,3))][daj_xe(daj_exp(cus,3))]=zwroc_enr_pola(cus,3);

        cJSON_Delete(cus);
    }

    
}
*/
//wypisz(mapa);

//cJSON_Delete(cus);

  return 0;
}