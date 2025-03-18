#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char sir[256],matrice[256][256];
    int nrcuvinte=0;
    fgets(sir,sizeof(sir),stdin);
    char *p=strtok(sir," \n");
    while(p)
    {
        strcpy(matrice[++nrcuvinte],p);
        p=strtok(NULL," \n");
    }
    for(int i=1;i<nrcuvinte;i++)
    {
        for(int j=i+1;j<=nrcuvinte;j++)
        {

            if(strlen(matrice[i])<=strlen(matrice[j]))
            {
                if(strlen(matrice[i])==strlen(matrice[j]))
                {

                    if(strcmp(matrice[i],matrice[j])>0)
                    {

                    char aux[256];
                    strcpy(aux,matrice[i]);
                    strcpy(matrice[i],matrice[j]);
                    strcpy(matrice[j],aux);
                    }

                }
                if(strlen(matrice[i])<strlen(matrice[j]))
                {
                    char aux[256];
                    strcpy(aux,matrice[i]);
                    strcpy(matrice[i],matrice[j]);
                    strcpy(matrice[j],aux);
                }
            }
        }
    }
    for(int i=1;i<nrcuvinte;i++)
        printf("%s\n",matrice[i]);
    return 0;
}
