#include<stdio.h>
#include<time.h>
#define SUN 0
#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6
struct tm
{
    int tm_sec;   // 秒，范围从 0 到 59
    int tm_min;   // 分，范围从 0 到 59
    int tm_hour;  // 小时，范围从 0 到 23
    int tm_mday;  // 一个月中的第几天，范围从 1 到 31
    int tm_mon;   // 月份，范围从 0 到 11（注意：0 表示一月，11 表示十二月）
    int tm_year;  // 年份，从 1900 年开始计算
    int tm_wday;  // 一周中的第几天，范围从 0 到 6（注意：0 表示星期日，6 表示星期六）
    int tm_yday;  // 一年中的第几天，范围从 0 到 365（注意：0 表示 1 月 1 日，365 表示 12 月 31 日）
    int tm_isdst; // 夏令时标志，通常为 0、1 或 -1
};

// int main()
// {
//     // 定义一个指向结构体 tm 的指针 p，用于存储时间信息
//     struct tm *p;
//     // 定义一个 time_t 类型的变量 t，用于存储时间戳
//     time_t t;
//     // 获取当前时间的时间戳，并存储在变量 t 中
//     time(&t);
//     // 使用 localtime 函数将时间戳 t 转换为本地时间，并将结果存储在指针 p 所指向的结构体 tm 中
//     p=localtime(&t);
//     switch(p->tm_wday)
//     {
//         case MON:
//         case TUE:
//         case WED:
//         case THU:
//         case FRI:
//          printf("工作日\n");
//          break;
//         case SAT:
//         case SUN:
//          printf("周末\n");
//          break;
//         default:
//         printf("输入错误\n");
       

//     }
//     return 0;
// }
int main()
{
    enum Week {Sun, Mon, Tue, Wed, Thu, Fri, Sat};//可以不用define
    enum Week day;
    struct tm *p;
    time_t t;
    time(&t);
    p=localtime(&t);
    day=p->tm_wday;
    switch(p->tm_wday)
        {
            case MON:
            case TUE:
            case WED:
            case THU:
            case FRI:
             printf("工作日\n");
             break;
            case SAT:
            case SUN:
             printf("周末\n");
             break;
            default:
            printf("输入错误\n");
           
    
        }
    return 0;
}