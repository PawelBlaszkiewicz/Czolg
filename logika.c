#include"logika.h"
#include"siec.h"
#include"interpretacja.h"

int zero (int a, int b, int taba[a][b])
{
    for( int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(taba[i][j]==0)
            {
                return 1;
            }
        }
    }
    return 0;
}

int krance (int taba[N][K])
{
    int i=0,j=0;
    while(taba[i][0]==3)
    {
        i++;
    }
    if(i==0 || i==1 || i==2)
    {
        return 1;
    }
    while(taba[0][j]==3)
    {
        j++;
    }
    if(j==0 || j==1 || j==2)
    {
        return 1;
    }
    for(int k=0;k<j;k++)
    {
        if(taba[i-1][k]!=3)
        {
            return 1;
        }
    }
    for(int m=0;m<i;m++)
    {
        if(taba[m][j-1]!=3)
        {
            return 1;
        }
    }
    return 0;
}

void odwroc(int a, int b,int taba[a][b])
{
    int c;
    for( int i=0;i<a/2;i++)
    {
        for(int j=0;j<b;j++)
        {
            c=taba[i][j];
            taba[i][j]=taba[a-1-i][j];
            taba[a-1-i][j]=c;
        }
    }
}

void zapisz(FILE *fout,int a, int b, int taba[a][b])
{
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++)
        {
            fprintf(fout, "%d ", taba[i][j]);
        }
    fprintf(fout, "\n");
    }
}

int xkoniec (int taba[N][K])
{
    int i=0;
    while(taba[i][0]==3)
    {
        i++;
    }
    return i;
}

int ykoniec (int taba[N][K])
{
    int j=0;
    while(taba[0][j]==3)
    {
        j++;
    }
    return j;
}

void przepisz(int a, int b, int mapa[a][b], int taba[N][K])
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            mapa[i][j]=taba[i][j];
        }
    }
}

