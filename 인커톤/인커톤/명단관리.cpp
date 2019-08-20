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
			gotoxy(44, 2);
			cout << "���� ����� �߰��ϴ� ���Դϴ�" << endl;

			gotoxy(38, 5);
			cout << "���: ";

			gotoxy(38, 7);
			cout << "�й�: ";

			gotoxy(38, 9);
			cout << "�̸�: ";
			
			gotoxy(38, 11);
			cout << "�а�: ";
			
			gotoxy(38, 13);
			cout << "����: ";
			
			gotoxy(38, 15);
			cout << "����: ";

			gotoxy(44, 5);
			cin >> mem.cardinal_num;

			gotoxy(44, 7);
			cin >> mem.student_id;

			gotoxy(44, 9);
			cin >> mem.name;

			gotoxy(44, 11);
			cin >> mem.major;

			gotoxy(44, 13);
			cin >> mem.phone_num;

			gotoxy(44, 15);
			cin >> mem.statement;

			list.push_back(mem);
			index++;

			gotoxy(38, 18);
			cout << "��� �Ͻðڽ��ϱ�? y/n >> ";
			cin >> answer;
		}
	}
	void view_member()
	{
		
			int bbb;
			string find;
			string tmp;
			while(1){
			system("cls");
			cout << "������ �˻� �Ͻǰǰ���?" << endl;
			cout << "1. ���" << endl;
			cout << "2. �й�" << endl;
			cout << "3. �̸�" << endl;
			cout << "4. ��ȭ��ȣ(010-xxxx-xxxx �������� �˻�)" << endl;
			cout << "5. ���� ����(����, ����, ����) �˻�" << endl;
			cout << "6. ���� ȭ������ ���ư���" << endl;
			cout << "�޴��� �����ϼ���: ";
			cin >> bbb;

			switch (bbb)
			{
			case 1:
			{
				cout << "����� �Է��ϼ��� : " << endl;
				cin >> find;
				for (int i = 0;i < index;i++)
				{
					if (find.compare(list[i].cardinal_num) == 0)
					{
						cout << list[i].cardinal_num << "\t" << list[i].student_id << "\t" << list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num << "\t" << list[i].statement << endl;
					}
				}
				cout << "�������� �����ϱ����� �ƹ��ų� �Է��Ͻÿ� " << endl;
				cin >> tmp;
				break;
			}
			case 2:
			{
				cout << "�й��� �Է��ϼ��� : " << endl;
				cin >> find;
				for (int i = 0;i < index;i++)
				{

					if (find.compare(list[i].cardinal_num) == 0)
					{
						cout << list[i].cardinal_num << "\t" << list[i].student_id << "\t" << list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num << "\t" << list[i].statement << endl;
					}
				}
				cout << "�������� �����ϱ����� �ƹ��ų� �Է��Ͻÿ� " << endl;
				cin >> tmp;
				break;
			}
			case3:
			{
				cout << "�̸��� �Է��ϼ��� : " << endl;
				cin >> find;
				for (int i = 0;i < index;i++)
				{
					if (find.compare(list[i].cardinal_num) == 0)
					{
						cout << list[i].cardinal_num << "\t" << list[i].student_id << "\t" << list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num << "\t" << list[i].statement << endl;
					}
				}
				cout << "�������� �����ϱ����� �ƹ��ų� �Է��Ͻÿ� " << endl;
				cin >> tmp;
				break;
			}
			}

		}
	}

	void save_member()
	{
		ofstream file("���.txt");
		if (!file)
		{
			cout << "���� �б⸦ �����Ͽ����ϴ�" << endl;
			exit(1);
		}
		for (int i = 0;i < index;i++)
		{
			file << list[i].cardinal_num << "\t" << list[i].student_id << "\t"<<list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num <<
				"\t" << list[i].statement << endl;
		}
		file.close();
	
	}

public:

	vector<Member> list;
	Member mem;
	int index;

	Manage()
	{
		Member tmp;

		ifstream file("���.txt");
		if (!file)
		{
			cout << "����� �ҷ��ü��� �����ϴ�";
		
		}
		index = 0;
		while (!file.eof())
		{
			file >> tmp.cardinal_num >> tmp.student_id >> tmp.name >> tmp.major >> tmp.phone_num >> tmp.statement;
			list.push_back(tmp);
			
			index++;
		}
		
	}

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
		setcolor(15, 0);
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
					list.clear();
					break;
				}
				default:
				{
					system("cls");
					gotoxy(44,10);
					cout << "�޴��� ��Ȯ�ϰ� �Է����ּ���" << endl;
					gotoxy(44,20);
					system("pause");
					break;
				}
			}

			
		}
	}


};

int main()
{
	system("mod con cols=118 lines=30"); //�ܼ�â ���� ���� ���� ����
	system("title �������̽� ��� ���� ���α׷�");
	Manage test;
	string bbb;
	test.start_menu();
	test.menu();

	return 0;
}