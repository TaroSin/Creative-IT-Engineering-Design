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
<<<<<<< HEAD
	void SetToday(int tm, int td);
=======
	void SetToday(int m, int d);
>>>>>>> e83e24673c5ae715b0720526ca92d3fb678af4a6
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

<<<<<<< HEAD
void DayofYear::SetToday(int tm, int td)
{
	t_mon = tm;
	t_day = td;
}

// m���� ��¥ ��
=======
void DayofYear::SetToday(int m, int d)
{
	t_mon = m;
	t_day = d;
}

>>>>>>> e83e24673c5ae715b0720526ca92d3fb678af4a6
int DayofYear::GetDays(int m)
{
	int Month_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return Month_days[m - 1];
}

<<<<<<< HEAD
// 1�� 1�Ϻ��� m�� d�ϱ��� ��¥ ��
=======
>>>>>>> e83e24673c5ae715b0720526ca92d3fb678af4a6
int DayofYear::GetPastDay(int m, int d)
{
	int i, past = 0;

<<<<<<< HEAD
	// 1������ �ٷ� ���ޱ��� ��¥ ��
=======
>>>>>>> e83e24673c5ae715b0720526ca92d3fb678af4a6
	for (i = 1; i < m; i++)
	{
		past = past + GetDays(i);
	}

<<<<<<< HEAD
	// �̹��� ��¥ ��
=======
>>>>>>> e83e24673c5ae715b0720526ca92d3fb678af4a6
	past = past + d;

	return past;
}

int DayofYear::GetLeftDay()
{
<<<<<<< HEAD
	// 1�� 1�Ϻ��� D-day������ ��¥ �� - 1�� 1�Ϻ��� ���ñ����� ��¥ ��
=======
>>>>>>> e83e24673c5ae715b0720526ca92d3fb678af4a6
	return GetPastDay(d_mon, d_day) - GetPastDay(t_mon, t_day);
}

void DayofYear::ShowLeftDay()
{
	int left = GetLeftDay();

<<<<<<< HEAD
	// D-day�� ���� ��¥���� �ռ� ���
	if (left < 0)
	{
		cout << "D-day�� ���� ��¥���� �ռ� �� ����" << endl;
		return;
	}

=======
>>>>>>> e83e24673c5ae715b0720526ca92d3fb678af4a6
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
<<<<<<< HEAD
}
=======
}
>>>>>>> e83e24673c5ae715b0720526ca92d3fb678af4a6
