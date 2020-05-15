#ifndef INC_514_SORT_H
#define INC_514_SORT_H

#include <dirent.h>
#include <string.h>
#include <zconf.h>
#include <libnet.h>

static int filterDot(const struct dirent * dir) {
    if (strcmp(dir->d_name,".") == 0 || strcmp(dir->d_name, "..") == 0) {
        // 过滤掉 "."和".."
        return -1;
    } else {
        return 1;
    }
}

static int readFile(char *filename,Student *stuList ){
    FILE *fp;
    fp = fopen(filename,"r");
    if(fp==NULL){
        printf("对不起,该文件不存在.\n");
        return -1;
    }
    int  stuNum= 0;
    int flag = 0;
    do {
//        if(NULL==realloc(stuList,(stuNum+1)*sizeof(Student))){
//            printf("内存不足,无法读入.\n");
//        }

        if(1==fread(&(stuList[stuNum]),sizeof(Student),1,fp)){
            ++stuNum;
        } else{
            fclose(fp);
            flag=1;
        }
    }while (flag==0);
    return stuNum;
}

void sort(){
    struct dirent **namelist;
    int n = scandir(SCHOOLFOLDERS, &namelist, filterDot, alphasort);
    if(n<0){
        printf("scandir(%s) failed:%s \n", SCHOOLFOLDERS, strerror(errno));
        return;
    }
    if (n==0){
        printf("没有找到学生信息文件\n");
        return;
    }

//    int option=2;
    int option;
    int flag = 0;
    do {
        for (int i = 0; i < n; ++i) {
            if(namelist[i]->d_type==DT_REG)
                printf("%d. %-20s\n", i, namelist[i]->d_name);
        }
        option = menuInput();
        if(option>=0&&option<=n&&namelist[option]->d_type==DT_REG)
            flag=1;
    }while (flag==0);

    int lenOfName = 0;
    for (; namelist[option]->d_name[lenOfName]!='\0'; ++lenOfName) {}
    int length = sizeof(SCHOOLFOLDERS)+lenOfName;
    char *filename = (char *)malloc(sizeof(char)*length);
    *filename='\0';
    strcat(filename,SCHOOLFOLDERS);
    strcat(filename,namelist[option]->d_name);

    Student *stuList = (Student*)malloc(sizeof(Student));
    int stuNum = readFile(filename,stuList);
    for (int j = 0; j < stuNum; ++j) {
        printf("%s\n",stuList[j].name);
    }
}

#endif //INC_514_SORT_H
