namespace PongGame
{
    class NetworkMessage
    {
    public:
        IPEndPoint Sender;
        Packet Packet;
        DateTime RecieveTime;
    }
}