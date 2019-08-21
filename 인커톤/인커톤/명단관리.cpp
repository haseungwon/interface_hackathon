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
	if (x.compare("\n") == 0)
		return 4;
	for (i = 0;i < x.length();i++)
	{
		if (x.length() > y.length())
			break;
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
			cout << "���� ����� �߰��ϴ� ���Դϴ�";

			gotoxy(30, 26);
			cout << "���Է��� ���Ͻø� rŰ, ���� �޴��� ���ư��� �ʹٸ� mŰ �Է����ּ���" << endl;

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
			if (mem.cardinal_num == "r")
			{
				mem.cardinal_num = ""; mem.student_id = ""; mem.name = ""; mem.major = ""; mem.phone_num = ""; mem.statement = "";
				continue;
			}
			else if (mem.cardinal_num == "m") {
				mem.cardinal_num = ""; mem.student_id = ""; mem.name = ""; mem.major = ""; mem.phone_num = ""; mem.statement = "";
				break;
			}

			gotoxy(45, 8);
			cin >> mem.student_id;
			if (mem.student_id == "r")
			{
				mem.cardinal_num = ""; mem.student_id = ""; mem.name = ""; mem.major = ""; mem.phone_num = ""; mem.statement = "";
				continue;
			}
			else if (mem.student_id == "m") {
				mem.cardinal_num = ""; mem.student_id = ""; mem.name = ""; mem.major = ""; mem.phone_num = ""; mem.statement = "";
				break;
			}

			gotoxy(45, 11);
			cin >> mem.name;
			if (mem.name == "r")
			{
				mem.cardinal_num = ""; mem.student_id = ""; mem.name = ""; mem.major = ""; mem.phone_num = ""; mem.statement = "";
				continue;
			}
			else if (mem.name == "m") {
				mem.cardinal_num = ""; mem.student_id = ""; mem.name = ""; mem.major = ""; mem.phone_num = ""; mem.statement = "";
				break;
			}

			gotoxy(45, 14);
			cin >> mem.major;
			if (mem.major == "r")
			{
				mem.cardinal_num = ""; mem.student_id = ""; mem.name = ""; mem.major = ""; mem.phone_num = ""; mem.statement = "";
				continue;
			}
			else if (mem.major == "m") {
				mem.cardinal_num = ""; mem.student_id = ""; mem.name = ""; mem.major = ""; mem.phone_num = ""; mem.statement = "";
				break;
			}
			gotoxy(45, 17);
			cin >> mem.phone_num;
			if (mem.phone_num == "r")
			{
				mem.cardinal_num = ""; mem.student_id = ""; mem.name = ""; mem.major = ""; mem.phone_num = ""; mem.statement = "";
				continue;
			}
			else if (mem.phone_num == "m") {
				mem.cardinal_num = ""; mem.student_id = ""; mem.name = ""; mem.major = ""; mem.phone_num = ""; mem.statement = "";
				break;
			}
			gotoxy(45, 20);
			cin >> mem.statement;
			if (mem.statement == "r")
			{
				mem.cardinal_num = ""; mem.student_id = ""; mem.name = ""; mem.major = ""; mem.phone_num = ""; mem.statement = "";
				continue;
			}
			else if (mem.statement == "m") {
				mem.cardinal_num = ""; mem.student_id = ""; mem.name = ""; mem.major = ""; mem.phone_num = ""; mem.statement = "";
				break;
			}
			list.push_back(mem);
			index++;

			for (int i = 0; i < index - 1; i++) {
				if (mem.cardinal_num.compare(list[i].cardinal_num) == 0 && mem.major.compare(list[i].major) == 0 && mem.name.compare(list[i].name) == 0 && mem.phone_num.compare(list[i].phone_num) == 0 && mem.statement.compare(list[i].statement) == 0 && mem.student_id.compare(list[i].student_id) == 0)
				{
					gotoxy(38, 29);
					cout << "�̹� ���Ե� �ο��Դϴ�.";
					list.pop_back();
					index--;
				}
			}

			gotoxy(38, 23);
			cout << "��� �Ͻðڽ��ϱ�? y/n >> ";
			cin >> answer;
			while (answer != 'y'&&answer != 'n') {
				system("cls");
				gotoxy(38, 10);
				cout << "y �Ǵ� n ���� �Է����ּ���";
				gotoxy(38, 15);
				cout << "��� �Ͻðڽ��ϱ�? y/n >> ";
				cin >> answer;
			}
		}
	}

	void error() {
		system("cls");
		gotoxy(44, 10);
		cout << "�޴��� ��Ȯ�ϰ� �Է����ּ���" << endl;
		gotoxy(44, 15);
		system("pause");
	}

	void view_member()
	{
		int bbb;
		string find;
		string tmp;
		while (1) {
			system("cls");
			gotoxy(38, 2);
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


			if (bbb == 1)
			{
				int idx = 0; // ǥ���ϴ� ��� ��
				system("cls");
				gotoxy(38, 2);
				cout << "����� �Է��ϼ��� : ";
				cin >> find;
				for (int i = 0; i < index; i++)
				{
					if (inside(find,list[i].cardinal_num) == 1)
					{
						idx++;
						gotoxy(28, 2 + 3 * idx);
						cout << list[i].cardinal_num << "\t" << list[i].student_id << "\t" << list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num << "\t" << list[i].statement;
					}
					gotoxy(28, 2 + 3 * (idx + 1));
				}
				system("pause");

			}
			else if (bbb == 2)
			{
				int idx = 0; // ǥ���ϴ� ��� ��
				system("cls");
				gotoxy(38, 2);
				cout << "�й��� �Է��ϼ��� : ";
				cin >> find;
				for (int i = 0; i < index; i++)
				{
					if (inside(find, list[i].student_id) == 1)
					{
						idx++;
						gotoxy(28, 2 + 3 * idx);
						cout << list[i].cardinal_num << "\t" << list[i].student_id << "\t" << list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num << "\t" << list[i].statement;
					}
					gotoxy(28, 2 + 3 * (idx + 1));
				}
				system("pause");

			}
			else if (bbb == 3)
			{
				int idx = 0; // ǥ���ϴ� ��� ��
				system("cls");
				gotoxy(38, 2);
				cout << "�̸��� �Է��ϼ��� : ";
				cin >> find;
				for (int i = 0; i < index; i++)
				{

					if (inside(find, list[i].name) == 1)
					{
						idx++;
						gotoxy(28, 2 + 3 * idx);
						cout << list[i].cardinal_num << "\t" << list[i].student_id << "\t" << list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num << "\t" << list[i].statement;
					}
					gotoxy(28, 2 + 3 * (idx + 1));
				}
				system("pause");

			}
			else if (bbb == 4)
			{
				int idx = 0; // ǥ���ϴ� ��� ��
				system("cls");
				gotoxy(38, 2);
				cout << "�а��� �Է��ϼ��� : ";
				cin >> find;
				for (int i = 0; i < index; i++)
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

			}
			else if (bbb == 5)
			{
				int idx = 0; // ǥ���ϴ� ��� ��
				system("cls");
				gotoxy(38, 2);
				cout << "��ȣ�� �Է��ϼ��� : ";
				cin >> find;
				for (int i = 0; i < index; i++)
				{

					if (inside(find, list[i].phone_num) == 1)
					{
						idx++;
						gotoxy(28, 2 + 3 * idx);
						cout << list[i].cardinal_num << "\t" << list[i].student_id << "\t" << list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num << "\t" << list[i].statement;
					}
					gotoxy(28, 2 + 3 * (idx + 1));
				}
				system("pause");

			}
			else if (bbb == 6)
			{
				int idx = 0; // ǥ���ϴ� ��� ��
				system("cls");
				gotoxy(38, 2);
				cout << "���� ����(����, ����, ����)�� �Է��ϼ��� : ";
				cin >> find;
				for (int i = 0; i < index; i++)
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


			}
			else if (bbb == 7) 
			{
				break;
			}
			else
			{
				error();

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
		for (int i = 0; i < index; i++)
		{
			file << list[i].cardinal_num << "\t" << list[i].student_id << "\t" << list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num <<
				"\t" << list[i].statement << endl;
		}
		file.close();

	}

	void delete_member()
	{

		Member tmp;
		vector<string> enter;
		char x;
		while (1) {
			index_arr.clear();
			tmp.cardinal_num = "\n";
			tmp.student_id = "\n";
			tmp.name = "\n";
			tmp.major = "\n";
			tmp.phone_num = "\n";
			tmp.statement = "\n";

			system("cls");
			gotoxy(38, 2);
			cout << "����� �����ϴ� ���Դϴ� �ƽô� ������ �Է��ϼ��� " << endl;

			gotoxy(26, 26);
			cout << "���Է��� ���Ͻø� rŰ, ���� �޴��� ���ư��� �ʹٸ� mŰ�� �Է����ּ���" << endl;

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
			
			int num_people = 0;
			getline(cin, tmp.cardinal_num);
			if (tmp.cardinal_num == "r")
			{
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				continue;
			}
			else if (tmp.cardinal_num == "m") {
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				break;
			}

			gotoxy(45, 8);
			getline(cin, tmp.student_id);
			if (tmp.student_id == "r")
			{
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				continue;
			}
			else if (tmp.student_id == "m") {
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				break;
			}

			gotoxy(45, 11);
			getline(cin, tmp.name);
			if (tmp.name == "r")
			{
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				continue;
			}
			else if (tmp.name == "m") {
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				break;
			}

			gotoxy(45, 14);
			getline(cin, tmp.major);
			if (tmp.major == "r")
			{
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				continue;
			}
			else if (tmp.major == "m") {
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				break;
			}

			gotoxy(45, 17);
			getline(cin, tmp.phone_num);
			if (tmp.phone_num == "r")
			{
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				continue;
			}
			else if (tmp.phone_num == "m") {
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				break;
			}

			gotoxy(45, 20);
			getline(cin, tmp.statement);
			if (tmp.statement == "r")
			{
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				continue;
			}
			else if (tmp.statement == "m") {
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				break;
			}

			for (int i = 0; i < index; i++)
			{
				if (inside(tmp.cardinal_num, list[i].cardinal_num) == 1 && inside(tmp.student_id, list[i].student_id) == 1 && inside(tmp.name, list[i].name) == 1 && inside(tmp.major, list[i].major) == 1 && inside(tmp.phone_num, list[i].phone_num) == 1 && inside(tmp.statement, list[i].statement) == 1)
				{
					
					gotoxy(26, 29+3*num_people);
					cout << list[i].cardinal_num << "\t" << list[i].student_id << "\t" << list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num << "\t" << list[i].statement << endl;
					num_people++;
					index_arr.push_back(i);
				}	
			}
			if (index_arr.size() != 1)
			{
				gotoxy(38, 23);
				cout << "������ ����� �ϳ��� �ٽ� �˻����ּ���" << endl;
				gotoxy(38, 29 + 3 * num_people);
				system("pause");
				index_arr.clear();
			}

			else if (index_arr.size() == 1)
			{
				gotoxy(38, 23);
				cout << "�������̽� ȸ�� ��ܿ��� �����ұ��? >>> y/n ";
				gotoxy(85, 23);
				cin >> x;
				if (x == 'y')
				{
					for (int i = index_arr.front(); i < index - 1; i++)
					{
						list[i] = list[i + 1];
					}
					index--;
					break;
				}
				else
				{
					continue;
				}

			}
		}

	}

	void change_member()
	{
		Member tmp;
		vector<string> enter;
		string before;
		string after;
		int tm;
		char x;
		while (1) {
			index_arr.clear();
			tmp.cardinal_num = "\n";
			tmp.student_id = "\n";
			tmp.name = "\n";
			tmp.major = "\n";
			tmp.phone_num = "\n";
			tmp.statement = "\n";

			system("cls");
			gotoxy(30, 2);
			cout << "����� �����ϴ� ���Դϴ� �ƽô� ������ �Է��ؼ� ����� ã���ּ��� " << endl;

			gotoxy(26, 29);
			cout << "���Է��� ���Ͻø� rŰ, ���� �޴��� ���ư��� �ʹٸ� mŰ�� �Է����ּ���" << endl;

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
			if (tmp.cardinal_num == "r")
			{
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				continue;
			}
			else if (tmp.cardinal_num == "m") {
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				break;
			}

			gotoxy(45, 8);
			getline(cin, tmp.student_id);
			if (tmp.student_id == "r")
			{
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				continue;
			}
			else if (tmp.student_id == "m") {
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				break;
			}

			gotoxy(45, 11);
			getline(cin, tmp.name);
			if (tmp.name == "r")
			{
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				continue;
			}
			else if (tmp.name == "m") {
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				break;
			}

			gotoxy(45, 14);
			getline(cin, tmp.major);
			if (tmp.major == "r")
			{
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				continue;
			}
			else if (tmp.major == "m") {
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				break;
			}

			gotoxy(45, 17);
			getline(cin, tmp.phone_num);
			if (tmp.phone_num == "r")
			{
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				continue;
			}
			else if (tmp.phone_num == "m") {
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				break;
			}

			gotoxy(45, 20);
			getline(cin, tmp.statement);
			if (tmp.statement == "r")
			{
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				continue;
			}
			else if (tmp.statement == "m") {
				tmp.cardinal_num = ""; tmp.student_id = ""; tmp.name = ""; tmp.major = ""; tmp.phone_num = ""; tmp.statement = "";
				break;
			}

			for (int i = 0; i < index; i++)
			{
				if (inside(tmp.cardinal_num, list[i].cardinal_num) == 1 && inside(tmp.student_id, list[i].student_id) == 1 && inside(tmp.name, list[i].name) == 1 && inside(tmp.major, list[i].major) == 1 && inside(tmp.phone_num, list[i].phone_num) == 1 && inside(tmp.statement, list[i].statement) == 1)
				{
					gotoxy(26, 22);
					cout << list[i].cardinal_num << "\t" << list[i].student_id << "\t" << list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num << "\t" << list[i].statement << endl;

					index_arr.push_back(i);
				}
			}
			if (index_arr.size() != 1)
			{
				gotoxy(38, 23);
				cout << "������ ����� �ϳ��� �ٽ� �˻����ּ���" << endl;
				system("pause");
				index_arr.clear();
			}

			else if (index_arr.size() == 1)
			{
				gotoxy(38, 24);
				cout << "���� ���� ���� �ĸ� �Է����ּ���" << endl;
				gotoxy(38, 26);
				cout << "���� �� : ";
				gotoxy(49, 26);
				cin >> before;
				gotoxy(38, 27);
				cout << "���� �� : ";
				gotoxy(49, 27);
				cin >> after;
				if (list[index_arr.front()].cardinal_num.compare(before) == 0)
				{
					tm = list[index_arr.front()].cardinal_num.length();
					list[index_arr.front()].cardinal_num.replace(0, tm, after);

					system("cls");
					gotoxy(50, 10);
					cout << "������ �Ϸ�Ǿ����ϴ�.";
					gotoxy(26, 15);
					cout << list[index_arr.front()].cardinal_num << "\t" << list[index_arr.front()].student_id << "\t" << list[index_arr.front()].name << "\t" << list[index_arr.front()].major << "\t" << list[index_arr.front()].phone_num << "\t" << list[index_arr.front()].statement << endl;
					gotoxy(26, 20);
					system("pause");

					break;
				}
				if (list[index_arr.front()].student_id.compare(before) == 0)
				{
					tm = list[index_arr.front()].student_id.length();
					list[index_arr.front()].student_id.replace(0, tm, after);

					system("cls");
					gotoxy(50, 10);
					cout << "������ �Ϸ�Ǿ����ϴ�.";
					gotoxy(26, 15);
					cout << list[index_arr.front()].cardinal_num << "\t" << list[index_arr.front()].student_id << "\t" << list[index_arr.front()].name << "\t" << list[index_arr.front()].major << "\t" << list[index_arr.front()].phone_num << "\t" << list[index_arr.front()].statement << endl;
					gotoxy(26, 20);
					system("pause");
					break;
				}
				if (list[index_arr.front()].name.compare(before) == 0)
				{
					tm = list[index_arr.front()].name.length();
					list[index_arr.front()].name.replace(0, tm, after);

					system("cls");
					gotoxy(50, 10);
					cout << "������ �Ϸ�Ǿ����ϴ�.";
					gotoxy(26, 15);
					cout << list[index_arr.front()].cardinal_num << "\t" << list[index_arr.front()].student_id << "\t" << list[index_arr.front()].name << "\t" << list[index_arr.front()].major << "\t" << list[index_arr.front()].phone_num << "\t" << list[index_arr.front()].statement << endl;
					gotoxy(26, 20);
					system("pause");
					break;
				}
				if (list[index_arr.front()].major.compare(before) == 0)
				{
					tm = list[index_arr.front()].major.length();
					list[index_arr.front()].major.replace(0, tm, after);

					system("cls");
					gotoxy(50, 10);
					cout << "������ �Ϸ�Ǿ����ϴ�.";
					gotoxy(26, 15);
					cout << list[index_arr.front()].cardinal_num << "\t" << list[index_arr.front()].student_id << "\t" << list[index_arr.front()].name << "\t" << list[index_arr.front()].major << "\t" << list[index_arr.front()].phone_num << "\t" << list[index_arr.front()].statement << endl;
					gotoxy(26, 20);
					system("pause");
					break;
				}
				if (list[index_arr.front()].phone_num.compare(before) == 0)
				{
					tm = list[index_arr.front()].phone_num.length();
					list[index_arr.front()].phone_num.replace(0, tm, after);

					system("cls");
					gotoxy(50, 10);
					cout << "������ �Ϸ�Ǿ����ϴ�.";
					gotoxy(26, 15);
					cout << list[index_arr.front()].cardinal_num << "\t" << list[index_arr.front()].student_id << "\t" << list[index_arr.front()].name << "\t" << list[index_arr.front()].major << "\t" << list[index_arr.front()].phone_num << "\t" << list[index_arr.front()].statement << endl;
					gotoxy(26, 20);
					system("pause");
					break;
				}
				if (list[index_arr.front()].statement.compare(before) == 0)
				{
					tm = list[index_arr.front()].statement.length();
					list[index_arr.front()].statement.replace(0, tm, after);

					system("cls");
					gotoxy(50, 10);
					cout << "������ �Ϸ�Ǿ����ϴ�.";
					gotoxy(26, 15);
					cout << list[index_arr.front()].cardinal_num << "\t" << list[index_arr.front()].student_id << "\t" << list[index_arr.front()].name << "\t" << list[index_arr.front()].major << "\t" << list[index_arr.front()].phone_num << "\t" << list[index_arr.front()].statement << endl;
					gotoxy(26, 20);
					system("pause");
					break;
				}
			}
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
		for (int i = 0; i < 1; i++) {
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

	void instruction()
	{
		system("cls");
		gotoxy(28, 2);
		cout << "�١ڡ١ڡ١ڡ١� ��� ���� ���α׷� ���� �١ڡ١ڡ١ڡ١�" << endl;
		gotoxy(38, 5);
		cout << "�߰� �޴� �Է� ����";
		gotoxy(38, 8);
		cout << "��� : 31";
		gotoxy(38, 11);
		cout << "�й� : 18010847";
		gotoxy(38, 14);
		cout << "�̸� : �ڻ��";
		gotoxy(38, 15);
		cout << "�а� : ����������Ű��а�";
		gotoxy(38, 18);
		cout << "��ȣ : 010 - 5187 - 5312";
		gotoxy(38, 21);
		cout << "����: ����";
		gotoxy(38, 24);
		cout << "�߰� �޴� r / m Ű ��� ����\tex) ��� : r";
		gotoxy(38, 27);
		system("pause");
	}

	void menu()
	{
		setcolor(15, 0);
		int select_menu;
		while (1)
		{
			system("cls");
			gotoxy(28, 2);
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
			cout << "5. ���ȳ�";
			gotoxy(40, 21);
			cout << "6. ����";
			gotoxy(24, 27);
			cout << "�޴��Է¿� �ѱ��� ����Ͻð� �Ǹ� �ۼ����̽ô� ������ ��� ���ư� �� �ֽ��ϴ�";
			gotoxy(40, 24);
			cout << "�޴��� �����ϼ��� : ";
			cin >> select_menu;
			if (select_menu == 1)
			{
				insert_member();
			}
			else if (select_menu == 2)
			{
				view_member();
			}
			else if (select_menu == 3)
			{
				change_member();
			}
			else if (select_menu == 4)
			{
				getchar();
				delete_member();
			}
			else if (select_menu == 5)
			{
				instruction();
			}
			else if (select_menu == 6)
			{
				save_member();
				exit(1);
				list.clear();
			}
			else
			{
				error();
			}

		}
	}
};

int main()
{
	system("mod con cols=120 lines=35"); //�ܼ�â ���� ���� ���� ����
	system("title �������̽� ��� ���� ���α׷�");
	Manage test;
	string bbb;
	test.start_menu();
	test.menu();

	return 0;
}