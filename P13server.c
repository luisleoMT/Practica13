import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) {
        int port = 5000; // Puerto en el que el servidor escuchará
        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Servidor iniciado, escuchando en el puerto: " + port);

            // El servidor necesita correr indefinidamente
            while (true) {
                try {
                    Socket clientSocket = serverSocket.accept(); // Aceptar una conexión de un cliente
                    System.out.println("Cliente conectado");

                    // Abrir un stream para leer lo que el cliente está enviando
                    BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                    String inputLine = in.readLine(); // Leer los datos enviados por el cliente
                    System.out.println("Mensaje del Cliente: " + inputLine);

                    // Abrir un stream para enviar una respuesta al cliente
                    PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
                    out.println("Hola, cliente! Mensaje recibido.");

                    // Cerrar la conexión con el cliente después de enviar la respuesta
                    clientSocket.close();
                } catch (IOException e) {
                    System.out.println("Exception caught when trying to listen on port " + port + " or listening for a connection");
                    System.out.println(e.getMessage());
                }
            }
        } catch (IOException e) {
            System.out.println("Exception caught when trying to listen on port " + port);
            System.out.println(e.getMessage());
        }
    }
}