#include <stdio.h>
int n;
 
int solveMazeUtil(int maze[n][n], int x, int y, int sol[n][n]);
 
void print(int sol[n][n])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            printf(" %d ", sol[i][j]);}
        printf("\n");
    }
}
 

int isSafe(int maze[n][n], int x, int y)
{
  
    if (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1)
        return 1;
 
    return 0;
}
 
int solve(int maze[n][n])
{
   int sol[n][n];
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           sol[i][j]=0;
       }
   }
    if (solveMazeUtil(maze, 0, 0, sol) == 0) {
        printf("Cant find the path....");
        return 0;
    }
 
    print(sol);
    return 1;
}
 
int solveMazeUtil(int maze[][n], int x, int y, int sol[][n])
{
    if (x == n - 1 && y == n - 1) {
        sol[x][y] = 1;
        return 1;
    }
 
    if (isSafe(maze, x, y) ==1) {
        sol[x][y] = 1;
        
        if (solveMazeUtil(maze, x + 1, y, sol) == 1)
            return 1;
 
        if (solveMazeUtil(maze, x, y + 1, sol) == 1)
            return 1;

        sol[x][y] = 0;
        return 0;
    }
 
    return 0;
}

int main()
{
    int c;
        printf("Enter the size of the maze:");
        scanf("%d",&n);
        printf("Enter the maze:\n");
        int maze[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&maze[i][j]);
            }
        }
    
    printf("Maze is:\n");
    print(maze);
    printf("Solution is:\n");
    
    solve(maze);
    printf("Enter 1 to modify your maze:");
    scanf("%d",&c);
    if(c==1){
        printf("\nEnter 1 until you quit\n");
        scanf("%d",&c);
        while(c!=0){
            printf("Enter the x-coordinate:");
            int x,y;
            scanf("%d",&x);
            printf("Enter the y-coordinate:");
            scanf("%d",&y);
            printf("Enter the value:");
            scanf("%d",&maze[x][y]);
            printf("Enter your choice:");
            scanf("%d",&c);
        }
          printf("Solution is:\n");
        solve(maze);
    }
    else{
        printf("exit...");
    }
    
    return 0;
}
