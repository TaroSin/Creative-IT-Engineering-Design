<<<<<<< HEAD
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
	
	return 0;
}
=======
#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

int Month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int year, month, week;
void input(); // ������ ���� �Է¹޴� �Լ�. 
int getweek(int year, int month);
void Cal_leap(); // ������ 
void output_calendar(); // �Է¹��� ������ ���� �޷��� ���  
void Select_Option(int&); // �ɼ��� ����ϰ� �Է¹��� 
void textcolor(int foreground, int background); //�����߰���� 
void gotoxy(int x, int y);
int main()
{
    input();
    week = getweek(year, month);
    Cal_leap();
    output_calendar();
    int option_num = 0;
    Select_Option(option_num);
    return 0;
}

void input() {
    printf("��: ");
    cin >> year;
    printf("��: ");
    cin >> month;
}

int getweek(int year, int month) {
    int week = year + (year / 4 - year / 100 + year / 400);

    for (int i = 0; i < month - 1; i++)
        week += Month_days[i];

    return (week % 7);
}

void Cal_leap() {
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        Month_days[1]++;
}

void output_calendar() {
	textcolor(11, 0);
	cout << "  " << endl << "       " << year << "�� " << month << "��       " << endl << endl << "  " <<
        "�� " << "�� " << "ȭ " << "�� " << "�� " << "�� " << "��  " << endl << "  ";
	textcolor(15, 0);
    for (int i = 0; i < week; i++)
        cout << "   ";

    for (int j = 1; j <= Month_days[month - 1]; j++)
    {
        printf("%2d ", j);
        if (week % 7 == 6)
            cout << "  " << endl << "  ";
        week = (week + 1) % 7;
    }
    cout << endl;
}

void Select_Option(int &num) {	
    gotoxy(59, 2);
	cout << "[���ϴ� �ɼ� ����]";
	gotoxy(60, 3);
	cout << "�� ���� �߰�" ;
    gotoxy(60, 4);
	cout << "�� ���� ����" ;
    gotoxy(60, 5);
	cout << "�� ���� ����" ;
    gotoxy(60, 6);
	cout << "�� ���� ��ȯ" ;
    gotoxy(60, 7);
	cout << "�� ��¥ ���" ;
    gotoxy(60, 8);
	cout << "�� ��ü ���� Ȯ��" ;
    gotoxy(60, 9);
	cout << "�� ��¥ ����" ;
    gotoxy(60, 10);
	cout << "�� ����" ;
    gotoxy(60, 11);
	cout << "�ɼ� ��ȣ: ";
    cin >> num;
    if (num == 7) {
        system("cls");
        input();
        week = getweek(year, month);
        Cal_leap();
        output_calendar();
        while(num != 8) Select_Option(num);  
	}
    else if (num == 8)
	{
		system("cls");
		cout << "\n���α׷��� �����մϴ�." << endl;
		Sleep(1000);	
	}
    else {
    	cout << "\n\n*************�ٽ� �������ּ���.*************" << endl;
        while(num != 1 && num != 2 && num != 3 && num != 4 && num != 5 && num != 6 && num != 7 && num != 8)  
            Select_Option(num);
    }
}

void textcolor(int foreground, int background) {
    int color = foreground + background * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x,int y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}
>>>>>>> upstream/develop
