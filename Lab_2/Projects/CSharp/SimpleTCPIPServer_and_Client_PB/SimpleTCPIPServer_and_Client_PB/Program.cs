using SimpleTCPIPServer_and_Client_PB.Client;
using SimpleTCPIPServer_and_Client_PB.Server;

namespace SimpleTCPIPServer_and_Client_PB
{
    internal class Program
    {
        static async Task Main(string[] args)
        {
            Console.WriteLine("Hello, World!");


#if SERVER
                    await Simple_Server_PB.StartServer();
#elif FOREVER_SERVER
                    await Forever_Server_PB.StartForeverServer();
#elif CLIENT
                       await Simple_Client_PB.StartClient();
#endif
        }
    }
}
