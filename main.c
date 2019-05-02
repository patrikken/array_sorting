#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"
#define Taille_min 2
#define N 40

//autor patrik kenfack
//************************************tri-selection***************
int tri_selection(int *T,int i, int j,int cmp){

    int k,max,pos,tem;

    for(k=j; k>i; k--){

    max=i;cmp+=4;

    for(pos=i;pos<=k;pos++){cmp+=3;
        if(T[pos]>T[max]){max=pos; cmp+=2;}
     // permutation T[max] et T[k]
     tem=T[max];
     T[max]=T[k];
     T[k]=tem;
     cmp+=3;
}
}
    return cmp;
}
//************************************tri-fusion***************
int tri_fusion(int *T,int i, int j,int cmp){

    int m;

        if((j-i+1)<Taille_min){cmp++; cmp=tri_selection(T,i,j,cmp);}
        else{

            m=(int)(i+j)/2;
                cmp++;
            cmp=tri_fusion(T,i,m,cmp);
            cmp=tri_fusion(T,m+1,j,cmp);
            cmp=fusion(T,i,m,j,cmp);

        }
return cmp;
}
//께께께께께께께께께께께께께께께께께께께쾓usion께께께께께께께�
int fusion(int T[N],int i,int m,int j,int cmp){

   int *v;
   v=(int *)malloc(sizeof(int)*(j-i+1));
   int p,q,k;

   p=i; q=m+1; k=0;cmp+=4;

   while((p<=m)&&(q<=j)){
    cmp=cmp+2;
    if(T[p]<=T[q]){
        v[k]=T[p];
            k++;
               p++;
               cmp=cmp+4;
    }else{

         v[k]=T[q];
         k++;
         q++;
         cmp+=4;
    }
}
    if(p<=m){
        for(;p<=m;p++,k++){ v[k]=T[p]; cmp=cmp+5;};
    }else{
        for(;q<=j;q++,k++){ v[k]=T[q]; cmp=cmp+5;};
    }

  for(k=0,p=i;p<=j;p++,k++){ T[p]=v[k]; cmp+=6;}

    free(v);
    return cmp;

}

/*****************tri-bulle***********************/
int Tri_bulle(int* T,int j,int cpt){
    int val,pos,i;

    i=j;cpt++;
    while(i>=1){
            cpt++;
        for(pos=1; pos<=i; pos++){
                cpt+=3;
            if(T[pos]<T[pos-1]){
                val=T[pos];
                T[pos]=T[pos-1];
                T[pos-1]=val;
                cpt+=4;
            }
        }

        i--;
        cpt++;

    }
        return cpt;
}
/*****************affichage du tableaux***********************/

void affich_Tab(int *T,int j){
int i=0;

    for(i=0;i<=j;i++) printf(" %d ",T[i]);
    printf("\n");
    printf("\n");
    return;
}
int main(){
    int cmp=0;
    int cpt=0;
    int tem=0;
    int T1[N]={9,10,-80,30,7,50,123,-12};
    int T2=T1;
    int T3=T1;
    int y=strlen(T1);


    printf("\n\n      => tableau de depart : T=");
    affich_Tab(T1,7);
    cmp=tri_fusion(T1,0,7,cmp);
    printf("\n-> Tableau trier a l'aide du trie fusion: \n\n      =>  T-tri_fusion= ");
    affich_Tab(T1,7);
    printf("      => Nbre d'operations du tri-fusion: %d operations \n\n",cmp);
    cpt=Tri_bulle(T2,7,cpt);

    printf("\n-> Tableau trier a l'aide du tri-bulle: \n\n      =>  T-tri_bulle= ");
    affich_Tab(T2,7);

    printf("      => Nbre d'operations du tri-bulle: %d operations\n\n",cpt);

    tem=tri_seg(T3,0,7,tem);
printf("\n-> Tableau trier a l'aide du tri-segmentation: \n\n      =>  T-tri_seg= ");
    affich_Tab(T2,7);

    printf("      => Nbre d'operations du tri-segementation: %d operations\n\n",tem);

    printf("==>         ces statistiques montrent que \n           le tri-fusion effectue plus d'operation\n           que le tri-bulle\n\n");
    printf("press any key to end this programme");
    cmp=getchar();

    return 0;
}
