#pragma once
#include <ctime>

namespace PongGame
{
    enum PacketType
    {
        RequestJoin = 1,
        AcceptJoin,
        AcceptJoingAck,
        HeartBeat,
        HeartBeatAck,
        GameStart,
        GameStartAck,
    };

    class Packet
    {
    public:
        long Timestamp;
        PacketType Type;
        unsigned char *Payload;

        Packet(PacketType type);

        Packet(unsigned char bytes);

        string ToString();

        void Send(UdpClient client, IPEndPoint reciever);

        void Send(UdpClient client);
    };

    class RequestJoinPacket : public Packet
    {
    public:
        int car;
        RequestJoinPacket();
    };

    class AcceptJoingPacket : Packet
    {
    public:
        AcceptJoingPacket();
    }
};