#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

int main(int argc, char** argv){
	
	int PORT = 8000;
	
	int aflag = 0;
	int bflag = 0;
	char *ip = NULL;
	int index;
	int c;

	opterr = 0;


	while ((c = getopt (argc, argv, "p:i:")) != -1)
		switch (c)
		{
			case 'p':
				PORT = atoi(optarg);
				printf("Using port: %d\n", PORT);
				break;
			case 'i':
				ip = optarg;
				printf("Using IP: %s\n", ip);
				break;
			default:
				abort ();
		}

	if(ip == NULL)
	{
		ip = (char *) malloc(sizeof(char)*10);
		strcpy(ip, "127.0.0.1");
	}
		
	int clientSocket, ret;
	struct sockaddr_in serverAddr;
	char buffer[1024];

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket < 0){
		printf("Error in connection.\n");
		exit(1);
	}
	printf("Client Socket is created.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr(ip);

	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("Error in connection.\n");
		exit(1);
	}
	printf("Connected to Server.\n");

	struct timeval t1, t2;
    int elapsedTime;

    // start timer
    gettimeofday(&t1, NULL);
	while(1){
		
		gettimeofday(&t2, NULL);
		elapsedTime = (int)(t2.tv_sec - t1.tv_sec) ; 
		
		//printf("Client: \t");
		//scanf("%s", &buffer[0]);
		//send(clientSocket, buffer, strlen(buffer), 0);
		if(elapsedTime >= 1)
		{
			printf("Sending auto message, asking for total messages count\n");
			//bzero(buffer, sizeof(buffer));
			strcpy(buffer, "count");
			//printf("Buffer: %s\n", buffer);
			send(clientSocket, buffer, sizeof(buffer), 0);
			bzero(buffer, sizeof(buffer));
			if(recv(clientSocket, buffer, 1024, 0) < 0){
				printf("Error in receiving data.\n");
			}else{
				printf("Server: %s\n", buffer);
			}
			gettimeofday(&t1, NULL);
		}
		

		if(strcmp(buffer, "exit") == 0){
			close(clientSocket);
			printf("Disconnected from server.\n");
			exit(1);
		}

		//if(recv(clientSocket, buffer, 1024, 0) < 0){
		//	printf("Error in receiving data.\n");
		//}else{
		//	printf("Server: \t%s\n", buffer);
		//}
	}

	return 0;
}
