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
			cout << "신입 기수를 추가하는 란입니다" << endl;

			gotoxy(38, 5);
			cout << "기수: ";

			gotoxy(38, 7);
			cout << "학번: ";

			gotoxy(38, 9);
			cout << "이름: ";
			
			gotoxy(38, 11);
			cout << "학과: ";
			
			gotoxy(38, 13);
			cout << "전번: ";
			
			gotoxy(38, 15);
			cout << "상태: ";

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
			cout << "계속 하시겠습니까? y/n >> ";
			cin >> answer;
		}
	}
	void view_member()
	{

	}

	void save_member()
	{
		ofstream file("'명단.txt");
		if (!file)
		{
			cout << "파일 읽기를 실패하였습니다" << endl;
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
			cout << "☆★☆★☆★☆★ 인터페이스 명부 관리 프로그램 ☆★☆★☆★☆★" << endl;
			Sleep(500);
			system("cls");
			setcolor(14, 0);
			gotoxy(25, 2);
			cout << "☆★☆★☆★☆★ 인터페이스 명부 관리 프로그램 ☆★☆★☆★☆★" << endl;
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
			cout << "☆★☆★☆★☆★ 인터페이스 명부 관리 프로그램 ☆★☆★☆★☆★" << endl;
			gotoxy(40, 6);
			cout << "1. 추가";
			gotoxy(40, 9);
			cout << "2. 검색";
			gotoxy(40, 12);
			cout << "3. 수정";
			gotoxy(40, 15);
			cout << "4. 삭제";
			gotoxy(40, 18);
			cout << "5. 끝내기";
			gotoxy(40, 21);
			cout << "메뉴를 선택하세요 : ";
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
					system("cls");
					gotoxy(44,10);
					cout << "메뉴를 정확하게 입력해주세요" << endl;
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
	system("mod con cols=118 lines=30"); //콘솔창 가로 세로 길이 고정
	system("title 인터페이스 명부 관리 프로그램");
	Manage test;
	string bbb;
	test.start_menu();
	test.menu();

	return 0;
}