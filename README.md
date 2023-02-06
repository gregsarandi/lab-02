# Lab 2
[Fork](https://docs.github.com/en/get-started/quickstart/fork-a-repo) this repo and clone it to your machine to get started!

## Team Members
- Greg Sarandi
- Kameran Mody

## Lab Question Answers

Answer for Question 1: 

Answer for Question 2:

Answer for Question 3: 


## TCP SERVER QUESTIONS:

     1. What is argc and *argv[]?
     
        *  argc and *argv[] are known as the command line arguments. These are important to use
        *  when passing values from the command line into a C program. argc refers to the number
        *  of arguments passed from the command line into the program. Meanwhile, *argv[] is a 
        *  pointer arrray that points to each argument passed into the program from the command line.
        *  Note that the *argv array begins with an index value of 0. Thus, argv[1] actually points to 
        *  the second argument passed from the command line. Additionally, the first argument passed from
        *  the command line (i.e argv[0]) will be the executable file produced from the desired c code
        *  after its been compiled, generically named "a.out" if not otherwise specified. 
        * 
        *  By including argc and *argv[] in the argument to int main(), we will be able to input the desired
        *  server port for our server, which will be the same server entered in the accompanying c++ client program
        * 
        *  SOURCE USED: https://www.tutorialspoint.com/cprogramming/c_command_line_arguments.htm
        *

     2. What is a UNIX file descriptor and file descriptor table?
         
        *  A UNIX file descriptor essentially operates as the UNIX equivalent for an input/output stream. 
        *  Whereas other input/output tools, such as "stdin" or "stdout", are pointers to an object structure, a
        *  file descriptor is simply an integer such as 0(stdin), 1(stdout), and 2(stderr). 
        *  UNIX file descriptors are indeces within the "file descriptor table", which acts as an array of objects similar to those 
        *  that would be seen in an input/output stream (such as stdin, stdout, etc.). Applications thus manipulate file descriptors 
        *  to access the file descriptor table and its object array.
        * 
        *  SOURCE USED: https://cs61.seas.harvard.edu/site/ref/file-descriptors/#gsc.tab=0
     

     3. What is a struct? What's the structure of sockaddr_in?

        * A struct is essentially the C version of a class(which is used in C++). It is used to group several related
        * variables together in one place. These variables are typically referred to as "members". 
        * The sockaddr_in structure is used to specify a transport address and port for the AF_INET address family.
        * The sockaddr_in struct contains several members, including sin_family(address family for transport address), 
        * sin_port(transport protocol port number), sin_addr(contains an IPv4 transport address), and sin_zero[8] (reserved for system use)
        * 
        * SOURCES USED: 
        * 
        * https://www.tutorialspoint.com/cprogramming/c_structures.htm
        * 
        * https://learn.microsoft.com/en-us/windows/win32/api/ws2def/ns-ws2def-sockaddr_in
        *

     4. What are the input parameters and return value of socket()

        * The first input parameter (denoted "domain"), in this case "AF_INET", is an integer used to 
        * specify the communication domain. AF_INET is input for communication between processes on different hosts connected
        * by IPV4. For communication between processes on the same host, AF_LOCAL would be input. 
        * 
        * The second input parameter (denoted type), in this case "SOCK_STREAM", is used to specify the 
        * communication type. SOCK_STREAM indicates TCP communication, while SOCK_DGRAM indicates UDP communication
        * 
        * The third input parameter (denoted protocol), is the protocol value for Internet Protocol(IP).
        * It will almost always be 0 (I could not find an instance where it would not be 0, however I did
        * not look much past geeksforgeeks)
        *

     5. What are the input parameters of bind() and listen()?
        *  
        *      The input parameters for listen() are "sockfd" and "backlog". sockfd is an int that is a UNIX file descriptor referring
        *      to a socket of type SOCK_STREAM or SOCK_SEQPACKET. backlog is an int that defines the maximum number of pending connections
        *      permittable for the server and sockfd.
        * 
        * 
        *      The input paramaters for bind() are "sockfd", "addr", and "addrlen". "addr" is a const struct sockaddr pointer that specifies an 
        *      address to the socket referred to by sockfd. addrlen specifies the size (in bytes) of the address structure pointed to by addr.
        *
        *      
        *      SOURCES USED: 
        * 
        *      https://man7.org/linux/man-pages/man2/listen.2.html
        * 
        *      https://man7.org/linux/man-pages/man2/bind.2.html
     

    6.  Why use while(1)? Based on the code below, what problems might occur if there are multiple simultaneous connections to handle?
        *       
        *       While(1) is an infinite loop which will run until broken by an explicitly stated break. It is used here because the server 
        *       must be consistently running/on in order to receive data packets sent from clients at any given momeny. If there are multiple simultaneous 
        *       connections to handle for the server, it may theoretically send the wrong return data packets to a client. Additionally, there may be added 
        *       latency between system-client response times, since the system would only attend to one client at a time. 
        *       This can be solved using the "multi-threading" technique. With modern technology, this is rarely an issue. This issue can also be solved using 
        *       the select() system call, or designing a concurrent server using the fork() system call.     
        * 
        *       SOURCE USED: https://www.geeksforgeeks.org/difference-while1-while0-c-language/  
        *


    7. Research how the command fork() works. How can it be applied here to better handle multiple connections?
         
         *      The fork() system call would be useful here for handling multiple clients. The fork() command creates a child process that runs in sync with the 
         *      assigned parent process. It is the simplest technique for creating a concurrent server, which can run in parallel with the original server and thus
         *      be used to handle multiple clients without sacrificing accuracy/efficiency. 
         * 
         * 
         *      SOURCE USED: https://www.geeksforgeeks.org/design-a-concurrent-server-for-handling-multiple-clients-using-fork/
         *
     
     8. This program makes several system calls such as 'bind', and 'listen.' What exactly is a system call?
 
        *  According to GNU.org, a system call is defined as "a request for service that a program makes of the kernel. The service is generally something that 
        *  only the kernel has the privilege to do, such as I/O". System calls make programming much easier overall.
        * 
        *  SOURCE USED: https://www.gnu.org/software/libc/manual/html_node/System-Calls.html#:~:text=A%20system%20call%20is%20a,such%20as%20doing%20I%2FO.
        *
        */
