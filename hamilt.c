#include<stdio.h>
#include<stdbool.h>
int x[20],a[5][5]={{0 , 1 , 1 ,0,1},{1,0,1,1,1},{1,1,0,1,0},{0,1,1,0,1},{1,1,0,1,0}};;

void nextvalue(int k,int n){
    do{
        x[k]=(x[k]+1)%(n+1);
       if(x[k]==0){
          return; 
       }    
       if(a[x[k-1]][x[k]]==1){
           int j;
           for(j=1;j<=k-1;j++){
               if(x[j]==x[k]){
                   break;
               }
           }
          if(j==k){
              if(k<n || k==n && a[x[n]][x[1]]==1){
                  return;
              }
          }
       }
       
    }while(true);
}

void hamilt(int k,int n){
    do{
    nextvalue(k,n);
    if(x[k]==0)
       return;
     if (k==n){
         for(int i=1;i<=n;i++){
             printf("%d ",x[i]);
         }
         printf("\n");
     }
    else{
        hamilt(k+1,n);
    }   
    }while(true);
}


int main(){
    int n=5,i,j;
    /*scanf("%d",&n);*/
    for(i=1;i<=n;i++){
        x[i]=0;
    }
    x[1]=1;
    printf("Give adjacancy matrix:\n");
   /* for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }*/
    hamilt(1,n);
}

