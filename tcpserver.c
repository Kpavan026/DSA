#include<stdio.h>
#include<stdib.h>
#include<netdb.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#define PORT 8055
#define SA struct sockaddr
int main(){
    int sockfd,connfd,len;
    struct sockaddr_in serv,cli;
    char *ip = "192.168.29.145";
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==-1){
        printf("Socket failed\n");
    }
    else{
        printf("Socket created succesfully");
    }
    bzero(&serv, sizeof(serv));
    serv.sin_family=AF_INET;
    serv.sin_addr.s_addr = inet_addr(ip);;
    serv.sin_port = htons(PORT);
    if((bind(sockfd,(SA*)&serv,sizeof(serv)))!=0){
         printf("socket bind failed...\n");
        exit(0);
    }
    else{
        printf("Socket successfully binded..\n");
    }
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        printf("server accept failed...\n");
        exit(0);
    }
    else
        printf("server accept the client...\n");
    char buff[100];
    int n;
    
    bzero(buff, 100);
    read(connfd, buff, sizeof(buff));
    printf("From client: %s\t To client : ", buff);
    
    bzero(buff, 100);
        n = 0;
        
        while ((buff[n++] = getchar()) != '\n');
            
            
        write(connfd, buff, sizeof(buff));
    close(sockfd);
  
}
















bzero(buff, 100);
    read(connfd, buff, sizeof(buff));
    printf("From client Message is %s\t  ", buff);
    strcpy(input,buff);
    strcpy(buff,"Give Generator:");
    bzero(buff, 100);
    write(connfd, buff, sizeof(buff));
    read(connfd, buff, sizeof(buff));
    printf("From client Message is %s\t  ", buff);
    strcpy(key,buff);
    bzero(buff, 100);
    n = 0;
    write(connfd, buff, sizeof(buff));
    close(sockfd);
