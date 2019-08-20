#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4244)

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

//��� ������ ��� ����ü
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

//x,y��ǥ ����
void gotoxy(short x, short y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//���� �� ��ȭ
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

			gotoxy(44, 2);
			cout << "���� ����� �߰��ϴ� ���Դϴ�" << endl;

			gotoxy(34, 6);
			cout << "���: ";
			
			gotoxy(34, 8);
			cout << "�й�: ";

			gotoxy(34, 10);
			cout << "�̸�: ";

			gotoxy(34, 12);
			cout << "�а�: ";

			gotoxy(34, 14);
			cout << "����: ";

			gotoxy(34, 16);
			cout << "����: ";

			gotoxy(40, 6);
			cin >> mem.cardinal_num;

			gotoxy(40, 8);
			cin >> mem.student_id;

			gotoxy(40, 10);
			cin >> mem.name;

			gotoxy(40, 12);
			cin >> mem.major;

			gotoxy(40, 14);
			cin >> mem.phone_num;

			gotoxy(40, 16);
			cin >> mem.statement;

			list.push_back(mem);
			index++;

			gotoxy(34, 20);
			cout << "��� �Ͻðڽ��ϱ�? y/n >> ";
			cin >> answer;
		}
	}
	void view_member()
	{

	}

public:

	vector<Member> list;	//Member ������ ���� list
	Member mem;				//����ü mem

	int index = 0;


	void start_menu() {

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
		setcolor(15, 0);
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
			gotoxy(40, 18);
			cout << "5. ����";
			gotoxy(38, 21);
			cout << "�޴��� �����ϼ��� : ";
			cin >> select_menu;
			switch (select_menu)
			{
				case 1:
				{
					insert_member();
				}
				break;
				case 2:
				{
					view_member();
				}
				break;
				case 5:
				{
					
				}
				break;
			}
			if (select_menu == 5)break;
		}
	}

	void exit_menu() {
		system("cls");
		gotoxy(48, 10);
		cout << "�̿����ּż� �����մϴ�" << endl;
		Sleep(2000);
	}

};

int main()
{
	system("mode con cols=118 lines=30"); //cols = ĭ/�� (����)  lines = ��/�� (����)
	system("title �������̽� ��� ���� ���α׷�"); //���α׷� ���� �ٲٴ� ����
	Manage test;
	string bbb;
	test.start_menu();
	test.menu();
	test.exit_menu();

	return 0;
}

//���� - �ɼ� - ����� - �Ϲ� >> ������� �����Ǹ� �ڵ����� �ܼ�â �ݱ��ϸ� 0�ڵ������ ����Ǿ����ϴ� �ȶ