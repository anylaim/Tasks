#include "User.h"

User::User(const string& username, const string& login, const string& password, unsigned int id, vector<unsigned int> chatId) : _username(username), _login(login), _password(password), _id(id), _chatsId(chatId) {}

void User::loginOut()
{
	_username = "";
	_login = "";
	_password = "";
	_id = 0;

	vector<unsigned int> empty;
	_chatsId = empty;
}