//
// Created by vcinex on 5/14/20.
//

#ifndef INC_514_DATATYPE_H
#define INC_514_DATATYPE_H

//定义一段路程的交通路线及工具
typedef struct Trans{
    char locationStart[20];  //起点
    char locationEnd[20];    //终点
    char tools[8];           //所乘工具
    struct Trans * next;     //下一段路程
}Trans;

//定义接触者信息
typedef struct Human{
    char name[6];           //姓名
    char personalId[18];    //身份证号
    char location[20];      //接触地点
    char *time;             //接触时间
}Human;

//定义入校登记信息
typedef struct Info{
    float temperature;      //体温
    char * history;         //过去 14 天病史
    int flag;               //是否有发烧咳嗽等症状
    char *time;             //进校时间
}Info;

//定义学生信息
typedef struct student{
    char *stuId;            //定义学号
    char *name;             //定义姓名
    char *personalId;       //身份证号
    char *school;           //学院
    char *major;            //专业
    int stuType;            //学生类型(博士生、硕士生、本科生)
    Trans * trans;          //交通
    Human * others;         //接触人员
    Info *info;             //入校信息
}student;

#endif //INC_514_DATATYPE_H
