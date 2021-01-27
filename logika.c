#include"logika.h"
#include"siec.h"
#include"interpretacja.h"

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

int zwroc_x (int a, int b, int tab[a][b])
{
    for( int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(tab[i][j]==3)
            {
                return i;
            }
        }
    }
    
}

int zwroc_y(int a, int b, int tab[a][b])
{
    for( int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(tab[i][j]==3)
            {
                return j;
            }
        }
    }
}

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

int krance (int a,int b,int taba[a][b])
{
    int i=0,j=0,m=0,k=0;

    int x=zwroc_x(a,b,taba);
    int y=zwroc_y(a,b,taba);
    
    while(taba[y+i][x]==3)
    {
        i++;
    }

    if(i==0 || i==1 || i==2)
    {
            return 1;
    }

    while(taba[y][x+j]==3)
    {
        j++;
    }

    if(j==0 || j==1 || j==2)
    {
        return 1;
    }

    for(k=0;k<j;k++)
    {
        if(taba[y+i-1][x+k]!=3)
        {
            return 1;
        }
    }
    
    for(m=0;m<i;m++)
    {
        if(taba[y+m][x+j-1]!=3)
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

int xkoniec (int a,int b,int taba[a][b])
{
    int i=0;
    while(taba[zwroc_x(a,b,taba)+i][zwroc_y(a,b,taba)]==3)
    {
        i++;
    }
    return i;
}

int ykoniec (int a,int b,int taba[a][b])
{
    int j=0;
    while(taba[zwroc_x(a,b,taba)][zwroc_y(a,b,taba)+j]==3)
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
            mapa[i][j]=taba[zwroc_x(N,K,taba)+i][zwroc_y(N,K,taba)+j];
        }
    }
}

void exploruj(cJSON *zmienna, int a, int b, int mapa[a][b])
{
    cJSON *pay = cJSON_GetObjectItemCaseSensitive(zmienna, "payload");
    cJSON *name = cJSON_GetObjectItemCaseSensitive(pay, "list");

    cJSON *ex1= name->child;
    cJSON *ex2=name->child->next;
    cJSON *ex3=name->child->next->next;

    int xe=daj_xe(ex1);
    int ye=daj_ye(ex1);
    
    mapa[ye+20][xe+20]=zwroc_enr_pola(ex1);
    
    ye=daj_ye(ex2);
    xe=daj_xe(ex2);

    mapa[ye+20][xe+20]=zwroc_enr_pola(ex2);

    ye=daj_ye(ex3);
    xe=daj_xe(ex3);

    mapa[ye+20][xe+20]=zwroc_enr_pola(ex3);
}

void exploruj_jesli_musisz(int a, int b, int mapa[a][b], char *kierunek, int x, int y, int bilans_skrety, cJSON *cus, char *url1, char *url2)
{
    char *url_exp =  url1;
    char *url_rleft =  url2;

    if(strcmp(kierunek, "\"N\"") == 0)                    
 {
    if(mapa[1+y][x]!=0 && mapa[1+y][x-1]!=0 && mapa[1+y][x+1]!=0 && bilans_skrety == -4)
    {
        cJSON_Delete(cus);
        cus=make_request(url_rleft);
    }
    else if(mapa[1+y][x]==0 || mapa[1+y][x-1]==0 || mapa[1+y][x+1]==0)
    {
        cJSON *zmienna = make_request(url_exp);
    
        exploruj(zmienna, a, b, mapa);

        cJSON_Delete(zmienna);
    }
 }
 else if(strcmp(kierunek, "\"E\"") == 0)
 {
    if(mapa[-1+y][x+1]!=0 && mapa[y][x+1]!=0 && mapa[1+y][x+1]!=0 && bilans_skrety == -4)
    {
        cJSON_Delete(cus);
        cus=make_request(url_rleft);
    }
    else if(mapa[-1+y][x+1]==0 || mapa[y][x+1]==0 || mapa[1+y][x+1]==0)
    {
        cJSON *zmienna = make_request(url_exp);
    
        exploruj(zmienna, a, b, mapa);

        cJSON_Delete(zmienna);
    }
 }
 else if(strcmp(kierunek, "\"S\"") == 0)            
 {
    if(mapa[-1+y][x+1]!=0 && mapa[-1+y][x-1]!=0 && mapa[-1+y][x]!=0 && bilans_skrety == -4)
    {
        cJSON_Delete(cus);
        cus=make_request(url_rleft);
    }
    else if(mapa[-1+y][x+1]==0 || mapa[-1+y][x-1]==0 || mapa[-1+y][x]==0)
    {
        cJSON *zmienna = make_request(url_exp);
    
        exploruj(zmienna, a, b, mapa);

        cJSON_Delete(zmienna);
    }
 }
 else if(strcmp(kierunek, "\"W\"") == 0)
 {
    if(mapa[-1+y][x-1]!=0 && mapa[y][x-1]!=0 && mapa[1+y][x-1]!=0 && bilans_skrety == -4)
    {
        cJSON_Delete(cus);
        cus=make_request(url_rleft);
    }
    else if(mapa[-1+y][x-1]==0 || mapa[y][x-1]==0 || mapa[1+y][x-1]==0)
    {
        cJSON *zmienna = make_request(url_exp);
    
        exploruj(zmienna, a, b, mapa);

        cJSON_Delete(zmienna);
    }
 }
}

