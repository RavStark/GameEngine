#pragma once

#include <queue>
#include <list>
#include <functional>
//tmp Message class
class Message
{
	std::string msg;
};
class BusNode;

class MessageBus
{
public:
	MessageBus();
	~MessageBus();
	void update();
	void addListener(const BusNode* busNode);
	void addMsg(const Message& message);

private:
	std::queue<Message> _messages;
	std::list<std::function<void(Message)>> _receivers;
};