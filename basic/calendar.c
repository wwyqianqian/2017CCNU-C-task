#include <stdio.h>

// 是否是闰年
#define LEAPYEAR(Y) (((Y) % 4) == 0 && ((Y) % 100 != 0) || ((Y) % 400) == 0)

// 返回year年month月的天数
inline int month_day(int year, int month)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 | month == 8 || month == 10 || month== 12)
        return 31;
    else if (month == 2)
        if (LEAPYEAR(year))
            return 29;
        else return 28;
    else 
        return 30;
}

// 生成日历头
inline void make_title(int start)
{
    if(start < 10)
        printf("%12c%d月%28c%d月%27c%d月\n", ' ', start, ' ', start + 1, ' ', start + 2);
    else
        printf("%12c%d月%27c%d月%26c%d月\n", ' ', start, ' ', start + 1, ' ', start + 2);
    printf("Mon Tue Wed Thu Fri Sat Sun    ");
    printf("Mon Tue Wed Thu Fri Sat Sun    ");
    printf("Mon Tue Wed Thu Fri Sat Sun\n");
}

// 计算year年month月day天是星期几，用来第一天对齐
int week_day(int year, int month, int day)
{
    /* 计算星期几 */
    int i;
    for(i = 1; i < month; ++i)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 | i == 8 || i == 10 || i== 12)
            day += 31;
        else if (i == 2)
        {
            if (LEAPYEAR(year))
                day += 29;
            else
                day += 28;
        }else
        {
            day += 30;
        }
    }
    int week_start = ((year - 1) + (int)((year - 1) / 4) - (int)((year - 1) / 100) \
    + (int)((year - 1) / 400) + day) % 7;
    return week_start == 0?7:week_start;
}

// 输出一行（一周）
void echo_line(int start_week, int start, int len)
{
    int i;
    // 补齐开头的空白
    for (i = 1; i < start_week; ++i)
        printf("    ");
    // 输出连续的天数，直到这周结束，或者这个月结束
    for(i = 0; i < len; start ++)
    {
        i++;
        printf("%-4d", start);
    }
    // 补齐结束的空白
    for(i = 0; i < 7 - (start_week + len - 1); ++i)
        printf("    ");
}

int main()
{
    int month = 1,          // 当前月
        day[3] = {1, 1, 1}, // 横排的三个月，每个月已经输出的天数
        year = 2017;        // 年

    int i = 0, j = 0, k = 0;

    int month_2 = 0;        // 横排的第几个
    int total_day[3] = {0, 0, 0};   // 横排的三个月的每个月的总天数
    int week_start[3] = {0, 0, 0};  // 横排三个月的每个月的第一天是星期几
    int len[3] = {0, 0, 0};         // 从开始到周结束的长度

    for(; month <= 12; )
    {
        make_title(month);
        // 似乎没用
        j = month + 3;
        // 横排第几个
        month_2 = month;

        // 初始化横排三个月的总天数
        for(i = 0; i < 3; i++)
            total_day[i] = month_day(year, month_2 + i);

        // 一直输出，直到三个月都输出完毕
        while(day[0] <= total_day[0] || day[1] <= total_day[1] || day[2] <= total_day[2])
        {
            // 分别输出三个月的每一行
            for(i = 0; i < 3; i++)
            {
                // 计算是第几周，不过其实只需要计算第一周是啥时候开始的就行
                week_start[i] = week_day(year, month_2, day[i]);
                // 从开始到结束有几天
                len[i] = 8 - week_start[i];
                // 如果超出这个月总共的天数，就修正一下长度
                if((day[i] + len[i] - 1) > total_day[i])
                    len[i] = total_day[i] - day[i] + 1;
                // 输出这一行，并不换行
                echo_line(week_start[i], day[i], len[i]);
                // 更新输出到了第几天
                day[i] = day[i] + 8 - week_start[i];
                // 处理横排的下一个
                month_2++;
                // 横排月中间四个空格
                printf("   ");
            }
            // 重设一下指示器
            month_2 = month;
            // 一周输出完毕，换行，下一周
            printf("\n");
        }
        // 下一个三个月
        month += 3;
        // 换行
        printf("\n");
        // 重置天数
        day[0] = 1;
        day[1] = 1;
        day[2] = 1;
    }
}