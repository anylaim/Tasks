#pragma once
#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Message;
class User;
class Chat;
class User;

bool isValidKeys(char k); // допустимые символы для логина и пароля
bool isValidKeysUname(char k); // допустимые символы для имени пользователя

bool isValidLog(const string& login); // проверяет корректность введённого логина
bool isValidPwd(const string& password); // проверяет корректность введённого пароля
bool isValidUname(const string& userName); // проверяет корректность введённого имени прользователя

void processUser(const User& user); // запись пользователя на сервер

void printUserData(const unordered_map<unsigned int, User>& userData); // вывод данных из карты
void showUData(); // использует printUserData()

bool origLogin(const string& log); // проверяет логин на оригинальность
bool findLogin(const unordered_map<unsigned int, User>& userData, const string& login); // ищем логин

unsigned int newId(const unordered_map<unsigned int, User>& userData); // ищем наибольшее ID
unsigned int createId(unsigned int id); // присвоение id пользователю

unsigned int getIdFromLog(const unordered_map<unsigned int, User>& userData, const string& log);
unsigned int getIdFromLog(string& log);

string getUNameFromId(const unordered_map<unsigned int, User>& userData, unsigned int& id);
string getUNameFromId(unsigned int& id);

string getUNameFromLog(const unordered_map<unsigned int, User>& userData, const string& log);
string getUNameFromLog(string& log);
vector<unsigned int> getChatIdFromLog(string& log);

const string validPassword(const unordered_map<unsigned int, User>& userData, string& log);
bool validPwd(string& log, string& pwd);

void addChatIdToUser(unsigned int UserId, unsigned int ChatId); // добавляет id чата пользователям, состоящим в чате

void printChat(const unordered_map<unsigned int, Chat>& _chats);

void addUser(const Chat& chat);

unsigned int newChatId(const unordered_map<unsigned int, Chat>& _chats); // создание id для чата

unsigned int createChatId(unsigned int id); // присвоение id пользователю

void processChat(const Chat& chat); // запись чата на сервер

void printChatParticipants(const unordered_map<unsigned int, Chat>& chats, unsigned int chatId);
void getUnameFromId_Chats(unsigned int id);

bool isUserInChat(const User& user, const Chat& chat);
void processMessage(const User& user, unsigned int chatId);
