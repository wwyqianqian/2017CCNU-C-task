/************************************************************************************************
                                  实 验 四

    从键盘输入一个四位正整数。首先分离出该正整数中的每一位数字，并按逆序显示输出各位数字；然后用分离出的每位数字组成一个最大数和一个最小数，并显示输出。
    例如，若输入的四位正整数为3175。按逆序显示输出分离出的各位数字为5713；组成的最大数为7531，组成的最小数为1357。

    具体要求：
    （1）输入前要有提示。并检查输入数据的合法性，若输入的数据不合法，则显示输出错误信息。
    （2）对输出结果要用英文或汉语拼音进行具体说明。

   〖实验提示〗
    （1）首先要判断输入的数据是否是四位整数。
    （2）然后分离出该四位正整数的四位数字，例如从千位到个位依次为a,b,c,d，则按逆序显示输出为dcba。
    （3）最后对四位数字a,b,c,d按从大到小进行排序，按该顺序组成一个最大数，按逆序组成一个最小数。

************************************************************************************************/
#include <stdio.h>

int main(void) {
    int input_no = 0;
    int split[4] = {10};
    int i = 0;
    int order[4] = {10};
    int tmp = 0;

    printf("type a number: ");
    scanf("%d", &input_no);

    while(input_no < 1000 || input_no > 9999) {
        printf("invalid input :");
        scanf("%d", &input_no);
    }
    while(input_no) {
        split[i] = input_no % 10;
        input_no /= 10;
        i++;
    }
    printf("reverse number is: ");
    for(int i=0; i<4; i++) {
        printf("%d", split[i]);
    }
    printf("\n");

    for(int m=1; m<4; m++) {
        for(int n=0; n<4-m; n++) {
            if(split[n]>split[n+1])
            {
                tmp = split[n];
                split[n] = split[n+1];
                split[n+1] = tmp;
            }
        }
    }
    printf("the smallest number can produce is: ");
    for(int f=0; f<4; f++) {
        printf("%d", split[f]);
    }
    printf("\n");
    printf("the largest number can produce is: ");
    for(int p=3; p>=0; p--) {
        printf("%d", split[p]);
    }
    printf("\n");
    return 0;
}
