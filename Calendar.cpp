#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>
using namespace std;
#define MAX_NUM 100 
/*  �Ʒ��� ���� ������ :

    ��� -  ���� �� : 1
            ū��    : 2
    ������ �ִ� �� -  ����� �۰� ���޵� ������ : 3
                      ����� �۰� ������ ũ��   : 4
                      ����� ũ�� ������ ������ : 5
                      ��ް� ������ ��� ũ��   : 6  */
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
    unsigned short lunar_year;         // ���º�ȯ�ĳ⵵(��°��ٸ�������)
    unsigned char lunar_month;              // ���º�ȯ�Ĵ�
    unsigned char lunar_day;                // ���º�ȯ����
    bool isyoondal;          // ���޿���0:���/1:����
} lunar_t;
typedef struct _solar_info
{
    unsigned short year;               // ��º�ȯ�ĳ⵵(���°��ٸ�������)
    unsigned char month;              // ��º�ȯ�Ĵ�
    unsigned char day;                // ��º�ȯ����
    unsigned char dayofweek;          // ���߿��������ڷ�( 0:��, 1:��... 6:��)
} solar_t;

int Month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int lunar_Month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int solar_Month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int year, month, week;
void input(); // ������ ���� �Է¹޴� �Լ�. 
int getweek(int year, int month);
static void febdays(int y); // ������ ���� �ִ� ����
void Cal_leap(); // ������ 
void output_calendar(); // �Է¹��� ������ ���� �޷��� ���  
void Select_Option(int&); // �ɼ��� ����ϰ� �Է¹��� 
void textcolor(int foreground, int background); //�����߰���� 
void gotoxy(int x, int y);
bool SolarToLunar(lunar_t& lunar); // ��� -> ����
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
	cout << endl << endl << " ����� ���ϴ� �޷��� ������ ���� �Է��ϼ���." << endl << endl;
	textcolor(15, 0);
    cout << " ��: ";
    cin >> year;
    cout << " ��: ";
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

static void febdays(int y)  // ���� ���� �޴� ����
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
    cout << "\n ��¥�� �Է��Ͻÿ� (�� ��): ";
    int m, d;
    cin >> m >> d;
    while (m < 1 || m>12 || d < 1 || Month_days[m - 1] < d)
    {
        system("cls");
        Cal_leap();
        week = getweek(year, month);
        output_calendar();
        cout << "\n\n*************�ٽ� �Է����ּ���.*************" << endl;
        cout << "\n ��¥�� �Է��Ͻÿ� (�� ��): ";
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
	cout << "\n �������� �Է��ϼ��� (�� ��): ";
	cin >> hm >> hd;
	
    while (!((hm==1&&hd==1)||(hm==3&&hd==1)||(hm==5&&hd==5)||(hm==6&&hd==6)||(hm==8&&hd==15)||
	(hm==10&&hd==3)||(hm==10&&hd==9)||(hm==12&&hd==25)||(hm==solar1_1.month&&hd==solar1_1.day)||
	(hm==solar4_8.month&&hd==solar4_8.day)||(hm==solar8_15.month&&hd==solar8_15.day)))
    	{
    		system("cls");
    		
			fp = fopen("holiday.txt", "r");
    		
    		textcolor(12, 0);
    		cout << "\n\n " << year;
    		while (fgets(from_holiday_txt, 103, fp) != NULL)
    		{
        		cout << from_holiday_txt;
        		memset(from_holiday_txt, 0, 103);
        		textcolor(15, 0);
    		}

			fclose(fp);

			gotoxy(1, 17);
    		cout << "����";
    		gotoxy(1, 18);
    		cout << (int)solar1_1.month << "/" << (int)solar1_1.day << endl;
    		gotoxy(14, 17);
    		cout << "����ź����";
    		gotoxy(14, 18);
   			cout << (int)solar4_8.month << "/" << (int)solar4_8.day << endl;
    		gotoxy(30, 17);
    		cout << "�߼�";
    		gotoxy(30, 18);
    		cout << (int)solar8_15.month << "/" << (int)solar8_15.day << endl;
    	
    		if(hm < 1 || hm>12 || hd < 1 || Month_days[hm - 1] < hd)
    		{
    			cout << "\n\n*************������ ������ϴ�.*************" << endl;
        		cout << "\n*************�ٽ� �Է����ּ���.*************" << endl;
        		cout << "\n\n �������� �Է��ϼ��� (�� ��): ";
        		cin >> hm >> hd;
        		return;
			}
			
    		cout << "\n\n************* �������� �ƴմϴ�. *************" << endl;
        	cout << "************* �ٽ� �Է����ּ���. *************" << endl;
        	cout << "\n �������� �Է��ϼ��� (�� ��): ";
        	cin >> hm >> hd;
		}
	d_mon = hm;
    d_day = hd;
}
void DayofYear::SetToday()
{ 
    cout << "\n ������ �� ��¥�� �Է��ϼ��� (�� ��): ";
    int tm, td;
    cin >> tm >> td;
    while (tm < 1 || tm>12 || td < 1 || Month_days[tm - 1] < td)
    {
        system("cls");
        Cal_leap();
        week = getweek(year, month);
        output_calendar();
        cout << "\n\n*************�ٽ� �Է����ּ���.*************" << endl;
        cout << "\n ������ �� ��¥�� �Է��ϼ��� (�� ��): ";
        cin >> tm >> td;
    }

    t_mon = tm;
    t_day = td;

}