void ruchkoniec( int a, int b, int mapa[a][b])
{
    char *url_info =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/info/qwerty_1" ; // potem numer świata strcatem
    char *url_rleft =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/rotate/qwerty_1/left" ;
    char *url_rright =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/rotate/qwerty_1/right" ;
    char *url_move =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/move/qwerty_1" ;
    char *url_exp =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/explore/qwerty_1" ;

    cJSON *cus = make_request(url_info);
    char *x=daj_x(cus);
    char *y=daj_y(cus);
    mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
    char *kierunek=daj_kier(cus);
    

    while(krance(mapa)!=0)
    {
        x=daj_x(cus);
        y=daj_y(cus);
        kierunek=daj_kier(cus);

  if(strcmp(kierunek, "\"N\"") == 0)                    
 {
    if(mapa[1+atoi(y)][atoi(x)]==0 || mapa[1+atoi(y)][atoi(x)-1]==0 || mapa[1+atoi(y)][atoi(x)+1]==0)
    {
    cJSON *zmienna = make_request(url_exp);
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(zmienna, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "list");

    cJSON *ex1= name->child;
    cJSON *ex2=name->child->next;
    cJSON *ex3=name->child->next->next;
    
    char *x=daj_xe(ex1);
    char *y=daj_ye(ex1);
    
    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex1);
    
    cJSON_free(x);
    cJSON_free(y);
    y=daj_ye(ex2);
    x=daj_xe(ex2);

    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex2);

    cJSON_free(x);
    cJSON_free(y);
    y=daj_ye(ex3);
    x=daj_xe(ex3);

    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex3);

    cJSON_free(x);
    cJSON_free(y);

    cJSON_Delete(zmienna);
    }
 }
 else if(strcmp(kierunek, "\"E\"") == 0)
 {
    if(mapa[-1+atoi(y)][atoi(x)+1]==0 || mapa[atoi(y)][atoi(x)+1]==0 || mapa[1+atoi(y)][atoi(x)+1]==0)
    {
    cJSON *zmienna = make_request(url_exp);
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(zmienna, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "list");

    cJSON *ex1= name->child;
    cJSON *ex2=name->child->next;
    cJSON *ex3=name->child->next->next;
    
    char *x=daj_xe(ex1);
    char *y=daj_ye(ex1);
    
    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex1);
    
    cJSON_free(x);
    cJSON_free(y);
    y=daj_ye(ex2);
    x=daj_xe(ex2);

    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex2);

    cJSON_free(x);
    cJSON_free(y);
    y=daj_ye(ex3);
    x=daj_xe(ex3);

    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex3);

    cJSON_free(x);
    cJSON_free(y);

    cJSON_Delete(zmienna);
    }
 }
 else if(strcmp(kierunek, "\"S\"") == 0)            
 {
    if(mapa[-1+atoi(y)][atoi(x)+1]==0 || mapa[-1+atoi(y)][atoi(x)-1]==0 || mapa[-1+atoi(y)][atoi(x)]==0)
    {
    cJSON *zmienna = make_request(url_exp);
        cJSON *pay = cJSON_GetObjectItemCaseSensitive(zmienna, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "list");

    cJSON *ex1= name->child;
    cJSON *ex2=name->child->next;
    cJSON *ex3=name->child->next->next;
    
    char *x=daj_xe(ex1);
    char *y=daj_ye(ex1);
    
    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex1);
    
    cJSON_free(x);
    cJSON_free(y);
    y=daj_ye(ex2);
    x=daj_xe(ex2);

    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex2);

    cJSON_free(x);
    cJSON_free(y);
    y=daj_ye(ex3);
    x=daj_xe(ex3);

    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex3);

    cJSON_free(x);
    cJSON_free(y);

    cJSON_Delete(zmienna);
    }
 }
 else if(strcmp(kierunek, "\"W\"") == 0)
 {
    if(mapa[-1+atoi(y)][atoi(x)-1]==0 || mapa[atoi(y)][atoi(x)-1]==0 || mapa[1+atoi(y)][atoi(x)-1]==0)
    {
    cJSON *zmienna = make_request(url_exp);
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(zmienna, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "list");

    cJSON *ex1= name->child;
    cJSON *ex2=name->child->next;
    cJSON *ex3=name->child->next->next;
    
    char *x=daj_xe(ex1);
    char *y=daj_ye(ex1);
    
    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex1);
    
    cJSON_free(x);
    cJSON_free(y);
    y=daj_ye(ex2);
    x=daj_xe(ex2);

    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex2);

    cJSON_free(x);
    cJSON_free(y);
    y=daj_ye(ex3);
    x=daj_xe(ex3);

    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex3);

    cJSON_free(x);
    cJSON_free(y);

    cJSON_Delete(zmienna);
    }
 }
    
    
    if(strcmp(kierunek, "\"N\"") == 0)              
    {
        if(mapa[1+atoi(y)][1+atoi(x)] == 3 && mapa[1+atoi(y)][atoi(x)] == 3)
        {
            cus=make_request(url_rleft);
        }
        else if(mapa[1+atoi(y)][1+atoi(x)] != 3 && mapa[atoi(y)][1+atoi(x)] != 3 && mapa[1+atoi(y)][atoi(x)] == 3)
        {
            cus=make_request(url_rright);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
        else if(mapa[1+atoi(y)][1+atoi(x)] != 3 && mapa[atoi(y)][1+atoi(x)] != 3)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
        else if(mapa[1+atoi(y)][1+atoi(x)] == 1 || mapa[1+atoi(y)][1+atoi(x)] == 2)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
            cus=make_request(url_rright);
        }
        else if(mapa[1+atoi(y)][1+atoi(x)] == 3)
        {
            cus=make_request(url_move);
            cJSON_free(x);
            cJSON_free(y);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
    }
    else if( strcmp(kierunek, "\"E\"") == 0)
    {
        if(mapa[1+atoi(y)][1+atoi(x)] != 3 && mapa[1+atoi(y)][atoi(x)] != 3 && mapa[atoi(y)][1+atoi(x)] == 3)
        {
            cus=make_request(url_rright);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
        else if(mapa[1+atoi(y)][1+atoi(x)] != 3 && mapa[1+atoi(y)][atoi(x)] != 3)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
        else if(mapa[1+atoi(y)][1+atoi(x)] == 1 || mapa[1+atoi(y)][1+atoi(x)] == 2)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
            cus=make_request(url_rright);
        }
        else if(mapa[atoi(y)][1+atoi(x)] == 3 && mapa[1+atoi(y)][1+atoi(x)] == 3)
        {
            cus=make_request(url_rleft);
        }
        else if(mapa[1+atoi(y)][1+atoi(x)] == 3)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
    }
    else if(strcmp(kierunek, "\"S\"") == 0)                 
    {
        if(mapa[-1+atoi(y)][-1+atoi(x)] == 3 && mapa[-1+atoi(y)][atoi(x)] == 3)
        {
            cus=make_request(url_rleft);
        }
        else if(mapa[-1+atoi(y)][-1+atoi(x)] != 3 && mapa[atoi(y)][-1+atoi(x)] != 3 && mapa[-1+atoi(y)][atoi(x)] == 3)
        {
            cus=make_request(url_rright);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
        else if(mapa[-1+atoi(y)][-1+atoi(x)] != 3 && mapa[atoi(y)][-1+atoi(x)] != 3)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
        else if(mapa[-1+atoi(y)][-1+atoi(x)] == 1 || mapa[-1+atoi(y)][-1+atoi(x)] == 2)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
            cus=make_request(url_rright);
        }
        else if(mapa[-1+atoi(y)][-1+atoi(x)] == 3)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
    }
    else if( strcmp(kierunek, "\"W\"") == 0)
    {
        if(mapa[1+atoi(y)][-1+atoi(x)] != 3 && mapa[1+atoi(y)][atoi(x)] != 3 && mapa[atoi(y)][-1+atoi(x)] == 3)
        {
            cus=make_request(url_rright);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
        else if(mapa[1+atoi(y)][-1+atoi(x)] != 3 && mapa[1+atoi(y)][atoi(x)] != 3)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
        if(mapa[1+atoi(y)][-1+atoi(x)] == 1 || mapa[1+atoi(y)][-1+atoi(x)] == 2)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
            cus=make_request(url_rright);
        }
        else if(mapa[atoi(y)][-1+atoi(x)] == 3 && mapa[1+atoi(y)][-1+atoi(x)] == 3)
        {
            cus=make_request(url_rleft);
        }
        else if(mapa[1+atoi(y)][-1+atoi(x)] == 3)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
    }
    cJSON_free(x);
    cJSON_free(y);
    cJSON_free(kierunek);
 }
