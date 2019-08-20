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

	void save_member()
	{
		ofstream file("'���.txt");
		if (!file)
		{
			cout << "���� �б⸦ �����Ͽ����ϴ�" << endl;
			exit(1);
		}
		for (int i = 0;i < index;i++)
		{
			file << list[i].cardinal_num << "\t" << list[i].student_id << "\t" << list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num <<
				"\t" << list[i].statement << endl;
		}
		file.close();
	
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
		while (1)
		{
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
			cout << "5. ������";
			gotoxy(40, 21);
			
			cout << "�޴��� �����ϼ��� : ";
			cin >> select_menu;
			switch (select_menu)
			{
				case 1:
				{
					insert_member();
					break;
				}
				case 2:
				{
					view_member();
					break;
				}
				case 3:
				{

					break;
				}
				case 4:
				{

					break;
				}
				case 5:
				{
					save_member();
					exit(1);
					break;
				}
				default:
				{
					cout << "�޴��� ��Ȯ�ϰ� �Է����ּ���" << endl;
					break;
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