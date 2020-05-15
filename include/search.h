#ifndef INC_514_SEARCH_H
#define INC_514_SEARCH_H

int searchByStuId(){
    char stuId[20];
    inputString(stuId,"学号");

}

void search() {
    struct dirent **namelist;
    int n = scandir(SCHOOLFOLDERS, &namelist, filterDot, alphasort);
    if (n < 0) {
        printf("scandir(%s) failed:%s \n", SCHOOLFOLDERS, strerror(errno));
        return;
    }
    if (n == 0) {
        printf("没有找到学生信息文件\n");
        return;
    }
    int order = 0;

    printf("####################################\n");
    printf("#           1.按学号查找             #\n");
    printf("#           2.按学号查找             #\n");
    printf("#           3.按学号查找             #\n");
    printf("####################################\n");

    do {
        order = menuInput();
    }while (order<1||order>3);
    switch (order) {
        case 1:searchByStuId();
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
}


//    int option = menuInput();

////    int option;
//    int flag = 0;
//    do {
//        for (int i = 0; i < n; ++i) {
//            if(namelist[i]->d_type==DT_REG)
//                printf("%d. %-20s\n", i, namelist[i]->d_name);
//        }
//        option = menuInput();
//        if(option>=0&&option<=n&&namelist[option]->d_type==DT_REG)
//            flag=1;
//    }while (flag==0);
//}

#endif //INC_514_SEARCH_H
