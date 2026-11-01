//TCP Server- Reverse String

#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include <arpa/inet.h>

int main()
{
  char buff[512],str1[512],c;
  int SocketFD, len, i,k;
  struct sockaddr_in stSockAddr, cli_addr;
  SocketFD=socket(AF_INET,SOCK_STREAM,0);
  if(SocketFD<0)
  {
          perror("can not creat socket");
          exit(EXIT_FAILURE);
  }
  bzero(&stSockAddr,sizeof(stSockAddr));
  stSockAddr.sin_family=AF_INET;
  stSockAddr.sin_port=htons(1504);
  stSockAddr.sin_addr.s_addr=INADDR_ANY;
  if(bind(SocketFD,(struct sockaddr*)&stSockAddr,sizeof(stSockAddr))<0)
  {
          perror("can not bind");
          close(SocketFD);
          exit(EXIT_FAILURE);
  }
  int a=sizeof(cli_addr);
  listen(SocketFD,2);

 int connectFD=accept(SocketFD,(struct sockaddr*)&cli_addr,&a);
 if(connectFD<0)
 {
        perror("can not connect");
        close(SocketFD);
        exit(EXIT_FAILURE);
 }


        printf("\n Received String:");
        read(connectFD,buff,512);
        printf("%s",buff);
         len=strlen(buff);

        for(i=len-1, k=0; i>=0; i--, k++)
        {
                c=buff[i];
                str1[k]=c;
        }
         //strrev(buff);
         printf("\nReversed String:%s", str1);

         write(connectFD,str1,512);


    close(connectFD);
    printf("\n");
    return EXIT_SUCCESS;
}