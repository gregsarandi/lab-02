// Server side C/C++ program to demonstrate Socket programming 
// Here's some include statements that might be helpful for you
#include <string> 
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <sys/socket.h> 
#include <netdb.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char const *argv[]) 
{ 
	// check to see if user input is valid
	char socket_read_buffer[1024];
	
	// TODO: Fill out the server ip and port
	std::string server_ip = "127.20.10.4"; //IP address of raspberry pi
	std::string server_port = "12345"; //specific port number to enter in server

	int opt = 1;
	int client_fd = -1;

	// TODO: Create a TCP socket()
	client_fd = socket(AF_INET, SOCK_STREAM, 0);

	// Enable reusing address and port
	if (setsockopt(client_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
		return -1;
	}

	// Check if the client socket was set up properly
	if(client_fd == -1){
		printf("Error- Socket setup failed");
		return -1;
	}
	
	// Helping you out by pepping the struct for connecting to the server
	struct addrinfo hints;
	struct addrinfo *server_addr;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	getaddrinfo(server_ip.c_str(), server_port.c_str(), &hints, &server_addr);

	// TODO: Connect() to the server (hint: you'll need to use server_addr)
	if (connect(client_fd, server_addr->ai_addr, server_addr->ai_addrlen) < 0) {
		
		printf("Error connecting to server\n");

	}

	// TODO: Retreive user input

	printf("Please enter message: ");
    bzero(socket_read_buffer,1024); //erases the data in the 1024 bytes of socket_read_buffer, rewriting them as zeroes
    fgets(socket_read_buffer,1023,stdin); //reads input from client and stores it in socket_read_buffer

	// TODO: Send() the user input to the server

	send(client_fd, socket_read_buffer, 1024, 0);


	// TODO: Recieve any messages from the server and print it here. Don't forget to make sure the string is null terminated!

	bzero(socket_read_buffer, 1024); //erases the data in socket_read_buffer, rewriting it as zeroes
    read(client_fd, socket_read_buffer, 1024); 
    printf("Message sent from server: %s\n", socket_read_buffer);

	// TODO: Close() the socket

	close(client_fd);

	return 0; 
} 