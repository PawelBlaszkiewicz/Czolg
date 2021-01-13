#include"siec.h"
#include"logika.h"
#include "../cJSON/cJSON.h"
#include"interpretacja.h"

#define N 20
#define K 20

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

    ruchkoniec(N,K,mapa);

    int d=xkoniec(mapa);
    int e=ykoniec(mapa);
    int nowa[d][e];
    przepisz(d,e,nowa,mapa);

    if(zero(d,e,nowa)==1)
    {
        printf("Houston, mamy problem... Nie odkryłem mapy do końca, to nie wina programisty, tylko programu.\n");
        printf("Już poprawiam.\n");
        ruchzero(d,e,nowa);
    }
    char *url_info =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/info/qwerty_1" ;
    cJSON *cus=make_request(url_info);
    cJSON *c = cJSON_GetObjectItemCaseSensitive(cus, "payload") ;
    cJSON *name = cJSON_GetObjectItemCaseSensitive(c, "step");
    char *dd=cJSON_Print(name);
    int g=atoi(dd);
    cJSON_free(dd);
    printf("STEP : %d\n", g-1);
    odwroc(d,e,nowa);
    wypisz(d,e,nowa);
    zapisz(fout ,d,e, nowa);
    fclose(fout);
    cJSON_Delete(cus);

  return 0;
}