//  free(url_info);
//  free(url_move);
//  free(url_rleft);
//  free(url_rright);
//  free(url_exp);
 cJSON_Delete(cus);
}

void ruchzero( int a, int b, int mapa[a][b])
{
    char *url_info =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/info/qwerty_1" ; // potem numer świata strcatem
    char *url_rleft =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/rotate/qwerty_1/left" ;
    char *url_rright =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/rotate/qwerty_1/right" ;
    char *url_move =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/move/qwerty_1" ;
    char *url_exp =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/explore/qwerty_1" ;

    cJSON *cus = make_request(url_info);
    char *x=daj_x(cus);
    char *y=daj_y(cus);
    mapa[atoi(x)][atoi(y)]=zwroc_nr_pola(cus);
    char *kierunek=daj_kier(cus);

    while(zero(a,b,mapa)!=0)
    {

    x=daj_x(cus);
    y=daj_y(cus);
    kierunek=daj_kier(cus);

    wypisz(a,b,mapa);
    printf("\n");

  if(strcmp(kierunek, "\"N\"") == 0)                    
 {
    if(mapa[1+atoi(y)][atoi(x)]==0 || mapa[1+atoi(y)][atoi(x)-1]==0 || mapa[1+atoi(y)][atoi(x)+1]==0)
    {
    cJSON *zmienna = make_request(url_exp);
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(zmienna, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "list");

    cJSON *ex1= name->child;
    cJSON *ex2=name->child->next;
    cJSON *ex3=name->child->next->next;

    char *x=daj_xe(ex1);
    char *y=daj_ye(ex1);
    
    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex1);
    
    cJSON_free(x);
    cJSON_free(y);
    y=daj_ye(ex2);
    x=daj_xe(ex2);

    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex2);

    cJSON_free(x);
    cJSON_free(y);
    y=daj_ye(ex3);
    x=daj_xe(ex3);

    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex3);

    cJSON_free(x);
    cJSON_free(y);

    cJSON_Delete(zmienna);
    }
 }
 else if(strcmp(kierunek, "\"E\"") == 0)
 {
    if(mapa[-1+atoi(y)][atoi(x)+1]==0 || mapa[atoi(y)][atoi(x)+1]==0 || mapa[1+atoi(y)][atoi(x)+1]==0)
    {
    cJSON *zmienna = make_request(url_exp);
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(zmienna, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "list");

    cJSON *ex1= name->child;
    cJSON *ex2=name->child->next;
    cJSON *ex3=name->child->next->next;
    
    char *x=daj_xe(ex1);
    char *y=daj_ye(ex1);
    
    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex1);
    
    cJSON_free(x);
    cJSON_free(y);
    y=daj_ye(ex2);
    x=daj_xe(ex2);

    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex2);

    cJSON_free(x);
    cJSON_free(y);
    y=daj_ye(ex3);
    x=daj_xe(ex3);

    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex3);

    cJSON_free(x);
    cJSON_free(y);

    cJSON_Delete(zmienna);
    }
 }
 else if(strcmp(kierunek, "\"S\"") == 0)            
 {
    if(mapa[-1+atoi(y)][atoi(x)+1]==0 || mapa[-1+atoi(y)][atoi(x)-1]==0 || mapa[-1+atoi(y)][atoi(x)]==0)
    {
    cJSON *zmienna = make_request(url_exp);
        cJSON *pay = cJSON_GetObjectItemCaseSensitive(zmienna, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "list");

    cJSON *ex1= name->child;
    cJSON *ex2=name->child->next;
    cJSON *ex3=name->child->next->next;
    
    char *x=daj_xe(ex1);
    char *y=daj_ye(ex1);
    
    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex1);
    
    cJSON_free(x);
    cJSON_free(y);
    y=daj_ye(ex2);
    x=daj_xe(ex2);

    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex2);

    cJSON_free(x);
    cJSON_free(y);
    y=daj_ye(ex3);
    x=daj_xe(ex3);

    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex3);

    cJSON_free(x);
    cJSON_free(y);

    cJSON_Delete(zmienna);
    }
 }
 else if(strcmp(kierunek, "\"W\"") == 0)
 {
    if(mapa[-1+atoi(y)][atoi(x)-1]==0 || mapa[atoi(y)][atoi(x)-1]==0 || mapa[1+atoi(y)][atoi(x)-1]==0)
    {
    cJSON *zmienna = make_request(url_exp);
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(zmienna, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "list");

    cJSON *ex1= name->child;
    cJSON *ex2=name->child->next;
    cJSON *ex3=name->child->next->next;
    
    char *x=daj_xe(ex1);
    char *y=daj_ye(ex1);
    
    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex1);
    
    cJSON_free(x);
    cJSON_free(y);
    y=daj_ye(ex2);
    x=daj_xe(ex2);

    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex2);

    cJSON_free(x);
    cJSON_free(y);
    y=daj_ye(ex3);
    x=daj_xe(ex3);

    mapa[atoi(y)][atoi(x)]=zwroc_enr_pola(ex3);

    cJSON_free(x);
    cJSON_free(y);

    cJSON_Delete(zmienna);
    }
 }
    
    
    if(strcmp(kierunek, "\"N\"") == 0)              
    {
        if(mapa[1+atoi(y)][1+atoi(x)] == 3 && mapa[1+atoi(y)][atoi(x)] == 3)
        {
            cus=make_request(url_rleft);
        }
        else if(mapa[1+atoi(y)][1+atoi(x)] != 3 && mapa[atoi(y)][1+atoi(x)] != 3 && mapa[1+atoi(y)][atoi(x)] == 3)
        {
            cus=make_request(url_rright);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
        else if(mapa[1+atoi(y)][1+atoi(x)] != 3 && mapa[atoi(y)][1+atoi(x)] != 3)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
        else if(mapa[1+atoi(y)][1+atoi(x)] == 1 || mapa[1+atoi(y)][1+atoi(x)] == 2)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
            cus=make_request(url_rright);
        }
        else if(mapa[1+atoi(y)][1+atoi(x)] == 3)
        {
            cus=make_request(url_move);
            cJSON_free(x);
            cJSON_free(y);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
    }
    else if( strcmp(kierunek, "\"E\"") == 0)
    {
        if(mapa[1+atoi(y)][1+atoi(x)] != 3 && mapa[1+atoi(y)][atoi(x)] != 3 && mapa[atoi(y)][1+atoi(x)] == 3)
        {
            cus=make_request(url_rright);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
        else if(mapa[1+atoi(y)][1+atoi(x)] != 3 && mapa[1+atoi(y)][atoi(x)] != 3)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
        else if(mapa[1+atoi(y)][1+atoi(x)] == 1 || mapa[1+atoi(y)][1+atoi(x)] == 2)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
            cus=make_request(url_rright);
        }
        else if(mapa[atoi(y)][1+atoi(x)] == 3 && mapa[1+atoi(y)][1+atoi(x)] == 3)
        {
            cus=make_request(url_rleft);
        }
        else if(mapa[1+atoi(y)][1+atoi(x)] == 3)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
    }
    else if(strcmp(kierunek, "\"S\"") == 0)                 
    {
        if(mapa[-1+atoi(y)][-1+atoi(x)] == 3 && mapa[-1+atoi(y)][atoi(x)] == 3)
        {
            cus=make_request(url_rleft);
        }
        else if(mapa[-1+atoi(y)][-1+atoi(x)] != 3 && mapa[atoi(y)][-1+atoi(x)] != 3 && mapa[-1+atoi(y)][atoi(x)] == 3)
        {
            cus=make_request(url_rright);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
        else if(mapa[-1+atoi(y)][-1+atoi(x)] != 3 && mapa[atoi(y)][-1+atoi(x)] != 3)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
        else if(mapa[-1+atoi(y)][-1+atoi(x)] == 1 || mapa[-1+atoi(y)][-1+atoi(x)] == 2)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
            cus=make_request(url_rright);
        }
        else if(mapa[-1+atoi(y)][-1+atoi(x)] == 3)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
    }
    else if( strcmp(kierunek, "\"W\"") == 0)
    {
        if(mapa[1+atoi(y)][-1+atoi(x)] != 3 && mapa[1+atoi(y)][atoi(x)] != 3 && mapa[atoi(y)][-1+atoi(x)] == 3)
        {
            cus=make_request(url_rright);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
        else if(mapa[1+atoi(y)][-1+atoi(x)] != 3 && mapa[1+atoi(y)][atoi(x)] != 3)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
        if(mapa[1+atoi(y)][-1+atoi(x)] == 1 || mapa[1+atoi(y)][-1+atoi(x)] == 2)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
            cus=make_request(url_rright);
        }
        else if(mapa[atoi(y)][-1+atoi(x)] == 3 && mapa[1+atoi(y)][-1+atoi(x)] == 3)
        {
            cus=make_request(url_rleft);
        }
        else if(mapa[1+atoi(y)][-1+atoi(x)] == 3)
        {
            cus=make_request(url_move);
            cJSON_free(y);
            cJSON_free(x);
            x=daj_x(cus);
            y=daj_y(cus);
            mapa[atoi(y)][atoi(x)]=zwroc_nr_pola(cus);
        }
    }
    cJSON_free(x);
    cJSON_free(y);
 }
 free(url_info);
 free(url_move);
 free(url_rleft);
 free(url_rright);
 free(url_exp);
 cJSON_Delete(cus);
}