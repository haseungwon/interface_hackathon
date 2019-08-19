#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4244)
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

typedef struct member {
	
	string name;
	string student_id;
	string cardinal_num;
	string phone_num;
	string major;
	string statement;
	
}Member;


void file_open(fstream& f, string dir, char mode)
{
	if (mode == 'w')	f.open(dir, ios::app);
	else if (mode == 'r') f.open(dir, ios::in);

	if (!f) {
		cout << "Failed to load file" << endl;
	}
}

void gotoxy(short x, short y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

class Manage
{
private:
	fstream file;
	void insert_member()
	{
		char answer = 'y';
		while (answer == 'y') {
			system("cls");
			cout << "���� ����� �߰��ϴ� ���Դϴ�" << endl;


			cout << "���: ";
			cin >> mem.cardinal_num;


			cout << "�й�: ";
			cin >> mem.student_id;


			cout << "�̸�: ";
			cin >> mem.name;


			cout << "�а�: ";
			cin >> mem.major;


			cout << "����: ";
			cin >> mem.phone_num;


			cout << "����: ";
			cin >> mem.statement;

			list.push_back(mem);
			index++;

			cout << "��� �Ͻðڽ��ϱ�? y/n ";
			cin >> answer;
		}
	}
	void view_member()
	{

	}

public:

	vector<Member> list;
	Member mem;
	int index = 0;


	void start_menu() {

		string id;
		system("cls");
		for (int i = 0;i < 1;i++) {
			setcolor(10, 0);
			gotoxy(25, 2);
			cout << "�١ڡ١ڡ١ڡ١� �������̽� ��� ���� ���α׷� �١ڡ١ڡ١ڡ١�" << endl;
			Sleep(500);
			system("cls");
			setcolor(14, 0);
			gotoxy(25, 2);
			cout << "�١ڡ١ڡ١ڡ١� �������̽� ��� ���� ���α׷� �١ڡ١ڡ١ڡ١�" << endl;
			Sleep(500);
			system("cls");
		}

	}

	void menu()
	{
		int select_menu;
		while (1) {
			system("cls");
			gotoxy(25, 2);
			cout << "�١ڡ١ڡ١ڡ١� �������̽� ��� ���� ���α׷� �١ڡ١ڡ١ڡ١�" << endl;
			gotoxy(40, 6);
			cout << "1. �߰�";
			gotoxy(40, 9);
			cout << "2. �˻�";
			gotoxy(40, 12);
			cout << "3. ����";
			gotoxy(40, 15);
			cout << "4. ����";
			gotoxy(38, 18);
			cout << "�޴��� �����ϼ��� : ";
			cin >> select_menu;
			switch (select_menu)
			{
			case 1:
			{
				insert_member();
			}
			case 2:
			{
				view_member();
			}

			}
		}
	}


};

int main()
{
	system("title �������̽� ��� ���� ���α׷�");
	Manage test;
	string bbb;
	test.start_menu();
	test.menu();

	return 0;
}