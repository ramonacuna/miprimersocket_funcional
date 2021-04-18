#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
  int socked_id = 0;
  int conexion = 0;
  char msm[]="Mi primer socket exitoso";

     //Estructura de conexion al server
     struct sockaddr_in Server_Ramon ;
      Server_Ramon.sin_family= AF_INET;//Familia de protocolos
      Server_Ramon.sin_addr.s_addr = inet_addr("127.0.0.1");// Direccion Ip del server
      Server_Ramon.sin_port = htons(12000); //El puerto(Direccion de memoria) que estoy utilizando para enviar la info.
      // Creo mi socket 
     socked_id = socket(AF_INET, SOCK_STREAM, 0); 
     
   //Ahora estableceremos la conexion entre el socket y el server  
     
     conexion = connect(socked_id, (struct sockaddr*)&Server_Ramon, sizeof(Server_Ramon));

  if(conexion < 0){
      printf("Conexion fallida\n\r");
      return(-1);
  }

  printf("Conexion Exitosa\n\r");
  send(socked_id,msm,sizeof(msm),0);

   close(socked_id);
  
  return(0);
}