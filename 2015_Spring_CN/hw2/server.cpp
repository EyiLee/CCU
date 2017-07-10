#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<sys/uio.h>
#include<netinet/in.h>
#include<netdb.h>

using namespace std;

void Server(void) {
	struct addrinfo hints;
	struct addrinfo *servinfo;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	getaddrinfo("localhost", "14590", &hints, &servinfo);

	int sockfd;
	sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);

	bind(sockfd, servinfo->ai_addr, servinfo->ai_addrlen);

	listen(sockfd, 10);

	int sockcn;
	struct sockaddr_storage their_addr;
	socklen_t addr_size;
	addr_size = sizeof their_addr;

	while(true) {
		sockcn = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);
		if(sockcn < 0) {
			continue;
		}
		int bytes;
		char filename[512];
		while(true) {
			bytes = recv(sockcn, filename, sizeof(filename), 0);
			if(bytes <= 0) {
				send(sockcn, "QUIT", 5, 0);
				break;
			}

			filename[bytes] = '\0';
			if (filename[strlen(filename)-1] == '\n') {
		  		filename[strlen(filename)-1] = '\0';
			}
			if (filename[strlen(filename)-1] == '\r') {
				filename[strlen(filename)-1] = '\0';
			}
			if (strcmp(filename, "quit") == 0) {
				send(sockcn, "QUIT", 5, 0);
				break;
			}

			int fd;
			fd = open(filename, O_RDONLY);
			if(fd == -1) {
				send(sockcn, "FILENOTFOUND", 13, 0);
				continue;
			}

			send(sockcn, "FILEGET", 8, 0);

			char buf[512];
			while(true) {
				memset(buf,'\0',512);
				bytes = read(fd,buf,512);
				if(bytes == -1) {
					break;
				}
				send(sockcn, buf, sizeof(buf), 0);
				if(bytes == 0) {
					break;
				}
			}

			close(fd);
			break;
		}
		close(sockcn);
	}
}

int main(void) {
	Server();
	return 0;
}
