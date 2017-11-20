#pragma once

class MessageBus;
class Message;

class BusNode
{
public:
	BusNode(MessageBus *messageBus);
	virtual ~BusNode();

	virtual void OnNotify(const Message &message) = 0;
	void sendMsg(const Message &message);
private:
	MessageBus *_messageBus;
};