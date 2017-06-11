/************************************************************************************************
                                    实 验 十

  假设电话收费标准为:
    (1) 国际长途1.00元/分钟，
    (2) 国内长途0.60元/分钟，
    (3) 市话前3分钟0.20元，3分钟以后0.10元/分钟。现通过键盘输入6个话单记录（包括：通话日期、主叫码、被叫码、起始时间、通话时间）,要求计算每个话单的话费，并按话费从高到低输出所有的话单信息。

    话单格式：
    2006-06-06 67862101 01068790908 10:20:50 10:24:30

************************************************************************************************/
#include <stdio.h>
#include <string.h>

int TeleAttr(char *no);

int main(void) {
    int loc = 4;
    float pr = 0.000;

    struct Time {
        int hour;
        int min;
        int second;
    };

    struct Tele_Info {
        struct Time ymd;
        char call_no[50];
        char called_no[50];
        struct Time start_time;
        struct Time time_len;
        float price;
    };
    struct Tele_Info p[6];
    struct Tele_Info tele;
    struct Tele_Info tmp;

    for(int i=0; i<6; i++) {
        scanf("%d-%d-%d ", &tele.ymd.hour, &tele.ymd.min, &tele.ymd.second);
        scanf("%s %s", tele.call_no, tele.called_no);

        scanf("%d:%d:%d", &tele.start_time.hour, &tele.start_time.min, &tele.start_time.second);
        scanf("%d:%d:%d", &tele.time_len.hour, &tele.time_len.min, &tele.time_len.second);

        pr = 0;

        loc = TeleAttr(tele.called_no);
        switch(loc){
            case 0: pr = tele.time_len.hour * 6 + (tele.time_len.min - 3 + 1) * 0.1 + 3 * 0.2; break;
            case 1: pr = tele.time_len.hour * 36 + (tele.time_len.min + 1) * 0.6; break;
            case 2: pr = tele.time_len.hour * 60 + tele.time_len.min + 1; break;
        }
        tele.price = pr;
        p[i] = tele;
    }

    for(int m=1; m<6; m++) {
        for(int n=0; n<6-m; n++) {
            if(p[n].price<p[n+1].price)
            {
                tmp = p[n];
                p[n] = p[n+1];
                p[n+1] = tmp;
            }
        }
    }

    printf("排序后： ");
    printf("\n");
    for(int s=0; s<6; s++) {
        tele = p[s];
        printf("%d", s+1);
        printf(" %d-%d-%d", tele.ymd.hour, tele.ymd.min, tele.ymd.second);
        printf(" %s %s", tele.call_no, tele.called_no);
        printf(" %d:%d:%d", tele.start_time.hour, tele.start_time.min, tele.start_time.second);
        printf(" %d:%d:%d", tele.time_len.hour, tele.time_len.min, tele.time_len.second);
        printf("\n");
    }

    return 0;
}

int TeleAttr(char *called_no) {
    int lena = strlen(called_no);
    if(called_no[0]=='\0') return 1;
    if(lena==8) return 0;
    else return 2;
}
