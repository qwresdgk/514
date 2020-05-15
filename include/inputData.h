//
// Created by vcinex on 5/14/20.
//

#ifndef INC_514_INPUTDATA_H
#define INC_514_INPUTDATA_H

#include <zconf.h>
#include <libnet.h>
#include "utils.h"
#include "datatype.h"

static int stuBase(Student * newStu){
    char *desc[]= {"学生学号","姓名","身份证号","学院","学生类型","专业"};
    char *arg[]={newStu->stuId,newStu->name,newStu->personalId,newStu->school,newStu->major,newStu->stuType};
    int flag = inputMultiString(arg,6,desc);
    return flag;
}

static int stuTrans(Student * newStu){
    int tranNum = 0;
    inputInt(&tranNum,"路程中的换乘次数");

    for (int i = 0; i < tranNum; ++i) {
        char *desc[]= {"起点","终点","交通工具"};
        char *arg[]={newStu->trans[i].locationStart,newStu->trans[i].locationEnd,newStu->trans[i].tools};
        inputMultiString(arg,3,desc);
    }
    return tranNum;
}

static int stuOthers(Student * newStu){
    int otherNum = 0;
    inputInt(&otherNum,"你所接触人员个数");

    for (int j = 0; j < otherNum; ++j) {
        char *desc[]={"接触者的姓名","身份证号","接触地点","接触时间"};
        char *arg[]={newStu->others[j].name,newStu->others[j].personalId,newStu->others[j].location,newStu->others[j].time};
        inputMultiString(arg,4,desc);
    }
    return otherNum;
}

static int stuNow(Student * newStu){
    inputFloat(&newStu->info->temperature,"该生入校时的体温");
    char *arg[]={newStu->info->history,newStu->info->flag,newStu->info->time};
    char *desc[]={"病史","是否有发烧症状","入校时间"};
    int flag = inputMultiString(arg,3,desc);
    return flag+1;
}

int addStu(){
    if(0!=access(SCHOOLFOLDERS,W_OK)){
        mkdir(SCHOOLFOLDERS,S_IRWXU);
    }

    Student newStu;
    stuBase(&newStu);
    stuTrans(&newStu);
    stuOthers(&newStu);
    stuNow(&newStu);

    FILE *fp;

    int lenOfName = 0;
    for (; newStu.school[lenOfName]!='\0'; ++lenOfName) {}
    int length = sizeof(SCHOOLFOLDERS)+lenOfName;
    char *filename = (char *)malloc(sizeof(char)*length);
    *filename='\0';
    strcat(filename,SCHOOLFOLDERS);
    strcat(filename,newStu.school);

    fp = fopen(filename,"ab");
    if (fp == NULL)
        fp = fopen(filename,"wb");
    if(1 == fwrite(&newStu,sizeof(newStu),1,fp)) {
        fclose(fp);
        printf("录入成功\n");
        return 1;
    }
    else{
        printf("写入失败\n");
    }
}


#endif //INC_514_INPUTDATA_H
