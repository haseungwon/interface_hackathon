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
		return 0;
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
			cout << "신입 기수를 추가하는 란입니다";

			gotoxy(30, 25);
			cout << "재입력을 원하시면 r, 메인 메뉴로 돌아가고 싶다면 m키 입력해주세요" << endl;

			gotoxy(38, 5);
			cout << "기수 : ";

			gotoxy(38, 8);
			cout << "학번 : ";

			gotoxy(38, 11);
			cout << "이름 : ";

			gotoxy(38, 14);
			cout << "학과 : ";

			gotoxy(38, 17);
			cout << "전번 : ";

			gotoxy(38, 20);
			cout << "상태 : ";

			gotoxy(45, 5);
			cin >> mem.cardinal_num;
			if (mem.cardinal_num == "r")
			{
				mem.cardinal_num = "";
				continue;
			}
			else if (mem.cardinal_num == "m") {
				mem.cardinal_num = "";
				break;
			}

			gotoxy(45, 8);
			cin >> mem.student_id;
			if (mem.student_id == "r")
			{
				mem.student_id = "";
				continue;
			}
			else if (mem.student_id == "m") {
				mem.student_id = "";
				break;
			}

			gotoxy(45, 11);
			cin >> mem.name;
			if (mem.name == "r")
			{
				mem.name = "";
				continue;
			}
			else if (mem.name == "m") {
				mem.name = "";
				break;
			}

			gotoxy(45, 14);
			cin >> mem.major;
			if (mem.major == "r")
			{
				mem.major = "";
				continue;
			}
			else if (mem.major == "m") {
				mem.major = "";
				break;
			}
			gotoxy(45, 17);
			cin >> mem.phone_num;
			if (mem.phone_num == "r")
			{
				mem.phone_num = "";
				continue;
			}
			else if (mem.phone_num == "m") {
				mem.phone_num = "";
				break;
			}
			gotoxy(45, 20);
			cin >> mem.statement;
			if (mem.statement == "r")
			{
				mem.statement = "";
				continue;
			}
			else if (mem.statement == "m") {
				mem.statement = "";
				break;
			}
			list.push_back(mem);
			index++;

			gotoxy(38, 23);
			cout << "계속 하시겠습니까? y/n >> ";
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
			cout << "무엇을 검색 하실건가요?" << endl;
			gotoxy(38, 5);
			cout << "1. 기수" << endl;
			gotoxy(38, 8);
			cout << "2. 학번" << endl;
			gotoxy(38, 11);
			cout << "3. 이름" << endl;
			gotoxy(38, 14);
			cout << "4. 학과" << endl;
			gotoxy(38, 17);
			cout << "5. 전화번호(010-xxxx-xxxx 형식으로 검색)" << endl;
			gotoxy(38, 20);
			cout << "6. 재학 여부(신입, 재학, 휴학) 검색" << endl;
			gotoxy(38, 23);
			cout << "7. 메인 화면으로 돌아가기" << endl;
			gotoxy(38, 26);
			cout << "메뉴를 선택하세요 : ";
			cin >> bbb;

			switch (bbb)
			{
				case 1:
				{
					int idx = 0; // 표시하는 사람 수
					system("cls");
					gotoxy(38, 2);
					cout << "기수를 입력하세요 : ";
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
					int idx = 0; // 표시하는 사람 수
					system("cls");
					gotoxy(38, 2);
					cout << "학번을 입력하세요 : ";
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
					int idx = 0; // 표시하는 사람 수
					system("cls");
					gotoxy(38, 2);
					cout << "이름을 입력하세요 : " ;
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
					int idx = 0; // 표시하는 사람 수
					system("cls");
					gotoxy(38, 2);
					cout << "학과를 입력하세요 : " ;
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
					int idx = 0; // 표시하는 사람 수
					system("cls");
					gotoxy(38, 2);
					cout << "번호를 입력하세요 : " ;
					cin >> find;
					for (int i = 0;i < index;i++)
					{
					
						if (inside(find, list[i].phone_num) == 1)
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
					int idx = 0; // 표시하는 사람 수
					system("cls");
					gotoxy(38, 2);
					cout << "재학 여부(신입, 재학, 휴학)를 입력하세요 : ";
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
		ofstream file("명단.txt");
		if (!file)
		{
			cout << "파일 읽기를 실패하였습니다" << endl;
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
			gotoxy(44, 2);
			cout << "명단을 삭제하는 란입니다 아시는 정보를 입력하세요 " << endl;

			gotoxy(38, 5);
			cout << "기수 : ";

			gotoxy(38, 8);
			cout << "학번 : ";

			gotoxy(38, 11);
			cout << "이름 : ";

			gotoxy(38, 14);
			cout << "학과 : ";

			gotoxy(38, 17);
			cout << "전번 : ";

			gotoxy(38, 20);
			cout << "상태 : ";

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

			for (int i = 0;i < index;i++)
			{
				if (inside(tmp.cardinal_num, list[i].cardinal_num) == 1 && inside(tmp.student_id, list[i].student_id) == 1 && inside(tmp.name, list[i].name) == 1 && inside(tmp.major, list[i].major) == 1 && inside(tmp.phone_num, list[i].phone_num) == 1 && inside(tmp.statement, list[i].statement) == 1)
				{
					cout << list[i].cardinal_num << "\t" << list[i].student_id << "\t" << list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num << "\t" << list[i].statement << endl;

					index_arr.push_back(i);
				}
			}
			if (index_arr.size() != 1)
			{
				cout << "삭제할 대상을 하나로 다시 검색해주세요" << endl;
				system("pause");
				index_arr.clear();
			}

			else if (index_arr.size() == 1)
			{
				cout << "\n인터페이스 회원 명단에서 삭제할까요? >>> y/n ";
				cin >> x;
				if (x == 'y')
				{
					for (int i = index_arr.front();i < index-1;i++)
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
			gotoxy(44, 2);
			cout << "명단을 수정하는 란입니다 아시는 정보를 입력해서 대상을 찾아주세요 " << endl;

			gotoxy(38, 5);
			cout << "기수 : ";

			gotoxy(38, 8);
			cout << "학번 : ";

			gotoxy(38, 11);
			cout << "이름 : ";

			gotoxy(38, 14);
			cout << "학과 : ";

			gotoxy(38, 17);
			cout << "전번 : ";

			gotoxy(38, 20);
			cout << "상태 : ";

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

			for (int i = 0;i < index;i++)
			{
				if (inside(tmp.cardinal_num, list[i].cardinal_num) == 1 && inside(tmp.student_id, list[i].student_id) == 1 && inside(tmp.name, list[i].name) == 1 && inside(tmp.major, list[i].major) == 1 && inside(tmp.phone_num, list[i].phone_num) == 1 && inside(tmp.statement, list[i].statement) == 1)
				{
					cout << list[i].cardinal_num << "\t" << list[i].student_id << "\t" << list[i].name << "\t" << list[i].major << "\t" << list[i].phone_num << "\t" << list[i].statement << endl;

					index_arr.push_back(i);
				}
			}
			if (index_arr.size() != 1)
			{
				cout << "수정할 대상을 하나로 다시 검색해주세요" << endl;
				system("pause");
				index_arr.clear();
			}

			else if (index_arr.size() == 1)
			{
				cout << "수정전과 수정후를 입력해주세요" << endl;
				cout << " 수정 전: ";
				cin >> before;
				cout << "수정 후: ";
				cin >> after;
				if (list[index_arr.front()].cardinal_num.compare(before) == 0)
				{
					tm = list[index_arr.front()].cardinal_num.length();
					list[index_arr.front()].cardinal_num.replace(0, tm, after);
					break;
				}
				if (list[index_arr.front()].student_id.compare(before) == 0)
				{
					tm = list[index_arr.front()].student_id.length();
					list[index_arr.front()].student_id.replace(0, tm, after);
					break;
				}
				if (list[index_arr.front()].name.compare(before) == 0)
				{
					tm = list[index_arr.front()].name.length();
					list[index_arr.front()].name.replace(0, tm, after);
					break;
				}
				if (list[index_arr.front()].major.compare(before) == 0)
				{
					tm = list[index_arr.front()].major.length();
					list[index_arr.front()].major.replace(0, tm, after);
					break;
				}
				if (list[index_arr.front()].phone_num.compare(before) == 0)
				{
					tm = list[index_arr.front()].phone_num.length();
					list[index_arr.front()].phone_num.replace(0, tm, after);
					break;
				}
				if (list[index_arr.front()].statement.compare(before) == 0)
				{
					tm = list[index_arr.front()].statement.length();
					list[index_arr.front()].statement.replace(0, tm, after);
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

		ifstream file("명단.txt");
		if (!file)
		{
			cout << "명단을 불러올수가 없습니다";
		
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
			cout << "☆★☆★☆★☆★ 인터페이스 명부 관리 프로그램 ☆★☆★☆★☆★" << endl;
			Sleep(500);
			system("cls");
			setcolor(15, 0);
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
					change_member();
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