cJSON *ruszaj(int a, int b, int mapa[a][b], char *kierunek, int x, int y, int bilans_skrety, cJSON *cus, char *url1, char *url2, char *url3)
{
    char *url_rleft =  url1;
    char *url_rright =  url2;
    char *url_move =  url3;

    if(strcmp(kierunek, "\"N\"") == 0)              
    {
        if(mapa[1+y][1+x] == 3 && mapa[1+y][x] == 3)
        {
            cJSON_Delete(cus);
            cus=make_request(url_rleft);
            bilans_skrety++;
        }
        else if(mapa[1+y][1+x] != 3 && mapa[y][1+x] != 3 && mapa[1+y][x] == 3)
        {
            cJSON_Delete(cus);
            cus=make_request(url_rright);
            bilans_skrety--;
            x=daj_x(cus);
            y=daj_y(cus);
        }
        else if(mapa[1+y][1+x] != 3 && mapa[y][1+x] != 3)
        {
            cJSON_Delete(cus);
            cus=make_request(url_move);
            x=daj_x(cus);
            y=daj_y(cus);
        }
        else if(mapa[1+y][1+x] == 1 || mapa[1+y][1+x] == 2)
        {
            cJSON_Delete(cus);
            cus=make_request(url_move);
            x=daj_x(cus);
            y=daj_y(cus);
            cJSON_Delete(cus);
            cus=make_request(url_rright);
            bilans_skrety--;
        }
        else if(mapa[1+y][1+x] == 3)
        {
            cJSON_Delete(cus);
            cus=make_request(url_move);
            x=daj_x(cus);
            y=daj_y(cus);
        }
    }
    else if( strcmp(kierunek, "\"E\"") == 0)
    {
        if(mapa[1+y][1+x] != 3 && mapa[1+y][x] != 3 && mapa[y][1+x] == 3)
        {
            cJSON_Delete(cus);
            cus=make_request(url_rright);
            bilans_skrety--;
            x=daj_x(cus);
            y=daj_y(cus);
        }
        else if(mapa[1+y][1+x] != 3 && mapa[1+y][x] != 3)
        {
            cJSON_Delete(cus);
            cus=make_request(url_move);
            x=daj_x(cus);
            y=daj_y(cus);
        }
        else if(mapa[1+y][1+x] == 1 || mapa[1+y][1+x] == 2)
        {
            cJSON_Delete(cus);
            cus=make_request(url_move);
            x=daj_x(cus);
            y=daj_y(cus);
            cJSON_Delete(cus);
            cus=make_request(url_rright);
            bilans_skrety--;
        }
        else if(mapa[y][1+x] == 3 && mapa[1+y][1+x] == 3)
        {
            cJSON_Delete(cus);
            cus=make_request(url_rleft);
            bilans_skrety++;
        }
        else if(mapa[1+y][1+x] == 3)
        {
            cJSON_Delete(cus);
            cus=make_request(url_move);
            x=daj_x(cus);
            y=daj_y(cus);
        }
    }
    else if(strcmp(kierunek, "\"S\"") == 0)                 
    {   
        if(mapa[-1+y][-1+x] == 3 && mapa[-1+y][x] == 3)
        {
            cJSON_Delete(cus);
            cus=make_request(url_rleft);
            bilans_skrety++;
        }
        else if(mapa[-1+y][-1+x] != 3 && mapa[y][-1+x] != 3 && mapa[-1+y][x] == 3)
        {
            cJSON_Delete(cus);
            cus=make_request(url_rright);
            bilans_skrety--;
            x=daj_x(cus);
            y=daj_y(cus);
        }
        else if(mapa[-1+y][-1+x] != 3 && mapa[y][-1+x] != 3)
        {
            cJSON_Delete(cus);
            cus=make_request(url_move);
            x=daj_x(cus);
            y=daj_y(cus);
        }
        else if(mapa[-1+y][-1+x] == 1 || mapa[-1+y][-1+x] == 2)
        {
            cJSON_Delete(cus);
            cus=make_request(url_move);
            x=daj_x(cus);
            y=daj_y(cus);
            cJSON_Delete(cus);
            cus=make_request(url_rright);
            bilans_skrety--;
        }
        else if(mapa[-1+y][-1+x] == 3)
        {
            cJSON_Delete(cus);
            cus=make_request(url_move);
            x=daj_x(cus);
            y=daj_y(cus);
        }
    }
    else if( strcmp(kierunek, "\"W\"") == 0)
    {
        if(mapa[1+y][-1+x] != 3 && mapa[1+y][x] != 3 && mapa[y][-1+x] == 3)
        {
            cJSON_Delete(cus);
            cus=make_request(url_rright);
            bilans_skrety--;
            x=daj_x(cus);
            y=daj_y(cus);
        }
        else if(mapa[1+y][-1+x] != 3 && mapa[1+y][x] != 3)
        {
            cJSON_Delete(cus);
            cus=make_request(url_move);
            x=daj_x(cus);
            y=daj_y(cus);
        }
        if(mapa[1+y][-1+x] == 1 || mapa[1+y][-1+x] == 2)
        {
            cJSON_Delete(cus);
            cus=make_request(url_move);
            x=daj_x(cus);
            y=daj_y(cus);
            cJSON_Delete(cus);
            cus=make_request(url_rright);
            bilans_skrety--;
        }
        else if(mapa[y][-1+x] == 3 && mapa[1+y][-1+x] == 3)
        {
            cJSON_Delete(cus);
            cus=make_request(url_rleft);
            bilans_skrety++;
        }
        else if(mapa[1+y][-1+x] == 3)
        {
            cJSON_Delete(cus);
            cus=make_request(url_move);
            x=daj_x(cus);
            y=daj_y(cus);
        }
    }
    return cus;
}

