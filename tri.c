#include <stdio.h>
#include <stdlib.h>

int* fusion(int* tab1, int* tab2,int taille1, int taille2){
    int i = 0;
    int j = 0;
    int k = 0;
    int res[taille1+taille2];
    while (i < taille1 && j< taille2){
        if (tab1[i] < tab2[j]){
            res[k] = tab1[i];
            i++;
            k++;
        }
        else{
            res[k] = tab2[j];
            j++;
            k++;
        }
    }
    if (i == taille1 && j< taille2){
        int m = 0;
        for (m =0; m< taille2 -j ; m++){
            res[k+m] = tab2[j+m]; 
        }
    }
    else{
        int m = 0;
        for (m =0; m< taille1 -i ; m++){
            res[k+m] = tab1[i+m]; 
        }
    }
    int *p;
    p = res;
    return p;
}




void* triFusion(int tab[], int taille, int tmp[]){
    
        int i;
    if (taille <= 1){
        NULL;
    }
    else{
    triFuision(tab,taille/2, tmp);
    triFuision(tab + (taille/2),taille-(taille/2), tmp);
    tmp = fusion(tab, tab + (taille/2), taille/2,taille-(taille/2));
    
    for(i=0;i<taille; i++){
        tab[i] = tmp[i];
    }
    }
    
}
int main(){
    int tab[4] = {16,15,14,13};
    int tab1[2] = {1,2};
    int* tmp = malloc(4*sizeof(int));
    triFuision(tab, 4, tmp);

   int i = 0;
     while(i<4){
       printf("%d\n",tab[i]);
       i++;
   } 
   return 0;
}
