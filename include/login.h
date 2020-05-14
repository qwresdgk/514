
#ifndef INC_514_LOGIN_H
#define INC_514_LOGIN_H

int login(){
    //打开系统用户密码文件
    return 1;
    FILE *fp;
    fp = fopen(PASSFILE,"r");
    if (fp == NULL){
        printf("对不起,系统用户信息文件不存在,无法登录.\n");
        fp=fopen(PASSFILE,"w");
        fclose(fp);
        return 0;
    }

    char user[20], pass[20], userX[20],passX[20];
    char *arg[] = {user,pass};
    char *desc[] = {"用户名","密码"};
    inputMultiString(arg,2,desc);

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


#endif //INC_514_LOGIN_H
