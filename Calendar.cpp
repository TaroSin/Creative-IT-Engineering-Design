#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>
using namespace std;
#define MAX_NUM 100 
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

typedef struct{
     char name[30];
     char year[30];
     char day[30];
}User;

int saveFile(User* ptr, int* num);
int openFile(User* ptr, int* num);
void insert(User* ptr, int* num, int year);
int deleted(User* ptr, int* num);
int search(User* ptr, int* num);
void printAll(User* ptr, int* num);
void schedule();
typedef struct _lunar_info
{
    unsigned short lunar_year;         // 음력변환후년도(양력과다를수있음)
    unsigned char lunar_month;              // 음력변환후달
    unsigned char lunar_day;                // 음력변환후일
    bool isyoondal;          // 윤달여부0:평달/1:윤달
} lunar_t;
typedef struct _solar_info
{
    unsigned short year;               // 양력변환후년도(음력과다를수있음)
    unsigned char month;              // 양력변환후달
    unsigned char day;                // 양력변환후일
    unsigned char dayofweek;          // 주중요일을숫자로( 0:일, 1:월... 6:토)
} solar_t;

int Month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int lunar_Month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int solar_Month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int year, month, week;
void input(); // 연도와 월을 입력받는 함수. 
int getweek(int year, int month);
static void febdays(int y); // 윤년계산 인자 있는 버전
void Cal_leap(); // 윤년계산 
void output_calendar(); // 입력받은 연도와 월의 달력을 출력  
void Select_Option(int&); // 옵션을 출력하고 입력받음 
void textcolor(int foreground, int background); //색깔추가기능 
void gotoxy(int x, int y);
bool SolarToLunar(lunar_t& lunar); // 양력 -> 음력
bool LunarToSolar(int Year, int Month, int Day, bool Leaf, solar_t& solar);
void holiday(int year);
void dday();
void openHoliDay(int year);

class DayofYear
{
private:
    int d_mon;
    int d_day;
    int t_mon;
    int t_day;
public:
    void SetDday();
    void SetDdayHoliy(int year);
    void SetToday();
    int GetPastDay(int m, int d);
    int GetLeftDay();
    void ShowLeftDay();
};

int main()
{
    system("mode con cols=100 lines=32 | title Calendar");
    struct tm* now;
	time_t now_t;
	time(&now_t);
	now=localtime(&now_t);
    year=now->tm_year+1900;
    month=now->tm_mon+1;
    week = getweek(year, month);
    Cal_leap();
    output_calendar();
    int option_num = 0;
    Select_Option(option_num);
    return 0;
}

void input() {
	textcolor(9,0);
	cout << endl << "출력을 원하는 달력의 연도와 월을 입력하세요." << endl << endl;
	textcolor(15, 0);
    cout << "년: ";
    cin >> year;
    cout << "월: ";
    cin >> month;
}

int getweek(int year, int month) {
	int lastyear=year-1;
    int week1 = (lastyear*365) + (lastyear / 4) - (lastyear / 100) + (lastyear / 400);

    for (int i = 0; i < month - 1; i++)
    {
    	if(i==1)
			Cal_leap();	
        week1 += Month_days[i];
	}
    return (week1 % 7);
}

static void febdays(int y)  // 윤년 인자 받는 버전
{
    lunar_Month_days[1] = 28;

    if (y % 4 == 0)
    {
        if (y % 100 == 0 && y % 400 == 0)
            return;
    }
    else
        return;
    lunar_Month_days[1] = 29;
}
void Cal_leap() {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        Month_days[1] = 29;
    else
    	Month_days[1]=28;
}

