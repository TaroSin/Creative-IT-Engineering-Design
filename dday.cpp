class dday {
private:
	int d_mon;
	int d_day;
	int t_mon;
	int t_day; 
	char today[12];
public:
	void SetDday(int m, int d);
	void SetToday(int m, int d);
	char* GetMonth(int m);
	char* GetToday();
	
};

void DayofYear::SatDay(int m, int d)
{
	d_mon = m;
	d_day = d;
}