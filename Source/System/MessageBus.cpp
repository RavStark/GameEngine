#include "System/MessageBus.hpp"
#include "System/BusNode.hpp"

MessageBus::MessageBus()
{

}

MessageBus::~MessageBus()
{

}

void MessageBus::update()
{
	while (_messages.size() != 0)
	{
		for (auto it = _receivers.begin(); it != _receivers.end(); ++it)
		{
			(*it)(_messages.front());
		}
		_messages.pop();
	}
}

void MessageBus::addListener(const BusNode* busNode)
{
	//_receivers.push_back(busNode->OnNotify);
}

void MessageBus::addMsg(const Message& message)
{
	_messages.push(message);
}
