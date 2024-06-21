import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        String hostName = "localhost"; // Dirección del servidor, localhost significa que está en la misma máquina
        int port = 5000; // El puerto debe coincidir con el que el servidor está escuchando

        try (Socket socket = new Socket(hostName, port)) {
            // Enviar un mensaje al servidor
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            out.println("Hola, servidor!");
            System.out.println("Mensaje enviado al servidor.");

            // Recibir respuesta del servidor
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String serverResponse = in.readLine();
            System.out.println("Respuesta del servidor: " + serverResponse);
        } catch (UnknownHostException e) {
            System.out.println("No se pudo detectar el servidor en " + hostName);
            System.out.println(e.getMessage());
        } catch (IOException e) {
            System.out.println("No se pudo obtener I/O para la conexión con: " + hostName);
            System.out.println(e.getMessage());
        }
    }
}