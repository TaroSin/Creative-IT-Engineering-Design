#include <iostream>
#include <cstring>

using namespace std;

enum BOOL { FALSE = 0, TRUE = 1 };

/*  아래의 음력 데이터 :

    평달 -  작은 달 : 1
            큰달    : 2
    윤달이 있는 달 -  평달이 작고 윤달도 작으면 : 3
                      평달이 작고 윤달이 크면   : 4
                      평달이 크고 윤달이 작으면 : 5
                      평달과 윤달이 모두 크면   : 6  */
static const char _info_array[203][12] =
{
    /* 1841 */
    1, 2, 4, 1, 1, 2,    1, 2, 1, 2, 2, 1,
    2, 2, 1, 2, 1, 1,    2, 1, 2, 1, 2, 1,
    2, 2, 2, 1, 2, 1,    4, 1, 2, 1, 2, 1,
    2, 2, 1, 2, 1, 2,    1, 2, 1, 2, 1, 2,
    1, 2, 1, 2, 2, 1,    2, 1, 2, 1, 2, 1,
    2, 1, 2, 1, 5, 2,    1, 2, 2, 1, 2, 1,
    2, 1, 1, 2, 1, 2,    1, 2, 2, 2, 1, 2,
    1, 2, 1, 1, 2, 1,    2, 1, 2, 2, 2, 1,
    2, 1, 2, 3, 2, 1,    2, 1, 2, 1, 2, 2,
    2, 1, 2, 1, 1, 2,    1, 1, 2, 2, 1, 2,

    /* 1851 */
    2, 2, 1, 2, 1, 1,    2, 1, 2, 1, 5, 2,
    2, 1, 2, 2, 1, 1,    2, 1, 2, 1, 1, 2,
    2, 1, 2, 2, 1, 2,    1, 2, 1, 2, 1, 2,
    1, 2, 1, 2, 1, 2,    5, 2, 1, 2, 1, 2,
    1, 1, 2, 1, 2, 2,    1, 2, 2, 1, 2, 1,
    2, 1, 1, 2, 1, 2,    1, 2, 2, 2, 1, 2,
    1, 2, 1, 1, 5, 2,    1, 2, 1, 2, 2, 2,
    1, 2, 1, 1, 2, 1,    1, 2, 2, 1, 2, 2,
    2, 1, 2, 1, 1, 2,    1, 1, 2, 1, 2, 2,
    2, 1, 6, 1, 1, 2,    1, 1, 2, 1, 2, 2,

    /* 1861 */
    1, 2, 2, 1, 2, 1,    2, 1, 2, 1, 1, 2,
    2, 1, 2, 1, 2, 2,    1, 2, 2, 3, 1, 2,
    1, 2, 2, 1, 2, 1,    2, 2, 1, 2, 1, 2,
    1, 1, 2, 1, 2, 1,    2, 2, 1, 2, 2, 1,
    2, 1, 1, 2, 4, 1,    2, 2, 1, 2, 2, 1,
    2, 1, 1, 2, 1, 1,    2, 2, 1, 2, 2, 2,
    1, 2, 1, 1, 2, 1,    1, 2, 1, 2, 2, 2,
    1, 2, 2, 3, 2, 1,    1, 2, 1, 2, 2, 1,
    2, 2, 2, 1, 1, 2,    1, 1, 2, 1, 2, 1,
    2, 2, 2, 1, 2, 1,    2, 1, 1, 5, 2, 1,

    /* 1871 */
    2, 2, 1, 2, 2, 1,    2, 1, 2, 1, 1, 2,
    1, 2, 1, 2, 2, 1,    2, 1, 2, 2, 1, 2,
    1, 1, 2, 1, 2, 4,    2, 1, 2, 2, 1, 2,
    1, 1, 2, 1, 2, 1,    2, 1, 2, 2, 2, 1,
    2, 1, 1, 2, 1, 1,    2, 1, 2, 2, 2, 1,
    2, 2, 1, 1, 5, 1,    2, 1, 2, 2, 1, 2,
    2, 2, 1, 1, 2, 1,    1, 2, 1, 2, 1, 2,
    2, 2, 1, 2, 1, 2,    1, 1, 2, 1, 2, 1,
    2, 2, 4, 2, 1, 2,    1, 1, 2, 1, 2, 1,
    2, 1, 2, 2, 1, 2,    2, 1, 2, 1, 1, 2,

    /* 1881 */
    1, 2, 1, 2, 1, 2,    5, 2, 2, 1, 2, 1,
    1, 2, 1, 2, 1, 2,    1, 2, 2, 1, 2, 2,
    1, 1, 2, 1, 1, 2,    1, 2, 2, 2, 1, 2,
    2, 1, 1, 2, 3, 2,    1, 2, 2, 1, 2, 2,
    2, 1, 1, 2, 1, 1,    2, 1, 2, 1, 2, 2,
    2, 1, 2, 1, 2, 1,    1, 2, 1, 2, 1, 2,
    2, 2, 1, 5, 2, 1,    1, 2, 1, 2, 1, 2,
    2, 1, 2, 2, 1, 2,    1, 1, 2, 1, 2, 1,
    2, 1, 2, 2, 1, 2,    1, 2, 1, 2, 1, 2,
    1, 5, 2, 1, 2, 2,    1, 2, 1, 2, 1, 2,

    /* 1891 */
    1, 2, 1, 2, 1, 2,    1, 2, 2, 1, 2, 2,
    1, 1, 2, 1, 1, 5,    2, 2, 1, 2, 2, 2,
    1, 1, 2, 1, 1, 2,    1, 2, 1, 2, 2, 2,
    1, 2, 1, 2, 1, 1,    2, 1, 2, 1, 2, 2,
    2, 1, 2, 1, 5, 1,    2, 1, 2, 1, 2, 1,
    2, 2, 2, 1, 2, 1,    1, 2, 1, 2, 1, 2,
    1, 2, 2, 1, 2, 1,    2, 1, 2, 1, 2, 1,
    2, 1, 5, 2, 2, 1,    2, 1, 2, 1, 2, 1,
    2, 1, 2, 1, 2, 1,    2, 2, 1, 2, 1, 2,
    1, 2, 1, 1, 2, 1,    2, 5, 2, 2, 1, 2,

    /* 1901 */
    1, 2, 1, 1, 2, 1,    2, 1, 2, 2, 2, 1,
    2, 1, 2, 1, 1, 2,    1, 2, 1, 2, 2, 2,
    1, 2, 1, 2, 3, 2,    1, 1, 2, 2, 1, 2,
    2, 2, 1, 2, 1, 1,    2, 1, 1, 2, 2, 1,
    2, 2, 1, 2, 2, 1,    1, 2, 1, 2, 1, 2,
    1, 2, 2, 4, 1, 2,    1, 2, 1, 2, 1, 2,
    1, 2, 1, 2, 1, 2,    2, 1, 2, 1, 2, 1,
    2, 1, 1, 2, 2, 1,    2, 1, 2, 2, 1, 2,
    1, 5, 1, 2, 1, 2,    1, 2, 2, 2, 1, 2,
    1, 2, 1, 1, 2, 1,    2, 1, 2, 2, 2, 1,

    /* 1911 */
    2, 1, 2, 1, 1, 5,    1, 2, 2, 1, 2, 2,
    2, 1, 2, 1, 1, 2,    1, 1, 2, 2, 1, 2,
    2, 2, 1, 2, 1, 1,    2, 1, 1, 2, 1, 2,
    2, 2, 1, 2, 5, 1,    2, 1, 2, 1, 1, 2,
    2, 1, 2, 2, 1, 2,    1, 2, 1, 2, 1, 2,
    1, 2, 1, 2, 1, 2,    2, 1, 2, 1, 2, 1,
    2, 3, 2, 1, 2, 2,    1, 2, 2, 1, 2, 1,
    2, 1, 1, 2, 1, 2,    1, 2, 2, 2, 1, 2,
    1, 2, 1, 1, 2, 1,    5, 2, 2, 1, 2, 2,
    1, 2, 1, 1, 2, 1,    1, 2, 2, 1, 2, 2,

    /* 1921 */
    2, 1, 2, 1, 1, 2,    1, 1, 2, 1, 2, 2,
    2, 1, 2, 2, 3, 2,    1, 1, 2, 1, 2, 2,
    1, 2, 2, 1, 2, 1,    2, 1, 2, 1, 1, 2,
    2, 1, 2, 1, 2, 2,    1, 2, 1, 2, 1, 1,
    2, 1, 2, 5, 2, 1,    2, 2, 1, 2, 1, 2,
    1, 1, 2, 1, 2, 1,    2, 2, 1, 2, 2, 1,
    2, 1, 1, 2, 1, 2,    1, 2, 2, 1, 2, 2,
    1, 5, 1, 2, 1, 1,    2, 2, 1, 2, 2, 2,
    1, 2, 1, 1, 2, 1,    1, 2, 1, 2, 2, 2,
    1, 2, 2, 1, 1, 5,    1, 2, 1, 2, 2, 1,

    /* 1931 */
    2, 2, 2, 1, 1, 2,    1, 1, 2, 1, 2, 1,
    2, 2, 2, 1, 2, 1,    2, 1, 1, 2, 1, 2,
    1, 2, 2, 1, 6, 1,    2, 1, 2, 1, 1, 2,
    1, 2, 1, 2, 2, 1,    2, 2, 1, 2, 1, 2,
    1, 1, 2, 1, 2, 1,    2, 2, 1, 2, 2, 1,
    2, 1, 4, 1, 2, 1,    2, 1, 2, 2, 2, 1,
    2, 1, 1, 2, 1, 1,    2, 1, 2, 2, 2, 1,
    2, 2, 1, 1, 2, 1,    4, 1, 2, 2, 1, 2,
    2, 2, 1, 1, 2, 1,    1, 2, 1, 2, 1, 2,
    2, 2, 1, 2, 1, 2,    1, 1, 2, 1, 2, 1,

    /* 1941 */
    2, 2, 1, 2, 2, 4,    1, 1, 2, 1, 2, 1,
    2, 1, 2, 2, 1, 2,    2, 1, 2, 1, 1, 2,
    1, 2, 1, 2, 1, 2,    2, 1, 2, 2, 1, 2,
    1, 1, 2, 4, 1, 2,    1, 2, 2, 1, 2, 2,
    1, 1, 2, 1, 1, 2,    1, 2, 2, 2, 1, 2,
    2, 1, 1, 2, 1, 1,    2, 1, 2, 2, 1, 2,
    2, 5, 1, 2, 1, 1,    2, 1, 2, 1, 2, 2,
    2, 1, 2, 1, 2, 1,    1, 2, 1, 2, 1, 2,
    2, 2, 1, 2, 1, 2,    3, 2, 1, 2, 1, 2,
    2, 1, 2, 2, 1, 2,    1, 1, 2, 1, 2, 1,

    /* 1951 */
    2, 1, 2, 2, 1, 2,    1, 2, 1, 2, 1, 2,
    1, 2, 1, 2, 4, 2,    1, 2, 1, 2, 1, 2,
    1, 2, 1, 1, 2, 2,    1, 2, 2, 1, 2, 2,
    1, 1, 2, 1, 1, 2,    1, 2, 2, 1, 2, 2,
    2, 1, 4, 1, 1, 2,    1, 2, 1, 2, 2, 2,
    1, 2, 1, 2, 1, 1,    2, 1, 2, 1, 2, 2,
    2, 1, 2, 1, 2, 1,    1, 5, 2, 1, 2, 2,
    1, 2, 2, 1, 2, 1,    1, 2, 1, 2, 1, 2,
    1, 2, 2, 1, 2, 1,    2, 1, 2, 1, 2, 1,
    2, 1, 2, 1, 2, 5,    2, 1, 2, 1, 2, 1,

    /* 1961 */
    2, 1, 2, 1, 2, 1,    2, 2, 1, 2, 1, 2,
    1, 2, 1, 1, 2, 1,    2, 2, 1, 2, 2, 1,
    2, 1, 2, 3, 2, 1,    2, 1, 2, 2, 2, 1,
    2, 1, 2, 1, 1, 2,    1, 2, 1, 2, 2, 2,
    1, 2, 1, 2, 1, 1,    2, 1, 1, 2, 2, 1,
    2, 2, 5, 2, 1, 1,    2, 1, 1, 2, 2, 1,
    2, 2, 1, 2, 2, 1,    1, 2, 1, 2, 1, 2,
    1, 2, 2, 1, 2, 1,    5, 2, 1, 2, 1, 2,
    1, 2, 1, 2, 1, 2,    2, 1, 2, 1, 2, 1,
    2, 1, 1, 2, 2, 1,    2, 1, 2, 2, 1, 2,

    /* 1971 */
    1, 2, 1, 1, 5, 2,    1, 2, 2, 2, 1, 2,
    1, 2, 1, 1, 2, 1,    2, 1, 2, 2, 2, 1,
    2, 1, 2, 1, 1, 2,    1, 1, 2, 2, 2, 1,
    2, 2, 1, 5, 1, 2,    1, 1, 2, 2, 1, 2,
    2, 2, 1, 2, 1, 1,    2, 1, 1, 2, 1, 2,
    2, 2, 1, 2, 1, 2,    1, 5, 2, 1, 1, 2,
    2, 1, 2, 2, 1, 2,    1, 2, 1, 2, 1, 1,
    2, 2, 1, 2, 1, 2,    2, 1, 2, 1, 2, 1,
    2, 1, 1, 2, 1, 6,    1, 2, 2, 1, 2, 1,
    2, 1, 1, 2, 1, 2,    1, 2, 2, 1, 2, 2,

    /* 1981 */
    1, 2, 1, 1, 2, 1,    1, 2, 2, 1, 2, 2,
    2, 1, 2, 3, 2, 1,    1, 2, 2, 1, 2, 2,
    2, 1, 2, 1, 1, 2,    1, 1, 2, 1, 2, 2,
    2, 1, 2, 2, 1, 1,    2, 1, 1, 5, 2, 2,
    1, 2, 2, 1, 2, 1,    2, 1, 1, 2, 1, 2,
    1, 2, 2, 1, 2, 2,    1, 2, 1, 2, 1, 1,
    2, 1, 2, 2, 1, 5,    2, 2, 1, 2, 1, 2,
    1, 1, 2, 1, 2, 1,    2, 2, 1, 2, 2, 1,
    2, 1, 1, 2, 1, 2,    1, 2, 2, 1, 2, 2,
    1, 2, 1, 1, 5, 1,    2, 1, 2, 2, 2, 2,

    /* 1991 */
    1, 2, 1, 1, 2, 1,    1, 2, 1, 2, 2, 2,
    1, 2, 2, 1, 1, 2,    1, 1, 2, 1, 2, 2,
    1, 2, 5, 2, 1, 2,    1, 1, 2, 1, 2, 1,
    2, 2, 2, 1, 2, 1,    2, 1, 1, 2, 1, 2,
    1, 2, 2, 1, 2, 2,    1, 5, 2, 1, 1, 2,
    1, 2, 1, 2, 2, 1,    2, 1, 2, 2, 1, 2,
    1, 1, 2, 1, 2, 1,    2, 2, 1, 2, 2, 1,
    2, 1, 1, 2, 3, 2,    2, 1, 2, 2, 2, 1,
    2, 1, 1, 2, 1, 1,    2, 1, 2, 2, 2, 1,
    2, 2, 1, 1, 2, 1,    1, 2, 1, 2, 2, 1,

    /* 2001 */
    2, 2, 2, 3, 2, 1,    1, 2, 1, 2, 1, 2,
    2, 2, 1, 2, 1, 2,    1, 1, 2, 1, 2, 1,
    2, 2, 1, 2, 2, 1,    2, 1, 1, 2, 1, 2,
    1, 5, 2, 2, 1, 2,    1, 2, 1, 2, 1, 2,
    1, 2, 1, 2, 1, 2,    2, 1, 2, 2, 1, 1,
    2, 1, 2, 1, 2, 1,    5, 2, 2, 1, 2, 2,
    1, 1, 2, 1, 1, 2,    1, 2, 2, 2, 1, 2,
    2, 1, 1, 2, 1, 1,    2, 1, 2, 2, 1, 2,
    2, 2, 1, 1, 5, 1,    2, 1, 2, 1, 2, 2,
    2, 1, 2, 1, 2, 1,    1, 2, 1, 2, 1, 2,

    /* 2011 */
    2, 1, 2, 2, 1, 2,    1, 1, 2, 1, 2, 1,
    2, 1, 6, 2, 1, 2,    1, 1, 2, 1, 2, 1,
    2, 1, 2, 2, 1, 2,    1, 2, 1, 2, 1, 2,
    1, 2, 1, 2, 1, 2,    1, 2, 5, 2, 1, 2,
    1, 2, 1, 1, 2, 1,    2, 2, 2, 1, 2, 1,
    2, 1, 2, 1, 1, 2,    1, 2, 2, 1, 2, 2,
    1, 2, 1, 2, 3, 2,    1, 2, 1, 2, 2, 2,
    1, 2, 1, 2, 1, 1,    2, 1, 2, 1, 2, 2,
    2, 1, 2, 1, 2, 1,    1, 2, 1, 2, 1, 2,
    2, 1, 2, 5, 2, 1,    1, 2, 1, 2, 1, 2,

    /* 2021 */
    1, 2, 2, 1, 2, 1,    2, 1, 2, 1, 2, 1,
    2, 1, 2, 1, 2, 2,    1, 2, 1, 2, 1, 2,
    1, 5, 2, 1, 2, 1,    2, 2, 1, 2, 1, 2,
    1, 2, 1, 1, 2, 1,    2, 2, 1, 2, 2, 1,
    2, 1, 2, 1, 1, 5,    2, 1, 2, 2, 2, 1,
    2, 1, 2, 1, 1, 2,    1, 2, 1, 2, 2, 2,
    1, 2, 1, 2, 1, 1,    2, 1, 1, 2, 2, 2,
    1, 2, 2, 1, 5, 1,    2, 1, 1, 2, 2, 1,
    2, 2, 1, 2, 2, 1,    1, 2, 1, 1, 2, 2,
    1, 2, 1, 2, 2, 1,    2, 1, 2, 1, 2, 1,

    /* 2031 */
    2, 1, 5, 2, 1, 2,    2, 1, 2, 1, 2, 1,
    2, 1, 1, 2, 1, 2,    2, 1, 2, 2, 1, 2,
    1, 2, 1, 1, 2, 1,    2, 1, 2, 2, 5, 2,
    1, 2, 1, 1, 2, 1,    2, 1, 2, 2, 2, 1,
    2, 1, 2, 1, 1, 2,    1, 1, 2, 2, 1, 2,
    2, 2, 1, 2, 1, 4,    1, 1, 2, 1, 2, 2,
    2, 2, 1, 2, 1, 1,    2, 1, 1, 2, 1, 2,
    2, 2, 1, 2, 1, 2,    1, 2, 1, 1, 2, 1,
    2, 2, 1, 2, 5, 2,    1, 2, 1, 2, 1, 1,
    2, 1, 2, 2, 1, 2,    2, 1, 2, 1, 2, 1,

    /* 2041 */
    2, 1, 1, 2, 1, 2,    2, 1, 2, 2, 1, 2,
    1, 5, 1, 2, 1, 2,    1, 2, 2, 2, 1, 2,
    1, 2, 1, 1, 2, 1,    1, 2, 2, 1, 2, 2,
};