// 1�� 1�Ϻ��� m�� d�ϱ��� ��¥ ��

int DayofYear::GetPastDay(int m, int d)
{
    int i, past = 0;

    // 1������ �ٷ� ���ޱ��� ��¥ ��

    for (i = 1; i < m; i++)
    {
        past = past + Month_days[i - 1];
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
        cout << endl << " D-day�� ���� ��¥���� �ռ� �� ����" << endl;
        return;
    }
	textcolor(14, 0); 
    cout << "\n\n D-day " << left << endl;
    textcolor(15 ,0);
} 

void output_calendar() {
    textcolor(15, 0);
    cout << "  " << endl << endl << "            << " << year << " / " << month << " >>      " << endl << endl << "     ";
    textcolor(0, 12);
	cout << "SUN";
	textcolor(0, 7);
	cout << " MON " << "TUE " << "WED " << "THU " << "FRI ";
	textcolor(0, 9);
	cout << "SAT";
	textcolor(15, 0);
	cout << endl << endl;
	
	if(week %7 != 6) cout << "     ";
	else cout << "  ";

    for (int i = 0; i <= week; i++)
    {
       if(week==6) break; 
       cout << "    ";
    }

    for (int j = 1; j <= Month_days[month - 1]; j++)
    {
        if (week % 7 == 5) textcolor(9, 0); // ������� ���� ���� �Ķ������� 
        else if (week % 7 == 6) {
			textcolor(12, 0); // �Ͽ����� ���� ���� ����������  
			cout << "   ";
		}
        else textcolor(15, 0);
        printf("%3d ", j);
        if ((week+1) % 7 == 6)
            cout << "  " << endl << "  ";
        week = (week + 1) % 7;
    }
    cout << endl;
    textcolor(15, 0);
}

