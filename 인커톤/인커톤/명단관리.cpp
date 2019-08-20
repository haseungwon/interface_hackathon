#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4244)

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

//명부 내용이 담긴 구조체
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

//x,y좌표 설정
void gotoxy(short x, short y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//글자 색 변화
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
			cout << "신입 기수를 추가하는 란입니다" << endl;

			gotoxy(34, 6);
			cout << "기수: ";
			
			gotoxy(34, 8);
			cout << "학번: ";

			gotoxy(34, 10);
			cout << "이름: ";

			gotoxy(34, 12);
			cout << "학과: ";

			gotoxy(34, 14);
			cout << "전번: ";

			gotoxy(34, 16);
			cout << "상태: ";

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
			cout << "계속 하시겠습니까? y/n >> ";
			cin >> answer;
		}
	}
	void view_member()
	{

	}

public:

	vector<Member> list;	//Member 형식의 벡터 list
	Member mem;				//구조체 mem

	int index = 0;


	void start_menu() {

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
		while (1) {
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
			cout << "5. 종료";
			gotoxy(38, 21);
			cout << "메뉴를 선택하세요 : ";
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
		cout << "이용해주셔서 감사합니다" << endl;
		Sleep(2000);
	}

};

int main()
{
	system("mode con cols=118 lines=30"); //cols = 칸/행 (가로)  lines = 줄/열 (세로)
	system("title 인터페이스 명부 관리 프로그램"); //프로그램 제목 바꾸는 역할
	Manage test;
	string bbb;
	test.start_menu();
	test.menu();
	test.exit_menu();

	return 0;
}

//도구 - 옵션 - 디버깅 - 일반 >> 디버깅이 중지되면 자동으로 콘솔창 닫기하면 0코드로인해 종료되었습니다 안뜸