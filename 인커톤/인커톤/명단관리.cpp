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



int inside(string x, string y)
{
	int i;
	for (i = 0;i < x.length();i++)
	{
		if (x.at(i) == y.at(i))
			continue;
		else
			break;
	}
	if (i == x.length())
		return 1;
	else
		return 0;
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
	
	void insert_member()
	{
		char answer = 'y';
		while (answer == 'y') {

			system("cls");
			gotoxy(44, 2);
			cout << "���� ����� �߰��ϴ� ���Դϴ�\t\t\t\t ���Է��� ���Ͻø� r, ���� �޴��� ���ư��� �ʹٸ� mŰ �Է����ּ���" << endl;

			gotoxy(38, 5);
			cout << "��� : ";

			gotoxy(38, 8);
			cout << "�й� : ";

			gotoxy(38, 11);
			cout << "�̸� : ";
			
			gotoxy(38, 14);
			cout << "�а� : ";
			
			gotoxy(38, 17);
			cout << "���� : ";
			
			gotoxy(38, 20);
			cout << "���� : ";

			gotoxy(45, 5);
			cin >> mem.cardinal_num;

			gotoxy(45, 8);
			cin >> mem.student_id;

			gotoxy(45, 11);
			cin >> mem.name;

			gotoxy(45, 14);
			cin >> mem.major;

			gotoxy(45, 17);
			cin >> mem.phone_num;

			gotoxy(45, 20);
			cin >> mem.statement;

			list.push_back(mem);
			index++;

			gotoxy(38, 23);
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
			gotoxy(38,2);
			cout << "������ �˻� �Ͻǰǰ���?" << endl;
			gotoxy(38, 5);
			cout << "1. ���" << endl;
			gotoxy(38, 8);
			cout << "2. �й�" << endl;
			gotoxy(38, 11);
			cout << "3. �̸�" << endl;
			gotoxy(38, 14);
			cout << "4. �а�" << endl;
			gotoxy(38, 17);
			cout << "5. ��ȭ��ȣ(010-xxxx-xxxx �������� �˻�)" << endl;
			gotoxy(38, 20);
			cout << "6. ���� ����(����, ����, ����) �˻�" << endl;
			gotoxy(38, 23);
			cout << "7. ���� ȭ������ ���ư���" << endl;
			gotoxy(38, 26);
			cout << "�޴��� �����ϼ��� : ";
			cin >> bbb;

			switch (bbb)
			{
				case 1:
				{
					int idx = 0; // ǥ���ϴ� ��� ��
					system("cls");
					gotoxy(38, 2);
					cout << "����� �Է��ϼ��� : ";
					cin >> find;
					for (int i = 0;i < index;i++)
					{
						if (find.compare(list[i].cardinal_num) == 0)
						{
							idx++;
							gotoxy(28, 2+3*idx);
							cout << list[i].cardinal_num << "\t" << list[i].student_id << "\t" << list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num << "\t" << list[i].statement;
						}
						gotoxy(28, 2 + 3 * (idx + 1));
					}
					system("pause");
					break;
				}
				case 2:
				{
					int idx = 0; // ǥ���ϴ� ��� ��
					system("cls");
					gotoxy(38, 2);
					cout << "�й��� �Է��ϼ��� : ";
					cin >> find;
					for (int i = 0;i < index;i++)
					{
						if (inside(find,list[i].student_id)==1)
						{
							idx++;
							gotoxy(28, 2+3*idx);
							cout << list[i].cardinal_num << "\t" << list[i].student_id << "\t" << list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num << "\t" << list[i].statement;
						}
						gotoxy(28, 2 + 3 * (idx + 1));
					}
					system("pause");
					break;
				}
				case 3 :
				{
					int idx = 0; // ǥ���ϴ� ��� ��
					system("cls");
					gotoxy(38, 2);
					cout << "�̸��� �Է��ϼ��� : " ;
					cin >> find;
					for (int i = 0;i < index;i++)
					{
					
						if (inside(find,list[i].name)==1)
						{
							idx++;
							gotoxy(28, 2 + 3 * idx);
							cout << list[i].cardinal_num << "\t" << list[i].student_id << "\t" << list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num << "\t" << list[i].statement;
						}
						gotoxy(28, 2 + 3 * (idx + 1));
					}
					system("pause");
					break;
				}
				case 4:
				{
					int idx = 0; // ǥ���ϴ� ��� ��
					system("cls");
					gotoxy(38, 2);
					cout << "�а��� �Է��ϼ��� : " ;
					cin >> find;
					for (int i = 0;i < index;i++)
					{
						if (inside(find, list[i].major) == 1)
						{
							idx++;
							gotoxy(28, 2 + 3 * idx);
							cout << list[i].cardinal_num << "\t" << list[i].student_id << "\t" << list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num << "\t" << list[i].statement;
						}
						gotoxy(28, 2 + 3 * (idx + 1));
					}
					system("pause");
					break;
				}
				case 5:
				{
					int idx = 0; // ǥ���ϴ� ��� ��
					system("cls");
					gotoxy(38, 2);
					cout << "��ȣ�� �Է��ϼ��� : " ;
					cin >> find;
					for (int i = 0;i < index;i++)
					{
					
						if (inside(find, list[i].major) == 1)
						{
							idx++;
							gotoxy(28, 2 + 3 * idx);
							cout << list[i].cardinal_num << "\t" << list[i].student_id << "\t" << list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num << "\t" << list[i].statement;
						}
						gotoxy(28, 2 + 3 * (idx+1));
					}
					system("pause");
					break;
				}
				case 6:
				{
					int idx = 0; // ǥ���ϴ� ��� ��
					system("cls");
					gotoxy(38, 2);
					cout << "���� ����(����, ����, ����)�� �Է��ϼ��� : ";
					cin >> find;
					for (int i = 0;i < index;i++)
					{

						if (inside(find, list[i].statement) == 1)
						{
							idx++;
							gotoxy(28, 2 + 3 * idx);
							cout << list[i].cardinal_num << "\t" << list[i].student_id << "\t" << list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num << "\t" << list[i].statement;
						}
						gotoxy(28, 2 + 3 * (idx + 1));
					}
					system("pause");
					break;
				
				}
				case 7:
				{
					return;
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
	
	void delete_member()
	{
		
		Member tmp;
		vector<string> enter;
		tmp.cardinal_num = "\n";
		tmp.student_id = "\n";
		tmp.name = "\n";
		tmp.major = "\n";
		tmp.phone_num = "\n";
		tmp.statement = "\n";

		system("cls");
		gotoxy(44, 2);
		cout << "����� �����ϴ� ���Դϴ� �ƽô� ������ �Է��ϼ��� " << endl;

		gotoxy(38, 5);
		cout << "��� : ";

		gotoxy(38, 8);
		cout << "�й� : ";

		gotoxy(38, 11);
		cout << "�̸� : ";

		gotoxy(38, 14);
		cout << "�а� : ";

		gotoxy(38, 17);
		cout << "���� : ";

		gotoxy(38, 20);
		cout << "���� : ";

		gotoxy(45, 5);
		getchar();
		getline(cin, tmp.cardinal_num);
		

		gotoxy(45, 8);
		getline(cin, tmp.student_id);
		

		gotoxy(45, 11);
		getline(cin, tmp.name);
	

		gotoxy(45, 14);
		getline(cin, tmp.major);
	

		gotoxy(45, 17);
		getline(cin, tmp.phone_num);
	

		gotoxy(45, 20);
		getline(cin, tmp.statement);
		
		if (tmp.cardinal_num.compare("\n") != 0)
		{
			enter.push_back(tmp.cardinal_num);
		}
		if (tmp.student_id.compare("\n") != 0)
		{
			enter.push_back(tmp.student_id);
		}
		if (tmp.name.compare("\n") != 0)
		{
			enter.push_back(tmp.name);
		}
		if (tmp.major.compare("\n") != 0)
		{
			enter.push_back(tmp.major);
		}
		if (tmp.phone_num.compare("\n"))
		{
			enter.push_back(tmp.phone_num);
		}
		if (tmp.statement.compare("\n") != 0)
		{
			enter.push_back(tmp.statement);
		}

		for (int i = 0;i < index;i++)
		{

			if(inside(enter.front(),list[i].)==1)
		}


		for (int i = 1;i < enter.size();i++)
		{

		}
		
	}


	
public:

	vector<Member> list;
	Member mem;
	int index;
	vector<int> index_arr;
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
		list.pop_back();
		index--;
		
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
			setcolor(15, 0);
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
					delete_member();
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