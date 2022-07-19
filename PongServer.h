namespace PongGame
{
    class PongServer
    {
    public:
    private:
        UdpClient _udpClient;
        int Port;

    public:
        static PongServer server;

        PongServer(int port);
        void Start();
        void ShutDown();
        void Close();
        void _addNewArena();
        void NotifyDone(Arena arena);
        void Run();
        void _networkRun();
        void SendPacket(Packet packet, IPEndPoint to);
        void SendBye(IPEndpoint to);
    };
};