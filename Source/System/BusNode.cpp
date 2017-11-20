#include "System/BusNode.hpp"
#include "System/MessageBus.hpp"

BusNode::BusNode(MessageBus *messageBus)
	:_messageBus(messageBus)
{

}

BusNode::~BusNode()
{

}

void BusNode::sendMsg(const Message &message)
{
	_messageBus->addMsg(message);
}