void DayofYear::SetDday()
{
    cout << "\n\n날짜를 입력하시오 (월 일): ";
    int m, d;
    cin >> m >> d;
    while (m < 1 || m>12 || d < 1 || Month_days[m - 1] < d)
    {
        system("cls");
        Cal_leap();
        week = getweek(year, month);
        output_calendar();
        cout << "\n\n*************다시 입력해주세요.*************" << endl;
        cout << "\n\n날짜를 입력하시오 (월 일): ";
        cin >> m >> d;
    }

    d_mon = m;
    d_day = d;
}
void DayofYear::SetDdayHoliy(int year)
{
	char from_holiday_txt[103];
	FILE* fp;
    
	solar_t solar1_1, solar4_8, solar8_15;
    LunarToSolar(year, 1, 1, false, solar1_1);
    LunarToSolar(year, 4, 8, false, solar4_8);
    LunarToSolar(year, 8, 15, false, solar8_15);
	int hm, hd;
	cout << "\n\n공휴일을 입력하세요 (월 일): ";
	cin >> hm >> hd;
	
    while (!((hm==1&&hd==1)||(hm==3&&hd==1)||(hm==5&&hd==5)||(hm==6&&hd==6)||(hm==8&&hd==15)||
	(hm==10&&hd==3)||(hm==10&&hd==9)||(hm==12&&hd==25)||(hm==solar1_1.month&&hd==solar1_1.day)||
	(hm==solar4_8.month&&hd==solar4_8.day)||(hm==solar8_15.month&&hd==solar8_15.day)))
    	{
    		system("cls");
    		
			fp = fopen("holiday.txt", "r");
    		
    		cout << "\n\n " << year;
    		while (fgets(from_holiday_txt, 103, fp) != NULL)
    		{
        		cout << from_holiday_txt;
        		memset(from_holiday_txt, 0, 103);
    		}

			fclose(fp);

			gotoxy(1, 17);
    		cout << "설날";
    		gotoxy(1, 18);
    		cout << (int)solar1_1.month << "/" << (int)solar1_1.day << endl;
    		gotoxy(14, 17);
    		cout << "석가탄신일";
    		gotoxy(14, 18);
   			cout << (int)solar4_8.month << "/" << (int)solar4_8.day << endl;
    		gotoxy(30, 17);
    		cout << "추석";
    		gotoxy(30, 18);
    		cout << (int)solar8_15.month << "/" << (int)solar8_15.day << endl;
    	
    		if(hm < 1 || hm>12 || hd < 1 || Month_days[hm - 1] < hd)
    		{
    			cout << "\n\n*************범위를 벗어났습니다.*************" << endl;
        		cout << "\n*************다시 입력해주세요.*************" << endl;
        		cout << "\n\n공휴일을 입력하세요 (월 일): ";
        		cin >> hm >> hd;
        		return;
			}
			
    		cout << "\n\n*************공휴일이 아닙니다.*************" << endl;
        	cout << "\n*************다시 입력해주세요.*************" << endl;
        	cout << "\n\n공휴일을 입력하세요 (월 일): ";
        	cin >> hm >> hd;
		}
	d_mon = hm;
    d_day = hd;
}
void DayofYear::SetToday()
{
    cout << "\n\n기준이 될 날짜를 입력하세요 (월 일): ";
    int tm, td;
    cin >> tm >> td;
    while (tm < 1 || tm>12 || td < 1 || Month_days[tm - 1] < td)
    {
        system("cls");
        Cal_leap();
        week = getweek(year, month);
        output_calendar();
        cout << "\n\n*************다시 입력해주세요.*************" << endl;
        cout << "\n\n기준이 될 날짜를 입력하세요 (월 일): ";
        cin >> tm >> td;
    }

    t_mon = tm;
    t_day = td;

}

// 1월 1일부터 m월 d일까지 날짜 합

