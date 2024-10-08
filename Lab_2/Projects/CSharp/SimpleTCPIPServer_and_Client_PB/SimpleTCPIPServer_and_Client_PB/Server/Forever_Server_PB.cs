using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Net;
using System.Text;

namespace SimpleTCPIPServer_and_Client_PB.Server
{
    internal class Forever_Server_PB
    {
        public static async Task StartForeverServer()
        {
            Console.WriteLine("Hello World from simple_server_pb");

            using Socket listener = new(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            IPAddress iPAddress = IPAddress.Any;

            int port = 54321;

            IPEndPoint iPEndPoint = new IPEndPoint(iPAddress, port);

            listener.Bind(iPEndPoint);
            listener.Listen(100);

            var handler = await listener.AcceptAsync();

            while (true)
            {
                // Receive message
                var buffer = new byte[1_024];
                var received = await handler.ReceiveAsync(buffer, SocketFlags.None);
                var response = Encoding.UTF8.GetString(buffer, 0, received);

                var eom = "<|EOM|>";

                if (response.IndexOf(eom) > -1) // End of message
                {
                    Console.WriteLine($"Socket server received message: \" {response.Replace(eom, "")}\"");

                    var ackMessage = "<|ACK|>";
                    var echoBytes = Encoding.UTF8.GetBytes(ackMessage);
                    await handler.SendAsync(echoBytes, SocketFlags.None); //0
                    Console.WriteLine($"Socket Server sent acknowledgement: \" {ackMessage}\"");

                    break;
                }
            }
        }
    }
}
