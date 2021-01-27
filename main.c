#include"siec.h"
#include"logika.h"
#include "../cJSON/cJSON.h"
#include"interpretacja.h"
#include"obrazek.h"

#define N 50
#define K 50

int main(int argc, char **argv)
{
    int mapa[N][K] ;
    for( int i=0;i<N;i++)
    {
        for(int j=0;j<K;j++)
        {
            mapa[i][j]=0;
        }
    }

    char *url_info =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/info/qwerty_1" ; 
    char *url_rleft =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/rotate/qwerty_1/left" ;
    char *url_rright =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/rotate/qwerty_1/right" ;
    char *url_move =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/move/qwerty_1" ;
    char *url_exp =  "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/explore/qwerty_1" ;

    int kroki_na_początku=daj_krok(url_info);

    cJSON *cus = make_request(url_info);
    int x=daj_x(cus);
    int y=daj_y(cus);

    mapa[y+20][x+20]=zwroc_nr_pola(cus);  // 20 to podstawowe odniesienie w większej tablicy aby formować mapę świata przesuniętą zawsze o konkretną odległość
    char *kierunek;
    
    int bilans_skrety=0;

    while(krance(N,K,mapa)!=0)
    {
        x=daj_x(cus);
        y=daj_y(cus);

        x = x+20;
        y = y+20;

        kierunek=daj_kier(cus);

        exploruj_jesli_musisz(N,K,mapa , kierunek , x , y , bilans_skrety , cus, url_exp, url_rleft);
    
        cus = ruszaj(N,K,mapa, kierunek, x , y , bilans_skrety , cus, url_rleft, url_rright, url_move);

        cJSON_free(kierunek);
    }

    int dlugosc_mapy = xkoniec(N,K,mapa);
    int szerokosc_mapy = ykoniec(N,K,mapa);
    int nowa_mapa[dlugosc_mapy][szerokosc_mapy];

    przepisz(dlugosc_mapy , szerokosc_mapy , nowa_mapa , mapa);

    while(zero(dlugosc_mapy , szerokosc_mapy , nowa_mapa )==1)
    {
        x=daj_x(cus);
        y=daj_y(cus);

        x = x+20;
        y = y+20;

        kierunek=daj_kier(cus);

        exploruj_jesli_musisz(N,K,mapa , kierunek , x , y , bilans_skrety , cus, url_exp, url_rleft);
    
        cus = ruszaj_do_zera(N,K,mapa, kierunek, x , y , bilans_skrety , cus, url_rleft, url_rright, url_move);

        cJSON_free(kierunek);

        przepisz(dlugosc_mapy , szerokosc_mapy , nowa_mapa , mapa);

    }
    cJSON_Delete(cus);

    int kroki_na_koniec=daj_krok(url_info);
    printf("STEP : %d\n", kroki_na_koniec-kroki_na_początku-2);

    odwroc(dlugosc_mapy , szerokosc_mapy , nowa_mapa);
    wypisz(dlugosc_mapy , szerokosc_mapy , nowa_mapa);
    FILE *fout=fopen(argv[1],"w");
    zapisz(fout , dlugosc_mapy , szerokosc_mapy , nowa_mapa);

    narysuj_mape_png(dlugosc_mapy, szerokosc_mapy, nowa_mapa, argv[2], argv[3]);
    
    fclose(fout);

  return 0;
}