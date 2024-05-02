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

bool isValidKeys(char k); // ���������� ������� ��� ������ � ������
bool isValidKeysUname(char k); // ���������� ������� ��� ����� ������������

bool isValidLog(const string& login); // ��������� ������������ ��������� ������
bool isValidPwd(const string& password); // ��������� ������������ ��������� ������
bool isValidUname(const string& userName); // ��������� ������������ ��������� ����� �������������

void processUser(const User& user); // ������ ������������ �� ������

void printUserData(const unordered_map<unsigned int, User>& userData); // ����� ������ �� �����
void showUData(); // ���������� printUserData()

bool origLogin(const string& log); // ��������� ����� �� ��������������
bool findLogin(const unordered_map<unsigned int, User>& userData, const string& login); // ���� �����

unsigned int newId(const unordered_map<unsigned int, User>& userData); // ���� ���������� ID
unsigned int createId(unsigned int id); // ���������� id ������������

unsigned int getIdFromLog(const unordered_map<unsigned int, User>& userData, const string& log);
unsigned int getIdFromLog(string& log);

string getUNameFromId(const unordered_map<unsigned int, User>& userData, unsigned int& id);
string getUNameFromId(unsigned int& id);

string getUNameFromLog(const unordered_map<unsigned int, User>& userData, const string& log);
string getUNameFromLog(string& log);
vector<unsigned int> getChatIdFromLog(string& log);

const string validPassword(const unordered_map<unsigned int, User>& userData, string& log);
bool validPwd(string& log, string& pwd);

void addChatIdToUser(unsigned int UserId, unsigned int ChatId); // ��������� id ���� �������������, ��������� � ����

void printChat(const unordered_map<unsigned int, Chat>& _chats);

void addUser(const Chat& chat);

unsigned int newChatId(const unordered_map<unsigned int, Chat>& _chats); // �������� id ��� ����

unsigned int createChatId(unsigned int id); // ���������� id ������������

void processChat(const Chat& chat); // ������ ���� �� ������

void printChatParticipants(const unordered_map<unsigned int, Chat>& chats, unsigned int chatId);
void getUnameFromId_Chats(unsigned int id);

bool isUserInChat(const User& user, const Chat& chat);
void processMessage(const User& user, unsigned int chatId);
