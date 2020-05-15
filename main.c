#define PATH "./data/"         //设定数据存储位置
#define SCHOOLFOLDERS "./data/school/"
#define PASSFILE "./data/shadow"      //设定系统用户信息存储位置

#include <stdio.h>
#include "include/inputData.h"
#include "include/login.h"
#include "include/sort.h"
#include "include/search.h"

void modify(){}
void show(){}

int main() {
    printf("Hello, World!\n");
    int loginStat = 0;
    do {
        loginStat = login();
    }while (loginStat==0);

    int order = 0;
    do {
        printf("####################################\n");
        printf("#              1.录入               #\n");
        printf("#              2.排序               #\n");
        printf("#              3.查找               #\n");
        printf("#              4.修改               #\n");
        printf("#              5.显示               #\n");
        printf("####################################\n");

        order = 0;
        do {
            order=menuInput();
        }while (order<1||order>5);
        switch (order) {
            case 1:
                addStu();
                break;
            case 2: sort();
                break;
            case 3: search();
                break;
            case 4: modify();
                break;
            case 5: show();
                break;
            default:
                printf("你输入的指令有误,请重新输入\n");
        }
    }while (loginStat==1);
    return 0;
}
