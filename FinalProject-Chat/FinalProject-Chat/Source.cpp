#include <vector>
#include <memory>
#include "User.h"

using namespace std;

unique_ptr<User> currentUserPtr;

bool isAuthenticated = false;

void showHelp()
{
	cout << "\nList of commands:\n";
	cout << "/help - display the list of commands\n";
	cout << "/create_account - create an account\n";
	cout << "/login - log in to an account\n";
	cout << "/create_chat - create a chat\n";
	cout << "/display_chat - display user's chats\n";
	cout << "/open_chat - open chat and send message\n";
	cout << "/exit - exit the program\n\n";

}

void createUser()
{
	User* newUser = new User(User::CreateAccount());
	if (newUser->getId() == 0)
	{
		cout << "Account creation failed. Please try again\n\n";
		delete newUser; // Освобождаем память, выделенную для нового пользователя
	}
	else
	{
		processUser(*newUser);
		showUData();
		isAuthenticated = true;
		currentUserPtr.reset(newUser);
	}
}

void loginUser()
{
	User* newUser = new User(User::loginIn());
	if (newUser->getId() == 0)
	{
		cout << "Login failed. Please try again\n\n";
		delete newUser; // Освобождаем память, выделенную для нового пользователя
	}
	else
	{
		isAuthenticated = true;
		currentUserPtr.reset(newUser);
	}
}

void createChat()
{
	if (!isAuthenticated)
	{
		cout << "You need to log in or create an account first.\n\n";
		return; // Выходим из функции, чтобы не продолжать выполнение кода
	}

	Chat newChat = Chat::CreateChat();
	processChat(newChat);
}

void showChats()
{
	if (isAuthenticated)
	{
		if (currentUserPtr != nullptr)
		{
			currentUserPtr->printUserChats(*currentUserPtr);
		}
	}
	else
	{
		cout << "You need to log in or create an account first.\n\n";
		return; // Выходим из функции, чтобы не продолжать выполнение кода
	}
}

void writeMessage()
{
	if (isAuthenticated)
	{
		if (currentUserPtr != nullptr)
		{
			unsigned int id;

			cout << "\nEnter chat ID: ";
			cin >> id;

			cin.ignore();

			processMessage(*currentUserPtr, id);
		}
	}
	else
	{
		cout << "You need to log in or create an account first.\n\n";
	}
}

int main()
{
	string command;

	cout << "Enter /help to display the list of commands\n";

	while (true)
	{
		cout << "> ";
		cin >> command;

		if (command == "/help")
		{
			showHelp();
		}
		else if (command == "/create_account")
		{
			createUser();
		}
		else if (command == "/login")
		{
			loginUser();
		}
		else if (command == "/create_chat")
		{
			createChat();
		}
		else if (command == "/exit")
		{
			break;
		}
		else if (command == "/display_chat")
		{
			showChats();
		}
		else if (command == "/open_chat")
		{
			writeMessage();
		}
		else
		{
			cout << "Invalid command. Type / help for a list of commands\n";
		}
	}

	return 0;
}