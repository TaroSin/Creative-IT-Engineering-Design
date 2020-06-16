#include <iostream>
#include <ctime>

using namespace std;

int Month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int year, month, week;

void input(); // 연도와 월을 입력받는 함수. 
int getweek(int year, int month); 
void Cal_leap(); // 윤년계산 
void output_calendar(); // 달력  출 력  

int main(void)
{
	input();
    week = getweek(year, month);    
    Cal_leap();
    output_calendar();
    
    int choice_num;
    char ans;
    
    cout << "\n\n" << "[원하는 옵션 선택]" << "\n" << endl;
    cout << "① 일정 추가" << endl; 
    cout << "② 일정 수정" << endl; 
    cout << "③ 일정 삭제" << endl; 
    cout << "④ 음력 변환" << endl; 
    cout << "⑤ 날짜 계산" << endl; 
    cout << "⑥ 전체 일정 확인" << endl; 
    cout << "⑦ 날짜 변경" << endl << endl;
    
    cout << "옵션 변호: "; 
    cin >> choice_num; 
    
    if(choice_num == 7){
    	cout << endl;
    	input();
    	week = getweek(year, month);    
    	Cal_leap();
    	output_calendar();   	
	}
	else cout << "Error!" << endl;
}
 
void input(){
	printf("년: ");
    cin >> year;
    printf("월: ");
    cin >> month;
}

int getweek(int year, int month){
    int week = year + (year / 4 - year / 100 + year / 400);

    for (int i = 0; i < month - 1; i++)
        week += Month_days[i];

    return (week % 7);
}

void Cal_leap(){
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
    Month_days[1]++;
}

void output_calendar(){
	cout << "  " << endl << "       " << year << "년 " << month << "월       " << endl << endl << "  " <<
        "일 " << "월 " << "화 " << "수 " << "목 " << "금 " << "토  " << endl << "  ";

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