int DayofYear::GetPastDay(int m, int d)
{
    int i, past = 0;

    // 1월부터 바로 전달까지 날짜 합

    for (i = 1; i < m; i++)
    {
        past = past + Month_days[i - 1];
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


    cout << "\n\nD-day " << left << endl;
}

void output_calendar() {
    textcolor(15, 0);
    cout << "  " << endl << "      [" << year << "년 " << month << "월]      " << endl << endl << "  " <<
        "일 " << "월 " << "화 " << "수 " << "목 " << "금 " << "토  " << endl << endl << "  ";

    for (int i = 0; i <= week; i++)
    {
    	if(week==6) break; 
    	cout << "   ";
    }

    for (int j = 1; j <= Month_days[month - 1]; j++)
    {
        if (week % 7 == 5) textcolor(9, 0); // 토요일은 숫자 색을 파으로  
        else if (week % 7 == 6) textcolor(12, 0); // 일요일은 숫자 색을 빨색으로  
        else textcolor(15, 0);
        printf("%2d ", j);
        if ((week+1) % 7 == 6)
            cout << "  " << endl << "  ";
        week = (week + 1) % 7;
    }
    cout << endl;
    textcolor(15, 0);
}

void Select_Option(int& num) {
    gotoxy(59, 1);
    cout << "[원하는 옵션 선택]";
    gotoxy(60, 3);
    cout << "① 일정 관리(추가,변경,삭제,검색,확인) ";
    gotoxy(60, 4);
    cout << "② 날짜 계산";
    gotoxy(60, 5);
    cout << "③ 음력 변환";
    gotoxy(60, 6);
    cout << "④ 달력날짜 변경";
    gotoxy(60, 7);
    cout << "⑤ 올해 공휴일 확인";
    gotoxy(60, 8);
    cout << "⑥ 종료 ";
    gotoxy(60, 9);
    cout << endl;
    gotoxy(60, 10); 
    textcolor(2, 0);
    cout << "옵션 번호: ";
    cin >> num;
    textcolor(15,0);
//일정관리기능 추가,수정,삭제,검색,확인 
    if(num == 1)
    {
    	 system("cls");
         Cal_leap();
         week = getweek(year, month);
         output_calendar();
    	 schedule();
    	 system("cls");
         Cal_leap();
         week = getweek(year, month);
         output_calendar();
         Select_Option(num);
	}
    else if (num == 2)
    {
        system("cls");
        Cal_leap();
        week = getweek(year, month);
        output_calendar();
        dday();
        system("cls");
        Cal_leap();
        week = getweek(year, month);
        output_calendar();
        Select_Option(num);
    }
    else if (num == 3)
    {
        system("cls");
        Cal_leap();
        week = getweek(year, month);
        output_calendar();
        lunar_t lunar;
        while (!SolarToLunar(lunar))
        {
            system("cls");
            Cal_leap();
            week = getweek(year, month);
            output_calendar();
            cout << "\n\n*************다시 입력해주세요.*************" << endl;
        }
        Select_Option(num);
    }
    else if (num == 4) {
        system("cls");
        input();
        system("cls");
        Cal_leap();
        week = getweek(year, month);
        output_calendar();
        Select_Option(num);
    }
    else if ( num == 5)
	{
		system("cls");
        Cal_leap();
        week = getweek(year, month);
        output_calendar();
        holiday(year);
        Select_Option(num);
	} 
    else if (num == 6)
    {
        system("cls");
        cout << "\n프로그램을 종료합니다." << endl;
        Sleep(1000);
    }
    else {
        while (num != 1 && num != 2 && num != 3 && num != 4 && num != 5)
        {
            system("cls");
            Cal_leap();
            week = getweek(year, month);
            output_calendar();
            textcolor(12, 0);
            cout << "\n\n\n\n\n\n";
            cout << "*************다시 선택해주세요.*************" << endl;
            textcolor(15 ,0);
            Select_Option(num);
        }
    }
}

void textcolor(int foreground, int background) {
    int color = foreground + background * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

bool SolarToLunar(lunar_t& lunar)
{
    int Year, Month, Day;

    cout << "\n\n\n음력으로 바꿀 날짜를 입력하세요(연도 월 일) : ";
    cin >> Year >> Month >> Day;
    cout << endl;

    if (Year < 1841 || 2043 < Year)
    {
        return false;
    }
    if (Month < 1 || 12 < Month)
    {
        return false;
    }

    febdays(Year);

    if (Day < 1 || lunar_Month_days[Month - 1] < Day)
        return false;

    int ly, lm, ld;
    int m1, m2, mm, i, j;
    int sy = Year, sm = Month, sd = Day;
    long td, td1, td2;
    int dt[203];
    bool Yoon = false;

    td1 = 1840 * 365L + 1840 / 4 - 1840 / 100 + 1840 / 400 + 23;
    td2 = (sy - 1) * 365L + (sy - 1) / 4 - (sy - 1) / 100 + (sy - 1) / 400 + sd;

    for (i = 0; i < sm - 1; i++)
        td2 += lunar_Month_days[i];
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
                    Yoon = true;
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

    return true;
}
bool LunarToSolar(int Year, int Month, int Day, bool Leaf, solar_t& solar)
{
    if(Year < 1841 || 2043 < Year)
        return false;
 
    if(Month < 1 || 12 < Month)
        return false;
 
    int lyear, lmonth, lday, leapyes;
    int syear, smonth, sday;
    int mm, y1, y2, m1;
    int i, j, k1, k2, leap, w;
    long td, y;
    lyear = Year;
    lmonth = Month;
    y1 = lyear - 1841;
    m1 = lmonth - 1;
    leapyes = 0;
    
    if( _info_array[y1][m1] > 2)
        leapyes = Leaf;
    if( leapyes == 1)
    {
        switch( _info_array[y1][m1] )
        {
            case 3 :
            case 5 :
                mm = 29;
                break;
            case 4 :
            case 6 :
                mm = 30;
                break;
        }
    }
    else
    {
        switch( _info_array[y1][m1] )
        {
            case 1 :
            case 3 :
            case 4 :
                mm = 29;
                break;
            case 2 :
            case 5 :
            case 6 :
                mm = 30;
                break;
        }
    }

    lday = Day;
    td = 0;
    for(i=0; i<y1; i++)
    {
        for(j=0; j<12; j++)
        {
            switch( _info_array[i][j] )
            {
                case 1 :
                    td += 29;
                    break;
                case 2 :
                    td += 30;
                    break;
                case 3 :
                    td += 58;   // 29+29
                    break;
                case 4 :
                    td += 59;   // 29+30
                    break;
                case 5 :
                    td += 59;   // 30+29
                    break;
                case 6 :
                    td += 60;   // 30+30
                    break;
            }
        }
    }

    for (j=0; j<m1; j++)
    {
        switch( _info_array[y1][j] )
        {
            case 1 :
                td +=29;
                break;
            case 2 :
                td += 30;
                break;
            case 3 :
                td += 58;   // 29+29
                break;
            case 4 :
                td += 59;   // 29+30
                break;
            case 5 :
                td += 59;   // 30+29
                break;
            case 6 :
                td += 60;   // 30+30
                break;
        }
    }

    if( leapyes == 1 )
    {
        switch( _info_array[y1][m1] )
        {
            case 3 :
            case 4 :
                td += 29;
                break;
            case 5 :
            case 6 :
                td += 30;
                break;
        }
    }

    td += lday + 22;
    // td : 1841년1월1일부터원하는날까지의전체날수의합

    y1 = 1840;
    do {
        y1++;
        leap = (y1 % 400 == 0) || (y1 % 100 != 0) && (y1 % 4 ==0);
        if(leap)
            y2 = 366;
        else    
            y2 = 365;
        if(td <= y2)
            break;
        td -= y2;
       } while(1);
      
    syear = y1;
    solar_Month_days[1] = y2 - 337;
    m1 = 0;
    do
    {
        m1++;
        if( td <= solar_Month_days[m1-1] )
            break;
        td -= solar_Month_days[m1-1];
    } while(1);

    smonth = m1;
    sday = td;
    y = syear - 1;
    td = y * 365L + y/4 - y/100 + y/400;
    for(i=0; i<smonth-1; i++) td += solar_Month_days[i];
    td += sday;
    w = td % 7;
    i = (td + 4) % 10;
    j = (td + 2) % 12;
    k1 = (lyear + 6) % 10;
    k2 = (lyear + 8) % 12;
 
    solar.year = syear;
    solar.month = smonth;
    solar.day = sday;
    solar.dayofweek = w;

    return true;
}

void schedule()
{
	 int input;
     User user[MAX_NUM]; //일정 정보를 저장할 구조체 배열
     int plan = 0; //저장된 일정수
     openFile(user, &plan);//저장된 데이터를 불러오는 함수
     //메뉴 선택
     while (1){
     	  gotoxy(59, 1);
          cout << "[일정 관리 옵션]" << endl;
          gotoxy(60, 3);
          cout << "① 일정 추가" << endl;
          gotoxy(60, 4);
          cout << "② 일정 삭제" << endl;
          gotoxy(60, 5);
          cout << "③ 일정 검색" << endl; 
          gotoxy(60, 6);
          cout << "④ 일정 확인" << endl;
          gotoxy(60, 7);
          cout << "⑤ 저장하고 나가기" << endl;
          gotoxy(60, 9);
          textcolor(2, 0);
          cout << "옵션 번호: ";
          cin >> input;
          textcolor(15, 0);
       if (input == 1){
       		   system("cls");
               cout << endl << "[추가할 일정]" << endl << endl;
               insert(user, &plan, year);
          }
          else if (input == 2){
          	   system("cls");
               cout << endl << "[삭제할 일정]" << endl << endl;
               deleted(user, &plan);
          }
          else if (input == 3){
          	   system("cls");
               cout << endl << "[일정 검색]" << endl << endl;
               search(user, &plan);
          }
          else if (input == 4){
          	   system("cls");
               cout << endl << "[일정 확인]" << endl << endl;
               printAll(user, &plan);
          }
          else if (input == 5){
          	   system("cls");
               saveFile(user, &plan);
               break;
          }
          else if(input > 5 || input < 1){
          	   system("cls");
          	   textcolor(12, 0);
               cout << endl << endl << "다시 입력해주세요.";
               textcolor(15, 0);
             }
         }
}

//데이터를 파일에 저장하는 함수
int saveFile(User* ptr, int* num){

     if (*num >= 0){
          int i, state;
          FILE* fp = fopen("Schedule.txt", "wt");
          /* fopen함수는 오류발생시 NULL을 리턴하므로
          파일 개방 중 오류발생시 프로그램을 종료 */
          if (fp == NULL){
               cout << "File Open Error!" << endl;
               return 1;
          }
          //구조체 배열에 저장된 데이터를 파일에 저장
          //줄바꿈으로 구분하여 저장
          for (i = 0; i < *num; i++){
               fprintf(fp, "%s %s %s", ptr[i].name, ptr[i].year, ptr[i].day);
               fputc('\n', fp);
          }
          /* fclose함수는 종료시 오류가 발생하면
          0이 아닌 다른값을 리턴하므로 비정상 종료로 판단되면
          안내후 프로그램을 종료 */
          state = fclose(fp);
          if (state != 0){
               cout << "File Close Error!" << endl;
               return 1;
          }
          cout << endl << "Data Save \n";
          return 0;
     }
     else{
          cout << "Exit \n";
          return 0;
     }
}

//파일로부터 데이터를 불러오는 함수
int openFile(User* ptr, int* num){
     int state;
     char temp;
     FILE* fp = fopen("Schedule.txt", "rt");
     if (fp == NULL){
          cout << "File Open Error!" << endl;
          return 1;
     }
     //파일에 저장된 데이터를 구조체 배열에 저장
     while (1){
          fscanf(fp, "%s %s %s", ptr[*num].name, ptr[*num].year, ptr[*num].day);
          if (feof(fp) != 0)
               break;
          (*num)++;
     }
     /* fclose함수는 종료시 오류가 발생하면
     0이 아닌 다른값을 리턴하므로 비정상 종료로 판단되면
     안내후 프로그램을 종료 */
     state = fclose(fp);
     if (state != 0){
          cout << "File Close Error!" << endl;
          return 1;
     }
     return 0;
}
//일정 정보를 삽입하는 함수
void insert(User* ptr, int* num, int year){

     //일정정보가 꽉 차지 않으면
     if (*num < MAX_NUM){
          cout << "일정을 입력해주세요 : ";
          cin >> ptr[*num].name;
          itoa(year, ptr[*num].year, 10);
          cout << "날짜를 입력해주세요 : ";
          cin >> ptr[*num].day;

          (*num)++;
          cout << endl << "일정이 추가되었습니다." << endl;
     }
     //일정 정보가 꽉 차면
     else
          cout << "일정이 꽉 찼습니다." << endl << "불필요한 일정을 제거해주십시오." << endl; 
    }
//일정 정보를 삭제하는 함수
int deleted(User* ptr, int* num){
     char name[30];
     int i, j;
     //일정 정보가 한개라도 남아있으면
     if (*num > 0){
          cout << "삭제하고자하는 일정을 입력해주세요 : ";
          cin >> name; 
          for (i = 0; i < MAX_NUM; i++){
           //문자열이므로 비교하기위해 strcmp사용
               if (strcmp(name, ptr[i].name) == 0){

                    (*num)--;
                    cout << endl << "일정이 삭제되었습니다." << endl;
                    textcolor(12, 0);
					cout << "삭제된 일정: " << ptr[i].name;
					textcolor(15, 0);
                    //데이터가 가득 차지 않았다면
                    if (i != MAX_NUM - 1){
                         for (j = i; j < MAX_NUM; j++){
                              //문자열이므로 strcpy를 사용하여 데이터 복사
                              strcpy(ptr[j].name, ptr[j + 1].name);
                              strcpy(ptr[j].year, ptr[j + 1].year);
                              strcpy(ptr[j].day, ptr[j + 1].day);
                         }
                         //구조체 배열의 마지막을 NULL로 바꿈
                         *ptr[MAX_NUM - 1].name = NULL;
                         *ptr[MAX_NUM - 1].year = NULL;
                         *ptr[MAX_NUM - 1].day = NULL;
                    }
                        //데이터가 가득 찼다면
                    else{
                         //구조체 배열의 마지막을 NULL로 바꿈
                         *ptr[MAX_NUM - 1].name = NULL;
                         *ptr[MAX_NUM - 1].year = NULL;
                         *ptr[MAX_NUM - 1].day = NULL;
                    }
               return 0;
               }
          }
          cout << "찾지 못했습니다. \n\n";
          return 0;
     }
     //저장된 일정이 없다면
     else{
          cout << "-> 일정이 존재하지 않습니다. \n\n";
          return 0;
     }
}
//일정을 검색하는 함수
int search(User* ptr, int* num){
     char name[30];
     int i;
     //저장된 데이터가 있다면
     if (*num > 0){
          cout << "검색하고자 하는 일정을 입력해주세요 : ";
          cin >> name;
          for (i = 0; i < MAX_NUM; i++){
               //strcmp는 문자열이 일치할때 0을 반환
               //0은 C언어에서 거짓을 의미
               //그러므로 ! 을 붙여 참으로 변경하여 실행
               if (!strcmp(name, ptr[i].name)){
                    cout << endl << "일정: " << ptr[i].name << endl;
                    cout << "년도: " << ptr[i].year << endl;
                    cout << "날짜: " << ptr[i].day << endl;
                    return 0;
               }
          }
      cout << endl << "찾지 못했습니다." << endl;
      return 0;
     }
     else{
          cout << "-> 일정이 존재하지 않습니다." << endl << "   일정을 추가해주십시오." << endl;
          return 0;
     }
}
//저장된 모든 일정과 날짜 정보를 출력하는 함수
void printAll(User* ptr, int* num){
     int i = 0;
     if (*num > 0){
          for (i = 0; i < *num; i++){
               cout << "일정 : " << ptr[i].name << endl;
               cout << "연도 : " << ptr[i].year << endl;
               cout << "날짜 : " << ptr[i].day << endl;
          }
     }
     else
          cout << "-> 일정이 존재하지 않습니다." << endl << "   일정을 추가해주십시오." << endl;
}

void holiday(int year)
{
	solar_t solar1_1,solar4_8,solar8_15;
	LunarToSolar(year,1,1,false,solar1_1);
	LunarToSolar(year,4,8,false,solar4_8);
	LunarToSolar(year,8,15,false,solar8_15);

	char from_holiday_txt[103];
	FILE* fp;

	fp = fopen("holiday.txt", "r");
	
	cout << "\n\n\n " << year;
	
	while(fgets(from_holiday_txt,103,fp)!=NULL)
	{
		cout << from_holiday_txt;
		memset(from_holiday_txt,0,103);
	}
	
	gotoxy(1,29);
	cout << "설날";
	gotoxy(1,30);
	cout << (int)solar1_1.month << "/" << (int)solar1_1.day << endl;
	gotoxy(14,29); 
	cout << "석가탄신일";
	gotoxy(14,30);
	cout << (int)solar4_8.month << "/" << (int)solar4_8.day << endl;
	gotoxy(30,29);
	cout << "추석";
	gotoxy(30,30);
	cout << (int)solar8_15.month << "/" << (int)solar8_15.day << endl;
	
	fclose(fp);
}

void dday()
{
    int input;
    User user[MAX_NUM]; //일정 정보를 저장할 구조체 배열
    int plan = 0; //저장된 일정수
    openFile(user, &plan);//저장된 데이터를 불러오는 함수
    //메뉴 선택
    while (1) {
        gotoxy(59, 1);
        cout << "[날짜 계산]" << endl;
        gotoxy(60, 3);
        cout << "① 공휴일 D-day " << endl;
        gotoxy(60, 4);
        cout << "② D-day " << endl;
        gotoxy(60, 5);
        cout << "③ 나가기 " << endl;
        gotoxy(60, 9);
        textcolor(2, 0);
        cout << "옵션 번호: ";
        cin >> input;
        textcolor(15, 0);

        if (input == 1) {
            system("cls");
            openHoliDay(year);
            
        }
        else if (input == 2) {
            system("cls");
            DayofYear dy;
            dy.SetToday();
            dy.SetDday();
            dy.ShowLeftDay();
        }
        else if (input == 3) {
            system("cls");
            break;
        }
        else 
        {
            system("cls");
            textcolor(12, 0);
            cout << endl << endl << "다시 입력해주세요.";
            textcolor(15, 0);
        }
    }
}
void openHoliDay(int year) {
    char from_holiday_txt[103];
    DayofYear day;
    
    solar_t solar1_1, solar4_8, solar8_15;
    LunarToSolar(year, 1, 1, false, solar1_1);
    LunarToSolar(year, 4, 8, false, solar4_8);
    LunarToSolar(year, 8, 15, false, solar8_15);
    
    FILE* fp;
    fp = fopen("holiday.txt", "r");
 
    cout << "\n\n " << year;
    while (fgets(from_holiday_txt, 103, fp) != NULL)
    {
        cout << from_holiday_txt;
        memset(from_holiday_txt, 0, 103);
    }

	fclose(fp);

	gotoxy(1, 17);
    cout << "설날";
    gotoxy(1, 18);
    cout << (int)solar1_1.month << "/" << (int)solar1_1.day << endl;
    gotoxy(14, 17);
    cout << "석가탄신일";
    gotoxy(14, 18);
    cout << (int)solar4_8.month << "/" << (int)solar4_8.day << endl;
    gotoxy(30, 17);
    cout << "추석";
    gotoxy(30, 18);
    cout << (int)solar8_15.month << "/" << (int)solar8_15.day << endl;
    
	day.SetDdayHoliy(year);
    day.SetToday();
    day.ShowLeftDay();

    return ;
}
