#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // Inicializar socket del servidor
    int socketServidor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketServidor == -1) {
        std::cerr << "Fallo al inicializar el socket del servidor" << std::endl;
        return -1;
    }

    // Configuraci�n de direcci�n IP y puerto del servidor
    sockaddr_in direccionServidor;
    direccionServidor.sin_family = AF_INET;
    direccionServidor.sin_addr.s_addr = INADDR_ANY; // Aceptar cualquier direcci�n
    direccionServidor.sin_port = htons(54000); // Puerto de escucha

    // Asociar el socket con la direcci�n IP y puerto
    if (bind(socketServidor, (struct sockaddr*)&direccionServidor, sizeof(direccionServidor)) == -1) {
        std::cerr << "Error al enlazar el socket con la direcci�n IP y puerto" << std::endl;
        close(socketServidor);
        return -1;
    }

    // Empezar a escuchar conexiones
    if (listen(socketServidor, 5) == -1) {
        std::cerr << "Error al iniciar la escucha de conexiones" << std::endl;
        close(socketServidor);
        return -1;
    }

    std::cout << "Servidor en espera de conexiones..." << std::endl;

    // Aceptar conexi�n entrante
    int socketCliente = accept(socketServidor, nullptr, nullptr);
    if (socketCliente == -1) {
        std::cerr << "Error al aceptar la conexi�n del cliente" << std::endl;
        close(socketServidor);
        return -1;
    }

    std::cout << "Cliente conectado exitosamente" << std::endl;

    // Enviar mensaje al cliente
    const char* mensajeServidor = "Mensaje del Servidor: Conexi�n Exitosa";
    send(socketCliente, mensajeServidor, strlen(mensajeServidor), 0);

    // Cerrar sockets
    close(socketCliente);
    close(socketServidor);

    return 0;
}
