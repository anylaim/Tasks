#pragma once
#include "Chat.h"
#include "Server.h"
#include <iostream>
#include <string>
#include <limits>

class User
{
private:
	string _username;
	string _login;
	string _password;
	unsigned int _id;

	vector<unsigned int> _chatsId;

public:

	User(const string& username, const string& login, const string& password, unsigned int id, vector<unsigned int> chatsId);

	const string getUsername() const
	{
		return _username;
	}

	const string getLogin() const
	{
		return _login;
	}

	const unsigned int getId() const
	{
		return _id;
	}

	vector<unsigned int> getChats() const
	{
		return _chatsId;
	}

	void printUserChats(const User& user)
	{
		cout << "User's chats:" << endl;
		vector<unsigned int> chats = user.getChats();
		for (unsigned int chat : chats)
		{
			cout << "\n>> Chat ID: " << chat << " - ";
			getUnameFromId_Chats(chat);
		}
		cout << endl;
	}

	static User CreateAccount()
	{
		string _log;
		string _pwd;
		string _uname;
		unsigned int _id = 1;

		vector<unsigned int> _chatsId;

		do // ввод логина
		{
			cout << "\nEnter new login: ";
			cin >> _log;

			if (!isValidLog(_log))
			{
				cout << "Please use '_', '-'\n";
			}

			if (!origLogin(_log))
			{
				cout << "Login already exists. Please enter another login \n";
			}
		} while (!isValidLog(_log) || !origLogin(_log));

		do // ввод парол€
		{
			cout << "Enter new password: ";
			cin >> _pwd;

			if (!isValidPwd(_pwd))
			{
				cout << "Please use '_', '-'\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // будет игнорировать символы во входном буфере до тех пор, пока не встретит символ новой строки
		} while (!isValidPwd(_pwd));

		do // ввод имени пользовател€
		{
			cout << "Enter username: ";
			getline(cin, _uname); // ¬водим строку, включающую пробелы

			if (!isValidUname(_uname))
			{
				cout << "Please use '_', '-', '.'\n";
			}
		} while (!isValidUname(_uname));

		_id = createId(_id);

		return User(_uname, _log, _pwd, _id, _chatsId);
	};

	void loginOut();

	static User loginIn()
	{
		string _log;
		string _pwd;
		string _uname;
		unsigned int _id = 0;

		vector<unsigned int> _chatId;

		while (true)
		{
			cout << "\nEnter your login or type '/back' to cancel: ";
			cin >> _log;

			if (_log == "/back")
			{
				cout << "Operation canceled.\n";
				return User("", "", "", 0, vector<unsigned int>());
			}

			if (!isValidLog(_log))
			{
				cout << "Please use '_', '-'\n";
				continue;
			}

			if (origLogin(_log))
			{
				cout << "The entered login is incorrect or does not exist.\n";
				continue;
			}

			break;
		}

		while (true)
		{
			cout << "Enter password or type '/back' to cancel: ";
			cin >> _pwd;

			if (_pwd == "/back")
			{
				cout << "Operation canceled.\n";
				return User("", "", "", 0, vector<unsigned int>());
			}

			if (!isValidPwd(_pwd))
			{
				cout << "Please use '_', '-'\n";
				continue;
			}

			if (!validPwd(_log, _pwd))
			{
				cout << "Invalid password, please try again \n";
				continue;
			}

			break;
		}

		_id = getIdFromLog(_log);

		_uname = getUNameFromLog(_log);

		_chatId = getChatIdFromLog(_log);

		cout << "Successful\n\n";

		return User(_uname, _log, _pwd, _id, _chatId);
	}
}; 