#include <bits/stdc++.h>
#define endl '\n'

#include <iostream>
#include <ctime>

using namespace std;

int Month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int getweek(int year, int month){
    int week = year + (year / 4 - year / 100 + year / 400);

    for (int i = 0; i < month - 1; i++)
        week += Month_days[i];

    return (week % 7);
}

int main(void)
{
	cout << "hello" << endl;

	return 0;

    int year, month, week;

    printf("��: ");
    cin >> year;
    printf("��: ");
    cin >> month;

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        Month_days[1]++;

    week = getweek(year, month);

    cout << "  " << endl << "       " << year << "�� " << month << "��       " << endl << endl << "  " <<
        "�� " << "�� " << "ȭ " << "�� " << "�� " << "�� " << "��  " << endl << "  ";

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

