#pragma once
#include "Message.h"
#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>

class Chat
{
private:
	unsigned int _chatId;
	vector<unsigned int> _participants;
	vector<Message> _messages;

public:

	Chat(unsigned int chatId, vector<unsigned int> participants, vector<Message> messages) : _chatId(chatId), _participants(participants), _messages(messages) {}

	Chat(const Chat& other)
	{
		_chatId = other._chatId;
		_participants = other._participants;
		_messages = other._messages;
	}

	Chat& operator=(const Chat& other)
	{
		if (this != &other)
		{
			_chatId = other._chatId;
			_participants = other._participants;
			_messages = other._messages;
		}
		return *this;
	}

	void addParticipant(unsigned int userId) // Метод для добавления участника в чат
	{
		_participants.push_back(userId);
	}

	void removeParticipant(unsigned int userId) // Метод для удаления участника из чата
	{
		for (auto it = _participants.begin(); it != _participants.end(); ++it)
		{
			if (*it == userId)
			{
				_participants.erase(it);
				break;
			}
		}
	}

    static Chat CreateChat()
    {
        unsigned int _Id = 1;
        vector<unsigned int> _participants;
        vector<Message> _messages;

        while (true)
        {
            cout << "\nEnter /add to add user to chat, or /continue to finish: \n";

            string command;
            cin >> command;

            if (command == "/add")
            {
                string log;
                bool isDuplicate = false;

                do
                {
                    cout << "\nEnter user's login: ";
                    cin >> log;

                    if (!isValidLog(log))
                    {
                        cout << "\nPlease use '_', '-'\n\n";
                        continue;
                    }

                    for (unsigned int id : _participants)
                    {
                        if (getIdFromLog(log) == id)
                        {
                            isDuplicate = true;
                            cout << "\nThis login is already taken. Please choose another one\n\n";
                            break;
                        }
                    }

                    if (origLogin(log))
                    {
                        cout << "\nLogin not exist. Please try again\n\n";
                        continue;
                    }

                    isDuplicate = false;

                } while (!isValidLog(log) || isDuplicate || origLogin(log));

                _participants.push_back(getIdFromLog(log));
            }
            else if (command == "/continue")
            {
                break;
            }
            else
            {
                cout << "\nInvalid command. Please try again.\n";
            }
        }

        _Id = createChatId(_Id);

        for (unsigned int elem : _participants)
        {
            addChatIdToUser(elem, _Id);
        }

        return Chat(_Id, _participants, _messages);
    }


	vector<Message> getAllMessages() const
	{
		return _messages;
	}

	vector<unsigned int> getParticipants() const
	{
		return _participants;
	}
};