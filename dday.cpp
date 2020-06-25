#include <iostream>

using namespace std;

class DayofYear
{
private:
	int d_mon;
	int d_day;
	int t_mon;
	int t_day;
public:
	void SetDday(int m, int d);
	void SetToday(int tm, int td);

	void SetToday(int m, int d);
	int GetDays(int m);
	int GetPastDay(int m, int d);
	int GetLeftDay();
	void ShowLeftDay();
};

void DayofYear::SetDday(int m, int d)
{
	d_mon = m;
	d_day = d;
}

void DayofYear::SetToday(int tm, int td)
{
	t_mon = tm;
	t_day = td;
}


void DayofYear::SetToday(int m, int d)
{
	t_mon = m;
	t_day = d;
}

int DayofYear::GetDays(int m)
{
	int Month_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return Month_days[m - 1];
}


int DayofYear::GetPastDay(int m, int d)
{
	int i, past = 0;


	for (i = 1; i < m; i++)
	{
		past = past + GetDays(i);
	}


	past = past + d;

	return past;
}

int DayofYear::GetLeftDay()
{

	return GetPastDay(d_mon, d_day) - GetPastDay(t_mon, t_day);
}

void DayofYear::ShowLeftDay()
{
	int left = GetLeftDay();

	if (left < 0)
	{
		cout << "D-day가 오늘 날짜보다 앞설 수 없음" << endl;
		return;
	}


	cout << "D-day " << left << endl;
}

int main()
{
	int mon, day;
	DayofYear dy;

	dy.SetToday(3, 30);

	cout << "날짜를 입력하시오 (월 일): ";
	cin >> mon >> day;

	dy.SetDday(mon, day);

	dy.ShowLeftDay();

	return 0;
}

}