void Select_Option(int& num) {
    gotoxy(45, 2);
    cout << "[���ϴ� �ɼ� ����]";
    gotoxy(46, 4);
    cout << "�� ���� ����(�߰�,����,����,�˻�,Ȯ��) ";
    gotoxy(46, 5);
    cout << "�� ��¥ ���";
    gotoxy(46, 6);
    cout << "�� ���� ��ȯ";
    gotoxy(46, 7);
    cout << "�� �޷³�¥ ����";
    gotoxy(46, 8);
    cout << "�� ���� ������ Ȯ��";
    gotoxy(46, 9);
    cout << "�� ���� ";
    gotoxy(46, 10);
    cout << endl;
    gotoxy(46, 11); 
    textcolor(2, 0);
    cout << "�ɼ� ��ȣ: ";
    cin >> num;
    textcolor(15,0);
//����������� �߰�,����,����,�˻�,Ȯ�� 
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
            cout << "\n\n*************�ٽ� �Է����ּ���.*************" << endl;
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
        cout << "\n���α׷��� �����մϴ�." << endl;
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
            cout << "*************�ٽ� �������ּ���.*************" << endl;
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

    cout << "\n\n\n�������� �ٲ� ��¥�� �Է��ϼ���(���� �� ��) : ";
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

    cout << "����: " << lunar.lunar_year << "�� " <<
        (int)lunar.lunar_month << "�� " << (int)lunar.lunar_day << "��" << endl;
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
    // td : 1841��1��1�Ϻ��Ϳ��ϴ³���������ü��������

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
     User user[MAX_NUM]; //���� ������ ������ ����ü �迭
     int plan = 0; //����� ������
     openFile(user, &plan);//����� �����͸� �ҷ����� �Լ�
     //�޴� ����
     while (1){
     	  gotoxy(45, 2);
          cout << "[���� ���� �ɼ�]" << endl;
          gotoxy(46, 4);
          cout << "�� ���� �߰�" << endl;
          gotoxy(46, 5);
          cout << "�� ���� ����" << endl;
          gotoxy(46, 6);
          cout << "�� ���� �˻�" << endl; 
          gotoxy(46, 7);
          cout << "�� ���� Ȯ��" << endl;
          gotoxy(46, 8);
          cout << "�� �����ϰ� ������" << endl;
          gotoxy(46, 10);
          textcolor(2, 0);
          cout << "�ɼ� ��ȣ: ";
          cin >> input;
          textcolor(15, 0);
       if (input == 1){
       		   system("cls");
               cout << endl << endl << " [�߰��� ����]" << endl << endl;
               insert(user, &plan, year);
          }
          else if (input == 2){
          	   system("cls");
               cout << endl << endl << " [������ ����]" << endl << endl;
               deleted(user, &plan);
          }
          else if (input == 3){
          	   system("cls");
               cout << endl << endl << " [���� �˻�]" << endl << endl;
               search(user, &plan);
          }
          else if (input == 4){
          	   system("cls");
               cout << endl << endl << " [���� Ȯ��]" << endl << endl;
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
               cout << endl << endl << " �ٽ� �Է����ּ���.";
               textcolor(15, 0);
             }
         }
}

