int segmentation(int* v,int i,int j,int tem){

    int p,q;
    int val,per;

    p=i; q=j; val=v[j]; tem+=3;
    while(p<=q){
                tem++;
        while((v[p]<=val)&&(p<=j)) {p++; tem+=3;}
        while((v[q]>val)&&(i<=q)){ q--; tem+=3;}

        if(p<q){
        per=v[p];
        v[p]=v[q];
        v[q]=per;
            tem+=4;
        }

    }


                return q;

}
int tri_seg(int *T,int i,int j,int tem){

    int m;

    if(i<j){
        tem++;
    m=segmentation(T,i,j,tem);
   // printf("m=%d",m); getch();
    tem++;   if(m==j){ tem=tri_seg(T,i,m-1,tem); tem++;}
    else{ tem=tri_seg(T,i,m,tem); tem++;}
    tem=tri_seg(T,m+1,j,tem); tem++;
        }

        return tem;
}
