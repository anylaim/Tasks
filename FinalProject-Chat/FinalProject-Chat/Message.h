#pragma once
#include "Server.h"
#include <iostream>
#include <string>
#include <limits>

class Message
{
private:
	string _content;

public:

	Message(string content) : _content(content) {}

	string getContent() const
	{
		return _content;
	}
};