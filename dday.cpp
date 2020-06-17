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

// m월의 날짜 수
int DayofYear::GetDays(int m)
{
	int Month_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return Month_days[m - 1];
}

// 1월 1일부터 m월 d일까지 날짜 합
int DayofYear::GetPastDay(int m, int d)
{
	int i, past = 0;

	// 1월부터 바로 전달까지 날짜 합
	for (i = 1; i < m; i++)
	{
		past = past + GetDays(i);
	}

	// 이번달 날짜 합
	past = past + d;

	return past;
}

int DayofYear::GetLeftDay()
{
	// 1월 1일부터 D-day까지의 날짜 합 - 1월 1일부터 오늘까지의 날짜 합
	return GetPastDay(d_mon, d_day) - GetPastDay(t_mon, t_day);
}

void DayofYear::ShowLeftDay()
{
	int left = GetLeftDay();

	// D-day가 오늘 날짜보다 앞설 경우
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
