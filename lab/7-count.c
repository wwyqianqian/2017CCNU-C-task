/************************************************************************************************
                                    实 验 七

  编写一个程序，其功能是将用户输入的一段英文（注意包含空格、逗号、句号及英文字母）分离出单词，并以每个单词出现的次数从高到低输出单词及其次数，次数相同的单词以其对应字符串大小升序输出。
例如：Green is on the left，Red is on the Right，the right is afraid of water, the left is afraid of insects.
输出：is(4)  the(4)  afraid(2)  left(2)  of(2)  on(2)  right(2) Green(1)  insects(1)  Red(1)  water(1)

[提示:
 (1) 建立一函数用于接收输入的英文段落。
 (2) 建立字符串数组用于保存每次分离出的单词，及出现的次数(编一函数) 。
 (3) 对字符串数组按规定进行排序(编一函数)]

************************************************************************************************/
#include<stdio.h>
#include<string.h>
struct node{
    char word[20] ;
    int num ;
} ;
int cmp (struct node a , struct node b ){
    if ( a.num != b.num ){
        return a.num > b.num ;
    }
    return a.word > b.word ;
}

int main () {
    int i , j , k = 0 , t =  0  , len , s = 0 , z = 0 , end = 0  ;
    char in[200] ;
    gets(in) ;
    len = strlen(in) ;
    struct node p[50] ;
    struct node q[50] ;
    struct node temp ;
    for (  i = 0 ; i < len ; i++) {
        in[i] = tolower(in[i]) ;
    }
    for ( i = 0 ; i < len ; i++ ) {
        if ( in[i] >= 'a' && in[i] <= 'z') {
            temp.word[k++] = in[i] ;
            temp.num = 1 ;
        }
        else if ( in[i+1] >= 'a' && in[i+1] <= 'z'){
            p[t++] = temp ;
            memset(temp.word,0,sizeof(temp.word)) ;
            temp.num = 0 ;
            k = 0 ;
        }
    }
    k = 0 ;
    for ( i = len -1 ; ; i-- ){
        if (in[i] >= 'a' && in[i] <= 'z' ) {
            p[t].word[k++] = in[i] ;
            p[t].num = 1 ;
        }
        if (in[i] == ' ' ) {
            break ;
        }
    }
    len = strlen(p[t].word) ;
    k = len - 1 ;
    s = 0 ;
    while ( s <= k ){
        char c = p[t].word[k] ;
        p[t].word[k] = p[t].word[s] ;
        p[t].word[s] = c ;
        s++ ;
        k--;
    }
    k = t  ;
    for ( i = k  ; i >= 0 ; i--) {
        int flag = 0 ;
        for ( j = 0 ; j < i ; j++ ){
            if ( strcmp(p[i].word , p[j].word) == 0 ){
                if ( flag == 0 ){
                    p[j].num++ ;
                    flag = 1 ;
                }
                else {
                    p[j].num = 0 ;
                }
            }
        }
        if ( flag == 0 ){
            q[z++] = p[i] ;
        }
        else {
            p[i].num = 0 ;
        }
    }
    for ( i = 0 ; i < z ; i++ ){
        for ( j = 0 ; j + i < z - 1 ; j++){
            if ( (q[j].num < q[j+1].num) || ((q[j].num==q[j+1].num)&&strcmp(q[j].word,q[j+1].word)>0 )){
                temp  = q[j] ;
                q[j] = q[j+1] ;
                q[j+1] = temp  ;
            }
        }
    }
    for  ( i= 0 ; i < z ; i++) {
        printf("%s:%d\n",q[i].word,q[i].num) ;
    }
    return 0 ;
}
