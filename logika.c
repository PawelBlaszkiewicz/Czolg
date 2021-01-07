#include"logika.h"

int zero (int taba[N][K])
{
    for( int i=0;i<N;i++)
    {
        for(int j=0;j<K;j++)
        {
            if(taba[i][j]==0)
            {
                return 1;
            }
        }
    }
    return 0;
}

void zapisz(FILE *fout, int taba[N][K])
{
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++)
        {
            fprintf(fout, "%d ", taba[i][j]);
        }
    fprintf(fout, "\n");
    }
}