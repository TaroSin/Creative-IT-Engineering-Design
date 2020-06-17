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

// m���� ��¥ ��
int DayofYear::GetDays(int m)
{
	int Month_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return Month_days[m - 1];
}

// 1�� 1�Ϻ��� m�� d�ϱ��� ��¥ ��
int DayofYear::GetPastDay(int m, int d)
{
	int i, past = 0;

	// 1������ �ٷ� ���ޱ��� ��¥ ��
	for (i = 1; i < m; i++)
	{
		past = past + GetDays(i);
	}

	// �̹��� ��¥ ��
	past = past + d;

	return past;
}

int DayofYear::GetLeftDay()
{
	// 1�� 1�Ϻ��� D-day������ ��¥ �� - 1�� 1�Ϻ��� ���ñ����� ��¥ ��
	return GetPastDay(d_mon, d_day) - GetPastDay(t_mon, t_day);
}

void DayofYear::ShowLeftDay()
{
	int left = GetLeftDay();

	// D-day�� ���� ��¥���� �ռ� ���
	if (left < 0)
	{
		cout << "D-day�� ���� ��¥���� �ռ� �� ����" << endl;
		return;
	}

	cout << "D-day " << left << endl;
}

int main()
{
	int mon, day;
	DayofYear dy;

	dy.SetToday(3, 30);

	cout << "��¥�� �Է��Ͻÿ� (�� ��): ";
	cin >> mon >> day;

	dy.SetDday(mon, day);

	dy.ShowLeftDay();

	return 0;
}
