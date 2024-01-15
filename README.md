# Network-driver
Implementacion de una comunicación básica entre un cliente y un servidor utilizando sockets en C++. El servidor escucha en un puerto definido y espera la conexión de un cliente. Una vez establecida la conexión, el Este proyecto implementa una comunicación básica entre un cliente y un servidor utilizando sockets en C++. El servidor escucha en un puerto definido y espera la conexión de un cliente. Una vez establecida la conexión, el servidor envía un mensaje al cliente, que el cliente recibe y muestra.


## Estructura del Proyecto
El proyecto se compone de dos archivos principales:

  * server.cpp: Contiene el código para el servidor.
  * client.cpp: Contiene el código para el cliente.


## Cómo Funciona

### Servidor
El servidor realiza las siguientes acciones:

  * Inicializa y configura un socket para escuchar las conexiones entrantes.
  * Espera y acepta la conexión del cliente.
  * Envía un mensaje al cliente.
  * Cierra la conexión.

### Cliente
El cliente realiza las siguientes acciones:

  * Crea y configura un socket para conectarse al servidor.
  * Establece una conexión con el servidor.
  * Recibe el mensaje enviado por el servidor y lo muestra.
  * Cierra la conexión.