//�����͸� ���Ͽ� �����ϴ� �Լ�
int saveFile(User* ptr, int* num){

     if (*num >= 0){
          int i, state;
          FILE* fp = fopen("Schedule.txt", "wt");
          /* fopen�Լ��� �����߻��� NULL�� �����ϹǷ�
          ���� ���� �� �����߻��� ���α׷��� ���� */
          if (fp == NULL){
               cout << "File Open Error!" << endl;
               return 1;
          }
          //����ü �迭�� ����� �����͸� ���Ͽ� ����
          //�ٹٲ����� �����Ͽ� ����
          for (i = 0; i < *num; i++){
               fprintf(fp, "%s %s %s", ptr[i].name, ptr[i].year, ptr[i].day);
               fputc('\n', fp);
          }
          /* fclose�Լ��� ����� ������ �߻��ϸ�
          0�� �ƴ� �ٸ����� �����ϹǷ� ������ ����� �ǴܵǸ�
          �ȳ��� ���α׷��� ���� */
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

//���Ϸκ��� �����͸� �ҷ����� �Լ�
int openFile(User* ptr, int* num){
     int state;
     char temp;
     FILE* fp = fopen("Schedule.txt", "rt");
     if (fp == NULL){
          cout << "File Open Error!" << endl;
          return 1;
     }
     //���Ͽ� ����� �����͸� ����ü �迭�� ����
     while (1){
          fscanf(fp, "%s %s %s", ptr[*num].name, ptr[*num].year, ptr[*num].day);
          if (feof(fp) != 0)
               break;
          (*num)++;
     }
     /* fclose�Լ��� ����� ������ �߻��ϸ�
     0�� �ƴ� �ٸ����� �����ϹǷ� ������ ����� �ǴܵǸ�
     �ȳ��� ���α׷��� ���� */
     state = fclose(fp);
     if (state != 0){
          cout << "File Close Error!" << endl;
          return 1;
     }
     return 0;
}
//���� ������ �����ϴ� �Լ�
void insert(User* ptr, int* num, int year){

     //���������� �� ���� ������
     if (*num < MAX_NUM){
          cout << " ������ �Է����ּ��� : ";
          cin >> ptr[*num].name;
          itoa(year, ptr[*num].year, 10);
          cout << " ��¥�� �Է����ּ��� : ";
          cin >> ptr[*num].day;

          (*num)++;
          cout << endl << " ������ �߰��Ǿ����ϴ�." << endl;
     }
     //���� ������ �� ����
     else
          cout << " ������ �� á���ϴ�." << endl << " ���ʿ��� ������ �������ֽʽÿ�." << endl; 
    }
//���� ������ �����ϴ� �Լ�
int deleted(User* ptr, int* num){
     char name[30];
     int i, j;
     //���� ������ �Ѱ��� ����������
     if (*num > 0){
          cout << " �����ϰ����ϴ� ������ �Է����ּ���: " << endl << " ";
          cin >> name; 
          for (i = 0; i < MAX_NUM; i++){
           //���ڿ��̹Ƿ� ���ϱ����� strcmp���
               if (strcmp(name, ptr[i].name) == 0){

                    (*num)--;
                    cout << endl << " ������ �����Ǿ����ϴ�." << endl;
                    textcolor(12, 0);
					cout << " ������ ����: " << ptr[i].name;
					textcolor(15, 0);
                    //�����Ͱ� ���� ���� �ʾҴٸ�
                    if (i != MAX_NUM - 1){
                         for (j = i; j < MAX_NUM; j++){
                              //���ڿ��̹Ƿ� strcpy�� ����Ͽ� ������ ����
                              strcpy(ptr[j].name, ptr[j + 1].name);
                              strcpy(ptr[j].year, ptr[j + 1].year);
                              strcpy(ptr[j].day, ptr[j + 1].day);
                         }
                         //����ü �迭�� �������� NULL�� �ٲ�
                         *ptr[MAX_NUM - 1].name = NULL;
                         *ptr[MAX_NUM - 1].year = NULL;
                         *ptr[MAX_NUM - 1].day = NULL;
                    }
                        //�����Ͱ� ���� á�ٸ�
                    else{
                         //����ü �迭�� �������� NULL�� �ٲ�
                         *ptr[MAX_NUM - 1].name = NULL;
                         *ptr[MAX_NUM - 1].year = NULL;
                         *ptr[MAX_NUM - 1].day = NULL;
                    }
               return 0;
               }
          }
          cout << endl << " ã�� ���߽��ϴ�. \n\n";
          return 0;
     }
     //����� ������ ���ٸ�
     else{
          cout << "-> ������ �������� �ʽ��ϴ�. \n\n";
          return 0;
     }
}
//������ �˻��ϴ� �Լ�
int search(User* ptr, int* num){
     char name[30];
     int i;
     //����� �����Ͱ� �ִٸ�
     if (*num > 0){
          cout << " �˻��ϰ��� �ϴ� ������ �Է����ּ���: " << endl << " ";
          cin >> name;
          for (i = 0; i < MAX_NUM; i++){
               //strcmp�� ���ڿ��� ��ġ�Ҷ� 0�� ��ȯ
               //0�� C���� ������ �ǹ�
               //�׷��Ƿ� ! �� �ٿ� ������ �����Ͽ� ����
               if (!strcmp(name, ptr[i].name)){
                    cout << endl << " ����: " << ptr[i].name << endl;
                    cout << " �⵵: " << ptr[i].year << endl;
                    cout << " ��¥: " << ptr[i].day << endl << endl;
                    return 0;
               }
          }
      cout << endl << " ã�� ���߽��ϴ�." << endl;
      return 0;
     }
     else{
          cout << "-> ������ �������� �ʽ��ϴ�." << endl << "   ������ �߰����ֽʽÿ�." << endl;
          return 0;
     }
}
//����� ��� ������ ��¥ ������ ����ϴ� �Լ�
void printAll(User* ptr, int* num){
     int i = 0;
     if (*num > 0){
          for (i = 0; i < *num; i++){
               cout << " ���� : " << ptr[i].name << endl;
               cout << " ���� : " << ptr[i].year << endl;
               cout << " ��¥ : " << ptr[i].day << endl << endl;
          }
     }
     else
          cout << "-> ������ �������� �ʽ��ϴ�." << endl << "   ������ �߰����ֽʽÿ�." << endl;
}

void holiday(int year)
{
	textcolor(12, 0);
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
		textcolor(15, 0);
	}
	
	gotoxy(1,29);
	cout << "����";
	gotoxy(1,30);
	cout << (int)solar1_1.month << "/" << (int)solar1_1.day << endl;
	gotoxy(14,29); 
	cout << "����ź����";
	gotoxy(14,30);
	cout << (int)solar4_8.month << "/" << (int)solar4_8.day << endl;
	gotoxy(30,29);
	cout << "�߼�";
	gotoxy(30,30);
	cout << (int)solar8_15.month << "/" << (int)solar8_15.day << endl;
	
	fclose(fp);
}

void dday()
{
    int input;
    User user[MAX_NUM]; //���� ������ ������ ����ü �迭
    int plan = 0; //����� ������
    openFile(user, &plan);//����� �����͸� �ҷ����� �Լ�
    //�޴� ����
    while (1) {
        gotoxy(45, 2);
        cout << "[��¥ ���]" << endl;
        gotoxy(46, 4);
        cout << "�� ������ D-day " << endl;
        gotoxy(46, 5);
        cout << "�� D-day " << endl;
        gotoxy(46, 6);
        cout << "�� ������ " << endl;
        gotoxy(46, 8);
        textcolor(2, 0);
        cout << "�ɼ� ��ȣ: ";
        cin >> input;
        textcolor(15, 0);

        if (input == 1) {
            system("cls");
            openHoliDay(year);
            
        }
        else if (input == 2) {
            system("cls");
            DayofYear dy;
            cout << endl << endl << " [ D-DAY ��� ]" << endl;
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
            cout << endl << endl << "�ٽ� �Է����ּ���.";
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
    
 	textcolor(12, 0);
    cout << "\n\n " << year;
    while (fgets(from_holiday_txt, 103, fp) != NULL)
    {
        cout << from_holiday_txt;
        memset(from_holiday_txt, 0, 103);
        textcolor(15, 0);
    }

	fclose(fp);

	gotoxy(1, 17);
    cout << "����";
    gotoxy(1, 18);
    cout << (int)solar1_1.month << "/" << (int)solar1_1.day << endl;
    gotoxy(14, 17);
    cout << "����ź����";
    gotoxy(14, 18);
    cout << (int)solar4_8.month << "/" << (int)solar4_8.day << endl;
    gotoxy(30, 17);
    cout << "�߼�";
    gotoxy(30, 18);
    cout << (int)solar8_15.month << "/" << (int)solar8_15.day << endl;
    cout << "_______________________________________" << endl;
    
	day.SetDdayHoliy(year);
    day.SetToday();
    day.ShowLeftDay();

    return ;
}