int zwroc_x_zera(int a, int b, int mapa[a][b])
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(mapa[i][j]==0)
            return i;
        }
    }
}

int zwroc_y_zera(int a, int b, int mapa[a][b])
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(mapa[i][j]==0)
            return j;
        }
    }
}

cJSON *ruszaj_do_zera(int a, int b, int mapa[a][b], char *kierunek, int x, int y, int bilans_skrety, cJSON *cus, char *url1, char *url2, char *url3)
{
    char *url_rleft =  url1;
    char *url_rright =  url2;
    char *url_move =  url3;

    int dlugosc_mapy = xkoniec(N,K,mapa);
    int szerokosc_mapy = ykoniec(N,K,mapa);
    int nowa_mapa[dlugosc_mapy][szerokosc_mapy];

    przepisz(dlugosc_mapy , szerokosc_mapy , nowa_mapa , mapa);

    int yo = zwroc_x_zera(dlugosc_mapy , szerokosc_mapy , nowa_mapa );
    int xo = zwroc_y_zera(dlugosc_mapy , szerokosc_mapy , nowa_mapa );
    yo = yo+20;
    xo = xo+20;

    if(y == yo && x < xo)
    {
        if(strcmp(kierunek, "\"N\"") == 0)
        {
            cJSON_Delete(cus);
            cus = make_request(url_rright);
        }
        else if(strcmp(kierunek, "\"E\"") == 0)
        {
            if(mapa[yo][x+1]!=3)
            {
                cJSON_Delete(cus);
                cus = make_request(url_move);
            }
            else
            {
                while(y == yo)
                {
                    kierunek = daj_kier(cus);
                    cus = ruszaj(a,b,mapa,kierunek, x,y,bilans_skrety,cus,url1,url2,url3);
                    x=daj_x(cus)+20;
                    y=daj_y(cus)+20;
                    cJSON_free(kierunek);
                }
            }
        }
        else if(strcmp(kierunek, "\"S\"") == 0)
        {
            cJSON_Delete(cus);
            cus = make_request(url_rleft);
        }
        else if(strcmp(kierunek, "\"W\"") == 0)
        {
            cJSON_Delete(cus);
            cus = make_request(url_rleft);
            cJSON_Delete(cus);
            cus = make_request(url_rleft);
        }
    }
    else if(y == yo && x > xo)
    {
        if(strcmp(kierunek, "\"N\"") == 0)
        {
            cJSON_Delete(cus);
            cus = make_request(url_rleft);
        }
        else if(strcmp(kierunek, "\"E\"") == 0)
        {
            cJSON_Delete(cus);
            cus = make_request(url_rleft);
            cJSON_Delete(cus);
            cus = make_request(url_rleft);
        }
        else if(strcmp(kierunek, "\"S\"") == 0)
        {
            cJSON_Delete(cus);
            cus = make_request(url_rright);
        }
        else if(strcmp(kierunek, "\"W\"") == 0)
        {
            if(mapa[yo][x-1]!=3)
            {
                cJSON_Delete(cus);
                cus = make_request(url_move);
            }
            else
            {
                while( y == yo)
                {
                    kierunek = daj_kier(cus);
                    cus = ruszaj(a,b,mapa,kierunek, x,y,bilans_skrety,cus,url1,url2,url3);
                    x=daj_x(cus)+20;
                    y=daj_y(cus)+20;
                    cJSON_free(kierunek);
                }
            }
        }
    }
    else if(y > yo && x == xo)
    {
        if(strcmp(kierunek, "\"N\"") == 0)
        {
            cJSON_Delete(cus);
            cus = make_request(url_rleft);
            cJSON_Delete(cus);
            cus = make_request(url_rleft);
        }
        else if(strcmp(kierunek, "\"E\"") == 0)
        {
            cJSON_Delete(cus);
            cus = make_request(url_rleft);
        }
        else if(strcmp(kierunek, "\"S\"") == 0)
        {
            if(mapa[yo+1][x]!=3)
            {
                cJSON_Delete(cus);
                cus = make_request(url_move);
            }
            else
            {
                while(x == xo)
                {
                    kierunek = daj_kier(cus);
                    cus = ruszaj(a,b,mapa,kierunek, x,y,bilans_skrety,cus,url1,url2,url3);
                    x=daj_x(cus)+20;
                    y=daj_y(cus)+20;
                    cJSON_free(kierunek);
                }
            }
        }
        else if(strcmp(kierunek, "\"W\"") == 0)
        {
            cJSON_Delete(cus);
            cus = make_request(url_rright);
        }
    }
    else if(y < yo && x == xo)
    {
        if(strcmp(kierunek, "\"N\"") == 0)
        {
            if(mapa[yo-1][x]!=3)
            {
                cJSON_Delete(cus);
                cus = make_request(url_move);
            }
            else
            {
                while(x == xo)
                {
                    kierunek = daj_kier(cus);
                    cus = ruszaj(a,b,mapa,kierunek, x,y,bilans_skrety,cus,url1,url2,url3);
                    x=daj_x(cus)+20;
                    y=daj_y(cus)+20;
                    cJSON_free(kierunek);
                }
            }
        }
        else if(strcmp(kierunek, "\"E\"") == 0)
        {
            cJSON_Delete(cus);
            cus = make_request(url_rleft);
        }
        else if(strcmp(kierunek, "\"S\"") == 0)
        {
            cJSON_Delete(cus);
            cus = make_request(url_rleft);
            cJSON_Delete(cus);
            cus = make_request(url_rleft);
        }
        else if(strcmp(kierunek, "\"W\"") == 0)
        {
            cJSON_Delete(cus);
            cus = make_request(url_rright);
        }
    }
    else
    {
        cus = ruszaj(a,b,mapa,kierunek, x,y,bilans_skrety,cus,url1,url2,url3);
    }

    return cus;
}