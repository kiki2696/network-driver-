#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // Creaci�n del socket del cliente
    int socketCliente = socket(AF_INET, SOCK_STREAM, 0);
    if (socketCliente == -1) {
        std::cerr << "No se pudo crear el socket del cliente" << std::endl;
        return -1;
    }

    // Configurar los detalles del servidor al que se conectar�
    sockaddr_in detallesServidor;
    detallesServidor.sin_family = AF_INET;
    detallesServidor.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP del servidor
    detallesServidor.sin_port = htons(54000); // Puerto del servidor

    // Intento de conexi�n al servidor
    if (connect(socketCliente, (struct sockaddr*)&detallesServidor, sizeof(detallesServidor)) == -1) {
        std::cerr << "Conexi�n con el servidor fallida" << std::endl;
        close(socketCliente);
        return -1;
    }

    std::cout << "Conexi�n con el servidor establecida" << std::endl;

    // Recepci�n de datos del servidor
    char bufferDelServidor[1024] = {0};
    recv(socketCliente, bufferDelServidor, sizeof(bufferDelServidor), 0);

    std::cout << "Respuesta del servidor: " << bufferDelServidor << std::endl;

    // Cierre del socket del cliente
    close(socketCliente);

    return 0;
}

