#include "Packet.h"

using namespace PongGame;

Packet::Packet(PacketType type)
{
    Type = type;
}

RequestJoinPacket::RequestJoinPacket() : Packet(RequestJoin)
{
}

AcceptJoingPacket::AcceptJoingPacket() : Packet(AcceptJoin)
{
}