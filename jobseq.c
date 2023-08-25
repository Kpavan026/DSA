#include <stdio.h>
#include<stdlib.h>
int n=5;
struct job{
    int pos;
    int d;
    int p;
};
int main()
{   
    struct job j[5]={
    {1, 2,  60},
    {2, 1, 100},
    {3, 3,  20},
    {4, 2,  40},
    {5, 1,  20},
    };
    
   /* for(int i=0;i<n;i++){
    scanf("%d%d",&j[i].p,&j[i].d);
    j[i].pos=i+1;
    }*/
    int md=j[0].d;
    for(int i=1;i<n;i++){
        if(md<j[i].d){
            md=j[i].d;
        }
    }
    for(int i=0;i<n-1;i++){
        for(int k=i+1;k<n;k++){
            if(j[i].p<j[k].p){
                struct job temp;
                temp=j[k];
                j[k]=j[i];
                j[i]=temp;
            }
        }
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t",j[i].pos,j[i].d,j[i].p);
        printf("\n");
    }
   int ts[md+1],mp=0,ft=0,k;
    for(int i=1;i<=n;i++){
        ts[i]=-1;
    }
    for(int i=1;i<=n;i++){
        k=md<j[i-1].d ?md:j[i-1].d;
        while(k >= 1) {
        if(ts[k] == -1) {
        ts[k] = i-1;
        ft++;
        break;
        }
      k--;
    }
    
    if(ft==md){
        break;
    }

    }
    for(int i=1;i<=md;i++){
        printf("%d ",ts[i]);
    }
     printf("\n");
    
     printf("\nRequired Jobs: ");
     for(int i = 1; i <= md; i++) {
       printf("%d", j[ts[i]].pos);

        if(i < md) {
      printf(" --> ");
    }
  }
  for(int i = 1; i <= md; i++) {
    mp += j[ts[i]].p;
  }
  printf("\nMax Profit: %d\n", mp);

    


    return 0;
}
