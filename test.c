#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <winsock2.h>
#include <windows.h>
#include<string.h>
#include<stdbool.h>
#include <sys/types.h>
#include <ws2tcpip.h>
//#include <Ws2def.h>

#pragma comment(lib, "ws2_32.lib")


DWORD WINAPI SocketHandler(void* lp);
void replyto_client(char *buf, int, int *csock);

DWORD WINAPI SocketHandler(void* lp){

	int i ;
	for(i = 0; i < 10; ++i)
		printf("\nhandler 1 - %d", i);
}

DWORD WINAPI SocketHandler2(void* lp){

	int i ;
	for(i = 0; i < 10; ++i)
		printf("\nhandler 2 - %d", i);

}


void socket_server() {
	
	int* csock = NULL;

	CreateThread(0, 0, &SocketHandler, (void*)csock, 0, 0);
	CreateThread(0, 0, &SocketHandler2, (void*)csock, 0, 0);
}

int main(){

	socket_server();
	getchar();
}
