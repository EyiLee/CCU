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

void Client(char **argv) {
	struct addrinfo hints;
	struct addrinfo *servinfo;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	getaddrinfo("localhost", "14590", &hints, &servinfo);

	int sockfd;
	sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
	connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen);

	int sockcn;
	struct sockaddr_storage their_addr;
	socklen_t addr_size;
	addr_size = sizeof their_addr;

	int bytes;
	char buf[512];
	send(sockfd, argv[1], strlen(argv[1]), 0);
	bytes = recv(sockfd, buf, sizeof(buf), 0);
	if(bytes == -1) {
		cerr << "Connection error." << endl;
		return;
	}
	
	if( strcmp(buf,"FILEGET") ) {
		cout << buf << endl;
		return;
	}

	char filename[512];
	strcpy(filename,argv[1]);
	strcat(filename,"_new");

	cout << "Ready to write file into " << filename << "." << endl;

	FILE *fp;
	fp = fopen(filename,"w");
	while(true) {
		bytes = recv(sockfd, buf, sizeof(buf), 0);
		if(bytes <= 0) {
			break;
		}
		fwrite(buf, 1, strlen(buf), fp);
	}
	fclose(fp);
	close(sockfd);
}

int main(int argc, char **argv) {
	if(argc > 1) {
		Client(argv);
	}
	else {
		cerr << "You should type filename in command line." << endl;
	}
	return 0;
}
