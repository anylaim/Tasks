#include "Server.h"

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


class Chat
{
private:
	unsigned int _chatId;
	vector<unsigned int> _participants;
	vector<Message> _messages;

public:

	Chat() : _chatId(0) {}

	Chat(unsigned int chatId) : _chatId(chatId) {}

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


	vector<Message> getAllMessages() const // вывести все сообщения
	{
		return _messages;
	}

	vector<unsigned int> getParticipants() const // вывести список пользователей чата
	{
		return _participants;
	}

	void sendMessage(unsigned int userId, const string& message)
	{
		string fullMessage = getUNameFromId(userId) + ": " + message;
		_messages.emplace_back(Message(fullMessage));
	}

	const unsigned int getChatId() const
	{
		return _chatId;
	}

	void sendMessage(string userName, string message) // исправить
	{
		string fullMessage = userName + ": " + message;
		_messages.emplace_back(Message(fullMessage));
	}

};



bool isValidKeys(char k)
{
	return (k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z') ||
		(k >= '0' && k <= '9') || k == '_' || k == '-';
}

bool isValidKeysUname(char k)
{
	return (k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z') ||
		(k >= '0' && k <= '9') || k == '_' || k == '-' || k == '.'; // добавил точку
}

bool isValidLog(const string& login)
{
	if (login.length() < 3 || login.length() > 20) // Проверка длины логина
	{
		return false;
	}

	for (char k : login)
	{
		if (!isValidKeys(k)) // Проверка на допустимые символы
		{
			return false;
		}
	}

	return true;
}

bool isValidPwd(const string& password)
{
	if (password.length() < 8 || password.length() > 30) // Проверка длины пароля
	{
		return false;
	}

	for (char k : password)
	{
		if (!isValidKeys(k)) // Проверка на допустимые символы
		{
			return false;
		}
	}
	return true;
}

bool isValidUname(const string& userName)
{
	if (userName.empty() || userName.length() < 2 || userName.length() > 20)
	{
		return false;
	}

	for (char k : userName)
	{
		if (!isValidKeysUname(k) && k != ' ') // Проверка на допустимые символы
		{
			return false;
		}
	}
	return true;
}

class User
{
private:
	string username;
	string login;
	string password;
	unsigned int id;

	vector<unsigned int> chatsId;

public:

	User() = default;

	// Конструктор копирования
	User(const User& other)
	{
		username = other.username;
		login = other.login;
		password = other.password;
		id = other.id;

		chatsId = other.chatsId;
	}

	// Оператор присваивания
	User& operator=(const User& other)
	{
		if (this != &other) 
		{
			username = other.username;
			login = other.login;
			password = other.password;
			id = other.id;

			chatsId = other.chatsId;
		}
		return *this;
	}

	const unsigned int getId() const
	{
		return id;
	}

	const string getUsername() const
	{
		return username;
	}

	const string getLogin() const
	{
		return login;
	}

	const string getPassword() const
	{
		return password;
	}

	vector<unsigned int> getChats() const
	{
		return chatsId;
	}

	void addChatId(unsigned int chatId)
	{
		chatsId.push_back(chatId);
	}
};

unordered_map<unsigned int, User> userData; // данные пользователей

void processUser(const User& user)
{
	userData[user.getId()] = user;
	cout << "\nAccount was created \n\n";
}

void printUserData(const unordered_map<unsigned int, User>& userData)
{
	for (const auto& pair : userData)
	{
		cout << "ID: " << pair.first << endl;
		cout << "Username: " << pair.second.getUsername() << endl;
		cout << "Login: " << pair.second.getLogin() << endl;
		cout << "Password: " << pair.second.getPassword() << endl;
		cout << endl;
	}
}

void showUData()
{
	printUserData(userData);
}

bool findLogin(const unordered_map<unsigned int, User>& userData, const string& log) // ищет совпадение логина
{
	for (const auto& pair : userData)
	{
		if (pair.second.getLogin() == log)
		{
			return false;
		}
	}
	return true;
}

bool origLogin(const string& log) // проверяет логин на оригинальность
{
	return findLogin(userData, log);
}

unsigned int newId(const unordered_map<unsigned int, User>& userData)
{
	unsigned int maxId = 1000000000;
	for (const auto& pair : userData)
	{
		if (pair.first > maxId)
		{
			maxId = pair.first;
		}
	}
	return maxId + 1;
}

unsigned int createId(unsigned int id) // присвоение id пользователю
{
	id = newId(userData);
	return id;
}


unsigned int getIdFromLog(const unordered_map<unsigned int, User>& userData, const string& log)
{
	for (const auto& pair : userData)
	{
		if (pair.second.getLogin() == log)
		{
			return pair.first;
		}
	}
	return 0;
}

unsigned int getIdFromLog(string& log)
{
	return getIdFromLog(userData, log);
}

string getUNameFromId(const unordered_map<unsigned int, User>& userData, unsigned int& id)
{
	for (const auto& pair : userData)
	{
		if (pair.first == id)
		{
			return pair.second.getUsername();
		}
	}
	return "";
}

string getUNameFromId(unsigned int& id)
{
	return getUNameFromId(userData, id);
}

string getUNameFromLog(const unordered_map<unsigned int, User>& userData, const string& log)
{
	for (const auto& pair : userData)
	{
		if (pair.second.getLogin() == log)
		{
			return pair.second.getUsername();
		}
	}
	return "";
}

string getUNameFromLog(string& log)
{
	return getUNameFromLog(userData, log);
}

const string validPassword(const unordered_map<unsigned int, User>& userData, string& log)
{
	for (const auto& pair : userData)
	{
		if (pair.second.getLogin() == log)
		{
			return pair.second.getPassword();
		}
	}
}

vector<unsigned int> getChatIdFromLog(string& log)
{
	for (const auto& pair : userData)
	{
		if (pair.second.getLogin() == log)
		{
			return pair.second.getChats();
		}
	}
}

bool validPwd(string& log, string& pwd)
{
	validPassword(userData, log);
	if (pwd == validPassword(userData, log))
	{
		return true;
	}

	return false;
}

void addChatIdToUser(unsigned int userId, unsigned int chatId)
{
	auto userIter = userData.find(userId);
	userIter->second.addChatId(chatId);
}

unordered_map<unsigned int, Chat> _chats;

void printChat(const unordered_map<unsigned int, Chat>& _chats)
{
	for (const auto& pair : _chats)
	{
		cout << "ID: " << pair.first << endl;
		cout << endl;
	}
}

void addUser(const Chat& chat)
{
	_chats[chat.getChatId()] = chat;
	cout << "\nChat was created\n\n";
}

unsigned int newChatId(const unordered_map<unsigned int, Chat>& _chats)
{
	unsigned int maxId = 1000000000;
	for (const auto& pair : _chats)
	{
		if (pair.first > maxId)
		{
			maxId = pair.first;
		}
	}
	return maxId + 1;
}

unsigned int createChatId(unsigned int id) // присвоение id чату
{
	id = newChatId(_chats);
	return id;
}

void processChat(const Chat& chat)
{
	_chats[chat.getChatId()] = chat;
	cout << "\nChat was created \n\n";
}

void printChatParticipants(const unordered_map<unsigned int, Chat>& chats, unsigned int chatId)
{
	auto it = chats.find(chatId);
	if (it != chats.end())
	{
		vector<unsigned int> participants = it->second.getParticipants();
		cout << "Participants of chat: " << endl;
		for (unsigned int participant : participants)
		{
			cout << getUNameFromId(participant) << endl;
		}
	}
	else
	{
		cout << "Chat " << chatId << " not found." << endl;
	}
}

void getUnameFromId_Chats(unsigned int id)
{
	printChatParticipants(_chats, id);
}

bool isUserInChat(const User& user, const Chat& chat)
{
	// Получаем список участников чата
	vector<unsigned int> participants = chat.getParticipants();

	// Проверяем, есть ли ID пользователя в списке участников чата
	for (unsigned int userId : participants)
	{
		if (userId == user.getId())
		{
			return true; // Пользователь состоит в чате
		}
	}

	return false; // Пользователь не состоит в чате
}

void processMessage(const User& user, unsigned int chatId) {
	auto it = _chats.find(chatId); // Находим чат по его идентификатору
	if (it != _chats.end()) // Если чат найден
	{
		Chat& chat = it->second;

		vector<Message> messages = chat.getAllMessages();
		cout << "\n" << endl;
		for (const Message& message : messages)
		{
			cout << message.getContent() << endl;
		}
		// Проверяем, состоит ли пользователь в чате
		if (isUserInChat(user, chat))
		{
			string content;
			while (true)
			{
				cout << "\nEnter message (type '/back' to return to the main menu): ";
				getline(cin, content);

				if (content == "/back")
				{
					cout << "Returning to the main menu..." << endl;
					break;
				}

				// Отправляем сообщение в найденный чат
				chat.sendMessage(user.getUsername(), content);
			}
		}
		else
		{
			cout << "\nYou are not a member of this chat.\n" << endl;
		}
	}
	else
	{
		cout << "\nChat not found.\n" << endl;
	}
}

