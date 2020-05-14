#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datatype.h"
#define PATH "./data/"         //设定数据存储位置
#define PASSFILE "shadow"      //设定系统用户信息存储位置

int menuInput(){
    int order = 0;
    do {
        printf("请选择你的操作(输入命令前的数字后回车):\n");
        if (1==scanf("%d",&order))
            break;
        while (getchar()!='\n'); //消化掉多余输入
    }while (1);
}

int login(){
    //打开系统用户密码文件
    FILE *fp;
    char filename[20]=PATH;
    char s1[20] = PASSFILE;
    strcat(filename,PASSFILE);
    fp = fopen(filename,"r");
    if (fp == NULL){
        printf("对不起,系统用户信息文件不存在,无法登录.\n");
        return 0;
    }

    char user[20], pass[20], userX[20],passX[20];
    printf("请输入用户名与密码(以空格分开,以回车结束):\n");
    scanf("%s %s",user,pass);
    int fileEnd = 0; //标记文件结束
    int flag = 0;    //标记用户名与密码匹配情况
    do {
        if(2 != fscanf(fp,"%s %s",userX,passX))
            fileEnd = 1;
        if ((strcmp(user,userX)==0)&&(0==strcmp(pass,passX))){
            flag = 1;
        }
    }while ((fileEnd==0)&&(flag==0)); //文件未结束,用户名与密码未匹配成功则继续循环
    fclose(fp);
    return flag; //返回匹配情况,为1则登录成功,为0则登录失败.
}

int inputBaseData( Student * newStu){
    int flag;
    flag = 0;
    do {
        printf("请依次输入学生学号,姓名,身份证号,学院,学生类型,专业:\n");
        int stat;
        stat = scanf("%s %s %s %s %s %s",newStu->stuId,newStu->name,newStu->personalId,newStu->school,newStu->major,newStu->stuType);
        if (stat == 6)
            flag = 1;
        while (getchar()!='\n');
    }while (flag == 0);
    return flag;
}

int inputTrans(Student * newStu){
    int flag;

    int tranNum = 0;
    flag = 0;
    do {
        printf("请输入路程中的换乘次数:\n");
        if (1 == scanf("%d",&tranNum))
            flag = 1;
        while (getchar()!='\n');
    }while (flag == 0);

//    if ((newStu->trans = (Trans *)malloc(tranNum * sizeof(Trans))) == NULL){
//        printf("内存不足,添加失败.");
//        return 0;
//    }
    for (int i = 0; i < tranNum; ++i) {
        flag = 0;
        do {
            printf("请输入第%d段路程的起点,终点,交通工具.\n",i+1);
            if (3==scanf("%s %s %s",newStu->trans[i].locationStart,newStu->trans[i].locationEnd,newStu->trans[i].tools))
                flag = 1;
            while (getchar()!='\n');
        }while (flag == 0);
    }
    return tranNum;
}

int inputOthers(Student * newStu){
    int flag;

    int otherNum = 0;
    flag = 0;
    do {
        printf("请输入你所接触人员个数:\n");
        if (1 == scanf("%d",&otherNum))
            flag = 1;
        while (getchar()!='\n');
    }while (flag == 0);

//    if ((newStu->others = (Human *)malloc(otherNum * sizeof(Human))) == NULL){
//        printf("内存不足,添加失败.");
//        return 0;
//    }
    for (int j = 0; j < otherNum; ++j) {
        flag = 0;
        do {
            printf("请输入第%d位接触者的姓名,身份证号,接触地点,接触时间.\n",j+1);
            if (4==scanf("%s %s %s",newStu->others[j].name,newStu->others[j].personalId,newStu->others[j].location,newStu->others[j].time));
            flag = 1;
            while (getchar()!='\n');
        }while (flag == 0);
    }
    return otherNum;
}

int inputNow(Student * newStu){
    int flag;
    flag = 0;
    do {
        printf("请输入该生入校时的体温,病史,是否有发烧症状,入校时间\n");
        if(4 == scanf("%f %s %s %s",&newStu->info->temperature,newStu->info->history,newStu->info->flag,newStu->info->time))
            flag = 1;
        while (getchar()!='\n');
    }while (flag == 0);
    return flag;
}

int inputData(){
    Student newStu;
    inputBaseData(&newStu);
    int tranNum = inputTrans(&newStu);
    int otherNum = inputOthers(&newStu);
    inputNow(&newStu);

    FILE *fp;
    char filename[20]=PATH;
    char s1[20] = PATH;
    strcat(filename,(newStu.school));
    fp = fopen(filename,"ab");
    if (fp == NULL)
        fp = fopen(filename,"wb");
    if(1 == fwrite(&newStu,sizeof(newStu),1,fp))
        return 1;
    else{
        printf("写入失败\n");
    }
}

void sort();
void search();
void modify();
void show();

int main() {
    printf("Hello, World!\n");
    int loginStat = 0;
    do {
        loginStat = login();
    }while (loginStat==0);
    while (1){
        printf("####################################\n");
        printf("1.录入数据\n");
        printf("2.排序\n");
        printf("3.查找\n");
        printf("4.修改\n");
        printf("5.显示\n");
        printf("####################################\n");
        int flag = 0;
        int order = 0;
        do {
            if(1 == scanf("%d",&order))
                flag = 1;
            while (getchar()!='\n');
        }while (flag==0);
        switch (order) {
            case 1: inputData();
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
    }
    return 0;
}
