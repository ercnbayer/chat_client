#include "listen.h"
#include<iostream>
#include <errno.h>
#include <curses.h>
#include <unistd.h>
using namespace std;
void *recvMessage(void *pData)
{
int *server_socket=(int*)pData;
int fd=*server_socket;
char recv_buf[256];
while(1)
{
  int r =recv(fd,recv_buf,int(sizeof(recv_buf)),0);
  printf("%s",recv_buf);
  memset(recv_buf,0,sizeof(recv_buf));
  if(r<0)
  {
    printf("couldnt connect");
    printf(" err  val %s %d ",strerror(errno),errno);
    break;
  }

}
free(server_socket);
return NULL;
}
void *sendMessage(void *pclient)
{
  int *server_socket=(int*)pclient;
  int fd=*server_socket;
  char *send_buf=(char*)malloc(sizeof(char)*255+1);
  while(1)
  {
    char  senbuf[255];
    scanf("%s",senbuf);
    strcpy(send_buf,senbuf);   
    int r=send(fd,send_buf,int(strlen(send_buf)),0);
    printf("%d",strlen(send_buf));
    memset(send_buf,0,sizeof(send_buf));
    if(r<0)
    {
      printf(" err  val %s %d ",strerror(errno),errno);
      break;
    } 
  }  
  free(server_socket);
  return NULL;     
}          
int main ()
{ 
  int TCPServerSocket; 
  struct  sockaddr_in  TCPServerAdd;
  memset((char *) &TCPServerAdd,0, sizeof(TCPServerAdd));
  TCPServerAdd.sin_family = AF_INET;
  TCPServerAdd.sin_addr.s_addr =inet_addr("127.0.0.1");
  TCPServerAdd.sin_port = htons(8000);
  TCPServerSocket = socket(AF_INET,SOCK_STREAM,0);
  //memset(&(TCPServerAdd.sin_zero), '\0', 8); 
  if (TCPServerSocket<0)
  {
  printf("sock creation err");
  }
  pthread_t recieve,sendm;
  connect(TCPServerSocket,(sockaddr*)&TCPServerAdd,sizeof(TCPServerAdd)); 
  if(TCPServerSocket>-1)
  {
    int*psend;
    psend=(int*)malloc(sizeof(TCPServerSocket));
    *psend=socket(AF_INET,SOCK_STREAM,0); 
    *psend=TCPServerSocket;
    int*precv;
    precv=(int*)malloc(sizeof(TCPServerSocket));
    *precv=socket(AF_INET,SOCK_STREAM,0); 
    *precv=TCPServerSocket; 
    pthread_create(&recieve,NULL,recvMessage,(void*)precv);
    unsigned int microsecond = 1000000;
    usleep(3 * microsecond);         
    pthread_create(&sendm,NULL,sendMessage,(void*)psend);             
  }                       
  else 
  {
    printf(" err val %d",errno);
    printf("couldnt connect");
    exit(0);
  }                
  char recv_buf[256]; 
  printf(" err  val %s %d ",strerror(errno),errno);
  while(1)
  {
    int a =3;//dummy code to keep program in main loop
  }
  close(TCPServerSocket);
  return 0;
}    

  
  
 






    
      
    
  
  
  
     
    

  
      
    
