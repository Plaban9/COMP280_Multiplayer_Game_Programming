using System.Net.Sockets;
using System.Net;
using System.Text;

namespace SimpleTCPIPServer_and_Client_PB.Client
{
    internal class Simple_Client_PB
    {
        public static async Task StartClient()
        {
            Console.WriteLine("Hello World from simple_client_pb");

            using Socket client = new(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            IPAddress iPAddress = IPAddress.Parse("127.0.0.1");

            int port = 54321;

            IPEndPoint iPEndPoint = new IPEndPoint(iPAddress, port);

            await client.ConnectAsync(iPEndPoint);

            while (true)
            {
                // Send Message
                var message = "Hi friends !<|EOM|>";
                var messageBytes = Encoding.UTF8.GetBytes(message);

                _ = await client.SendAsync(messageBytes, SocketFlags.None);

                Console.WriteLine($"Socket Client sent message: \" {message} \"");

                // Receive ACK
                var buffer = new byte[1_024];
                var received = await client.ReceiveAsync(buffer, SocketFlags.None);
                var response = Encoding.UTF8.GetString(buffer, 0, received);

                if (response == "<|ACK|>")
                {
                    Console.WriteLine($"Socket Client received acknowledgement: \"{response}\"");
                    break;
                }
            }

            client.Shutdown(SocketShutdown.Both);
        }
    }
}
