DOT NET style wrapper for Linux Sockets and TCP/IP networking.

    TcpListener - Responsible for creating a socket, binding to it and listening (waiting) for incoming client connections.

    TcpClient - Responsible for connecting to a socket that was created by TcpListener.

    NetworkStream - Will be returned by TcpListener/TcpClient in case there was a successfully established connection. It will allow user to send/recieve data.

Names of these classes and their methods are identical to the names in .NET. 