typedef struct _lunar_info
{
    unsigned short lunar_year;         // 음력변환후년도(양력과다를수있음)
    unsigned char lunar_month;              // 음력변환후달
    unsigned char lunar_day;                // 음력변환후일
    bool isyoondal;          // 윤달여부0:평달/1:윤달
} lunar_t;

static int _info_month[12] =  // 나중에 Calendar.cpp 파일에 합칠 때 제거
{
       31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

BOOL SolarToLunar(lunar_t& lunar);

static void febdays(int y)  // 나중에 Calendar.cpp 파일에 합칠 때 제거
{
    _info_month[1] = 28;

    if (y % 4 == 0)
    {
        if (y % 100 == 0 && y % 400 == 0)
            return;
    }
    else
        return;
    _info_month[1] = 29;
}

int main()
{
    lunar_t lunar;

    SolarToLunar(lunar);

    return 0;
}

BOOL SolarToLunar(lunar_t& lunar)
{
    int Year, Month, Day;

    cout << "음력으로 바꿀 날짜를 입력하세요(연도 월 일) : ";
    cin >> Year >> Month >> Day;
    cout << endl;

    if (Year < 1841 || 2043 < Year)
    {
        return FALSE;
    }
    if (Month < 1 || 12 < Month)
    {
        return FALSE;
    }

    febdays(Year);

    if (Day < 1 || _info_month[Month - 1] < Day)
    {
        return FALSE;
    }

    int ly, lm, ld;
    int m1, m2, mm, i, j;
    int sy = Year, sm = Month, sd = Day;
    long td, td1, td2;
    int dt[203];
    BOOL Yoon = FALSE;

    td1 = 1840 * 365L + 1840 / 4 - 1840 / 100 + 1840 / 400 + 23;
    td2 = (sy - 1) * 365L + (sy - 1) / 4 - (sy - 1) / 100 + (sy - 1) / 400 + sd;

    for (i = 0; i < sm - 1; i++)
        td2 += _info_month[i];
    td = td2 - td1 + 1;

    for (i = 0; i <= sy - 1841; i++)
    {
        dt[i] = 0;
        for (j = 0; j < 12; j++)
        {
            switch (_info_array[i][j])
            {
            case 1: mm = 29;
                break;
            case 2: mm = 30;
                break;
            case 3: mm = 58;   /* 29+29 */
                break;
            case 4: mm = 59;   /* 29+30 */
                break;
            case 5: mm = 59;   /* 30+29 */
                break;
            case 6: mm = 60;   /* 30+30 */
                break;
            }
            dt[i] += mm;
        }
    }
    ly = 0;
    while (1)
    {
        if (td > dt[ly])
        {
            td -= dt[ly];
            ly++;
        }
        else
            break;
    }
    lm = 0;
    while (1)
    {
        if (_info_array[ly][lm] <= 2)
        {
            mm = _info_array[ly][lm] + 28;
            if (td > mm)
            {
                td -= mm;
                lm++;
            }
            else
                break;
        }
        else
        {
            switch (_info_array[ly][lm])
            {
            case 3: m1 = 29;
                m2 = 29;
                break;
            case 4: m1 = 29;
                m2 = 30;
                break;
            case 5: m1 = 30;
                m2 = 29;
                break;
            case 6: m1 = 30;
                m2 = 30;
                break;
            }
            if (td > m1)
            {
                td -= m1;
                if (td > m2)
                {
                    td -= m2;
                    lm++;
                }
                else
                {
                    Yoon = TRUE;
                    break;
                }
            }
            else
                break;
        }
    }

    ly += 1841;
    lm += 1;
    ld = (Year % 400 == 0 || Year % 100 != 0 || Year % 4 == 0) ? td : td - 1;

    lunar.lunar_day = ld;
    lunar.isyoondal = Yoon ? true : false;
    lunar.lunar_month = lm;
    lunar.lunar_year = ly;

    cout << "음력: " << lunar.lunar_year << "년 " <<
        (int)lunar.lunar_month << "월 " << (int)lunar.lunar_day << "일" << endl;
    cout << endl;

    return TRUE;
}